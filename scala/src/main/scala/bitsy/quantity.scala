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

import java.lang.{Integer => JInt, Long => JLong, Short => JShort}

import scala.math.{ScalaNumericAnyConversions, ceil}

import spire.math.{UByte, UShort, UInt, ULong}
import spire.syntax._

import shapeless._; import Nat._

// TODO add '@inline final' on all applicable methods
// TODO caliper for benchmarking
// TODO override equals and hashCode, check contracts
// TODO integrate with spire
// TODO capnpc options for reading/writing to/from stdin/stdout, or custom file names
// TODO consider implicitly converting from larger to smaller widths (and vice versa?) - still not from Int to Quantity, obviously - maybe Quantity to Int?
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

  def width(implicit order: ToInt[N]) = Bits(1 << order())

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
  def toBytes(implicit order: ToInt[N], otherOrder: ToInt[_0]) = toQuantity[_0]
  def toShorts(implicit order: ToInt[N], otherOrder: ToInt[_1]) = toQuantity[_1]
  def toQuads(implicit order: ToInt[N], otherOrder: ToInt[_2]) = toQuantity[_2]
  def toWords(implicit order: ToInt[N], otherOrder: ToInt[_3]) = toQuantity[_3]
  def toBits(implicit order: ToInt[N], byteOrder: ToInt[_0]) = Bits(toBytes.toInt * 8)

  def unary_+ = this
  def unary_- = Quantity[N](-underlying)

  // TODO macro to cut down on boilerplate - should be able to derive all other comparison operators from == and <, including implicit conditions - or, do example for +, and it figures out -, *, and /
  // TODO calling these causes boxing - use macro to inject them, but still have them inherit from quantity, and keep the abstract declarations in Quantity
  def +(other: Int) = Quantity[N](underlying + other)
  def -(other: Int) = this + -other
  def %(other: Int) = Quantity[N](underlying % other)
  // TODO consider getting rid of these - they return Ints, which is logical, but unintuitive; typechecker won't catch misuses like `1.shorts + 2.shorts * 3`, which will evaluate to `13.shorts`, not `7.shorts`
  def *(other: Int) = Quantity[N](underlying * other)
  def /(other: Int) = Quantity[N](underlying / other)

  // comparing quantities of different widths is unintuitive, at the very least (because of truncation), so require
  // users to explicitly convert to same width beforehand
  def ==(other: Int) = underlying == other
  def ==[M <: Nat](other: Quantity[N])(implicit order: ToInt[N]) = underlying == other.underlying
  def !=(other: Int) = underlying != other
  def !=[M <: Nat](other: Quantity[N])(implicit order: ToInt[N]) = !(this == other)
  def <(other: Int) = underlying < other
  def <[M <: Nat](other: Quantity[N])(implicit order: ToInt[N]) = underlying < other.underlying
  def <=(other: Int) = underlying <= other
  def <=[M <: Nat](other: Quantity[N])(implicit order: ToInt[N]) = this < other || this == other
  def >(other: Int) = underlying > other
  def >[M <: Nat](other: Quantity[N])(implicit order: ToInt[N]) = !(this < other)
  def >=(other: Int) = underlying >= other
  def >=[M <: Nat](other: Quantity[N])(implicit order: ToInt[N]) = this > other || this == other

  def abs = Quantity[N](underlying.abs)
  def max(other: Int)(implicit order: ToInt[N]) = Quantity[N](underlying.max(other))
  def min(other: Int)(implicit order: ToInt[N]) = Quantity[N](underlying.min(other))

  // TODO might require macro implicit injection of some kind
  //def toString(implicit order: ToInt[N]) = s"Quantity[${order()} : ${width.toInt} bits]($underlying)"
  //override def toString = s"Quantity[<unknown width>]($underlying)"
}

private[bitsy] class ThinnerOps[N <: Nat](val underlying: Int) extends AnyVal {
  def +[M <: Nat](other: Quantity[M])(implicit ev: LT[N, M], order: ToInt[N], otherOrder: ToInt[M]) = other.toQuantity[N] + underlying
  def -[M <: Nat](other: Quantity[M])(implicit ev: LT[N, M], order: ToInt[N], otherOrder: ToInt[M]) = this + -other
  def max[M <: Nat](other: Quantity[M])(implicit ev: LT[N, M], order: ToInt[N], otherOrder: ToInt[M]) = other.toQuantity[N].max(underlying)
  def min[M <: Nat](other: Quantity[M])(implicit ev: LT[N, M], order: ToInt[N], otherOrder: ToInt[M]) = other.toQuantity[N].min(underlying)
}

private[bitsy] class WiderOps[N <: Nat](val underlying: Int) extends AnyVal {
  def +[M <: Nat](other: Quantity[M])(implicit ev: LTEq[M, N], order: ToInt[N], otherOrder: ToInt[M]) = Quantity[N](underlying).toQuantity[M] + other.underlying
  def -[M <: Nat](other: Quantity[M])(implicit ev: LTEq[M, N], order: ToInt[N], otherOrder: ToInt[M]) = this + -other
  def max[M <: Nat](other: Quantity[M])(implicit ev: LTEq[M, N], order: ToInt[N], otherOrder: ToInt[M]) = other.max(Quantity[N](underlying).toQuantity[M].underlying)
  def min[M <: Nat](other: Quantity[M])(implicit ev: LTEq[M, N], order: ToInt[N], otherOrder: ToInt[M]) = other.min(Quantity[N](underlying).toQuantity[M].underlying)
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

    // FIXME move elsewhere
    implicit class RichInt(val value: Int) extends AnyVal {
      // spire may actually have something for this - if not, add it
      def toggleEndian = JInt.reverseBytes(value)
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
      def toggleEndian = UInt(JInt.reverseBytes(value))
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

case class Bits(override val underlying: Int) extends AnyVal with ScalaNumericAnyConversions with Serializable with Ordered[Bits] {
  override def byteValue = underlying.byteValue
  override def doubleValue = underlying.doubleValue
  override def floatValue = underlying.floatValue
  override def intValue = underlying.intValue
  override def longValue = underlying.longValue
  override def shortValue = underlying.shortValue
  override def isWhole = true

  override def compare(other: Bits) = underlying.compare(other.underlying)

  def toQuantity[N <: Nat](implicit order: ToInt[N]) = Quantity[N](ceil(underlying.toDouble / (1 << (order() + 3))).toInt)
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
  def unary_- = new Bits(-1 * underlying)

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

private[bitsy] class BitsOps(val underlying: Int) extends AnyVal {
  // TODO get around type erasure making these have the same signature as their equivalents that accept Int
  def +(other: Bits) = new Bits(underlying + other.underlying)
  def -(other: Bits) = new Bits(underlying - other.underlying)
  def ==(other: Bits) = underlying == other.underlying
  def !=(other: Bits) = underlying != other.underlying
  def <(other: Bits) = underlying < other.underlying
  def <=(other: Bits) = underlying <= other.underlying
  def >(other: Bits) = underlying > other.underlying
  def >=(other: Bits) = underlying >= other.underlying
  def max(other: Bits) = new Bits(underlying.max(other.underlying))
  def min(other: Bits) = new Bits(underlying.min(other.underlying))
}

object Bits {
  implicit def bitsOps(bits: Bits) = new BitsOps(bits.underlying)
}

// TODO consider way to parametrize Quantity on other Quantity (or on phantom newtype) to represent an "offset"

trait QuantityBuilder[N <: Nat] {
  def apply(value: Int) = Quantity[N](value)
  def order(value: Int) = Quantity.order[N](value)
}

// TODO consider UWords, etc, as well as wrapping Longs - some kind of type parametrization - probably not currently supported by scala
object Bytes extends QuantityBuilder[_0]
object Shorts extends QuantityBuilder[_1]
object Quads extends QuantityBuilder[_2]
object Words extends QuantityBuilder[_3]
