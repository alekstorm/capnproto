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

import java.io.{InputStream, InputStreamReader}
import java.lang.{Iterable => JIterable}
import java.nio.{ByteBuffer, CharBuffer}
import java.nio.charset.StandardCharsets
import java.util.{Iterator => JIterator}

import scala.collection.generic.{Growable, Sizing}

import spire.math.UInt

import bitsy._; import Quantity.implicits._

// TODO haven't touched this in a while, still quite a mess

class TextGateway(context: BaseContext[ListPointerTarget], default: Option[Array[Byte]]) extends CollectionGateway[Text, ModifiableText](context, default) {
  override def reader: Text = ???
  override def builder: Option[ModifiableText] = ???
  override def init(size: UInt): ModifiableText = ???
  override def resize(newSize: UInt): ModifiableText = ???
  override def set(text: Text): ModifiableText = ???

  def set(text: String): this.type = ???
}

class Text(override val context: BaseContext[ListPointerTarget]) extends Collection[Text, ModifiableText] with Readable with JIterable[Char] with Comparable[Text] /*with IterableView[Char, ByteBuffer] with GenericTraversableTemplate[Char, Text] with IterableViewLike[Char, ByteBuffer, Text]*/ with Sizing {
  protected def segment = NearContext.compositeSegment(context.near)

  protected final def toByteArray = segment.readRawBytes(0 bytes, segment.size.toBytes).toArray

  override final def read(charBuffer: CharBuffer) = {
    val decoder = StandardCharsets.UTF_8.newDecoder()
    decoder.decode(ByteBuffer.wrap(toByteArray), charBuffer, true)
    decoder.flush(charBuffer)
    -1
  }

  override final def toString() = new String(toByteArray, StandardCharsets.UTF_8)

  /*override*/ final def length() = toString().length
  /*override*/ final def size = length()

  // TODO invalidate if list gets resized, no matter whether it grows or shrinks (or shrink() is called on it), or whether the underlying memory gets moved elsewhere - has to be consistent - modifiable version too
  override def iterator = new Text.Iterator(context)

  override final def compareTo(other: Text) = segment.buffer.compareTo(other.segment.buffer)

  override final def equals(other: Any) = other.isInstanceOf[Text] && segment.buffer.equals(other.asInstanceOf[Text].segment.buffer)
  override final def hashCode() = segment.buffer.hashCode()

  // FIXME
  //override final def companion = Text
  //protected override final def newBuilder = new ListBuffer[Char].mapResult(l => new Text(new )
}

object Text {
  // TODO make inner class of Text
  class Iterator(context: BaseContext[ListPointerTarget]) extends JIterator[Char] {
    protected def segment = NearContext.compositeSegment(context.near)
    // TODO eliminate as many direct accesses of segment.buffer as possible
    // adapted from http://stackoverflow.com/questions/4332264/wrapping-a-bytebuffer-with-an-inputstream/6603018
    protected val stream = new InputStream {
      override def read() = if (!segment.buffer.hasRemaining()) -1 else segment.buffer.get() & 0xFF

      override def read(bytes: Array[Byte], offset: Int, length: Int): Int = {
        if (!segment.buffer.hasRemaining())
          -1
        else {
          val left = Math.min(length, segment.buffer.remaining())
          segment.buffer.get(bytes, offset, left)
          left
        }
      }
    }
    protected val reader = new InputStreamReader(stream, StandardCharsets.UTF_8)
    protected var pos = 0

    override final def hasNext() = reader.ready()
    // TODO should have ability to iterate backwards - custom utf8 decoder (probably already necessary for performance)
    override final def next() = {
      pos += 1
      reader.read().toChar
    }
    override final def remove { throw new UnsupportedOperationException() }

    final def index: Int = pos
  }
}

// can't use immutable.Iterable on Text, since underlying bytes could still be mutated
// TODO implement mutable.Iterable - currently conflicts with JIterable
// TODO this thing is basically like a stack, with a maximum size
// TODO add macros that check much more aggressively for things like ConcurrentModificationException in debug mode, but get erased completely in non-debug mode
// TODO might need new ModifiableTextPortion class (that this implements, and adds an init() method to) to get IterableView and such to work, since they need a Builder for the type
// TODO is tying inner classes to their containing instances necessary when they can be parametrized on singleton types?
// if pointer itself is moved (from movement of parent object), all child builders are also invalidated
class ModifiableText(context: BaseContext[ListPointerTarget]) extends Text(context) with Modifiable[Text] with Appendable with Growable[Char] {
  protected var pos = 0
  // TODO check that appending past limit throws error
  // TODO add all append()/remove() overloads to iterator as well
  override def append(c: Char) = { append(new String(Array(c))) }
  override def append(cs: CharSequence) = { append(cs, 0, cs.length - 1) }
  override def append(cs: CharSequence, start: Int, end: Int) = {
    // TODO factor this repeated chunk out
    val encoder = StandardCharsets.UTF_8.newEncoder()
    encoder.encode(CharBuffer.wrap(cs, start, end), segment.buffer, true)
    encoder.flush(segment.buffer)
    this
  }

  override def +=(c: Char) = { append(c); this }

  override def iterator = new ModifiableText.Iterator(context)

  // simply resets position to beginning, rather than zeroing out memory - unclear whether this violates Growable contract, but we're already violating it by defining a maximum size anyway
  override def clear() { pos = 0 }

  def ++=(cs: CharSequence) = { append(cs); this }

  def set(cs: CharSequence): this.type = {
    clear()
    this ++= cs.toString
  }
}

object ModifiableText {
  def init(segment: Segment, offset: Words, manager: Manager) { ??? }

  final class Iterator(context: BaseContext[ListPointerTarget]) extends Text.Iterator(context) {
    def set(c: Char) {
      val encoder = StandardCharsets.UTF_8.newEncoder()
      val subBuffer = segment.buffer.slice()
      encoder.encode(CharBuffer.wrap(Array(c)), subBuffer, true)
      encoder.flush(subBuffer)
    }
  }
}
