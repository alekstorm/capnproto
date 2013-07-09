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

// TODO make spire dependency optional?

import java.io.{File, FileInputStream}
import java.nio.{ByteBuffer, ByteOrder}
import java.nio.channels.FileChannel.MapMode
import java.nio.file.{Files, Path}

import scala.collection.{IndexedSeq => ISeq}
import scala.collection.mutable.{ArrayBuffer, ListBuffer}

import spire.math.UInt
import spire.syntax.literals

import bitsy._; import Quantity.implicits._
import internal._

trait Allocator {
  def getArena(size: Words): Arena // returns exact size
  trait Arena {
    val buffer: ByteBuffer
    def free()
  }
}
object Allocator {
  var instance = new MemoryAllocator
}

class MemoryAllocator extends Allocator {
  override def getArena(size: Words) = new Arena { // users should not assume that calling free() on an Arena causes its underlying memory region to be freed (so they shouldn't keep Arenas in long-lived data structures, lengthening reachability)
    val buffer = ByteBuffer.allocateDirect(size.toBytes.toInt)
    buffer.limit(0)
    override def free() {} // TODO use in Manager
  }
}

class MappedAllocator(rootDir: Option[Path]) extends Allocator {
  override def getArena(size: Words) = new Arena {
    val tmpPath = rootDir match {
      case Some(r) => Files.createTempFile(r, "", MappedAllocator.TmpExtension)
      case None => Files.createTempFile("", MappedAllocator.TmpExtension)
    }
    val file = new File(tmpPath.toString)
    val stream = new FileInputStream(file)
    val channel = stream.getChannel()
    val byteSize = size.toInt
    for (i <- 0 until (byteSize.toFloat / MappedAllocator.ZeroChunkSize).toInt)
      channel.write(ByteBuffer.allocateDirect(MappedAllocator.ZeroChunkSize))
    channel.write(ByteBuffer.allocateDirect(byteSize % MappedAllocator.ZeroChunkSize))
    val buffer = channel.map(MapMode.READ_WRITE, 0, byteSize).load()
    buffer.limit(0)

    override def free() {
      channel.close()
      file.delete()
    }
  }
}
object MappedAllocator {
  val TmpExtension = ".capnp-tmp"
  val ZeroChunkSize = 64
}

// TODO make iterable over segments
trait Manager extends AutoCloseable {
  protected var inUse = false
  protected var segments = new ArrayBuffer[Segment]

  override def close() {
    if (!inUse)
      throw new Exception
    inUse = false
    segments = new ArrayBuffer[Segment]
  }

  def init() {
    if (inUse)
      throw new Exception
    inUse = true
  }

  def apply(idx: UInt) = segments(idx.toInt) // FIXME

  def segmentCount = UInt(segments.size)

  def allocateSegment(size: Words): Segment
}

object Manager {
  def open[M <: Manager](manager: M)(f: M => Unit) {
    manager.init()
    f(manager)
    manager.close()
  }

  // TODO lazy and eager (copying) versions
  def toStreamFormat(manager: Manager): ISeq[Byte] = {
    val output = new ListBuffer[Byte]
    output ++= (manager.segmentCount - ui"1").toggleEndian.toByteArray
    for (i <- 0 until manager.segmentCount.toInt) // FIXME
      output ++= manager(new UInt(i)).size.toInt.toggleEndian.toByteArray // UInt.apply() throws an inliner warning
    if (manager.segmentCount % ui"2" == 0) // padding to word boundary
      output ++= List.fill(4)(0)
    for (i <- 0 until manager.segmentCount.toInt) // FIXME
      output ++= manager(new UInt(i)).readRawBytes(0 bytes, manager(new UInt(i)).size.toBytes)
    output.toIndexedSeq
  }

  // TODO should this return an OutputStream instead?
  //def pack(input: InputStream, output: OutputStream) {}
}

class FixedManager(allocator: Allocator, segmentSize: Words) extends Manager {
  def this(segmentSize: Words) { this(Allocator.instance, segmentSize)}
  def this(allocator: Allocator) { this(allocator, Words.order(10)) }
  def this() { this(Allocator.instance) } // for Java compatibility

  private var firstSegment = new Segment(allocator.getArena(segmentSize).buffer)

  override def allocateSegment(size: Words) = {
    if (!inUse)
      throw new Exception
    segments += (if (segments.size > 0 || size > segmentSize)
      new Segment(allocator.getArena(segmentSize.max(size)).buffer)
    else
      firstSegment)
    segments.last
  }
}

object FixedManager {
  def open(f: FixedManager => Unit) {
    Manager.open(new FixedManager)(f)
  }
}

class GrowingManager(allocator: Allocator, firstSegmentSize: Words) extends Manager {
  def this(firstSegmentSize: Words) { this(Allocator.instance, firstSegmentSize)}
  def this(allocator: Allocator) { this(allocator, Words.order(10)) }
  def this() { this(Allocator.instance) }

  protected var lastSize = 0 words
  protected val firstSegment = new Segment(allocator.getArena(firstSegmentSize).buffer)

  override def allocateSegment(size: Words) = {
    if (!inUse)
      throw new Exception
    val segment = if (segments.size > 0 || size > firstSegmentSize)
      new Segment(allocator.getArena(size.max(lastSize * 2)).buffer)
    else
      firstSegment
    segments += segment
    lastSize = segment.capacity
    segment.size = size
    segment
  }
}

object GrowingManager {
  def open(f: GrowingManager => Unit) {
    Manager.open(new GrowingManager)(f)
  }
}
