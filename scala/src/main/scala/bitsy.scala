package capnproto

import bitsy.Quantity

import shapeless._; import Nat._

package object bitsy {
  type Bytes = Quantity[_0]
  type Shorts = Quantity[_1]
  type Quads = Quantity[_2]
  type Words = Quantity[_3]
}
