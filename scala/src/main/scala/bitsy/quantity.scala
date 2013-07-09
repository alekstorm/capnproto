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

import java.lang.{Long => JLong, Short => JShort}

import scala.math.ScalaNumericAnyConversions

import spire.math.{UShort, UInt, ULong}
import spire.syntax._

import shapeless._; import Nat._

// TODO add '@inline final' on all applicable methods
// TODO caliper for benchmarking
// TODO override equals and hashCode, check contracts
// TODO integrate with spire
// TODO consider way to parametrize Quantity on other Quantity (or on phantom newtype) to represent an "offset"
// TODO capnpc options for reading/writing to/from stdin/stdout, or custom file names
// TODO consider implicitly converting from larger to smaller widths (and vice versa?) - still not from Int to Quantity, obviously - maybe Quantity to Int?
// TODO linkify toQuantity, etc references in doc comments
/** Int-based value class representing a quantity of bytes or some multiple thereof.
  *
  * Handy factory objects and Int enrichments are provided for the first four orders: [[Bytes]] (1 byte), [[Shorts]]
  * (2 bytes), [[Quads]] (4 bytes), and [[Words]] (8 bytes). See [[Quantity.implicits.QuantityRichInt QuantityRichInt]].
  *
  * A Quantity can be converted to a different order with toQuantity (or the convenience methods toBytes,
  * toShorts, toQuads, and toWords), but if the new order is wider, a fractional result will be rounded up. Intuitively,
  * this is so that the wider quantity will "cover" the amount of memory represented by the thinner one.
  *
  * {{{
  * > val foo = 12 bytes
  * Bytes(12)
  * > foo.toWords
  * Words(2)
  * > foo.toWords.toBytes
  * Bytes(16)
  * }}}
  *
  * Arithmetic operations and comparisons involving a Quantity and a bare Int will interpret the Int as being a Quantity
  * of the same order.
  *
  * {{{
  * > val bar = 8 bytes
  * Bytes(8)
  * > bar * 3 + 2
  * Bytes(26)
  }}}
  *
  * Addition and subtraction of two Quantity's of different orders will return a Quantity of the *thinner* of the two
  * input orders (reword). Multiplication, division, and modulo are not supported, as their return types under
  * dimensional analysis are impossible to represent using Quantity's. Comparison is only allowed between two
  * Quantity's of the same order, as the results between different orders would be unintuitive.
  *
  * {{{
  * > val (baz, qux) = (3 bytes, 2 words)
  * (Bytes(3), Words(2))
  * > baz + qux
  * Bytes(19)
  * > baz < qux.toBytes
  * true
  }}}
  *
  * @tparam N Binary logarithm of the width ("order") of the quantity (e.g. byte = 0, short = 1, quad = 2, word = 3).
  * Uses type-level natural numbers from the [[https://github.com/milessabin/shapeless shapeless metaprogramming
  * library]].
  */
case class Quantity[N <: Nat](val underlying: Int) extends AnyVal with ScalaNumericAnyConversions with Serializable /*with Ordered[Quantity[_]]*/ {
  override def byteValue = underlying.byteValue
  override def doubleValue = underlying.doubleValue
  override def floatValue = underlying.floatValue
  override def intValue = underlying.intValue
  override def longValue = underlying.longValue
  override def shortValue = underlying.shortValue
  override def isWhole = true

  // TODO Ordering-like typeclass that compares values of two different classes - phantom types to represent set of comparable classes - spire might provide this
  // TODO use Orderable instead, but keep all the comparison operators here
  //override def compare(other: Quantity[_]) = value.compare(other.value)

  /** @usecase def width: Bits
    */
  def width(implicit order: ToInt[N]) = Bits(1 << order())

  /** @usecase def toQuantity[M <: Nat]: Quantity[M]
    */
  def toQuantity[M <: Nat](implicit order: ToInt[N], otherOrder: ToInt[M]) = {
    val diff = order() - otherOrder()
    Quantity[M](
      if (diff == 0)
        underlying
      else if (diff > 0)
        (underlying << (order() - otherOrder())) & 0xffffffff
      else {
        val result = underlying >>> -diff
        if ((underlying & (0xffffffff >>> diff)) > 0) result + 1 else result
      }
    )
  }
  /** @usecase def toBytes: Bytes
    */
  def toBytes(implicit order: ToInt[N], otherOrder: ToInt[_0]) = toQuantity[_0]
  /** @usecase def toShorts: Shorts
    */
  def toShorts(implicit order: ToInt[N], otherOrder: ToInt[_1]) = toQuantity[_1]
  /** @usecase def toQuads: Quads
    */
  def toQuads(implicit order: ToInt[N], otherOrder: ToInt[_2]) = toQuantity[_2]
  /** @usecase def toWords: Words
    */
  def toWords(implicit order: ToInt[N], otherOrder: ToInt[_3]) = toQuantity[_3]
  /** @usecase def toBits: Bits
    */
  def toBits(implicit order: ToInt[N], byteOrder: ToInt[_0]) = Bits(toBytes.toInt * 8)

  def unary_+ = this
  def unary_- = Quantity[N](-underlying)

  // TODO macro to cut down on boilerplate - should be able to derive all other comparison operators from == and <, including implicit conditions - or, do example for +, and it figures out -, *, and /
  // TODO calling these causes boxing - use macro to inject them, but still have them inherit from quantity, and keep the abstract declarations in Quantity
  // TODO consider supporting arithmetic and comparisons with Bits as well
  def +(other: Int) = Quantity[N](underlying + other)
  def -(other: Int) = this + -other
  def %(other: Int) = Quantity[N](underlying % other)
  // TODO consider getting rid of these - they return Ints, which is logical, but unintuitive; typechecker won't catch misuses like `1.shorts + 2.shorts * 3`, which will evaluate to `13.shorts`, not `7.shorts`
  def *(other: Int) = Quantity[N](underlying * other)
  def /(other: Int) = Quantity[N](underlying / other)

  /** @usecase def ==(other: Quantity[N]): Boolean
    */
  def ==(other: Quantity[N])(implicit order: ToInt[N]) = underlying == other.underlying
  def ==(other: Int) = underlying == other
  /** @usecase def !=(other: Quantity[N]): Boolean
    */
  def !=(other: Quantity[N])(implicit order: ToInt[N]) = !(this == other)
  def !=(other: Int) = underlying != other
  /** @usecase def <(other: Quantity[N]): Boolean
    */
  def <(other: Quantity[N])(implicit order: ToInt[N]) = underlying < other.underlying
  def <(other: Int) = underlying < other
  /** @usecase def <=(other: Quantity[N]): Boolean
    */
  def <=(other: Quantity[N])(implicit order: ToInt[N]) = this < other || this == other
  def <=(other: Int) = underlying <= other
  /** @usecase def >(other: Quantity[N]): Boolean
    */
  def >(other: Quantity[N])(implicit order: ToInt[N]) = !(this < other)
  def >(other: Int) = underlying > other
  /** @usecase def >=(other: Quantity[N]): Boolean
    */
  def >=(other: Quantity[N])(implicit order: ToInt[N]) = this > other || this == other
  def >=(other: Int) = underlying >= other

  def abs = Quantity[N](underlying.abs)
  /** @usecase def max(other: Quantity[N]): Quantity[N]
    */
  def max(other: Int)(implicit order: ToInt[N]) = Quantity[N](underlying.max(other))
  /** @usecase def min(other: Quantity[N]): Quantity[N]
    */
  def min(other: Int)(implicit order: ToInt[N]) = Quantity[N](underlying.min(other))

  // TODO might require macro implicit injection of some kind
  //def toString(implicit order: ToInt[N]) = s"Quantity[${order()} : ${width.toInt} bits]($underlying)"
  //override def toString = s"Quantity[<unknown width>]($underlying)"
}

class ThinnerOps[N <: Nat](val underlying: Int) extends AnyVal {
  /** @usecase def +[M <: Nat](other: Quantity[M]): Quantity[N]
    */
  def +[M <: Nat](other: Quantity[M])(implicit ev: LT[N, M], order: ToInt[N], otherOrder: ToInt[M]) =
    other.toQuantity[N] + underlying
  /** @usecase def -[M <: Nat](other: Quantity[M]): Quantity[N]
    */
  def -[M <: Nat](other: Quantity[M])(implicit ev: LT[N, M], order: ToInt[N], otherOrder: ToInt[M]) = this + -other
  /** @usecase def max[M <: Nat](other: Quantity[M]): Quantity[N]
    */
  def max[M <: Nat](other: Quantity[M])(implicit ev: LT[N, M], order: ToInt[N], otherOrder: ToInt[M]) =
    other.toQuantity[N].max(underlying)
  /** @usecase def min[M <: Nat](other: Quantity[M]): Quantity[N]
    */
  def min[M <: Nat](other: Quantity[M])(implicit ev: LT[N, M], order: ToInt[N], otherOrder: ToInt[M]) =
    other.toQuantity[N].min(underlying)
}

class WiderOps[N <: Nat](val underlying: Int) extends AnyVal {
  /** @usecase def +[M <: Nat](other: Quantity[M]): Quantity[M]
    */
  def +[M <: Nat](other: Quantity[M])(implicit ev: LTEq[M, N], order: ToInt[N], otherOrder: ToInt[M]) =
    Quantity[N](underlying).toQuantity[M] + other.underlying
  /** @usecase def -[M <: Nat](other: Quantity[M]): Quantity[M]
    */
  def -[M <: Nat](other: Quantity[M])(implicit ev: LTEq[M, N], order: ToInt[N], otherOrder: ToInt[M]) = this + -other
  /** @usecase def max[M <: Nat](other: Quantity[M]): Quantity[M]
    */
  def max[M <: Nat](other: Quantity[M])(implicit ev: LTEq[M, N], order: ToInt[N], otherOrder: ToInt[M]) =
    other.max(Quantity[N](underlying).toQuantity[M].underlying)
  /** @usecase def min[M <: Nat](other: Quantity[M]): Quantity[M]
    */
  def min[M <: Nat](other: Quantity[M])(implicit ev: LTEq[M, N], order: ToInt[N], otherOrder: ToInt[M]) =
    other.min(Quantity[N](underlying).toQuantity[M].underlying)
}

private[bitsy] trait QuantityLow {
  implicit def thinnerOps[N <: Nat](quantity: Quantity[N]) = new ThinnerOps[N](quantity.underlying)
}

object Quantity extends QuantityLow {
  def order[N <: Nat](value: Int) = apply[N](1 << value)

  implicit def widerOps[N <: Nat](quantity: Quantity[N]) = new WiderOps[N](quantity.underlying)

  object implicits {
    private def bigIntByteArray(value: BigInt, length: Int) = value.toByteArray.padTo(length, b"0").take(length)

    implicit class QuantityRichInt(val value: Int) extends AnyVal {
      def quantity[N <: Nat] = Quantity[N](value)
      def bytes = Bytes(value)
      def shorts = Shorts(value)
      def quads = Quads(value)
      def words = Words(value)
      def bits = Bits(value)
      def order = 1 << value

      // TODO expand
      def <<(bits: Bits) = value << bits.toInt
      def >>(bits: Bits) = value >> bits.toInt
      def >>>(bits: Bits) = value >>> bits.toInt
    }

    // FIXME move elsewhere (?)
    implicit class RichInt(val value: Int) extends AnyVal {
      // spire may actually have something for this - if not, contribute it
      def toggleEndian = Integer.reverseBytes(value)
      def toByteArray = bigIntByteArray(BigInt(value), 4)
    }
    implicit class RichShort(val value: Short) extends AnyVal {
      def toggleEndian = JShort.reverseBytes(value)
      def toByteArray = bigIntByteArray(BigInt(value), 2)
    }
    implicit class RichLong(val value: Long) extends AnyVal {
      def toggleEndian = JLong.reverseBytes(value)
      def toByteArray = bigIntByteArray(BigInt(value), 8)
    }

    class RichUShort(val value: Short) extends AnyVal {
      def toggleEndian = UShort(JShort.reverseBytes(value))
      def toByteArray = bigIntByteArray(BigInt(value), 2)
    }
    implicit def enrichUShort(value: UShort) = new RichUShort(value.toShort)
    class RichUInt(val value: Int) extends AnyVal {
      def toggleEndian = UInt(Integer.reverseBytes(value))
      def toByteArray = bigIntByteArray(BigInt(value), 4)
    }
    implicit def enrichUInt(value: UInt) = new RichUInt(value.toInt)
    class RichULong(val value: Long) extends AnyVal {
      def toggleEndian = ULong(JLong.reverseBytes(value))
      def toByteArray = bigIntByteArray(BigInt(value), 8)
    }
    implicit def enrichULong(value: ULong) = new RichULong(value.toLong)
  }
}

trait QuantityBuilder[N <: Nat] {
  def apply(value: Int) = Quantity[N](value)
  def order(value: Int) = Quantity.order[N](value)
}

// TODO consider UWords, etc, as well as wrapping Longs - some kind of type parametrization
// probably not currently supported by scala - will need macros, won't be generic
object Bytes extends QuantityBuilder[_0]
object Shorts extends QuantityBuilder[_1]
object Quads extends QuantityBuilder[_2]
object Words extends QuantityBuilder[_3]
