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

import spire.math.UInt
import spire.syntax.literals

import bitsy._; import Quantity.implicits._

// Represents the composition of a pointer with its location in memory
// REWORD the Pointer case classes represent only the information in that word
// TODO still not entirely happy with needing a base class
abstract class BaseContext[I <: NearPointerTarget](val manager: Manager, val segmentId: UInt, val offset: Words) {
  type P <: Pointer

  def pointer: P
  def near: NearContext[I]

  def segment = manager(segmentId) // TODO lazy val?

  def isReset = segment.isPointerReset(offset)
  def reset() {
    segment.resetPointer(offset)
  }

  def writeNearPointer(targetOffset: Words, pointerTarget: I) {
    segment.writePointer(offset, NearPointer(targetOffset - offset - 1, pointerTarget))
  }

  def writeFarPointer(newFarPointer: FarPointer, targetOffset: Words, pointerTarget: I) {
    segment.writePointer(offset, newFarPointer)
    manager(newFarPointer.segmentId).writePointer(newFarPointer.offset, NearPointer(targetOffset - newFarPointer.offset - 1, pointerTarget))
  }
}

case class Context[I <: NearPointerTarget](override val manager: Manager, override val segmentId: UInt, override val offset: Words) extends BaseContext[I](manager, segmentId, offset) {
  type P = Pointer

  override def pointer: P = segment.readPointer(offset)

  // TODO maybe rename to "target" or "near"
  override def near: NearContext[I] = {
    // TODO refactor (?)
    /*if (isReset)
      new NearContext[P](manager, segmentId, offset)
    else*/
      segment.readPointer(offset) match {
        case nearPointer: NearPointer[I] => new NearContext[I](manager, segmentId, offset)
        case FarPointer(hasTag, landingPadOffset, segmentId) => {
          val (targetSegmentId, targetOffset) = if (hasTag) {
            val landingPad = manager(segmentId).readTaggedLandingPad[I](landingPadOffset)
            (landingPad.segmentId, landingPad.offset)
          }
          else
            (segmentId, landingPadOffset)
          new NearContext[I](manager, targetSegmentId, targetOffset)
        }
      }
  }
}

case class NearContext[I <: NearPointerTarget](override val manager: Manager, override val segmentId: UInt, override val offset: Words) extends BaseContext[I](manager, segmentId, offset) {
  type P = NearPointer[I]

  override def near: NearContext[I] = this
  override def pointer: P = segment.readPointer(offset).asInstanceOf[P]

  // TODO rename 'offset' to 'address' or 'location', except in NearPointerTarget
  def targetOffset: Words = offset + pointer.offset + 1
}

object NearContext {
  implicit def enrichStruct(near: NearContext[StructPointerTarget]) = new RichStructContext(near)
  implicit def enrichList(near: NearContext[ListPointerTarget]) = new RichListContext(near)

  // TODO without the explicit type annotation, RichNearContext gets erased to NearContext[StructPointerTarget] - is that correct?
  val enrichStructGlue: Function1[NearContext[StructPointerTarget], RichNearContext] = enrichStruct _
  val enrichListGlue = enrichList _

  // TODO handle sourceContext == destContext
  def copyComposite[P <: NearPointerTarget](sourceContext: NearContext[P], destContext: NearContext[P])(implicit enrich: NearContext[P] => RichNearContext) {
    destContext.near.segment.writeRawBytes(destContext.near.targetOffset.toBytes, sourceContext.near.segment.readRawBytes((sourceContext.near.targetOffset).toBytes, sourceContext.near.targetSize.toBytes))
  }

  def eraseComposite[P <: NearPointerTarget](context: NearContext[P])(implicit enrich: NearContext[P] => RichNearContext) {
    context.near.segment.writeRawBytes(context.near.targetOffset.toBytes, Stream.continually(b"0").take(context.near.targetSize.toBytes.toInt).toIndexedSeq)
  }

  // TODO forgot what this is for
  def compositeSegment[P <: NearPointerTarget](context: NearContext[P])(implicit enrich: NearContext[P] => RichNearContext): Segment = {
    val nearOffset = context.near.targetOffset.toBytes.toInt
    val buffer = context.near.segment.buffer
    buffer.position(nearOffset)
    buffer.limit(nearOffset + context.near.targetSize.toBytes.toInt)
    new Segment(buffer.slice()) // FIXME set size correctly
  }
}

trait RichNearContext extends Any {
  def targetSize: Words
}

// TODO make these implicit objects
class RichStructContext(val near: NearContext[StructPointerTarget]) extends AnyVal with RichNearContext {
  override def targetSize: Words = {
    val StructPointerTarget(dataSize, pointerSize) = near.pointer.target
    dataSize + pointerSize
  }
}

class RichListContext(val near: NearContext[ListPointerTarget]) extends AnyVal with RichNearContext {
  override def targetSize: Words = {
    near.pointer.target match {
      case PrimitiveListPointerTarget(elemSize, elemCount) => (elemSize.bits * elemCount.toInt).toWords // FIXME
      case CompositeListPointerTarget(listSize) => listSize
    }
  }

  def elemCount: UInt = {
    near.pointer.target match {
      case PrimitiveListPointerTarget(_, elemCount) => elemCount
      case CompositeListPointerTarget(_) => near.segment.readCompositeListTag(near.targetOffset).elemCount
    }
  }

  def elemCount_=(newElemCount: UInt) {
    near.pointer.target match {
      case PrimitiveListPointerTarget(elemSize, elemCount) => near.segment.writePointer(near.offset, NearPointer(near.targetOffset, PrimitiveListPointerTarget(elemSize, newElemCount)))
      case CompositeListPointerTarget(_) => {
        val tag = near.segment.readCompositeListTag(near.targetOffset)
        near.segment.writeCompositeListTag(near.targetOffset, CompositeListTag(newElemCount, tag.dataSize, tag.pointerSize))
      }
    }
  }

  def elemSize: ElemSize = {
    near.pointer.target match {
      case PrimitiveListPointerTarget(elemSize, elemCount) => elemSize
      case CompositeListPointerTarget(_) => {
        val tag = near.segment.readCompositeListTag(near.targetOffset)
        CompositeElemSize(tag.dataSize, tag.pointerSize)
      }
    }
  }

  def elemOffset: Words = {
    near.pointer.target match {
      case PrimitiveListPointerTarget(_, _) => near.targetOffset
      case CompositeListPointerTarget(_) => near.targetOffset + 1
    }
  }
}
