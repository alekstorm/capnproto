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

import bitsy._; import Quantity.implicits._

/** Factory class inherited by generated Java code.
  *
  * Used by `StructGateway` to construct `Builder`s, since constructors can't be curried in the JVM.
  */
trait StructFactory[S <: Struct[S, MS], MS <: S /*with Modifiable[S]*/] {
  def reader(context: NearContext[StructPointerTarget]): S
  def builder(context: NearContext[StructPointerTarget]): MS
}

class StructGateway[S <: Struct[S, MS], MS <: S with Modifiable[S]](override val context: BaseContext[StructPointerTarget], factory: StructFactory[S, MS], dataSize: Words, pointerSize: Words, default: Option[Array[Byte]]) extends Gateway[S, MS, StructPointerTarget] {
  override def reader = factory.reader(context.near)

  override def builder = if (context.isReset) None else Some(directBuilder)

  override def set(struct: S): MS = {
    if (context.isReset)
      allocate()
    NearContext.copyComposite(struct.context.near, context.near)
    directBuilder
  }

  /** Allocate and clear memory to hold the struct.
    * @return A `Builder` over the allocated struct.
    */
  def init(): MS = {
    if (context.isReset)
      allocate()
    NearContext.eraseComposite(context.near)
    directBuilder
  }

  private def directBuilder = factory.builder(context.near)

  private def allocate() {
    val (targetSegmentId, offset) = allocate(dataSize + pointerSize)
    if (targetSegmentId == context.near.segmentId)
      context.near.writeNearPointer(offset, StructPointerTarget(dataSize, pointerSize))
    else
      context.writeFarPointer(FarPointer(false, 0 words, targetSegmentId), 1 words, StructPointerTarget(dataSize, pointerSize))
  }
}

// `MS` doesn't have a subtype bound of `Modifiable[S]` because Java doesn't know how to satisfy it
trait Struct[S <: Struct[S, MS], MS <: S /*with Modifiable[S]*/] extends Composite[S, MS] { type P = StructPointerTarget }
