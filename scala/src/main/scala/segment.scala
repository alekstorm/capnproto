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

import java.lang.{Double => JDouble, Float => JFloat}
import java.nio.ByteBuffer

import scala.collection.{IndexedSeq => ISeq}
import scala.runtime.BoxedUnit

import spire.math.{UByte, UShort, UInt, ULong}
import spire.syntax.literals
import spire.syntax.radix._

import bitsy._; import Quantity.implicits._

// TODO link to github source from scaladoc

// TODO put these all in a private[capnproto] package object or something
sealed trait Pointer {
  def offset: Words
}
sealed trait PointerType {
  val Flag: Byte
}

case class FarPointer(hasTag: Boolean, offset: Words, segmentId: UInt) extends Pointer
object FarPointer extends PointerType {
  final val Flag = x2"11".toByte
}

// TODO possibly rename to 'PointerTarget'
sealed trait NearPointerTarget
case class NearPointer[P <: NearPointerTarget](offset: Words, target: P) extends Pointer

case class StructPointerTarget(dataSize: Words, pointerSize: Words) extends NearPointerTarget
object StructPointerTarget extends PointerType {
  final val Flag = x2"00".toByte
}

sealed trait ListPointerTarget extends NearPointerTarget
object ListPointerTarget extends PointerType {
  final val Flag = x2"01".toByte
}

case class PrimitiveListPointerTarget(elemSize: PrimitiveElemSize, elemCount: UInt) extends ListPointerTarget
case class CompositeListPointerTarget(listSize: Words) extends ListPointerTarget

case class CompositeListTag(elemCount: UInt, dataSize: Words, pointerSize: Words)

case class TaggedLandingPad[P <: NearPointerTarget](offset: Words, segmentId: UInt, pointer: NearPointer[P])

sealed abstract class ElemSize(val bits: Bits)

case class CompositeElemSize(dataSize: Words, pointerSize: Words) extends ElemSize(dataSize.toBits + pointerSize.toBits)
object CompositeElemSize {
  val Flag = x2"111"
}

// TODO macro to generate numberings of case objects, kind of like enumerations (at both value and type level) - must extend a sealed superclass
sealed abstract class PrimitiveElemSize(bits: Bits) extends ElemSize(bits)
object PrimitiveElemSize {
  val Values = Seq(ZeroElemSize, BitElemSize, ByteElemSize, ShortElemSize, QuadElemSize, WordElemSize, PointerElemSize)
}

case object ZeroElemSize extends PrimitiveElemSize(0 bits)
case object BitElemSize extends PrimitiveElemSize(1 bits)
case object ByteElemSize extends PrimitiveElemSize(8 bits)
case object ShortElemSize extends PrimitiveElemSize(16 bits)
case object QuadElemSize extends PrimitiveElemSize(32 bits)
case object WordElemSize extends PrimitiveElemSize(64 bits)
case object PointerElemSize extends PrimitiveElemSize(64 bits)

// TODO might still have to declare every method as 'final' in order for it to be inlined, as an indication to the compiler that their implementations won't be changed - in that case, forget making the class final
final class Segment(val buffer: ByteBuffer) extends AnyVal {
  def capacity = buffer.capacity().bytes.toWords
  def size = buffer.limit().bytes.toWords
  def size_=(newSize: Words) { buffer.limit(newSize.toBytes.toInt) }

  def readVoid(offset: Any, default: Unit = Unit.box(())): BoxedUnit = Unit.box(()) // TODO get rid of offset argument
  def readBool(offset: Bits, default: Boolean = false): Boolean = ((buffer.get(offset.toBytes.toInt) & offset.mask.toByte) > 0) ^ default
  def readUInt8(offset: Bytes, default: UByte = ub"0"): UByte = UByte(readInt8(offset, default.toByte))
  def readUInt16(offset: Shorts, default: UShort = uh"0"): UShort = UShort(readInt16(offset, default.toShort))
  def readUInt32(offset: Quads, default: UInt = ui"0"): UInt = UInt(readInt32(offset, default.toInt))
  def readUInt64(offset: Words, default: ULong = ul"0"): ULong = ULong(readInt64(offset, default.toLong))
  def readInt8(offset: Bytes, default: Byte = b"0"): Byte = (buffer.get(offset.toInt) ^ default).toByte
  def readInt16(offset: Shorts, default: Short = h"0"): Short = (buffer.getShort(offset.toBytes.toInt).toggleEndian ^ default).toShort
  def readInt32(offset: Quads, default: Int = 0): Int = buffer.getInt(offset.toBytes.toInt).toggleEndian ^ default
  def readInt64(offset: Words, default: Long = 0L): Long = buffer.getLong(offset.toBytes.toInt).toggleEndian ^ default
  // TODO consider accepting Int and Long as defaults, respectively, for speed improvement
  def readFloat32(offset: Quads, default: Float = 0.0F): Float = JFloat.intBitsToFloat(readInt32(offset, JFloat.floatToIntBits(default)))
  def readFloat64(offset: Words, default: Double = 0.0): Double = JDouble.longBitsToDouble(readInt64(offset, JDouble.doubleToLongBits(default)))
  def readEnum(offset: Shorts, default: UShort = uh"0"): UShort = readUInt16(offset, default)

  def readPointer(offset: Words): Pointer = {
    val a = readUInt32(offset.toQuads)
    // TODO ux* StringContext series
    (a & UInt(x2"11")).toByte match {
      // TODO use macro for type inference on integer (or T <: Offset) argument
      case StructPointerTarget.Flag => NearPointer((a >>> 2).toInt.words, StructPointerTarget(readUInt16(offset + 2.shorts).toInt.words, readUInt16(offset + 3.shorts).toInt.words))
      case ListPointerTarget.Flag => {
        val listOffset = (a >>> 2).toInt.words
        val b = readUInt32(offset + 1.quads).toggleEndian
        val elemSizeIdx = b & UInt(x2"111")
        val elemCountOrListSize = b >>> 3
        NearPointer(listOffset, if (elemSizeIdx == CompositeElemSize.Flag)
          CompositeListPointerTarget(elemCountOrListSize.toInt.words)
        else
          // TODO make these enum values, automatically pull them out of source
          PrimitiveListPointerTarget(PrimitiveElemSize.Values(elemSizeIdx.toInt), elemCountOrListSize)
        )
      }
      case FarPointer.Flag => FarPointer((a & UInt(x2"100")) > ui"0", (a >>> 3).toInt.words, readUInt32(offset + 1.quads).toggleEndian)
    }
  }

  def readTaggedLandingPad[I <: NearPointerTarget](offset: Words): TaggedLandingPad[I] = {
    val FarPointer(_, contentOffset, segment) = readPointer(offset) // hack
    TaggedLandingPad(contentOffset, segment, readPointer(offset + 1).asInstanceOf[NearPointer[I]])
  }

  def readCompositeListTag(offset: Words): CompositeListTag = {
    val NearPointer(elemCount, StructPointerTarget(dataSize, pointerSize)) = readPointer(offset) // hack
    CompositeListTag(UInt(elemCount.toInt), dataSize, pointerSize)
  }

  def readRawBytes(offset: Bytes, length: Bytes): ISeq[Byte] = {
    val tmp = new Array[Byte](length.toInt)
    val subBuffer = buffer.duplicate()
    subBuffer.position(offset.toInt)
    subBuffer.get(tmp)
    tmp.toIndexedSeq
  }

  // TODO add unary_+ to UByte, etc
  def writeVoid(offset: Any, value: Unit, default: Unit = Unit.box(())) {}
  def writeBool(offset: Bits, value: Boolean, default: Boolean = false) {
    val byteOffset = offset.toBytes.toInt
    buffer.put(byteOffset, (UByte(buffer.get(byteOffset)) & ~offset.mask | ((if (value ^ default) ub"1" else ub"0") << offset.index)).toByte)
  }
  def writeUInt8(offset: Bytes, value: UByte, default: UByte = ub"0") { writeInt8(offset, value.toByte, default.toByte) }
  def writeUInt16(offset: Shorts, value: UShort, default: UShort = uh"0") { writeInt16(offset, value.toShort, default.toShort) }
  def writeUInt32(offset: Quads, value: UInt, default: UInt = ui"0") { writeInt32(offset, value.toInt, default.toInt) }
  def writeUInt64(offset: Words, value: ULong, default: ULong = ul"0") { writeInt64(offset, value.toLong, default.toLong) }
  def writeInt8(offset: Bytes, value: Byte, default: Byte = b"0") { buffer.put(offset.toInt, (value ^ default).toByte) }
  def writeInt16(offset: Shorts, value: Short, default: Short = h"0") { buffer.putShort(offset.toBytes.toInt, (value ^ default).toShort.toggleEndian) }
  def writeInt32(offset: Quads, value: Int, default: Int = 0) { buffer.putInt(offset.toBytes.toInt, (value ^ default).toggleEndian) }
  def writeInt64(offset: Words, value: Long, default: Long = 0L) { buffer.putLong(offset.toBytes.toInt, (value ^ default).toggleEndian) }
  def writeFloat32(offset: Quads, value: Float, default: Float = 0.0F) { writeInt32(offset, JFloat.floatToIntBits(value), JFloat.floatToIntBits(default)) }
  def writeFloat64(offset: Words, value: Double, default: Double = 0.0) { writeInt64(offset, JDouble.doubleToLongBits(value), JDouble.doubleToLongBits(default)) }
  def writeEnum(offset: Shorts, value: UShort, default: UShort = uh"0") { writeUInt16(offset, value, default) }

  // TODO type-level instructions for (en|de)coding case classes, so this logic isn't mirrored for reading and writing - lenses will probably be useful - or macro annotations on CC params/members
  // TODO macro for named parameters in shapeless lenses - names become Nats
  def writePointer(offset: Words, pointer: Pointer) {
    pointer match {
      case NearPointer(structOffset, StructPointerTarget(dataSize, pointerSize)) => {
        writeRawBytes(offset.toBytes, (structOffset.toInt << 2 | StructPointerTarget.Flag).toggleEndian.toByteArray)
        writeRawBytes(offset.toBytes + 4, dataSize.toShort.toggleEndian.toByteArray)
        writeRawBytes(offset.toBytes + 6, pointerSize.toShort.toggleEndian.toByteArray)
      }
      case NearPointer(listOffset, listPointerTarget: ListPointerTarget) => {
        writeRawBytes(offset.toBytes, (listOffset.toInt << 2 | ListPointerTarget.Flag).toggleEndian.toByteArray)
        val (sizeFlag, last) = listPointerTarget match {
          case PrimitiveListPointerTarget(elemSize, elemCount) => (PrimitiveElemSize.Values.indexOf(elemSize), elemCount)
          case CompositeListPointerTarget(listSize) => (CompositeElemSize.Flag, UInt(listSize.toInt))
        }
        writeRawBytes(offset.toBytes + 4, (last << 3 | UInt(sizeFlag)).toggleEndian.toByteArray)
      }
      case FarPointer(hasTag, offset, segmentId) => {
        writeRawBytes(offset.toBytes, (offset.toInt << 3 | (if (hasTag) 1 else 0) << 2 | FarPointer.Flag).toggleEndian.toByteArray)
        writeRawBytes(offset.toBytes + 4, segmentId.toggleEndian.toByteArray)
      }
    }
  }

  def resetPointer(offset: Words) {
    writeRawBytes(offset.toBytes, ISeq.fill(8)(b"0"))
  }

  def isPointerReset(offset: Words) = readRawBytes(offset.toBytes, 8 bytes).forall(_ == b"0")

  def writeTaggedLandingPad[I <: NearPointerTarget](offset: Words, landingPad: TaggedLandingPad[I]) {
    writePointer(offset, FarPointer(false, landingPad.offset, landingPad.segmentId))
    writePointer(offset + 1, landingPad.pointer)
  }

  def writeCompositeListTag(offset: Words, tag: CompositeListTag) {
    writePointer(offset, NearPointer(tag.elemCount.toInt.words, StructPointerTarget(tag.dataSize, tag.pointerSize))) // FIXME
  }

  def writeRawBytes(offset: Bytes, bytes: ISeq[Byte]) {
    val subBuffer = buffer.duplicate()
    subBuffer.position(offset.toInt)
    subBuffer.put(bytes.toArray)
  }

  // TODO remove - just for debugging
  def printAll() { Segment.printBytes(readRawBytes(0 bytes, size.toBytes)) }
}

object Segment {
  // TODO remove - just for debugging
  def printBytes(bytes: Seq[Byte]) {
    bytes.grouped(8).foreach { line =>
      line.foreach(byte => print(String.format("%8s", Integer.toBinaryString(byte & 0xFF)).replace(" ", "0") + " "))
      println()
    }
  }
}
