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

package capnproto.bitsy

import scala.math.{ScalaNumericAnyConversions, ceil}

import spire.math.UByte
import spire.syntax._

import shapeless._; import Nat._

/** Int-based value class representing a quantity of bits.
  *
  * A handy factory object and Int enrichments are provided. See [[Quantity.implicits.QuantityRichInt QuantityRichInt]].
  *
  * A Bits can be converted to a Quantity with toQuantity (or the convenience methods toBytes, toShorts,
  * toQuads, and toWords), but since the new order is wider, a fractional result will be rounded up. Intuitively, this
  * is so that the quantity will "cover" the amount of memory represented by the Bits.
  *
  * {{{
  * > val foo = 12 bits
  * Bits(12)
  * > foo.toBytes
  * Bytes(2)
  * > foo.toBytes.toBits
  * Bits(16)
  * }}}
  *
  * Arithmetic operations and comparisons involving a Bits and a bare Int will interpret the Int as being a Bits.
  *
  * {{{
  * > val bar = 8 bits
  * Bits(8)
  * > bar * 3 + 2
  * Bits(26)
  }}}
  *
  * Although addition, subtraction, and comparison of two Bits are allowed, multiplication, division, and modulo are
  * not, as their return types under dimensional analysis are impossible to represent using Bits.
  *
  * {{{
  * > val (baz, qux) = (3 bits, 2 bits)
  * (Bits(3), Bits(2))
  * > baz + qux
  * Bits(5)
  * > baz < qux
  * false
  }}}
  */
case class Bits(val underlying: Int) extends AnyVal with ScalaNumericAnyConversions with Serializable with Ordered[Bits] {
  override def byteValue = underlying.byteValue
  override def doubleValue = underlying.doubleValue
  override def floatValue = underlying.floatValue
  override def intValue = underlying.intValue
  override def longValue = underlying.longValue
  override def shortValue = underlying.shortValue
  override def isWhole = true

  override def compare(other: Bits) = underlying.compare(other.underlying)

  /** @usecase def toQuantity[N <: Nat]: Quantity[N]
    */
  def toQuantity[N <: Nat](implicit order: ToInt[N]) =
    Quantity[N](ceil(underlying.toDouble / (1 << (order() + 3))).toInt)
  def toBytes = toQuantity[_0]
  def toShorts = toQuantity[_1]
  def toQuads = toQuantity[_2]
  def toWords = toQuantity[_3]

  def index: Byte = (underlying % 8).toByte
  // TODO support other number widths as well? once we're using arbitrarily-large number (bitstring) classes, should support those as well
  def mask: UByte = ub"1" << index // TODO test with negative underlying
  // TODO mask for setting all bits up to underlying as well
  // TODO separate index/mask method families for different endianness?

  def unary_+ = this
  def unary_- = new Bits(-underlying)

  // TODO Ordered[Int]?
  def +(other: Int) = new Bits(underlying + other)
  def -(other: Int) = new Bits(underlying - other)
  def *(other: Int) = new Bits(underlying * other)
  def /(other: Int) = new Bits(underlying / other)
  def %(other: Int) = new Bits(underlying % other)

  def ==(other: Int) = underlying == other
  def !=(other: Int) = underlying != other
  def <(other: Int) = underlying < other
  def <=(other: Int) = underlying <= other
  def >(other: Int) = underlying > other
  def >=(other: Int) = underlying >= other

  def abs = new Bits(underlying.abs)
  def max(other: Int) = new Bits(underlying.max(other))
  def min(other: Int) = new Bits(underlying.min(other))
}

class BitsOps(val underlying: Int) extends AnyVal {
  // TODO get around type erasure making these have the same signature as their equivalents that accept Int
  def +(other: Bits) = new Bits(underlying + other.underlying)
  def -(other: Bits) = new Bits(underlying - other.underlying)
  def max(other: Bits) = new Bits(underlying.max(other.underlying))
  def min(other: Bits) = new Bits(underlying.min(other.underlying))
}

object Bits {
  implicit def bitsOps(bits: Bits) = new BitsOps(bits.underlying)
}
