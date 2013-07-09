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

import spire.math.UInt
import spire.syntax.literals

import bitsy._; import Quantity.implicits._
import internal._

trait Gateway[C <: Composite[C, _], P <: NearPointerTarget] {
  private[capnproto] def context: BaseContext[P]

  /** A `Reader` over the value. If the value is unallocated, this will represent the default value. Calling any
    * allocation method will invalidate pre-existing `Reader`s.
    */
  def reader: C
}

// TODO make default lazy
// TODO ReaderGateway, BuilderGateway, so that a Reader composite can't modify one of its fields through a Gateway
// TODO use Array[Byte] everywhere instead of ISeq[Byte], since it doesn't box, unless that one specialization library is an acceptable alternative
// TODO propose sealed[foo] to prevent subclassing by anything outside package 'foo'
/** The representation of a composite field or list element.
  *
  * All composite values are initially unallocated: `reader` returns a `Reader` over the default value, while `builder`
  * returns `None`. After calling an allocation method (`set`, `init`, etc), `reader` returns a `Reader` over the
  * allocated memory, while `builder` returns an `Option` containing a `Builder` over the same.
  *
  * Calling any allocation method on a `Reader` or `Builder`'s `Gateway` invalidates it, although an exception is thrown
  * only on a best-effort basis.
  *
  * `Gateway`s should never be constructed directly, outside of generated code.
  *
  * @tparam C Composite `Reader` class
  * @tparam MC Composite `Builder` class
  * @tparam P Encoded pointer format
  */
trait ModifiableGateway[C <: Composite[C, MC], MC <: C, P <: NearPointerTarget] extends Gateway[C, P] {
  /** A `Builder` over the value, wrapped in an `Option`. If the value is unallocated, this will be `None`. Calling any
    * allocation method will invalidate pre-existing `Reader`s.
    */
  def builder: Option[MC]

  /** Allocate, then copy the contents of a `Reader` of the appropriate type into the space.
    * @return A `Builder` over the copied composite.
    */
  def set(c: C): MC

  /** Reset the value's pointer to the default value.
    */
  def reset(): this.type = {
    context.reset()
    this
  }

  protected def allocate(size: Words) = {
    val nearSegment = if (context.isReset) context.segment else context.near.segment
    val (targetSegmentId, offset) = if (nearSegment.size + size < nearSegment.capacity)
      (context.segmentId, nearSegment.size)
    else {
      context.manager.allocateSegment(size)
      (context.manager.segmentCount - ui"1", 0 words)
    }
    context.manager(targetSegmentId).size += size
    (targetSegmentId, offset)
  }
}

trait CollectionGateway[C <: Collection[C, _]] extends Gateway[C, ListPointerTarget]

trait ModifiableCollectionGateway[C <: Collection[C, MC], MC <: C] extends ModifiableGateway[C, MC, ListPointerTarget] {
  /** Allocate and clear at least enough memory to hold `size` elements.
    * @return An empty `Builder` over the allocated collection.
    */
  def init(size: UInt): MC
  /** Allocate 
    * @return A `Builder` containing 
    */
  def resize(newSize: UInt): MC
}

trait Composite[C <: Composite[C, MC], MC <: C] {
  // TODO suffix struct fields with these names with $
  private[capnproto] val context: BaseContext[P]
  type P <: NearPointerTarget // TODO why isn't this a type parameter?
}

trait Collection[R <: Collection[R, MR], MR <: R] extends Composite[R, MR] { type P = ListPointerTarget }

abstract case class Union[T, F <: Enum[F]](which: F, value: T)
abstract case class Annotation[T](value: T) // TODO forgot what this is for
