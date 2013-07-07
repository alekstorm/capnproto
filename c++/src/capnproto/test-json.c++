#include "test.capnp.h"

#include <json/json.h>

#include <capnproto/io.h>
#include <capnproto/list.h>
#include <capnproto/message.h>
#include <capnproto/serialize.h>
#include <capnproto/type-safety.h>

#include <iostream>
#include <fstream>

/*
   base64.cpp and base64.h

   Copyright (C) 2004-2008 René Nyffenegger

   This source code is provided 'as-is', without any express or implied
   warranty. In no event will the author be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this source code must not be misrepresented; you must not
      claim that you wrote the original source code. If you use this source code
      in a product, an acknowledgment in the product documentation would be
      appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
      misrepresented as being the original source code.

   3. This notice may not be removed or altered from any source distribution.

   René Nyffenegger rene.nyffenegger@adp-gmbh.ch

  Modified from its original version.

*/

static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;
}

int base64_decode(std::string const& encoded_string, unsigned char* buffer) {
  int buf_idx = 0;
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::vector<unsigned char> ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        buffer[buf_idx++] = char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) buffer[buf_idx++] = char_array_3[j];
  }

  return buf_idx;
}

typedef std::uint64_t hash_t;

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis) {
  return *str ? hash_compile_time(str+1, (*str ^ last_value) * prime) : last_value;
}

hash_t hash(char const* str) {
  hash_t ret{basis};

  while (*str) {
    ret ^= *str;
    ret *= prime;
    str++;
  }

  return ret;
}

constexpr unsigned long long operator "" _hash(char const* p, size_t) {
  return hash_compile_time(p);
}

void hexdump(const void *ptr, int buflen);

template<typename T> T readValue(const Json::Value& value) {};

template<> ::capnproto::Void readValue(const Json::Value& value) { return ::capnproto::Void::VOID; }
template<> bool readValue(const Json::Value& value) { return value.asBool(); }
template<> ::int8_t readValue(const Json::Value& value) { return atoi(value.asCString()); }
template<> ::int16_t readValue(const Json::Value& value) { return atoi(value.asCString()); }
template<> ::int32_t readValue(const Json::Value& value) { return atoi(value.asCString()); }
template<> ::int64_t readValue(const Json::Value& value) { return atol(value.asCString()); }
template<> ::uint8_t readValue(const Json::Value& value) { return strtoul(value.asCString(), NULL, 10); }
template<> ::uint16_t readValue(const Json::Value& value) { return strtoul(value.asCString(), NULL, 10); }
template<> ::uint32_t readValue(const Json::Value& value) { return strtoul(value.asCString(), NULL, 10); }
template<> ::uint64_t readValue(const Json::Value& value) { return strtoul(value.asCString(), NULL, 10); }
template<> float readValue(const Json::Value& value) { return value.asFloat(); }
template<> double readValue(const Json::Value& value) { return value.asDouble(); }

template<typename T>
void buildPrimitiveList(typename ::capnproto::List<T>::Builder builder, const Json::Value& values) {
  auto members = values.getMemberNames();
  for (int i = 0; i < members.size(); i++)
    builder.set(i, readValue<T>(values[members[i]]));
}

template<typename T>
void buildCompositeList(typename ::capnproto::List<T>::Builder builder, const Json::Value& values, std::function<void (typename T::Builder elementBuilder, const Json::Value& value)> buildElement) {
  auto members = values.getMemberNames();
  for (int i = 0; i < members.size(); i++)
    buildElement(builder[i], values[members[i]]);
}

#define FIELD(builder, field, type, value) if (!value.isNull()) { builder.set##field(readValue<type>(value)); }

#define STRUCT(builder, field, fn, value) if (!value.isNull()) { fn(builder.init##field(), value); }

#define PRIMITIVE_LIST(builder, field, type, list) if (!list.isNull()) { buildPrimitiveList<type>(builder.init##field(readValue< ::uint32_t>(list["size"])), list["values"]); }

#define COMPOSITE_LIST(builder, field, type, list, fn) if (!list.isNull()) { buildCompositeList<type>(builder.init##field(readValue< ::uint32_t>(list["size"])), list["values"], fn); }

void buildTestAllTypes(::capnproto_test::capnproto::test::TestAllTypes::Builder&& builder, const Json::Value& fields) {
  /*FIELD(builder, VoidField, ::capnproto::Void, fields["voidField"])
  FIELD(builder, BoolField, bool, fields["boolField"])*/
  //FIELD(builder, Int8Field, ::int8_t, fields["int8Field"])
  /*FIELD(builder, Int16Field, ::int16_t, fields["int16Field"])
  FIELD(builder, Int32Field, ::int32_t, fields["int32Field"])
  FIELD(builder, Int64Field, ::int64_t, fields["int64Field"])
  FIELD(builder, UInt8Field, ::uint8_t, fields["uInt8Field"])
  FIELD(builder, UInt16Field, ::uint16_t, fields["uInt16Field"])
  FIELD(builder, UInt32Field, ::uint32_t, fields["uInt32Field"])
  FIELD(builder, UInt64Field, ::uint64_t, fields["uInt64Field"])
  FIELD(builder, Float32Field, float, fields["float32Field"])
  FIELD(builder, Float64Field, double, fields["float64Field"])*/

  //builder.setTextField(fields["textField"].asString());

  //auto base64Data = fields["dataField"].asString();
  //auto buffer = new unsigned char[(base64Data.size() + 3 - 1) / 3 * 4]; // ceil(base64Data.size() / 3) * 4; http://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
  //int decodedSize = base64_decode(base64Data, buffer);
  //builder.setDataField(::capnproto::Data::Reader(reinterpret_cast<const char*>(buffer), decodedSize));
  //delete[] buffer;

  /*STRUCT(builder, StructField, buildTestAllTypes, fields["structField"])

  PRIMITIVE_LIST(builder, VoidList, ::capnproto::Void, fields["voidList"])
  PRIMITIVE_LIST(builder, BoolList, bool, fields["boolList"])
  PRIMITIVE_LIST(builder, Int8List, ::int8_t, fields["int8List"])
  PRIMITIVE_LIST(builder, Int16List, ::int16_t, fields["int16List"])
  PRIMITIVE_LIST(builder, Int32List, ::int32_t, fields["int32List"])
  PRIMITIVE_LIST(builder, Int64List, ::int64_t, fields["int64List"])
  PRIMITIVE_LIST(builder, UInt8List, ::uint8_t, fields["uInt8List"])
  PRIMITIVE_LIST(builder, UInt16List, ::uint16_t, fields["uInt16List"])
  PRIMITIVE_LIST(builder, UInt32List, ::uint32_t, fields["uInt32List"])
  PRIMITIVE_LIST(builder, UInt64List, ::uint64_t, fields["uInt64List"])
  PRIMITIVE_LIST(builder, Float32List, float, fields["float32List"])
  PRIMITIVE_LIST(builder, Float64List, double, fields["float64List"])*/

  //COMPOSITE_LIST(builder, StructList, ::capnproto_test::capnproto::test::TestAllTypes, fields["structList"], buildTestAllTypes)
}

int main() {
  Json::Value root;
  Json::Reader reader;
  std::ifstream infile("/home/alek/capnproto/scala/src/test/resources/test.json");
  if (!reader.parse(infile, root)) {
      std::cout  << "Failed to parse JSON:" << std::endl
                 << reader.getFormattedErrorMessages();
      return 1;
  }

  const Json::Value tests = root["tests"];
  for (int i = 0; i < tests.size(); i++) {
    ::capnproto::MallocMessageBuilder message;
    bool recognized = true;
    std::string id = tests[i]["id"].asString();
    switch (hash(id.c_str())) {
      case "20a8f314b80b63fd"_hash: {
        buildTestAllTypes(message.initRoot< ::capnproto_test::capnproto::test::TestAllTypes>(), tests[i]["fields"]);
        break;
      }
      default: {
        std::cout << "Unrecognized ID: " << id << std::endl;
        recognized = false;
      }
    }

    if (recognized) {
      std::string UNDERLINE = "\n" + std::string(15, '-') + "\n";
      ::capnproto::byte buffer[2048];
      ::capnproto::ArrayOutputStream outputStream(arrayPtr(buffer, sizeof(buffer)));
      ::capnproto::writeMessage(outputStream, message);
      auto output = outputStream.getArray();
      auto actual = output.begin();
      auto data = tests[i]["expected"].asString();
      auto expected = new unsigned char[(data.size() + 3 - 1) / 3 * 4]; // ceil(base64Data.size() / 3) * 4; http://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
      int decodedSize = base64_decode(data, expected);
      //std::cout << "One: " << data << "\nTwo: " << base64_encode(expected, decodedSize) << std::endl;
      std::cout << "Size: " << output.size() << std::endl;
      //if (output.size() != decodedSize || memcmp(actual, expected, output.size()) != 0) {
        std::cout << "Mismatch for test: " << id << std::endl;
        std::cout << "Expected" << UNDERLINE;
        hexdump(expected, decodedSize);
        std::cout << std::endl << "Actual" << UNDERLINE;
        hexdump(actual, output.size());
        std::cout << std::endl << "Actual (encoded): " << base64_encode((unsigned char*)actual, output.size()) << std::endl;
      //}
      delete[] expected;
    }
  }

  return 0;
}

void hexdump(const void *ptr, int buflen) {
  unsigned char *buf = (unsigned char*)ptr;
  int i, j;
  for (i=0; i<buflen; i+=16) {
    printf("%06x: ", i);
    for (j=0; j<16; j++)
      if (i+j < buflen)
        printf("%02x ", buf[i+j]);
      else
        printf("   ");
    printf(" ");
    for (j=0; j<16; j++)
      if (i+j < buflen)
        printf("%c", isprint(buf[i+j]) ? buf[i+j] : '.');
    printf("\n");
  }
}
