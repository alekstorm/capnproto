// Copyright (c) 2013, Kenton Varda <temporal@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

package capnproto
package composite

import java.lang.{Boolean => BoxedBoolean, Byte => BoxedByte, Double => BoxedDouble, Float => BoxedFloat,
  Integer => BoxedInt, Long => BoxedLong, Short => BoxedShort}
import java.util.AbstractList

import scala.collection.generic.Growable
import scala.math.{ceil, min}

import spire.math.{UByte, UInt, ULong, UShort}
import spire.syntax._

import bitsy._; import Quantity.implicits._
import internal._

class ListGateway[T](override val context: BaseContext[ListPointerTarget], default: Option[Array[Byte]])
    (implicit formatter: Formatter[T])
    extends CollectionGateway[List[T]] {
  override def reader = new List[T](context, ui"0")
}

class ModifiableListGateway[T](context: BaseContext[ListPointerTarget], default: Option[Array[Byte]])
    (implicit formatter: Formatter[T])
    extends ListGateway[T](context, default) with ModifiableCollectionGateway[List[T], ModifiableList[T]] {
  private var capacity = ui"0"

  override def builder = if (context.isReset) None else Some(directBuilder)

  override def init(capacity: UInt = ui"0"): ModifiableList[T] = {
    allocate(ui"0", capacity)
    directBuilder
  }

  override def resize(newCapacity: UInt): ModifiableList[T] = {
    val oldContext = context
    allocate(UInt(min(context.near.elemCount.toInt, newCapacity.toInt)), newCapacity) // FIXME add min/max to UInt, etc
    if (context != oldContext)
      NearContext.copyComposite(oldContext.near, context.near) // TODO handle un-init'd oldContext
    directBuilder
  }

  override def set(other: List[T]): ModifiableList[T] = {
    allocate(UInt(other.size), other.capacity)
    NearContext.copyComposite(other.context.near, context.near)
    directBuilder
  }

  // TODO consider having a separate class for fill'd Lists that doesn't support appending, etc
  def fill(size: UInt): ModifiableList[T] = {
    allocate(size, size)
    NearContext.eraseComposite(context.near)
    directBuilder
  }

  private def directBuilder = new ModifiableList[T](context, capacity)

  // TODO rename to be different from superclass version
  private def allocate(newCount: UInt, newCapacity: UInt) {
    val elemSize = formatter.size match {
      case p: PrimitiveElemSize => p.bits
      case CompositeElemSize(dataSize, pointerSize) => 0 bits // FIXME
    }
    val listSize = (elemSize * newCapacity.toInt).toWords // FIXME
    val (targetSegmentId, offset) = allocate(listSize)
    if (targetSegmentId == context.segmentId) {
      context.near.writeNearPointer(offset, formatter.size match {
        case p: PrimitiveElemSize => PrimitiveListPointerTarget(p, newCount)
        case CompositeElemSize(dataSize, pointerSize) => CompositeListPointerTarget(listSize)
      })
    }
    else {
      val newNearPointerTarget = context.near.pointer.target match {
        case PrimitiveListPointerTarget(elemSize, elemCount) => PrimitiveListPointerTarget(elemSize, newCount)
        case CompositeListPointerTarget(_) => CompositeListPointerTarget(listSize)
      }
      context.writeFarPointer(FarPointer(false, 0 words, targetSegmentId), 1 words, newNearPointerTarget)
    }
    capacity = newCapacity
  }
}

// can't make a type alias, since it would be invisible from Java
//class ModifiableDataGateway(context: BaseContext[ListPointerTarget], default: Option[Array[Byte]])(implicit formatter: Formatter[UByte]) extends ModifiableListGateway[UByte](context, default)

// TODO does specializing automatically work on value classes?
// TODO make covariant (?)
// TODO use @specialized(Boolean, Byte, Short, Int, Long, Float, Double)
// TODO use default
// expose an interface that provides random element access and modification, but insertion and removal only at the end, with a maximum size (capacity)
// TODO separate classes for reset, allocated Lists
class List[T](override val context: BaseContext[ListPointerTarget], _capacity: UInt)(implicit formatter: Formatter[T])
    extends AbstractList[T] with Comparable[List[T]] with Collection[List[T], ModifiableList[T]] {
  protected def segment = NearContext.compositeSegment(context.near)

  override def size = if (context.isReset) 0 else context.near.elemCount.toInt // FIXME (?)

  // TODO make scala Traversable
  /*override*/ final def apply(idx: Int) = get(idx)
  /*override*/ final def length() = size
  /*override*/ final def seq = this

  override final def get(idx: Int) = {
    if (context.isReset || idx >= size)
      throw new Exception
    formatter.read(context, idx)
  }

  // FIXME
  override final def compareTo(other: List[T]) = {
    if (context.isReset)
      if (other.context.isReset) 1 else 0
    else
      segment.buffer.compareTo(other.segment.buffer)
  }

  final def capacity = _capacity
}

// TODO consider making inner class of List as well
class ModifiableList[T](context: BaseContext[ListPointerTarget], private var _capacity: UInt)
    (implicit formatter: Formatter[T])
    extends List[T](context, _capacity) with Growable[T] {

  override def set(idx: Int, value: T) = {
    if (idx >= size)
      throw new Exception // FIXME
    val prev = get(idx)
    formatter.write(context, idx, value)
    prev
  }

  override def add(value: T) = {
    if (UInt(size) == capacity)
      throw new Exception // FIXME
    context.near.elemCount += ui"1"
    set(size - 1, value)
    true
  }

  override def +=(value: T) = {
    add(value)
    this
  }

  override def clear() {
    context.near.elemCount = ui"0"
  }

  def update(idx: Int, value: T) {
    set(idx, value)
  }

  def remove() = removeCount(1)
  def removeCount(count: Int) = {
    context.near.elemCount -= ui"1"
    this
  }
}

// TODO
//type Data = List[Byte]
//type ModifiableData = ModifiableList[Byte]

sealed trait Formatter[T] {
  def size: ElemSize
  def read(context: BaseContext[ListPointerTarget], idx: Int): T
  def write(context: BaseContext[ListPointerTarget], idx: Int, value: T)
}

// TODO propose @notDocumentable, to disable doc generation for some compilation unit
object Formatter {
  final val voidEmpty = () // TODO make this a member of Formatter (?)
  // can't be `object`s because nested objects can't be accessed from Java (even as Formatter$voidFormatter$)
  class VoidFormatter extends Formatter[Unit] { // FIXME BoxedUnit?
    def size = ZeroElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readVoid(idx, voidEmpty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: Unit) { context.near.segment.writeVoid(idx, value, voidEmpty) }
  }
  def voidFormatter = new VoidFormatter

  final val boolEmpty = false
  class BoolFormatter extends Formatter[BoxedBoolean] {
    def size = BitElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readBool(context.near.targetOffset.toBits + idx, boolEmpty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: BoxedBoolean) { context.near.segment.writeBool(context.near.targetOffset.toBits + idx, value, boolEmpty) }
  }
  def boolFormatter = new BoolFormatter

  final val uint8Empty = ub"0"
  class UInt8Formatter extends Formatter[UByte] {
    def size = ByteElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readUInt8(context.near.targetOffset.toBytes + idx, uint8Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: UByte) { context.near.segment.writeUInt8(context.near.targetOffset.toBytes + idx, value, uint8Empty) }
  }
  def uint8Formatter = new UInt8Formatter

  final val uint16Empty = uh"0"
  class UInt16Formatter extends Formatter[UShort] {
    def size = ShortElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readUInt16(context.near.targetOffset.toShorts + idx, uint16Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: UShort) { context.near.segment.writeUInt16(context.near.targetOffset.toShorts + idx, value, uint16Empty) }
  }
  def uint16Formatter = new UInt16Formatter

  final val uint32Empty = ui"0"
  class UInt32Formatter extends Formatter[UInt] {
    def size = QuadElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readUInt32(context.near.targetOffset.toQuads + idx, uint32Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: UInt) { context.near.segment.writeUInt32(context.near.targetOffset.toQuads + idx, value, uint32Empty) }
  }
  def uint32Formatter = new UInt32Formatter

  final val uint64Empty = ul"0"
  class UInt64Formatter extends Formatter[ULong] {
    def size = WordElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readUInt64(context.near.targetOffset + idx, uint64Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: ULong) { context.near.segment.writeUInt64(context.near.targetOffset + idx, value, uint64Empty) }
  }
  def uint64Formatter = new UInt64Formatter

  final val int8Empty = b"0"
  class Int8Formatter extends Formatter[BoxedByte] {
    def size = ByteElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readInt8(context.near.targetOffset.toBytes + idx, int8Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: BoxedByte) { context.near.segment.writeInt8(context.near.targetOffset.toBytes + idx, value, int8Empty) }
  }
  def int8Formatter = new Int8Formatter

  final val int16Empty = h"0"
  class Int16Formatter extends Formatter[BoxedShort] {
    def size = ShortElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readInt16(context.near.targetOffset.toShorts + idx, int16Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: BoxedShort) { context.near.segment.writeInt16(context.near.targetOffset.toShorts + idx, value, int16Empty) }
  }
  def int16Formatter = new Int16Formatter

  final val int32Empty = 0
  class Int32Formatter extends Formatter[BoxedInt] {
    def size = QuadElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readInt32(context.near.targetOffset.toQuads + idx, int32Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: BoxedInt) { context.near.segment.writeInt32(context.near.targetOffset.toQuads + idx, value, int32Empty) }
  }
  def int32Formatter = new Int32Formatter

  final val int64Empty = 0L
  class Int64Formatter extends Formatter[BoxedLong] {
    def size = WordElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readInt64(context.near.targetOffset + idx, int64Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: BoxedLong) { context.near.segment.writeInt64(context.near.targetOffset + idx, value, int64Empty) }
  }
  def int64Formatter = new Int64Formatter

  final val float32Empty = 0.0F
  class Float32Formatter extends Formatter[BoxedFloat] {
    def size = QuadElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readFloat32(context.near.targetOffset.toQuads + idx, float32Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: BoxedFloat) { context.near.segment.writeFloat32(context.near.targetOffset.toQuads + idx, value, float32Empty) }
  }
  def float32Formatter = new Float32Formatter

  final val float64Empty = 0.0
  class Float64Formatter extends Formatter[BoxedDouble] {
    def size = WordElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = context.near.segment.readFloat64(context.near.targetOffset + idx, float64Empty)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: BoxedDouble) { context.near.segment.writeFloat64(context.near.targetOffset + idx, value, float64Empty) }
  }
  def float64Formatter = new Float64Formatter

  final val enumEmpty = uh"0"
  class EnumFormatter[E <: Enum[E]](enumerants: Array[E]) extends Formatter[E] {
    def size = ShortElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = enumerants(context.near.segment.readEnum(context.near.targetOffset.toShorts + idx, enumEmpty).toInt)
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: E) { context.near.segment.writeEnum(context.near.targetOffset.toShorts + idx, UShort(value.ordinal()), enumEmpty) }
  }
  def enumFormatter[E <: Enum[E]](enumerants: Array[E]) = new EnumFormatter[E](enumerants)

  // TODO is there a way to not pass all these type parameters?
  /*class CompositeFormatter[C <: Composite[C, _], P <: NearPointerTarget, G <: Gateway[C, P]](gateway: BaseContext[P] => G, mutableGateway: BaseContext[P] => MG) extends Formatter[G] {
    def size = PointerElemSize
    def read(context: BaseContext[ListPointerTarget], idx: Int) = gateway(new Context(context.manager, context.near.segmentId, context.near.targetOffset + idx)).reader
    def write(context: BaseContext[ListPointerTarget], idx: Int, value: C) { mutableGateway(new Context(context.manager, context.near.segmentId, context.near.targetOffset + idx)).set(value) }
  }
  def listFormatter[T](implicit elemFormatter: Formatter[T]) = new CompositeFormatter[List[T], ListPointerTarget, ListGateway[T], ModifiableListGateway[T]](new ListGateway[T](_, None), new ModifiableListGateway[T](_, None))
  //def textFormatter = new CompositeFormatter[Text, ListPointerTarget, TextGateway, ModifiableTextGateway](_ => new TextGateway, new ModifiableTextGateway(_, None))
  def structFormatter[S <: Struct[S, MS], MS <: S](elemFactory: StructFactory[S, MS], dataSize: Words, pointerSize: Words) = new CompositeFormatter[S, StructPointerTarget, StructGateway[S], ModifiableStructGateway[S, MS]](new StructGateway(_, elemFactory), new ModifiableStructGateway(_, elemFactory, dataSize, pointerSize, None))*/
  // TODO handle inline structs
  // TODO implicitly-available "instance" of a class containing all static members of a given Java class
}
