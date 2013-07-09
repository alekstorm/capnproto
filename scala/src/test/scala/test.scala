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

package capnproto.test

import java.io.File
import java.lang.{Boolean => JBoolean, Byte => JByte, Double => JDouble, Integer, Float => JFloat, Long => JLong,
  Short => JShort}
import java.nio.charset.StandardCharsets

import scala.runtime.BoxedUnit

import net.liftweb.json.{JArray, JObject, JsonParser}

import org.apache.commons.codec.binary.Base64
import org.apache.commons.io.FileUtils

import org.junit.runner.RunWith

import org.scalatest.FunSuite
import org.scalatest.junit.JUnitRunner

import spire.math.{UByte, UInt, ULong, UShort}
import spire.syntax.literals

import capnproto.{GrowingManager, Manager}
import capnproto.composite.{ListGateway, Struct, StructGateway}

import generated._

trait FromJson[B] {
  def apply(builder: B, fields: JObject#Values)
}

trait Converter[T] {
  def apply(value: Any): T
}

@RunWith(classOf[JUnitRunner])
class TestRegressions extends FunSuite {
  def readValue[T](value: Any)(implicit converter: Converter[T]) = converter(value)

  implicit def convertVoid = new Converter[BoxedUnit] {
    def apply(value: Any) = Unit.box(())
  }

  implicit def convertBool = new Converter[Boolean] {
    def apply(value: Any) = value.asInstanceOf[Boolean]
  }

  implicit def convertBoxedBool = new Converter[JBoolean] {
    def apply(value: Any) = convertBool(value)
  }

  implicit def convertInt8 = new Converter[Byte] {
    def apply(value: Any) = value.asInstanceOf[String].toByte
  }

  implicit def convertBoxedInt8 = new Converter[JByte] {
    def apply(value: Any) = convertInt8(value)
  }

  implicit def convertInt16 = new Converter[Short] {
    def apply(value: Any) = value.asInstanceOf[String].toShort
  }

  implicit def convertBoxedInt16 = new Converter[JShort] {
    def apply(value: Any) = convertInt16(value)
  }

  implicit def convertInt32 = new Converter[Int] {
    def apply(value: Any) = value.asInstanceOf[String].toInt
  }

  implicit def convertBoxedInt32 = new Converter[Integer] {
    def apply(value: Any) = convertInt32(value)
  }

  implicit def convertInt64 = new Converter[Long] {
    def apply(value: Any) = value.asInstanceOf[String].toLong
  }

  implicit def convertBoxedInt64 = new Converter[JLong] {
    def apply(value: Any) = convertInt64(value)
  }

  implicit def convertUInt8 = new Converter[UByte] {
    def apply(value: Any) = UByte((BigInt(value.asInstanceOf[String]) - BigInt("256")).byteValue)
  }

  implicit def convertUInt16 = new Converter[UShort] {
    def apply(value: Any) = UShort((BigInt(value.asInstanceOf[String]) - BigInt("65536")).shortValue.toChar)
  }

  implicit def convertUInt32 = new Converter[UInt] {
    def apply(value: Any) = UInt((BigInt(value.asInstanceOf[String]) - BigInt("4294967296")).intValue)
  }

  implicit def convertUInt64 = new Converter[ULong] {
    def apply(value: Any) = ULong((BigInt(value.asInstanceOf[String]) - BigInt("18446744073709551616")).longValue)
  }

  implicit def convertFloat32 = new Converter[Float] {
    def apply(value: Any) = value.asInstanceOf[Double].toFloat
  }

  implicit def convertBoxedFloat32 = new Converter[JFloat] {
    def apply(value: Any) = convertFloat32(value)
  }

  implicit def convertFloat64 = new Converter[Double] {
    def apply(value: Any) = value.asInstanceOf[Double]
  }

  implicit def convertBoxedFloat64 = new Converter[JDouble] {
    def apply(value: Any) = convertFloat64(value)
  }

  def buildPrimitiveList[T](gateway: ListGateway[T], entry: JObject#Values)(implicit converter: Converter[T]) {
    val list = gateway.fill(convertUInt32(entry("size")))
    entry("values").asInstanceOf[JObject#Values].foreach(pair => list.set(convertInt32(pair._1), converter(pair._2)))
  }

  // TODO scala's type members would let us only pass the containing type
  def buildCompositeList[R <: Struct[R, B], B <: R with Modifiable[R]](gateway: ListGateway[StructGateway[R, B]],
      entry: JObject#Values)(implicit fromJson: FromJson[B]) {
    val list = gateway.fill(convertUInt32(entry("size")))
    entry("values").asInstanceOf[JObject#Values].foreach { pair =>
      fromJson(list.get(convertInt32(pair._1)).init(), pair._2.asInstanceOf[JObject#Values])
    }
  }

  // TODO make automatic CnP-to-JSON conversion look sort of like this
  // TODO re-implement all the *-test.c++ tests here
  // TODO test reading capnp under a bunch of weird segment conditions - including security restrictions, etc

  // TODO this shouldn't need to be explicitly tagged
  implicit def fromJsonTestAllTypes: FromJson[TestAllTypes.Builder] = new FromJson[TestAllTypes.Builder] {
    def apply(builder: TestAllTypes.Builder, fields: JObject#Values) {
      /*fields.get("voidField").map(field => builder.setVoidField(readValue[BoxedUnit](field)))
      fields.get("boolField").map(field => builder.setBoolField(readValue[Boolean](field)))*/
      fields.get("int8Field").map(field => builder.setInt8Field(readValue[Byte](field)))
      /*fields.get("int16Field").map(field => builder.setInt16Field(readValue[Short](field)))
      fields.get("int32Field").map(field => builder.setInt32Field(readValue[Int](field)))
      fields.get("int64Field").map(field => builder.setInt64Field(readValue[Long](field)))
      // TODO java annotation to preserve type-checking for value classes (bare primitives still acceptable) - use case for subclasses?
      fields.get("uInt8Field").map(field => builder.setUInt8Field(readValue[UByte](field).toByte))
      fields.get("uInt16Field").map(field => builder.setUInt16Field(readValue[UShort](field).toShort.toChar))
      fields.get("uInt32Field").map(field => builder.setUInt32Field(readValue[UInt](field).toInt))
      fields.get("uInt64Field").map(field => builder.setUInt64Field(readValue[ULong](field).toLong))
      fields.get("float32Field").map(field => builder.setFloat32Field(readValue[Float](field)))
      fields.get("float64Field").map(field => builder.setFloat64Field(readValue[Double](field)))*/

      //builder.getTextField.set(fields("textField").asInstanceOf[String])
      //builder.getDataField.set(fromBase64(fields("dataField")))

      /*fields.get("structField").map(field => fromJsonTestAllTypes(builder.structField.init(), field.asInstanceOf[JObject#Values]))

      fields.get("voidList").map(field => buildPrimitiveList(builder.voidList, field.asInstanceOf[JObject#Values]))
      fields.get("boolList").map(field => buildPrimitiveList(builder.boolList, field.asInstanceOf[JObject#Values]))
      fields.get("int8List").map(field => buildPrimitiveList(builder.int8List, field.asInstanceOf[JObject#Values]))
      fields.get("int16List").map(field => buildPrimitiveList(builder.int16List, field.asInstanceOf[JObject#Values]))
      fields.get("int32List").map(field => buildPrimitiveList(builder.int32List, field.asInstanceOf[JObject#Values]))
      fields.get("int64List").map(field => buildPrimitiveList(builder.int64List, field.asInstanceOf[JObject#Values]))
      fields.get("uInt8List").map(field => buildPrimitiveList(builder.uInt8List, field.asInstanceOf[JObject#Values]))
      fields.get("uInt16List").map(field => buildPrimitiveList(builder.uInt16List, field.asInstanceOf[JObject#Values]))
      fields.get("uInt32List").map(field => buildPrimitiveList(builder.uInt32List, field.asInstanceOf[JObject#Values]))
      fields.get("uInt64List").map(field => buildPrimitiveList(builder.uInt64List, field.asInstanceOf[JObject#Values]))
      fields.get("float32List").map(field => buildPrimitiveList(builder.float32List, field.asInstanceOf[JObject#Values]))
      fields.get("float64List").map(field => buildPrimitiveList(builder.float64List, field.asInstanceOf[JObject#Values]))*/

      fields.get("structList").map { field =>
        buildCompositeList[TestAllTypes.Reader, TestAllTypes.Builder](builder.structList,
          field.asInstanceOf[JObject#Values])
      }
    }
  }

  test("sdfsdf") {
    try {
      val json = JsonParser.parse(FileUtils.readFileToString(
        new File("src/test/resources/test.json"), StandardCharsets.UTF_8).replaceAll("#.*", " "))
      (json \ "tests").asInstanceOf[JArray].values.asInstanceOf[List[JObject#Values]].foreach { test =>
        GrowingManager.open { manager =>
          test("id") match {
            case "20a8f314b80b63fd" => {
              fromJsonTestAllTypes(new TestAllTypes.Builder(manager), test("fields").asInstanceOf[JObject#Values])
              // TODO macro to automatically prepend "get" to method names in calls
              val actual = Manager.toStreamFormat(manager)
              println("Actual:")
              TestRegressions.printBytes(actual)
              val expected = Base64.decodeBase64(test("expected").asInstanceOf[String])
              println("\nExpected:")
              TestRegressions.printBytes(expected.toIndexedSeq)
              assert(actual.toArray === expected)
            }
            case _ =>
          }
        }
      }
    } catch {
      case e: Throwable => e.printStackTrace()
    }
  }
}

object TestRegressions {
  def printBytes(bytes: Seq[Byte]) {
    bytes.grouped(8).foreach { line =>
      line.foreach(byte => print(String.format("%8s", Integer.toBinaryString(byte & 0xFF)).replace(" ", "0") + " "))
      println()
    }
  }
}
