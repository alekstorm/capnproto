// Generated code, DO NOT EDIT

#ifndef CAPNP_INCLUDED_cf321c6d9838c2958f78108066479a59
#define CAPNP_INCLUDED_cf321c6d9838c2958f78108066479a59

#include <capnp/generated-header-support.h>

namespace capnproto_test {
namespace capnp {
namespace test {


struct TestAllTypes {
  TestAllTypes() = delete;

  class Reader;
  class Builder;

private:
};

struct TestDefaults {
  TestDefaults() = delete;

  class Reader;
  class Builder;

private:
  static const ::capnp::_::AlignedData<1> DEFAULT_TEXT_FIELD;
  static const ::capnp::_::AlignedData<1> DEFAULT_DATA_FIELD;
  static const ::capnp::_::AlignedData<208> DEFAULT_STRUCT_FIELD;
  static const ::capnp::_::AlignedData<1> DEFAULT_VOID_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_BOOL_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_INT8_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_INT16_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_INT32_LIST;
  static const ::capnp::_::AlignedData<3> DEFAULT_INT64_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_U_INT8_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_U_INT16_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_U_INT32_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_U_INT64_LIST;
  static const ::capnp::_::AlignedData<3> DEFAULT_FLOAT32_LIST;
  static const ::capnp::_::AlignedData<5> DEFAULT_FLOAT64_LIST;
  static const ::capnp::_::AlignedData<7> DEFAULT_TEXT_LIST;
  static const ::capnp::_::AlignedData<8> DEFAULT_DATA_LIST;
  static const ::capnp::_::AlignedData<86> DEFAULT_STRUCT_LIST;
  static const ::capnp::_::AlignedData<2> DEFAULT_ENUM_LIST;
};

struct TestFieldZeroIsBit {
  TestFieldZeroIsBit() = delete;

  class Reader;
  class Builder;

private:
};

struct TestLateUnion {
  TestLateUnion() = delete;

  class Reader;
  class Builder;
  struct TheUnion;
  struct AnotherUnion;

private:
};

struct TestLateUnion::AnotherUnion {
  AnotherUnion() = delete;

  class Reader;
  class Builder;

  enum Which: uint16_t {
    QUX = 0,
    CORGE = 1,
    GRAULT = 2,
  };

private:
};

struct TestLateUnion::TheUnion {
  TheUnion() = delete;

  class Reader;
  class Builder;

  enum Which: uint16_t {
    QUX = 0,
    CORGE = 1,
    GRAULT = 2,
  };

private:
};

struct TestListDefaults {
  TestListDefaults() = delete;

  class Reader;
  class Builder;

private:
  static const ::capnp::_::AlignedData<123> DEFAULT_LISTS;
};

struct TestLists {
  TestLists() = delete;

  class Reader;
  class Builder;
  struct Struct0;
  struct Struct1;
  struct Struct8;
  struct Struct16;
  struct Struct32;
  struct Struct64;
  struct StructP;

private:
};

struct TestLists::Struct0 {
  Struct0() = delete;

  class Reader;
  class Builder;

private:
};

struct TestLists::Struct1 {
  Struct1() = delete;

  class Reader;
  class Builder;

private:
};

struct TestLists::Struct16 {
  Struct16() = delete;

  class Reader;
  class Builder;

private:
};

struct TestLists::Struct32 {
  Struct32() = delete;

  class Reader;
  class Builder;

private:
};

struct TestLists::Struct64 {
  Struct64() = delete;

  class Reader;
  class Builder;

private:
};

struct TestLists::Struct8 {
  Struct8() = delete;

  class Reader;
  class Builder;

private:
};

struct TestLists::StructP {
  StructP() = delete;

  class Reader;
  class Builder;

private:
};

struct TestNestedTypes {
  TestNestedTypes() = delete;

  class Reader;
  class Builder;
  struct NestedStruct;

  enum class NestedEnum: uint16_t {
    FOO = 0,
    BAR = 1,
  };

private:
};

struct TestNestedTypes::NestedStruct {
  NestedStruct() = delete;

  class Reader;
  class Builder;

  enum class NestedEnum: uint16_t {
    BAZ = 0,
    QUX = 1,
    QUUX = 2,
  };

private:
};

struct TestNewVersion {
  TestNewVersion() = delete;

  class Reader;
  class Builder;

private:
  static const ::capnp::_::AlignedData<1> DEFAULT_NEW2;
};

struct TestObject {
  TestObject() = delete;

  class Reader;
  class Builder;

private:
};

struct TestOldVersion {
  TestOldVersion() = delete;

  class Reader;
  class Builder;

private:
};

struct TestOutOfOrder {
  TestOutOfOrder() = delete;

  class Reader;
  class Builder;

private:
};

struct TestUnion {
  TestUnion() = delete;

  class Reader;
  class Builder;
  struct Union0;
  struct Union1;
  struct Union2;
  struct Union3;

private:
};

struct TestUnion::Union0 {
  Union0() = delete;

  class Reader;
  class Builder;

  enum Which: uint16_t {
    U0F0S0 = 0,
    U0F0S1 = 1,
    U0F0S8 = 2,
    U0F0S16 = 3,
    U0F0S32 = 4,
    U0F0S64 = 5,
    U0F0SP = 6,
    U0F1S0 = 7,
    U0F1S1 = 8,
    U0F1S8 = 9,
    U0F1S16 = 10,
    U0F1S32 = 11,
    U0F1S64 = 12,
    U0F1SP = 13,
  };

private:
};

struct TestUnion::Union1 {
  Union1() = delete;

  class Reader;
  class Builder;

  enum Which: uint16_t {
    U1F0S0 = 0,
    U1F0S1 = 1,
    U1F1S1 = 2,
    U1F0S8 = 3,
    U1F1S8 = 4,
    U1F0S16 = 5,
    U1F1S16 = 6,
    U1F0S32 = 7,
    U1F1S32 = 8,
    U1F0S64 = 9,
    U1F1S64 = 10,
    U1F0SP = 11,
    U1F1SP = 12,
    U1F2S0 = 13,
    U1F2S1 = 14,
    U1F2S8 = 15,
    U1F2S16 = 16,
    U1F2S32 = 17,
    U1F2S64 = 18,
    U1F2SP = 19,
  };

private:
};

struct TestUnion::Union2 {
  Union2() = delete;

  class Reader;
  class Builder;

  enum Which: uint16_t {
    U2F0S64 = 4,
    U2F0S32 = 3,
    U2F0S16 = 2,
    U2F0S8 = 1,
    U2F0S1 = 0,
  };

private:
};

struct TestUnion::Union3 {
  Union3() = delete;

  class Reader;
  class Builder;

  enum Which: uint16_t {
    U3F0S64 = 4,
    U3F0S32 = 3,
    U3F0S16 = 2,
    U3F0S8 = 1,
    U3F0S1 = 0,
  };

private:
};

struct TestUnionDefaults {
  TestUnionDefaults() = delete;

  class Reader;
  class Builder;

private:
  static const ::capnp::_::AlignedData<11> DEFAULT_S16S8S64S8_SET;
  static const ::capnp::_::AlignedData<12> DEFAULT_S0SPS1S32_SET;
};

struct TestUsing {
  TestUsing() = delete;

  class Reader;
  class Builder;

private:
};


enum class TestEnum: uint16_t {
  FOO = 0,
  BAR = 1,
  BAZ = 2,
  QUX = 3,
  QUUX = 4,
  CORGE = 5,
  GRAULT = 6,
  GARPLY = 7,
};


}  // namespace
}  // namespace
}  // namespace

namespace capnp {
namespace schemas {
extern const ::capnp::_::RawSchema s_a0a8f314b80b63fd;
extern const ::capnp::_::RawSchema s_eb3f9ebe98c73cb6;
extern const ::capnp::_::RawSchema s_9c8e9318b29d9cd3;
extern const ::capnp::_::RawSchema s_92fc29a80f3ddd5c;
extern const ::capnp::_::RawSchema s_a76e3c9bb7fd56d3;
extern const ::capnp::_::RawSchema s_a851ad32cbc2ffea;
extern const ::capnp::_::RawSchema s_e41885c94393277e;
extern const ::capnp::_::RawSchema s_8412c03b75b2cfee;
extern const ::capnp::_::RawSchema s_e0fe5870b141ad69;
extern const ::capnp::_::RawSchema s_a8abf7a82928986c;
extern const ::capnp::_::RawSchema s_ad7beedc4ed30742;
extern const ::capnp::_::RawSchema s_ef9a34f2ff7cc646;
extern const ::capnp::_::RawSchema s_a6411a353090145b;
extern const ::capnp::_::RawSchema s_c6abf1b0329e6227;
extern const ::capnp::_::RawSchema s_d9f2b5941a343bcd;
extern const ::capnp::_::RawSchema s_b651d2fba42056d4;
extern const ::capnp::_::RawSchema s_82cd03a53b29d76b;
extern const ::capnp::_::RawSchema s_cfa0d546993a3df3;
extern const ::capnp::_::RawSchema s_8ed75a7469f04ce3;
extern const ::capnp::_::RawSchema s_d1f4434616a112ca;
extern const ::capnp::_::RawSchema s_95b30dd14e01dda8;
extern const ::capnp::_::RawSchema s_a9d5f8efe770022b;
extern const ::capnp::_::RawSchema s_f47697362233ce52;
extern const ::capnp::_::RawSchema s_94f7e0b103b4b718;
extern const ::capnp::_::RawSchema s_e78aac389e77b065;
}  // namespace schemas
namespace _ {  // private
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestAllTypes, a0a8f314b80b63fd,
    6, 20, INLINE_COMPOSITE);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestDefaults, eb3f9ebe98c73cb6,
    6, 20, INLINE_COMPOSITE);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestFieldZeroIsBit, 92fc29a80f3ddd5c,
    1, 0, TWO_BYTES);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLateUnion, a76e3c9bb7fd56d3,
    3, 3, INLINE_COMPOSITE);
CAPNP_DECLARE_UNION(
    ::capnproto_test::capnp::test::TestLateUnion::TheUnion,
    ::capnproto_test::capnp::test::TestLateUnion, 3);
CAPNP_DECLARE_UNION(
    ::capnproto_test::capnp::test::TestLateUnion::AnotherUnion,
    ::capnproto_test::capnp::test::TestLateUnion, 4);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestListDefaults, a851ad32cbc2ffea,
    0, 1, POINTER);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLists, e41885c94393277e,
    0, 10, INLINE_COMPOSITE);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLists::Struct0, 8412c03b75b2cfee,
    0, 0, VOID);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLists::Struct1, e0fe5870b141ad69,
    1, 0, BIT);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLists::Struct16, a8abf7a82928986c,
    1, 0, TWO_BYTES);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLists::Struct32, ad7beedc4ed30742,
    1, 0, FOUR_BYTES);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLists::Struct64, ef9a34f2ff7cc646,
    1, 0, EIGHT_BYTES);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLists::Struct8, a6411a353090145b,
    1, 0, BYTE);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestLists::StructP, c6abf1b0329e6227,
    0, 1, POINTER);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestNestedTypes, d9f2b5941a343bcd,
    1, 1, INLINE_COMPOSITE);
CAPNP_DECLARE_ENUM(
    ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum, b651d2fba42056d4);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct, 82cd03a53b29d76b,
    1, 0, FOUR_BYTES);
CAPNP_DECLARE_ENUM(
    ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum, cfa0d546993a3df3);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestNewVersion, 8ed75a7469f04ce3,
    2, 3, INLINE_COMPOSITE);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestObject, d1f4434616a112ca,
    0, 1, POINTER);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestOldVersion, 95b30dd14e01dda8,
    1, 2, INLINE_COMPOSITE);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestOutOfOrder, a9d5f8efe770022b,
    0, 9, INLINE_COMPOSITE);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestUnion, f47697362233ce52,
    8, 2, INLINE_COMPOSITE);
CAPNP_DECLARE_UNION(
    ::capnproto_test::capnp::test::TestUnion::Union0,
    ::capnproto_test::capnp::test::TestUnion, 0);
CAPNP_DECLARE_UNION(
    ::capnproto_test::capnp::test::TestUnion::Union1,
    ::capnproto_test::capnp::test::TestUnion, 1);
CAPNP_DECLARE_UNION(
    ::capnproto_test::capnp::test::TestUnion::Union2,
    ::capnproto_test::capnp::test::TestUnion, 2);
CAPNP_DECLARE_UNION(
    ::capnproto_test::capnp::test::TestUnion::Union3,
    ::capnproto_test::capnp::test::TestUnion, 3);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestUnionDefaults, 94f7e0b103b4b718,
    0, 2, INLINE_COMPOSITE);
CAPNP_DECLARE_STRUCT(
    ::capnproto_test::capnp::test::TestUsing, e78aac389e77b065,
    1, 0, FOUR_BYTES);
CAPNP_DECLARE_ENUM(
    ::capnproto_test::capnp::test::TestEnum, 9c8e9318b29d9cd3);
}  // namespace capnp
}  // namespace _ (private)

namespace capnproto_test {
namespace capnp {
namespace test {



class TestAllTypes::Reader {
public:
  typedef TestAllTypes Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // voidField@0: Void;  # (none)
  inline  ::capnp::Void getVoidField() const;

  // boolField@1: Bool;  # bits[0, 1)
  inline bool getBoolField() const;

  // int8Field@2: Int8;  # bits[8, 16)
  inline  ::int8_t getInt8Field() const;

  // int16Field@3: Int16;  # bits[16, 32)
  inline  ::int16_t getInt16Field() const;

  // int32Field@4: Int32;  # bits[32, 64)
  inline  ::int32_t getInt32Field() const;

  // int64Field@5: Int64;  # bits[64, 128)
  inline  ::int64_t getInt64Field() const;

  // uInt8Field@6: UInt8;  # bits[128, 136)
  inline  ::uint8_t getUInt8Field() const;

  // uInt16Field@7: UInt16;  # bits[144, 160)
  inline  ::uint16_t getUInt16Field() const;

  // uInt32Field@8: UInt32;  # bits[160, 192)
  inline  ::uint32_t getUInt32Field() const;

  // uInt64Field@9: UInt64;  # bits[192, 256)
  inline  ::uint64_t getUInt64Field() const;

  // float32Field@10: Float32;  # bits[256, 288)
  inline float getFloat32Field() const;

  // float64Field@11: Float64;  # bits[320, 384)
  inline double getFloat64Field() const;

  // textField@12: Text;  # ptr[0]
  inline bool hasTextField() const;
  inline  ::capnp::Text::Reader getTextField() const;

  // dataField@13: Data;  # ptr[1]
  inline bool hasDataField() const;
  inline  ::capnp::Data::Reader getDataField() const;

  // structField@14: .TestAllTypes;  # ptr[2]
  inline bool hasStructField() const;
  inline  ::capnproto_test::capnp::test::TestAllTypes::Reader getStructField() const;

  // enumField@15: .TestEnum;  # bits[288, 304)
  inline  ::capnproto_test::capnp::test::TestEnum getEnumField() const;

  // interfaceField@16: Void;  # (none)
  inline  ::capnp::Void getInterfaceField() const;

  // voidList@17: List(Void);  # ptr[3]
  inline bool hasVoidList() const;
  inline  ::capnp::List< ::capnp::Void>::Reader getVoidList() const;

  // boolList@18: List(Bool);  # ptr[4]
  inline bool hasBoolList() const;
  inline  ::capnp::List<bool>::Reader getBoolList() const;

  // int8List@19: List(Int8);  # ptr[5]
  inline bool hasInt8List() const;
  inline  ::capnp::List< ::int8_t>::Reader getInt8List() const;

  // int16List@20: List(Int16);  # ptr[6]
  inline bool hasInt16List() const;
  inline  ::capnp::List< ::int16_t>::Reader getInt16List() const;

  // int32List@21: List(Int32);  # ptr[7]
  inline bool hasInt32List() const;
  inline  ::capnp::List< ::int32_t>::Reader getInt32List() const;

  // int64List@22: List(Int64);  # ptr[8]
  inline bool hasInt64List() const;
  inline  ::capnp::List< ::int64_t>::Reader getInt64List() const;

  // uInt8List@23: List(UInt8);  # ptr[9]
  inline bool hasUInt8List() const;
  inline  ::capnp::List< ::uint8_t>::Reader getUInt8List() const;

  // uInt16List@24: List(UInt16);  # ptr[10]
  inline bool hasUInt16List() const;
  inline  ::capnp::List< ::uint16_t>::Reader getUInt16List() const;

  // uInt32List@25: List(UInt32);  # ptr[11]
  inline bool hasUInt32List() const;
  inline  ::capnp::List< ::uint32_t>::Reader getUInt32List() const;

  // uInt64List@26: List(UInt64);  # ptr[12]
  inline bool hasUInt64List() const;
  inline  ::capnp::List< ::uint64_t>::Reader getUInt64List() const;

  // float32List@27: List(Float32);  # ptr[13]
  inline bool hasFloat32List() const;
  inline  ::capnp::List<float>::Reader getFloat32List() const;

  // float64List@28: List(Float64);  # ptr[14]
  inline bool hasFloat64List() const;
  inline  ::capnp::List<double>::Reader getFloat64List() const;

  // textList@29: List(Text);  # ptr[15]
  inline bool hasTextList() const;
  inline  ::capnp::List< ::capnp::Text>::Reader getTextList() const;

  // dataList@30: List(Data);  # ptr[16]
  inline bool hasDataList() const;
  inline  ::capnp::List< ::capnp::Data>::Reader getDataList() const;

  // structList@31: List(.TestAllTypes);  # ptr[17]
  inline bool hasStructList() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader getStructList() const;

  // enumList@32: List(.TestEnum);  # ptr[18]
  inline bool hasEnumList() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Reader getEnumList() const;

  // interfaceList@33: List(Void);  # ptr[19]
  inline bool hasInterfaceList() const;
  inline  ::capnp::List< ::capnp::Void>::Reader getInterfaceList() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestAllTypes::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestAllTypes::Reader reader) {
  return ::capnp::_::structString<TestAllTypes>(reader._reader);
}



class TestAllTypes::Builder {
public:
  typedef TestAllTypes Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // voidField@0: Void;  # (none)
  inline  ::capnp::Void getVoidField();
  inline void setVoidField( ::capnp::Void value);

  // boolField@1: Bool;  # bits[0, 1)
  inline bool getBoolField();
  inline void setBoolField(bool value);

  // int8Field@2: Int8;  # bits[8, 16)
  inline  ::int8_t getInt8Field();
  inline void setInt8Field( ::int8_t value);

  // int16Field@3: Int16;  # bits[16, 32)
  inline  ::int16_t getInt16Field();
  inline void setInt16Field( ::int16_t value);

  // int32Field@4: Int32;  # bits[32, 64)
  inline  ::int32_t getInt32Field();
  inline void setInt32Field( ::int32_t value);

  // int64Field@5: Int64;  # bits[64, 128)
  inline  ::int64_t getInt64Field();
  inline void setInt64Field( ::int64_t value);

  // uInt8Field@6: UInt8;  # bits[128, 136)
  inline  ::uint8_t getUInt8Field();
  inline void setUInt8Field( ::uint8_t value);

  // uInt16Field@7: UInt16;  # bits[144, 160)
  inline  ::uint16_t getUInt16Field();
  inline void setUInt16Field( ::uint16_t value);

  // uInt32Field@8: UInt32;  # bits[160, 192)
  inline  ::uint32_t getUInt32Field();
  inline void setUInt32Field( ::uint32_t value);

  // uInt64Field@9: UInt64;  # bits[192, 256)
  inline  ::uint64_t getUInt64Field();
  inline void setUInt64Field( ::uint64_t value);

  // float32Field@10: Float32;  # bits[256, 288)
  inline float getFloat32Field();
  inline void setFloat32Field(float value);

  // float64Field@11: Float64;  # bits[320, 384)
  inline double getFloat64Field();
  inline void setFloat64Field(double value);

  // textField@12: Text;  # ptr[0]
  inline bool hasTextField();
  inline  ::capnp::Text::Builder getTextField();
  inline void setTextField( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initTextField(unsigned int size);

  // dataField@13: Data;  # ptr[1]
  inline bool hasDataField();
  inline  ::capnp::Data::Builder getDataField();
  inline void setDataField( ::capnp::Data::Reader other);
  inline  ::capnp::Data::Builder initDataField(unsigned int size);

  // structField@14: .TestAllTypes;  # ptr[2]
  inline bool hasStructField();
  inline  ::capnproto_test::capnp::test::TestAllTypes::Builder getStructField();
  inline void setStructField( ::capnproto_test::capnp::test::TestAllTypes::Reader other);
  inline  ::capnproto_test::capnp::test::TestAllTypes::Builder initStructField();

  // enumField@15: .TestEnum;  # bits[288, 304)
  inline  ::capnproto_test::capnp::test::TestEnum getEnumField();
  inline void setEnumField( ::capnproto_test::capnp::test::TestEnum value);

  // interfaceField@16: Void;  # (none)
  inline  ::capnp::Void getInterfaceField();
  inline void setInterfaceField( ::capnp::Void value);

  // voidList@17: List(Void);  # ptr[3]
  inline bool hasVoidList();
  inline  ::capnp::List< ::capnp::Void>::Builder getVoidList();
  inline void setVoidList( ::capnp::List< ::capnp::Void>::Reader other);
  inline void setVoidList(
      std::initializer_list< ::capnp::Void> other);
  inline  ::capnp::List< ::capnp::Void>::Builder initVoidList(unsigned int size);

  // boolList@18: List(Bool);  # ptr[4]
  inline bool hasBoolList();
  inline  ::capnp::List<bool>::Builder getBoolList();
  inline void setBoolList( ::capnp::List<bool>::Reader other);
  inline void setBoolList(
      std::initializer_list<bool> other);
  inline  ::capnp::List<bool>::Builder initBoolList(unsigned int size);

  // int8List@19: List(Int8);  # ptr[5]
  inline bool hasInt8List();
  inline  ::capnp::List< ::int8_t>::Builder getInt8List();
  inline void setInt8List( ::capnp::List< ::int8_t>::Reader other);
  inline void setInt8List(
      std::initializer_list< ::int8_t> other);
  inline  ::capnp::List< ::int8_t>::Builder initInt8List(unsigned int size);

  // int16List@20: List(Int16);  # ptr[6]
  inline bool hasInt16List();
  inline  ::capnp::List< ::int16_t>::Builder getInt16List();
  inline void setInt16List( ::capnp::List< ::int16_t>::Reader other);
  inline void setInt16List(
      std::initializer_list< ::int16_t> other);
  inline  ::capnp::List< ::int16_t>::Builder initInt16List(unsigned int size);

  // int32List@21: List(Int32);  # ptr[7]
  inline bool hasInt32List();
  inline  ::capnp::List< ::int32_t>::Builder getInt32List();
  inline void setInt32List( ::capnp::List< ::int32_t>::Reader other);
  inline void setInt32List(
      std::initializer_list< ::int32_t> other);
  inline  ::capnp::List< ::int32_t>::Builder initInt32List(unsigned int size);

  // int64List@22: List(Int64);  # ptr[8]
  inline bool hasInt64List();
  inline  ::capnp::List< ::int64_t>::Builder getInt64List();
  inline void setInt64List( ::capnp::List< ::int64_t>::Reader other);
  inline void setInt64List(
      std::initializer_list< ::int64_t> other);
  inline  ::capnp::List< ::int64_t>::Builder initInt64List(unsigned int size);

  // uInt8List@23: List(UInt8);  # ptr[9]
  inline bool hasUInt8List();
  inline  ::capnp::List< ::uint8_t>::Builder getUInt8List();
  inline void setUInt8List( ::capnp::List< ::uint8_t>::Reader other);
  inline void setUInt8List(
      std::initializer_list< ::uint8_t> other);
  inline  ::capnp::List< ::uint8_t>::Builder initUInt8List(unsigned int size);

  // uInt16List@24: List(UInt16);  # ptr[10]
  inline bool hasUInt16List();
  inline  ::capnp::List< ::uint16_t>::Builder getUInt16List();
  inline void setUInt16List( ::capnp::List< ::uint16_t>::Reader other);
  inline void setUInt16List(
      std::initializer_list< ::uint16_t> other);
  inline  ::capnp::List< ::uint16_t>::Builder initUInt16List(unsigned int size);

  // uInt32List@25: List(UInt32);  # ptr[11]
  inline bool hasUInt32List();
  inline  ::capnp::List< ::uint32_t>::Builder getUInt32List();
  inline void setUInt32List( ::capnp::List< ::uint32_t>::Reader other);
  inline void setUInt32List(
      std::initializer_list< ::uint32_t> other);
  inline  ::capnp::List< ::uint32_t>::Builder initUInt32List(unsigned int size);

  // uInt64List@26: List(UInt64);  # ptr[12]
  inline bool hasUInt64List();
  inline  ::capnp::List< ::uint64_t>::Builder getUInt64List();
  inline void setUInt64List( ::capnp::List< ::uint64_t>::Reader other);
  inline void setUInt64List(
      std::initializer_list< ::uint64_t> other);
  inline  ::capnp::List< ::uint64_t>::Builder initUInt64List(unsigned int size);

  // float32List@27: List(Float32);  # ptr[13]
  inline bool hasFloat32List();
  inline  ::capnp::List<float>::Builder getFloat32List();
  inline void setFloat32List( ::capnp::List<float>::Reader other);
  inline void setFloat32List(
      std::initializer_list<float> other);
  inline  ::capnp::List<float>::Builder initFloat32List(unsigned int size);

  // float64List@28: List(Float64);  # ptr[14]
  inline bool hasFloat64List();
  inline  ::capnp::List<double>::Builder getFloat64List();
  inline void setFloat64List( ::capnp::List<double>::Reader other);
  inline void setFloat64List(
      std::initializer_list<double> other);
  inline  ::capnp::List<double>::Builder initFloat64List(unsigned int size);

  // textList@29: List(Text);  # ptr[15]
  inline bool hasTextList();
  inline  ::capnp::List< ::capnp::Text>::Builder getTextList();
  inline void setTextList( ::capnp::List< ::capnp::Text>::Reader other);
  inline void setTextList(
      std::initializer_list< ::capnp::Text::Reader> other);
  inline  ::capnp::List< ::capnp::Text>::Builder initTextList(unsigned int size);

  // dataList@30: List(Data);  # ptr[16]
  inline bool hasDataList();
  inline  ::capnp::List< ::capnp::Data>::Builder getDataList();
  inline void setDataList( ::capnp::List< ::capnp::Data>::Reader other);
  inline void setDataList(
      std::initializer_list< ::capnp::Data::Reader> other);
  inline  ::capnp::List< ::capnp::Data>::Builder initDataList(unsigned int size);

  // structList@31: List(.TestAllTypes);  # ptr[17]
  inline bool hasStructList();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Builder getStructList();
  inline void setStructList( ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Builder initStructList(unsigned int size);

  // enumList@32: List(.TestEnum);  # ptr[18]
  inline bool hasEnumList();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Builder getEnumList();
  inline void setEnumList( ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Reader other);
  inline void setEnumList(
      std::initializer_list< ::capnproto_test::capnp::test::TestEnum> other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Builder initEnumList(unsigned int size);

  // interfaceList@33: List(Void);  # ptr[19]
  inline bool hasInterfaceList();
  inline  ::capnp::List< ::capnp::Void>::Builder getInterfaceList();
  inline void setInterfaceList( ::capnp::List< ::capnp::Void>::Reader other);
  inline void setInterfaceList(
      std::initializer_list< ::capnp::Void> other);
  inline  ::capnp::List< ::capnp::Void>::Builder initInterfaceList(unsigned int size);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestAllTypes::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestAllTypes::Builder builder) {
  return ::capnp::_::structString<TestAllTypes>(builder._builder.asReader());
}

class TestDefaults::Reader {
public:
  typedef TestDefaults Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // voidField@0: Void = void;  # (none)
  inline  ::capnp::Void getVoidField() const;

  // boolField@1: Bool = true;  # bits[0, 1)
  inline bool getBoolField() const;

  // int8Field@2: Int8 = -123;  # bits[8, 16)
  inline  ::int8_t getInt8Field() const;

  // int16Field@3: Int16 = -12345;  # bits[16, 32)
  inline  ::int16_t getInt16Field() const;

  // int32Field@4: Int32 = -12345678;  # bits[32, 64)
  inline  ::int32_t getInt32Field() const;

  // int64Field@5: Int64 = -123456789012345;  # bits[64, 128)
  inline  ::int64_t getInt64Field() const;

  // uInt8Field@6: UInt8 = 234;  # bits[128, 136)
  inline  ::uint8_t getUInt8Field() const;

  // uInt16Field@7: UInt16 = 45678;  # bits[144, 160)
  inline  ::uint16_t getUInt16Field() const;

  // uInt32Field@8: UInt32 = 3456789012;  # bits[160, 192)
  inline  ::uint32_t getUInt32Field() const;

  // uInt64Field@9: UInt64 = 12345678901234567890;  # bits[192, 256)
  inline  ::uint64_t getUInt64Field() const;

  // float32Field@10: Float32 = 1234.5;  # bits[256, 288)
  inline float getFloat32Field() const;

  // float64Field@11: Float64 = -1.23e47;  # bits[320, 384)
  inline double getFloat64Field() const;

  // textField@12: Text = "foo";  # ptr[0]
  inline bool hasTextField() const;
  inline  ::capnp::Text::Reader getTextField() const;

  // dataField@13: Data = "bar";  # ptr[1]
  inline bool hasDataField() const;
  inline  ::capnp::Data::Reader getDataField() const;

  // structField@14: .TestAllTypes = (voidField = void, boolField = true, int8Field = -12, int16Field = 3456, int32Field = -78901234, int64Field = 56789012345678, uInt8Field = 90, uInt16Field = 1234, uInt32Field = 56789012, uInt64Field = 345678901234567890, float32Field = -1.25e-10, float64Field = 345.0, textField = "baz", dataField = "qux", structField = (textField = "nested", structField = (textField = "really nested")), enumField = baz, voidList = [void, void, void], boolList = [false, true, false, true, true], int8List = [12, -34, -128, 127], int16List = [1234, -5678, -32768, 32767], int32List = [12345678, -90123456, -2147483648, 2147483647], int64List = [123456789012345, -678901234567890, -9223372036854775808, 9223372036854775807], uInt8List = [12, 34, 0, 255], uInt16List = [1234, 5678, 0, 65535], uInt32List = [12345678, 90123456, 0, 4294967295], uInt64List = [123456789012345, 678901234567890, 0, 18446744073709551615], float32List = [0.0, 1234567.0, 1.0e37, -1.0e37, 1.0e-37, -1.0e-37], float64List = [0.0, 1.23456789012345e14, 1.0e306, -1.0e306, 1.0e-306, -1.0e-306], textList = ["quux", "corge", "grault"], dataList = ["garply", "waldo", "fred"], structList = [(textField = "x structlist 1"), (textField = "x structlist 2"), (textField = "x structlist 3")], enumList = [qux, bar, grault]);  # ptr[2]
  inline bool hasStructField() const;
  inline  ::capnproto_test::capnp::test::TestAllTypes::Reader getStructField() const;

  // enumField@15: .TestEnum = corge;  # bits[288, 304)
  inline  ::capnproto_test::capnp::test::TestEnum getEnumField() const;

  // interfaceField@16: Void;  # (none)
  inline  ::capnp::Void getInterfaceField() const;

  // voidList@17: List(Void) = [void, void, void, void, void, void];  # ptr[3]
  inline bool hasVoidList() const;
  inline  ::capnp::List< ::capnp::Void>::Reader getVoidList() const;

  // boolList@18: List(Bool) = [true, false, false, true];  # ptr[4]
  inline bool hasBoolList() const;
  inline  ::capnp::List<bool>::Reader getBoolList() const;

  // int8List@19: List(Int8) = [111, -111];  # ptr[5]
  inline bool hasInt8List() const;
  inline  ::capnp::List< ::int8_t>::Reader getInt8List() const;

  // int16List@20: List(Int16) = [11111, -11111];  # ptr[6]
  inline bool hasInt16List() const;
  inline  ::capnp::List< ::int16_t>::Reader getInt16List() const;

  // int32List@21: List(Int32) = [111111111, -111111111];  # ptr[7]
  inline bool hasInt32List() const;
  inline  ::capnp::List< ::int32_t>::Reader getInt32List() const;

  // int64List@22: List(Int64) = [1111111111111111111, -1111111111111111111];  # ptr[8]
  inline bool hasInt64List() const;
  inline  ::capnp::List< ::int64_t>::Reader getInt64List() const;

  // uInt8List@23: List(UInt8) = [111, 222];  # ptr[9]
  inline bool hasUInt8List() const;
  inline  ::capnp::List< ::uint8_t>::Reader getUInt8List() const;

  // uInt16List@24: List(UInt16) = [33333, 44444];  # ptr[10]
  inline bool hasUInt16List() const;
  inline  ::capnp::List< ::uint16_t>::Reader getUInt16List() const;

  // uInt32List@25: List(UInt32) = [3333333333];  # ptr[11]
  inline bool hasUInt32List() const;
  inline  ::capnp::List< ::uint32_t>::Reader getUInt32List() const;

  // uInt64List@26: List(UInt64) = [11111111111111111111];  # ptr[12]
  inline bool hasUInt64List() const;
  inline  ::capnp::List< ::uint64_t>::Reader getUInt64List() const;

  // float32List@27: List(Float32) = [5555.5, Infinity, -Infinity, NaN];  # ptr[13]
  inline bool hasFloat32List() const;
  inline  ::capnp::List<float>::Reader getFloat32List() const;

  // float64List@28: List(Float64) = [7777.75, Infinity, -Infinity, NaN];  # ptr[14]
  inline bool hasFloat64List() const;
  inline  ::capnp::List<double>::Reader getFloat64List() const;

  // textList@29: List(Text) = ["plugh", "xyzzy", "thud"];  # ptr[15]
  inline bool hasTextList() const;
  inline  ::capnp::List< ::capnp::Text>::Reader getTextList() const;

  // dataList@30: List(Data) = ["oops", "exhausted", "rfc3092"];  # ptr[16]
  inline bool hasDataList() const;
  inline  ::capnp::List< ::capnp::Data>::Reader getDataList() const;

  // structList@31: List(.TestAllTypes) = [(textField = "structlist 1"), (textField = "structlist 2"), (textField = "structlist 3")];  # ptr[17]
  inline bool hasStructList() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader getStructList() const;

  // enumList@32: List(.TestEnum) = [foo, garply];  # ptr[18]
  inline bool hasEnumList() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Reader getEnumList() const;

  // interfaceList@33: List(Void);  # ptr[19]
  inline bool hasInterfaceList() const;
  inline  ::capnp::List< ::capnp::Void>::Reader getInterfaceList() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestDefaults::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestDefaults::Reader reader) {
  return ::capnp::_::structString<TestDefaults>(reader._reader);
}



class TestDefaults::Builder {
public:
  typedef TestDefaults Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // voidField@0: Void = void;  # (none)
  inline  ::capnp::Void getVoidField();
  inline void setVoidField( ::capnp::Void value);

  // boolField@1: Bool = true;  # bits[0, 1)
  inline bool getBoolField();
  inline void setBoolField(bool value);

  // int8Field@2: Int8 = -123;  # bits[8, 16)
  inline  ::int8_t getInt8Field();
  inline void setInt8Field( ::int8_t value);

  // int16Field@3: Int16 = -12345;  # bits[16, 32)
  inline  ::int16_t getInt16Field();
  inline void setInt16Field( ::int16_t value);

  // int32Field@4: Int32 = -12345678;  # bits[32, 64)
  inline  ::int32_t getInt32Field();
  inline void setInt32Field( ::int32_t value);

  // int64Field@5: Int64 = -123456789012345;  # bits[64, 128)
  inline  ::int64_t getInt64Field();
  inline void setInt64Field( ::int64_t value);

  // uInt8Field@6: UInt8 = 234;  # bits[128, 136)
  inline  ::uint8_t getUInt8Field();
  inline void setUInt8Field( ::uint8_t value);

  // uInt16Field@7: UInt16 = 45678;  # bits[144, 160)
  inline  ::uint16_t getUInt16Field();
  inline void setUInt16Field( ::uint16_t value);

  // uInt32Field@8: UInt32 = 3456789012;  # bits[160, 192)
  inline  ::uint32_t getUInt32Field();
  inline void setUInt32Field( ::uint32_t value);

  // uInt64Field@9: UInt64 = 12345678901234567890;  # bits[192, 256)
  inline  ::uint64_t getUInt64Field();
  inline void setUInt64Field( ::uint64_t value);

  // float32Field@10: Float32 = 1234.5;  # bits[256, 288)
  inline float getFloat32Field();
  inline void setFloat32Field(float value);

  // float64Field@11: Float64 = -1.23e47;  # bits[320, 384)
  inline double getFloat64Field();
  inline void setFloat64Field(double value);

  // textField@12: Text = "foo";  # ptr[0]
  inline bool hasTextField();
  inline  ::capnp::Text::Builder getTextField();
  inline void setTextField( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initTextField(unsigned int size);

  // dataField@13: Data = "bar";  # ptr[1]
  inline bool hasDataField();
  inline  ::capnp::Data::Builder getDataField();
  inline void setDataField( ::capnp::Data::Reader other);
  inline  ::capnp::Data::Builder initDataField(unsigned int size);

  // structField@14: .TestAllTypes = (voidField = void, boolField = true, int8Field = -12, int16Field = 3456, int32Field = -78901234, int64Field = 56789012345678, uInt8Field = 90, uInt16Field = 1234, uInt32Field = 56789012, uInt64Field = 345678901234567890, float32Field = -1.25e-10, float64Field = 345.0, textField = "baz", dataField = "qux", structField = (textField = "nested", structField = (textField = "really nested")), enumField = baz, voidList = [void, void, void], boolList = [false, true, false, true, true], int8List = [12, -34, -128, 127], int16List = [1234, -5678, -32768, 32767], int32List = [12345678, -90123456, -2147483648, 2147483647], int64List = [123456789012345, -678901234567890, -9223372036854775808, 9223372036854775807], uInt8List = [12, 34, 0, 255], uInt16List = [1234, 5678, 0, 65535], uInt32List = [12345678, 90123456, 0, 4294967295], uInt64List = [123456789012345, 678901234567890, 0, 18446744073709551615], float32List = [0.0, 1234567.0, 1.0e37, -1.0e37, 1.0e-37, -1.0e-37], float64List = [0.0, 1.23456789012345e14, 1.0e306, -1.0e306, 1.0e-306, -1.0e-306], textList = ["quux", "corge", "grault"], dataList = ["garply", "waldo", "fred"], structList = [(textField = "x structlist 1"), (textField = "x structlist 2"), (textField = "x structlist 3")], enumList = [qux, bar, grault]);  # ptr[2]
  inline bool hasStructField();
  inline  ::capnproto_test::capnp::test::TestAllTypes::Builder getStructField();
  inline void setStructField( ::capnproto_test::capnp::test::TestAllTypes::Reader other);
  inline  ::capnproto_test::capnp::test::TestAllTypes::Builder initStructField();

  // enumField@15: .TestEnum = corge;  # bits[288, 304)
  inline  ::capnproto_test::capnp::test::TestEnum getEnumField();
  inline void setEnumField( ::capnproto_test::capnp::test::TestEnum value);

  // interfaceField@16: Void;  # (none)
  inline  ::capnp::Void getInterfaceField();
  inline void setInterfaceField( ::capnp::Void value);

  // voidList@17: List(Void) = [void, void, void, void, void, void];  # ptr[3]
  inline bool hasVoidList();
  inline  ::capnp::List< ::capnp::Void>::Builder getVoidList();
  inline void setVoidList( ::capnp::List< ::capnp::Void>::Reader other);
  inline void setVoidList(
      std::initializer_list< ::capnp::Void> other);
  inline  ::capnp::List< ::capnp::Void>::Builder initVoidList(unsigned int size);

  // boolList@18: List(Bool) = [true, false, false, true];  # ptr[4]
  inline bool hasBoolList();
  inline  ::capnp::List<bool>::Builder getBoolList();
  inline void setBoolList( ::capnp::List<bool>::Reader other);
  inline void setBoolList(
      std::initializer_list<bool> other);
  inline  ::capnp::List<bool>::Builder initBoolList(unsigned int size);

  // int8List@19: List(Int8) = [111, -111];  # ptr[5]
  inline bool hasInt8List();
  inline  ::capnp::List< ::int8_t>::Builder getInt8List();
  inline void setInt8List( ::capnp::List< ::int8_t>::Reader other);
  inline void setInt8List(
      std::initializer_list< ::int8_t> other);
  inline  ::capnp::List< ::int8_t>::Builder initInt8List(unsigned int size);

  // int16List@20: List(Int16) = [11111, -11111];  # ptr[6]
  inline bool hasInt16List();
  inline  ::capnp::List< ::int16_t>::Builder getInt16List();
  inline void setInt16List( ::capnp::List< ::int16_t>::Reader other);
  inline void setInt16List(
      std::initializer_list< ::int16_t> other);
  inline  ::capnp::List< ::int16_t>::Builder initInt16List(unsigned int size);

  // int32List@21: List(Int32) = [111111111, -111111111];  # ptr[7]
  inline bool hasInt32List();
  inline  ::capnp::List< ::int32_t>::Builder getInt32List();
  inline void setInt32List( ::capnp::List< ::int32_t>::Reader other);
  inline void setInt32List(
      std::initializer_list< ::int32_t> other);
  inline  ::capnp::List< ::int32_t>::Builder initInt32List(unsigned int size);

  // int64List@22: List(Int64) = [1111111111111111111, -1111111111111111111];  # ptr[8]
  inline bool hasInt64List();
  inline  ::capnp::List< ::int64_t>::Builder getInt64List();
  inline void setInt64List( ::capnp::List< ::int64_t>::Reader other);
  inline void setInt64List(
      std::initializer_list< ::int64_t> other);
  inline  ::capnp::List< ::int64_t>::Builder initInt64List(unsigned int size);

  // uInt8List@23: List(UInt8) = [111, 222];  # ptr[9]
  inline bool hasUInt8List();
  inline  ::capnp::List< ::uint8_t>::Builder getUInt8List();
  inline void setUInt8List( ::capnp::List< ::uint8_t>::Reader other);
  inline void setUInt8List(
      std::initializer_list< ::uint8_t> other);
  inline  ::capnp::List< ::uint8_t>::Builder initUInt8List(unsigned int size);

  // uInt16List@24: List(UInt16) = [33333, 44444];  # ptr[10]
  inline bool hasUInt16List();
  inline  ::capnp::List< ::uint16_t>::Builder getUInt16List();
  inline void setUInt16List( ::capnp::List< ::uint16_t>::Reader other);
  inline void setUInt16List(
      std::initializer_list< ::uint16_t> other);
  inline  ::capnp::List< ::uint16_t>::Builder initUInt16List(unsigned int size);

  // uInt32List@25: List(UInt32) = [3333333333];  # ptr[11]
  inline bool hasUInt32List();
  inline  ::capnp::List< ::uint32_t>::Builder getUInt32List();
  inline void setUInt32List( ::capnp::List< ::uint32_t>::Reader other);
  inline void setUInt32List(
      std::initializer_list< ::uint32_t> other);
  inline  ::capnp::List< ::uint32_t>::Builder initUInt32List(unsigned int size);

  // uInt64List@26: List(UInt64) = [11111111111111111111];  # ptr[12]
  inline bool hasUInt64List();
  inline  ::capnp::List< ::uint64_t>::Builder getUInt64List();
  inline void setUInt64List( ::capnp::List< ::uint64_t>::Reader other);
  inline void setUInt64List(
      std::initializer_list< ::uint64_t> other);
  inline  ::capnp::List< ::uint64_t>::Builder initUInt64List(unsigned int size);

  // float32List@27: List(Float32) = [5555.5, Infinity, -Infinity, NaN];  # ptr[13]
  inline bool hasFloat32List();
  inline  ::capnp::List<float>::Builder getFloat32List();
  inline void setFloat32List( ::capnp::List<float>::Reader other);
  inline void setFloat32List(
      std::initializer_list<float> other);
  inline  ::capnp::List<float>::Builder initFloat32List(unsigned int size);

  // float64List@28: List(Float64) = [7777.75, Infinity, -Infinity, NaN];  # ptr[14]
  inline bool hasFloat64List();
  inline  ::capnp::List<double>::Builder getFloat64List();
  inline void setFloat64List( ::capnp::List<double>::Reader other);
  inline void setFloat64List(
      std::initializer_list<double> other);
  inline  ::capnp::List<double>::Builder initFloat64List(unsigned int size);

  // textList@29: List(Text) = ["plugh", "xyzzy", "thud"];  # ptr[15]
  inline bool hasTextList();
  inline  ::capnp::List< ::capnp::Text>::Builder getTextList();
  inline void setTextList( ::capnp::List< ::capnp::Text>::Reader other);
  inline void setTextList(
      std::initializer_list< ::capnp::Text::Reader> other);
  inline  ::capnp::List< ::capnp::Text>::Builder initTextList(unsigned int size);

  // dataList@30: List(Data) = ["oops", "exhausted", "rfc3092"];  # ptr[16]
  inline bool hasDataList();
  inline  ::capnp::List< ::capnp::Data>::Builder getDataList();
  inline void setDataList( ::capnp::List< ::capnp::Data>::Reader other);
  inline void setDataList(
      std::initializer_list< ::capnp::Data::Reader> other);
  inline  ::capnp::List< ::capnp::Data>::Builder initDataList(unsigned int size);

  // structList@31: List(.TestAllTypes) = [(textField = "structlist 1"), (textField = "structlist 2"), (textField = "structlist 3")];  # ptr[17]
  inline bool hasStructList();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Builder getStructList();
  inline void setStructList( ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Builder initStructList(unsigned int size);

  // enumList@32: List(.TestEnum) = [foo, garply];  # ptr[18]
  inline bool hasEnumList();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Builder getEnumList();
  inline void setEnumList( ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Reader other);
  inline void setEnumList(
      std::initializer_list< ::capnproto_test::capnp::test::TestEnum> other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Builder initEnumList(unsigned int size);

  // interfaceList@33: List(Void);  # ptr[19]
  inline bool hasInterfaceList();
  inline  ::capnp::List< ::capnp::Void>::Builder getInterfaceList();
  inline void setInterfaceList( ::capnp::List< ::capnp::Void>::Reader other);
  inline void setInterfaceList(
      std::initializer_list< ::capnp::Void> other);
  inline  ::capnp::List< ::capnp::Void>::Builder initInterfaceList(unsigned int size);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestDefaults::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestDefaults::Builder builder) {
  return ::capnp::_::structString<TestDefaults>(builder._builder.asReader());
}

class TestFieldZeroIsBit::Reader {
public:
  typedef TestFieldZeroIsBit Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // bit@0: Bool;  # bits[0, 1)
  inline bool getBit() const;

  // secondBit@1: Bool = true;  # bits[1, 2)
  inline bool getSecondBit() const;

  // thirdField@2: UInt8 = 123;  # bits[8, 16)
  inline  ::uint8_t getThirdField() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestFieldZeroIsBit::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestFieldZeroIsBit::Reader reader) {
  return ::capnp::_::structString<TestFieldZeroIsBit>(reader._reader);
}



class TestFieldZeroIsBit::Builder {
public:
  typedef TestFieldZeroIsBit Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // bit@0: Bool;  # bits[0, 1)
  inline bool getBit();
  inline void setBit(bool value);

  // secondBit@1: Bool = true;  # bits[1, 2)
  inline bool getSecondBit();
  inline void setSecondBit(bool value);

  // thirdField@2: UInt8 = 123;  # bits[8, 16)
  inline  ::uint8_t getThirdField();
  inline void setThirdField( ::uint8_t value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestFieldZeroIsBit::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestFieldZeroIsBit::Builder builder) {
  return ::capnp::_::structString<TestFieldZeroIsBit>(builder._builder.asReader());
}

class TestLateUnion::Reader {
public:
  typedef TestLateUnion Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // union theUnion@3 {  # [48, 64)
  inline TheUnion::Reader getTheUnion() const;

  // union anotherUnion@7 {  # [96, 112)
  inline AnotherUnion::Reader getAnotherUnion() const;

  // foo@0: Int32;  # bits[0, 32)
  inline  ::int32_t getFoo() const;

  // bar@1: Text;  # ptr[0]
  inline bool hasBar() const;
  inline  ::capnp::Text::Reader getBar() const;

  // baz@2: Int16;  # bits[32, 48)
  inline  ::int16_t getBaz() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLateUnion::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLateUnion::Reader reader) {
  return ::capnp::_::structString<TestLateUnion>(reader._reader);
}



class TestLateUnion::Builder {
public:
  typedef TestLateUnion Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // union theUnion@3 {  # [48, 64)
  inline TheUnion::Builder getTheUnion();

  // union anotherUnion@7 {  # [96, 112)
  inline AnotherUnion::Builder getAnotherUnion();

  // foo@0: Int32;  # bits[0, 32)
  inline  ::int32_t getFoo();
  inline void setFoo( ::int32_t value);

  // bar@1: Text;  # ptr[0]
  inline bool hasBar();
  inline  ::capnp::Text::Builder getBar();
  inline void setBar( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initBar(unsigned int size);

  // baz@2: Int16;  # bits[32, 48)
  inline  ::int16_t getBaz();
  inline void setBaz( ::int16_t value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLateUnion::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLateUnion::Builder builder) {
  return ::capnp::_::structString<TestLateUnion>(builder._builder.asReader());
}

class TestLateUnion::AnotherUnion::Reader {
public:
  typedef AnotherUnion Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline Which which() const;

  // qux@8: Text;  # ptr[2], union tag = 0
  inline bool hasQux() const;
  inline  ::capnp::Text::Reader getQux() const;

  // corge@9: List(Int32);  # ptr[2], union tag = 1
  inline bool hasCorge() const;
  inline  ::capnp::List< ::int32_t>::Reader getCorge() const;

  // grault@10: Float32;  # bits[128, 160), union tag = 2
  inline float getGrault() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLateUnion::AnotherUnion::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLateUnion::AnotherUnion::Reader reader) {
  return ::capnp::_::unionString<TestLateUnion::AnotherUnion>(reader._reader);
}



class TestLateUnion::AnotherUnion::Builder {
public:
  typedef AnotherUnion Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline Which which();

  // qux@8: Text;  # ptr[2], union tag = 0
  inline bool hasQux();
  inline  ::capnp::Text::Builder getQux();
  inline void setQux( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initQux(unsigned int size);

  // corge@9: List(Int32);  # ptr[2], union tag = 1
  inline bool hasCorge();
  inline  ::capnp::List< ::int32_t>::Builder getCorge();
  inline void setCorge( ::capnp::List< ::int32_t>::Reader other);
  inline void setCorge(
      std::initializer_list< ::int32_t> other);
  inline  ::capnp::List< ::int32_t>::Builder initCorge(unsigned int size);

  // grault@10: Float32;  # bits[128, 160), union tag = 2
  inline float getGrault();
  inline void setGrault(float value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLateUnion::AnotherUnion::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLateUnion::AnotherUnion::Builder builder) {
  return ::capnp::_::unionString<TestLateUnion::AnotherUnion>(builder._builder.asReader());
}

class TestLateUnion::TheUnion::Reader {
public:
  typedef TheUnion Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline Which which() const;

  // qux@4: Text;  # ptr[1], union tag = 0
  inline bool hasQux() const;
  inline  ::capnp::Text::Reader getQux() const;

  // corge@5: List(Int32);  # ptr[1], union tag = 1
  inline bool hasCorge() const;
  inline  ::capnp::List< ::int32_t>::Reader getCorge() const;

  // grault@6: Float32;  # bits[64, 96), union tag = 2
  inline float getGrault() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLateUnion::TheUnion::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLateUnion::TheUnion::Reader reader) {
  return ::capnp::_::unionString<TestLateUnion::TheUnion>(reader._reader);
}



class TestLateUnion::TheUnion::Builder {
public:
  typedef TheUnion Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline Which which();

  // qux@4: Text;  # ptr[1], union tag = 0
  inline bool hasQux();
  inline  ::capnp::Text::Builder getQux();
  inline void setQux( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initQux(unsigned int size);

  // corge@5: List(Int32);  # ptr[1], union tag = 1
  inline bool hasCorge();
  inline  ::capnp::List< ::int32_t>::Builder getCorge();
  inline void setCorge( ::capnp::List< ::int32_t>::Reader other);
  inline void setCorge(
      std::initializer_list< ::int32_t> other);
  inline  ::capnp::List< ::int32_t>::Builder initCorge(unsigned int size);

  // grault@6: Float32;  # bits[64, 96), union tag = 2
  inline float getGrault();
  inline void setGrault(float value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLateUnion::TheUnion::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLateUnion::TheUnion::Builder builder) {
  return ::capnp::_::unionString<TestLateUnion::TheUnion>(builder._builder.asReader());
}

class TestListDefaults::Reader {
public:
  typedef TestListDefaults Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // lists@0: .TestLists = (list0 = [(f = void), (f = void)], list1 = [(f = true), (f = false), (f = true), (f = true)], list8 = [(f = 123), (f = 45)], list16 = [(f = 12345), (f = 6789)], list32 = [(f = 123456789), (f = 234567890)], list64 = [(f = 1234567890123456), (f = 2345678901234567)], listP = [(f = "foo"), (f = "bar")], int32ListList = [[1, 2, 3], [4, 5], [12341234]], textListList = [["foo", "bar"], ["baz"], ["qux", "corge"]], structListList = [[(int32Field = 123), (int32Field = 456)], [(int32Field = 789)]]);  # ptr[0]
  inline bool hasLists() const;
  inline  ::capnproto_test::capnp::test::TestLists::Reader getLists() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestListDefaults::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestListDefaults::Reader reader) {
  return ::capnp::_::structString<TestListDefaults>(reader._reader);
}



class TestListDefaults::Builder {
public:
  typedef TestListDefaults Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // lists@0: .TestLists = (list0 = [(f = void), (f = void)], list1 = [(f = true), (f = false), (f = true), (f = true)], list8 = [(f = 123), (f = 45)], list16 = [(f = 12345), (f = 6789)], list32 = [(f = 123456789), (f = 234567890)], list64 = [(f = 1234567890123456), (f = 2345678901234567)], listP = [(f = "foo"), (f = "bar")], int32ListList = [[1, 2, 3], [4, 5], [12341234]], textListList = [["foo", "bar"], ["baz"], ["qux", "corge"]], structListList = [[(int32Field = 123), (int32Field = 456)], [(int32Field = 789)]]);  # ptr[0]
  inline bool hasLists();
  inline  ::capnproto_test::capnp::test::TestLists::Builder getLists();
  inline void setLists( ::capnproto_test::capnp::test::TestLists::Reader other);
  inline  ::capnproto_test::capnp::test::TestLists::Builder initLists();
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestListDefaults::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestListDefaults::Builder builder) {
  return ::capnp::_::structString<TestListDefaults>(builder._builder.asReader());
}

class TestLists::Reader {
public:
  typedef TestLists Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // list0@0: List(.TestLists.Struct0);  # ptr[0]
  inline bool hasList0() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>::Reader getList0() const;

  // list1@1: List(.TestLists.Struct1);  # ptr[1]
  inline bool hasList1() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>::Reader getList1() const;

  // list8@2: List(.TestLists.Struct8);  # ptr[2]
  inline bool hasList8() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>::Reader getList8() const;

  // list16@3: List(.TestLists.Struct16);  # ptr[3]
  inline bool hasList16() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>::Reader getList16() const;

  // list32@4: List(.TestLists.Struct32);  # ptr[4]
  inline bool hasList32() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>::Reader getList32() const;

  // list64@5: List(.TestLists.Struct64);  # ptr[5]
  inline bool hasList64() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>::Reader getList64() const;

  // listP@6: List(.TestLists.StructP);  # ptr[6]
  inline bool hasListP() const;
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>::Reader getListP() const;

  // int32ListList@7: List(List(Int32));  # ptr[7]
  inline bool hasInt32ListList() const;
  inline  ::capnp::List< ::capnp::List< ::int32_t>>::Reader getInt32ListList() const;

  // textListList@8: List(List(Text));  # ptr[8]
  inline bool hasTextListList() const;
  inline  ::capnp::List< ::capnp::List< ::capnp::Text>>::Reader getTextListList() const;

  // structListList@9: List(List(.TestAllTypes));  # ptr[9]
  inline bool hasStructListList() const;
  inline  ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::Reader getStructListList() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLists::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Reader reader) {
  return ::capnp::_::structString<TestLists>(reader._reader);
}



class TestLists::Builder {
public:
  typedef TestLists Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // list0@0: List(.TestLists.Struct0);  # ptr[0]
  inline bool hasList0();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>::Builder getList0();
  inline void setList0( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>::Builder initList0(unsigned int size);

  // list1@1: List(.TestLists.Struct1);  # ptr[1]
  inline bool hasList1();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>::Builder getList1();
  inline void setList1( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>::Builder initList1(unsigned int size);

  // list8@2: List(.TestLists.Struct8);  # ptr[2]
  inline bool hasList8();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>::Builder getList8();
  inline void setList8( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>::Builder initList8(unsigned int size);

  // list16@3: List(.TestLists.Struct16);  # ptr[3]
  inline bool hasList16();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>::Builder getList16();
  inline void setList16( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>::Builder initList16(unsigned int size);

  // list32@4: List(.TestLists.Struct32);  # ptr[4]
  inline bool hasList32();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>::Builder getList32();
  inline void setList32( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>::Builder initList32(unsigned int size);

  // list64@5: List(.TestLists.Struct64);  # ptr[5]
  inline bool hasList64();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>::Builder getList64();
  inline void setList64( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>::Builder initList64(unsigned int size);

  // listP@6: List(.TestLists.StructP);  # ptr[6]
  inline bool hasListP();
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>::Builder getListP();
  inline void setListP( ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>::Reader other);
  inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>::Builder initListP(unsigned int size);

  // int32ListList@7: List(List(Int32));  # ptr[7]
  inline bool hasInt32ListList();
  inline  ::capnp::List< ::capnp::List< ::int32_t>>::Builder getInt32ListList();
  inline void setInt32ListList( ::capnp::List< ::capnp::List< ::int32_t>>::Reader other);
  inline void setInt32ListList(
      std::initializer_list< ::capnp::List< ::int32_t>::Reader> other);
  inline  ::capnp::List< ::capnp::List< ::int32_t>>::Builder initInt32ListList(unsigned int size);

  // textListList@8: List(List(Text));  # ptr[8]
  inline bool hasTextListList();
  inline  ::capnp::List< ::capnp::List< ::capnp::Text>>::Builder getTextListList();
  inline void setTextListList( ::capnp::List< ::capnp::List< ::capnp::Text>>::Reader other);
  inline void setTextListList(
      std::initializer_list< ::capnp::List< ::capnp::Text>::Reader> other);
  inline  ::capnp::List< ::capnp::List< ::capnp::Text>>::Builder initTextListList(unsigned int size);

  // structListList@9: List(List(.TestAllTypes));  # ptr[9]
  inline bool hasStructListList();
  inline  ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::Builder getStructListList();
  inline void setStructListList( ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::Reader other);
  inline void setStructListList(
      std::initializer_list< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader> other);
  inline  ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::Builder initStructListList(unsigned int size);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLists::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Builder builder) {
  return ::capnp::_::structString<TestLists>(builder._builder.asReader());
}

class TestLists::Struct0::Reader {
public:
  typedef Struct0 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // f@0: Void;  # (none)
  inline  ::capnp::Void getF() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct0::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct0::Reader reader) {
  return ::capnp::_::structString<TestLists::Struct0>(reader._reader);
}



class TestLists::Struct0::Builder {
public:
  typedef Struct0 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // f@0: Void;  # (none)
  inline  ::capnp::Void getF();
  inline void setF( ::capnp::Void value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct0::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct0::Builder builder) {
  return ::capnp::_::structString<TestLists::Struct0>(builder._builder.asReader());
}

class TestLists::Struct1::Reader {
public:
  typedef Struct1 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // f@0: Bool;  # bits[0, 1)
  inline bool getF() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct1::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct1::Reader reader) {
  return ::capnp::_::structString<TestLists::Struct1>(reader._reader);
}



class TestLists::Struct1::Builder {
public:
  typedef Struct1 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // f@0: Bool;  # bits[0, 1)
  inline bool getF();
  inline void setF(bool value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct1::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct1::Builder builder) {
  return ::capnp::_::structString<TestLists::Struct1>(builder._builder.asReader());
}

class TestLists::Struct16::Reader {
public:
  typedef Struct16 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // f@0: UInt16;  # bits[0, 16)
  inline  ::uint16_t getF() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct16::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct16::Reader reader) {
  return ::capnp::_::structString<TestLists::Struct16>(reader._reader);
}



class TestLists::Struct16::Builder {
public:
  typedef Struct16 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // f@0: UInt16;  # bits[0, 16)
  inline  ::uint16_t getF();
  inline void setF( ::uint16_t value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct16::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct16::Builder builder) {
  return ::capnp::_::structString<TestLists::Struct16>(builder._builder.asReader());
}

class TestLists::Struct32::Reader {
public:
  typedef Struct32 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // f@0: UInt32;  # bits[0, 32)
  inline  ::uint32_t getF() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct32::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct32::Reader reader) {
  return ::capnp::_::structString<TestLists::Struct32>(reader._reader);
}



class TestLists::Struct32::Builder {
public:
  typedef Struct32 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // f@0: UInt32;  # bits[0, 32)
  inline  ::uint32_t getF();
  inline void setF( ::uint32_t value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct32::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct32::Builder builder) {
  return ::capnp::_::structString<TestLists::Struct32>(builder._builder.asReader());
}

class TestLists::Struct64::Reader {
public:
  typedef Struct64 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // f@0: UInt64;  # bits[0, 64)
  inline  ::uint64_t getF() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct64::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct64::Reader reader) {
  return ::capnp::_::structString<TestLists::Struct64>(reader._reader);
}



class TestLists::Struct64::Builder {
public:
  typedef Struct64 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // f@0: UInt64;  # bits[0, 64)
  inline  ::uint64_t getF();
  inline void setF( ::uint64_t value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct64::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct64::Builder builder) {
  return ::capnp::_::structString<TestLists::Struct64>(builder._builder.asReader());
}

class TestLists::Struct8::Reader {
public:
  typedef Struct8 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // f@0: UInt8;  # bits[0, 8)
  inline  ::uint8_t getF() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct8::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct8::Reader reader) {
  return ::capnp::_::structString<TestLists::Struct8>(reader._reader);
}



class TestLists::Struct8::Builder {
public:
  typedef Struct8 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // f@0: UInt8;  # bits[0, 8)
  inline  ::uint8_t getF();
  inline void setF( ::uint8_t value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLists::Struct8::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLists::Struct8::Builder builder) {
  return ::capnp::_::structString<TestLists::Struct8>(builder._builder.asReader());
}

class TestLists::StructP::Reader {
public:
  typedef StructP Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // f@0: Text;  # ptr[0]
  inline bool hasF() const;
  inline  ::capnp::Text::Reader getF() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestLists::StructP::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestLists::StructP::Reader reader) {
  return ::capnp::_::structString<TestLists::StructP>(reader._reader);
}



class TestLists::StructP::Builder {
public:
  typedef StructP Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // f@0: Text;  # ptr[0]
  inline bool hasF();
  inline  ::capnp::Text::Builder getF();
  inline void setF( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initF(unsigned int size);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestLists::StructP::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestLists::StructP::Builder builder) {
  return ::capnp::_::structString<TestLists::StructP>(builder._builder.asReader());
}

class TestNestedTypes::Reader {
public:
  typedef TestNestedTypes Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // nestedStruct@0: .TestNestedTypes.NestedStruct;  # ptr[0]
  inline bool hasNestedStruct() const;
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::Reader getNestedStruct() const;

  // outerNestedEnum@1: .TestNestedTypes.NestedEnum = bar;  # bits[0, 16)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum getOuterNestedEnum() const;

  // innerNestedEnum@2: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[16, 32)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum getInnerNestedEnum() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestNestedTypes::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestNestedTypes::Reader reader) {
  return ::capnp::_::structString<TestNestedTypes>(reader._reader);
}



class TestNestedTypes::Builder {
public:
  typedef TestNestedTypes Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // nestedStruct@0: .TestNestedTypes.NestedStruct;  # ptr[0]
  inline bool hasNestedStruct();
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::Builder getNestedStruct();
  inline void setNestedStruct( ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::Reader other);
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::Builder initNestedStruct();

  // outerNestedEnum@1: .TestNestedTypes.NestedEnum = bar;  # bits[0, 16)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum getOuterNestedEnum();
  inline void setOuterNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum value);

  // innerNestedEnum@2: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[16, 32)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum getInnerNestedEnum();
  inline void setInnerNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestNestedTypes::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestNestedTypes::Builder builder) {
  return ::capnp::_::structString<TestNestedTypes>(builder._builder.asReader());
}

class TestNestedTypes::NestedStruct::Reader {
public:
  typedef NestedStruct Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // outerNestedEnum@0: .TestNestedTypes.NestedEnum = bar;  # bits[0, 16)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum getOuterNestedEnum() const;

  // innerNestedEnum@1: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[16, 32)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum getInnerNestedEnum() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestNestedTypes::NestedStruct::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestNestedTypes::NestedStruct::Reader reader) {
  return ::capnp::_::structString<TestNestedTypes::NestedStruct>(reader._reader);
}



class TestNestedTypes::NestedStruct::Builder {
public:
  typedef NestedStruct Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // outerNestedEnum@0: .TestNestedTypes.NestedEnum = bar;  # bits[0, 16)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum getOuterNestedEnum();
  inline void setOuterNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum value);

  // innerNestedEnum@1: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[16, 32)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum getInnerNestedEnum();
  inline void setInnerNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestNestedTypes::NestedStruct::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestNestedTypes::NestedStruct::Builder builder) {
  return ::capnp::_::structString<TestNestedTypes::NestedStruct>(builder._builder.asReader());
}

class TestNewVersion::Reader {
public:
  typedef TestNewVersion Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // old1@0: Int64;  # bits[0, 64)
  inline  ::int64_t getOld1() const;

  // old2@1: Text;  # ptr[0]
  inline bool hasOld2() const;
  inline  ::capnp::Text::Reader getOld2() const;

  // old3@2: .TestNewVersion;  # ptr[1]
  inline bool hasOld3() const;
  inline  ::capnproto_test::capnp::test::TestNewVersion::Reader getOld3() const;

  // new1@3: Int64 = 987;  # bits[64, 128)
  inline  ::int64_t getNew1() const;

  // new2@4: Text = "baz";  # ptr[2]
  inline bool hasNew2() const;
  inline  ::capnp::Text::Reader getNew2() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestNewVersion::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestNewVersion::Reader reader) {
  return ::capnp::_::structString<TestNewVersion>(reader._reader);
}



class TestNewVersion::Builder {
public:
  typedef TestNewVersion Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // old1@0: Int64;  # bits[0, 64)
  inline  ::int64_t getOld1();
  inline void setOld1( ::int64_t value);

  // old2@1: Text;  # ptr[0]
  inline bool hasOld2();
  inline  ::capnp::Text::Builder getOld2();
  inline void setOld2( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initOld2(unsigned int size);

  // old3@2: .TestNewVersion;  # ptr[1]
  inline bool hasOld3();
  inline  ::capnproto_test::capnp::test::TestNewVersion::Builder getOld3();
  inline void setOld3( ::capnproto_test::capnp::test::TestNewVersion::Reader other);
  inline  ::capnproto_test::capnp::test::TestNewVersion::Builder initOld3();

  // new1@3: Int64 = 987;  # bits[64, 128)
  inline  ::int64_t getNew1();
  inline void setNew1( ::int64_t value);

  // new2@4: Text = "baz";  # ptr[2]
  inline bool hasNew2();
  inline  ::capnp::Text::Builder getNew2();
  inline void setNew2( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initNew2(unsigned int size);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestNewVersion::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestNewVersion::Builder builder) {
  return ::capnp::_::structString<TestNewVersion>(builder._builder.asReader());
}

class TestObject::Reader {
public:
  typedef TestObject Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // objectField@0: Object;  # ptr[0]
  inline bool hasObjectField() const;
  template <typename T> inline typename T::Reader getObjectField() const;
  template <typename T, typename Param> inline typename T::Reader
      getObjectField(Param&& param) const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestObject::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestObject::Reader reader) {
  return ::capnp::_::structString<TestObject>(reader._reader);
}



class TestObject::Builder {
public:
  typedef TestObject Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // objectField@0: Object;  # ptr[0]
  inline bool hasObjectField();
  template <typename T> inline typename T::Builder getObjectField();
  template <typename T, typename Param> inline typename T::Builder
      getObjectField(Param&& param);
  template <typename T> inline void setObjectField(typename T::Reader value);
  template <typename T, typename U> inline void
      setObjectField(std::initializer_list<U> value);
  template <typename T, typename... Params> inline typename T::Builder
      initObjectField(Params&&... params);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestObject::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestObject::Builder builder) {
  return ::capnp::_::structString<TestObject>(builder._builder.asReader());
}

class TestOldVersion::Reader {
public:
  typedef TestOldVersion Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // old1@0: Int64;  # bits[0, 64)
  inline  ::int64_t getOld1() const;

  // old2@1: Text;  # ptr[0]
  inline bool hasOld2() const;
  inline  ::capnp::Text::Reader getOld2() const;

  // old3@2: .TestOldVersion;  # ptr[1]
  inline bool hasOld3() const;
  inline  ::capnproto_test::capnp::test::TestOldVersion::Reader getOld3() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestOldVersion::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestOldVersion::Reader reader) {
  return ::capnp::_::structString<TestOldVersion>(reader._reader);
}



class TestOldVersion::Builder {
public:
  typedef TestOldVersion Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // old1@0: Int64;  # bits[0, 64)
  inline  ::int64_t getOld1();
  inline void setOld1( ::int64_t value);

  // old2@1: Text;  # ptr[0]
  inline bool hasOld2();
  inline  ::capnp::Text::Builder getOld2();
  inline void setOld2( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initOld2(unsigned int size);

  // old3@2: .TestOldVersion;  # ptr[1]
  inline bool hasOld3();
  inline  ::capnproto_test::capnp::test::TestOldVersion::Builder getOld3();
  inline void setOld3( ::capnproto_test::capnp::test::TestOldVersion::Reader other);
  inline  ::capnproto_test::capnp::test::TestOldVersion::Builder initOld3();
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestOldVersion::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestOldVersion::Builder builder) {
  return ::capnp::_::structString<TestOldVersion>(builder._builder.asReader());
}

class TestOutOfOrder::Reader {
public:
  typedef TestOutOfOrder Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // foo@3: Text;  # ptr[3]
  inline bool hasFoo() const;
  inline  ::capnp::Text::Reader getFoo() const;

  // bar@2: Text;  # ptr[2]
  inline bool hasBar() const;
  inline  ::capnp::Text::Reader getBar() const;

  // baz@8: Text;  # ptr[8]
  inline bool hasBaz() const;
  inline  ::capnp::Text::Reader getBaz() const;

  // qux@0: Text;  # ptr[0]
  inline bool hasQux() const;
  inline  ::capnp::Text::Reader getQux() const;

  // quux@6: Text;  # ptr[6]
  inline bool hasQuux() const;
  inline  ::capnp::Text::Reader getQuux() const;

  // corge@4: Text;  # ptr[4]
  inline bool hasCorge() const;
  inline  ::capnp::Text::Reader getCorge() const;

  // grault@1: Text;  # ptr[1]
  inline bool hasGrault() const;
  inline  ::capnp::Text::Reader getGrault() const;

  // garply@7: Text;  # ptr[7]
  inline bool hasGarply() const;
  inline  ::capnp::Text::Reader getGarply() const;

  // waldo@5: Text;  # ptr[5]
  inline bool hasWaldo() const;
  inline  ::capnp::Text::Reader getWaldo() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestOutOfOrder::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestOutOfOrder::Reader reader) {
  return ::capnp::_::structString<TestOutOfOrder>(reader._reader);
}



class TestOutOfOrder::Builder {
public:
  typedef TestOutOfOrder Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // foo@3: Text;  # ptr[3]
  inline bool hasFoo();
  inline  ::capnp::Text::Builder getFoo();
  inline void setFoo( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initFoo(unsigned int size);

  // bar@2: Text;  # ptr[2]
  inline bool hasBar();
  inline  ::capnp::Text::Builder getBar();
  inline void setBar( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initBar(unsigned int size);

  // baz@8: Text;  # ptr[8]
  inline bool hasBaz();
  inline  ::capnp::Text::Builder getBaz();
  inline void setBaz( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initBaz(unsigned int size);

  // qux@0: Text;  # ptr[0]
  inline bool hasQux();
  inline  ::capnp::Text::Builder getQux();
  inline void setQux( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initQux(unsigned int size);

  // quux@6: Text;  # ptr[6]
  inline bool hasQuux();
  inline  ::capnp::Text::Builder getQuux();
  inline void setQuux( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initQuux(unsigned int size);

  // corge@4: Text;  # ptr[4]
  inline bool hasCorge();
  inline  ::capnp::Text::Builder getCorge();
  inline void setCorge( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initCorge(unsigned int size);

  // grault@1: Text;  # ptr[1]
  inline bool hasGrault();
  inline  ::capnp::Text::Builder getGrault();
  inline void setGrault( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initGrault(unsigned int size);

  // garply@7: Text;  # ptr[7]
  inline bool hasGarply();
  inline  ::capnp::Text::Builder getGarply();
  inline void setGarply( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initGarply(unsigned int size);

  // waldo@5: Text;  # ptr[5]
  inline bool hasWaldo();
  inline  ::capnp::Text::Builder getWaldo();
  inline void setWaldo( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initWaldo(unsigned int size);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestOutOfOrder::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestOutOfOrder::Builder builder) {
  return ::capnp::_::structString<TestOutOfOrder>(builder._builder.asReader());
}

class TestUnion::Reader {
public:
  typedef TestUnion Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // union union0@0 {  # [0, 16)
  inline Union0::Reader getUnion0() const;

  // union union1@1 {  # [16, 32)
  inline Union1::Reader getUnion1() const;

  // union union2@2 {  # [32, 48)
  inline Union2::Reader getUnion2() const;

  // union union3@3 {  # [48, 64)
  inline Union3::Reader getUnion3() const;

  // bit0@18: Bool;  # bits[128, 129)
  inline bool getBit0() const;

  // bit2@39: Bool;  # bits[130, 131)
  inline bool getBit2() const;

  // bit3@40: Bool;  # bits[131, 132)
  inline bool getBit3() const;

  // bit4@41: Bool;  # bits[132, 133)
  inline bool getBit4() const;

  // bit5@42: Bool;  # bits[133, 134)
  inline bool getBit5() const;

  // bit6@43: Bool;  # bits[134, 135)
  inline bool getBit6() const;

  // bit7@44: Bool;  # bits[135, 136)
  inline bool getBit7() const;

  // byte0@49: UInt8;  # bits[280, 288)
  inline  ::uint8_t getByte0() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Reader reader) {
  return ::capnp::_::structString<TestUnion>(reader._reader);
}



class TestUnion::Builder {
public:
  typedef TestUnion Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // union union0@0 {  # [0, 16)
  inline Union0::Builder getUnion0();

  // union union1@1 {  # [16, 32)
  inline Union1::Builder getUnion1();

  // union union2@2 {  # [32, 48)
  inline Union2::Builder getUnion2();

  // union union3@3 {  # [48, 64)
  inline Union3::Builder getUnion3();

  // bit0@18: Bool;  # bits[128, 129)
  inline bool getBit0();
  inline void setBit0(bool value);

  // bit2@39: Bool;  # bits[130, 131)
  inline bool getBit2();
  inline void setBit2(bool value);

  // bit3@40: Bool;  # bits[131, 132)
  inline bool getBit3();
  inline void setBit3(bool value);

  // bit4@41: Bool;  # bits[132, 133)
  inline bool getBit4();
  inline void setBit4(bool value);

  // bit5@42: Bool;  # bits[133, 134)
  inline bool getBit5();
  inline void setBit5(bool value);

  // bit6@43: Bool;  # bits[134, 135)
  inline bool getBit6();
  inline void setBit6(bool value);

  // bit7@44: Bool;  # bits[135, 136)
  inline bool getBit7();
  inline void setBit7(bool value);

  // byte0@49: UInt8;  # bits[280, 288)
  inline  ::uint8_t getByte0();
  inline void setByte0( ::uint8_t value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Builder builder) {
  return ::capnp::_::structString<TestUnion>(builder._builder.asReader());
}

class TestUnion::Union0::Reader {
public:
  typedef Union0 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline Which which() const;

  // u0f0s0@4: Void;  # (none), union tag = 0
  inline  ::capnp::Void getU0f0s0() const;

  // u0f0s1@5: Bool;  # bits[64, 65), union tag = 1
  inline bool getU0f0s1() const;

  // u0f0s8@6: Int8;  # bits[64, 72), union tag = 2
  inline  ::int8_t getU0f0s8() const;

  // u0f0s16@7: Int16;  # bits[64, 80), union tag = 3
  inline  ::int16_t getU0f0s16() const;

  // u0f0s32@8: Int32;  # bits[64, 96), union tag = 4
  inline  ::int32_t getU0f0s32() const;

  // u0f0s64@9: Int64;  # bits[64, 128), union tag = 5
  inline  ::int64_t getU0f0s64() const;

  // u0f0sp@10: Text;  # ptr[0], union tag = 6
  inline bool hasU0f0sp() const;
  inline  ::capnp::Text::Reader getU0f0sp() const;

  // u0f1s0@11: Void;  # (none), union tag = 7
  inline  ::capnp::Void getU0f1s0() const;

  // u0f1s1@12: Bool;  # bits[64, 65), union tag = 8
  inline bool getU0f1s1() const;

  // u0f1s8@13: Int8;  # bits[64, 72), union tag = 9
  inline  ::int8_t getU0f1s8() const;

  // u0f1s16@14: Int16;  # bits[64, 80), union tag = 10
  inline  ::int16_t getU0f1s16() const;

  // u0f1s32@15: Int32;  # bits[64, 96), union tag = 11
  inline  ::int32_t getU0f1s32() const;

  // u0f1s64@16: Int64;  # bits[64, 128), union tag = 12
  inline  ::int64_t getU0f1s64() const;

  // u0f1sp@17: Text;  # ptr[0], union tag = 13
  inline bool hasU0f1sp() const;
  inline  ::capnp::Text::Reader getU0f1sp() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Union0::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Union0::Reader reader) {
  return ::capnp::_::unionString<TestUnion::Union0>(reader._reader);
}



class TestUnion::Union0::Builder {
public:
  typedef Union0 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline Which which();

  // u0f0s0@4: Void;  # (none), union tag = 0
  inline  ::capnp::Void getU0f0s0();
  inline void setU0f0s0( ::capnp::Void value);

  // u0f0s1@5: Bool;  # bits[64, 65), union tag = 1
  inline bool getU0f0s1();
  inline void setU0f0s1(bool value);

  // u0f0s8@6: Int8;  # bits[64, 72), union tag = 2
  inline  ::int8_t getU0f0s8();
  inline void setU0f0s8( ::int8_t value);

  // u0f0s16@7: Int16;  # bits[64, 80), union tag = 3
  inline  ::int16_t getU0f0s16();
  inline void setU0f0s16( ::int16_t value);

  // u0f0s32@8: Int32;  # bits[64, 96), union tag = 4
  inline  ::int32_t getU0f0s32();
  inline void setU0f0s32( ::int32_t value);

  // u0f0s64@9: Int64;  # bits[64, 128), union tag = 5
  inline  ::int64_t getU0f0s64();
  inline void setU0f0s64( ::int64_t value);

  // u0f0sp@10: Text;  # ptr[0], union tag = 6
  inline bool hasU0f0sp();
  inline  ::capnp::Text::Builder getU0f0sp();
  inline void setU0f0sp( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initU0f0sp(unsigned int size);

  // u0f1s0@11: Void;  # (none), union tag = 7
  inline  ::capnp::Void getU0f1s0();
  inline void setU0f1s0( ::capnp::Void value);

  // u0f1s1@12: Bool;  # bits[64, 65), union tag = 8
  inline bool getU0f1s1();
  inline void setU0f1s1(bool value);

  // u0f1s8@13: Int8;  # bits[64, 72), union tag = 9
  inline  ::int8_t getU0f1s8();
  inline void setU0f1s8( ::int8_t value);

  // u0f1s16@14: Int16;  # bits[64, 80), union tag = 10
  inline  ::int16_t getU0f1s16();
  inline void setU0f1s16( ::int16_t value);

  // u0f1s32@15: Int32;  # bits[64, 96), union tag = 11
  inline  ::int32_t getU0f1s32();
  inline void setU0f1s32( ::int32_t value);

  // u0f1s64@16: Int64;  # bits[64, 128), union tag = 12
  inline  ::int64_t getU0f1s64();
  inline void setU0f1s64( ::int64_t value);

  // u0f1sp@17: Text;  # ptr[0], union tag = 13
  inline bool hasU0f1sp();
  inline  ::capnp::Text::Builder getU0f1sp();
  inline void setU0f1sp( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initU0f1sp(unsigned int size);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Union0::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Union0::Builder builder) {
  return ::capnp::_::unionString<TestUnion::Union0>(builder._builder.asReader());
}

class TestUnion::Union1::Reader {
public:
  typedef Union1 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline Which which() const;

  // u1f0s0@19: Void;  # (none), union tag = 0
  inline  ::capnp::Void getU1f0s0() const;

  // u1f0s1@20: Bool;  # bits[129, 130), union tag = 1
  inline bool getU1f0s1() const;

  // u1f1s1@21: Bool;  # bits[129, 130), union tag = 2
  inline bool getU1f1s1() const;

  // u1f0s8@22: Int8;  # bits[136, 144), union tag = 3
  inline  ::int8_t getU1f0s8() const;

  // u1f1s8@23: Int8;  # bits[136, 144), union tag = 4
  inline  ::int8_t getU1f1s8() const;

  // u1f0s16@24: Int16;  # bits[144, 160), union tag = 5
  inline  ::int16_t getU1f0s16() const;

  // u1f1s16@25: Int16;  # bits[144, 160), union tag = 6
  inline  ::int16_t getU1f1s16() const;

  // u1f0s32@26: Int32;  # bits[160, 192), union tag = 7
  inline  ::int32_t getU1f0s32() const;

  // u1f1s32@27: Int32;  # bits[160, 192), union tag = 8
  inline  ::int32_t getU1f1s32() const;

  // u1f0s64@28: Int64;  # bits[192, 256), union tag = 9
  inline  ::int64_t getU1f0s64() const;

  // u1f1s64@29: Int64;  # bits[192, 256), union tag = 10
  inline  ::int64_t getU1f1s64() const;

  // u1f0sp@30: Text;  # ptr[1], union tag = 11
  inline bool hasU1f0sp() const;
  inline  ::capnp::Text::Reader getU1f0sp() const;

  // u1f1sp@31: Text;  # ptr[1], union tag = 12
  inline bool hasU1f1sp() const;
  inline  ::capnp::Text::Reader getU1f1sp() const;

  // u1f2s0@32: Void;  # (none), union tag = 13
  inline  ::capnp::Void getU1f2s0() const;

  // u1f2s1@33: Bool;  # bits[192, 193), union tag = 14
  inline bool getU1f2s1() const;

  // u1f2s8@34: Int8;  # bits[192, 200), union tag = 15
  inline  ::int8_t getU1f2s8() const;

  // u1f2s16@35: Int16;  # bits[192, 208), union tag = 16
  inline  ::int16_t getU1f2s16() const;

  // u1f2s32@36: Int32;  # bits[192, 224), union tag = 17
  inline  ::int32_t getU1f2s32() const;

  // u1f2s64@37: Int64;  # bits[192, 256), union tag = 18
  inline  ::int64_t getU1f2s64() const;

  // u1f2sp@38: Text;  # ptr[1], union tag = 19
  inline bool hasU1f2sp() const;
  inline  ::capnp::Text::Reader getU1f2sp() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Union1::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Union1::Reader reader) {
  return ::capnp::_::unionString<TestUnion::Union1>(reader._reader);
}



class TestUnion::Union1::Builder {
public:
  typedef Union1 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline Which which();

  // u1f0s0@19: Void;  # (none), union tag = 0
  inline  ::capnp::Void getU1f0s0();
  inline void setU1f0s0( ::capnp::Void value);

  // u1f0s1@20: Bool;  # bits[129, 130), union tag = 1
  inline bool getU1f0s1();
  inline void setU1f0s1(bool value);

  // u1f1s1@21: Bool;  # bits[129, 130), union tag = 2
  inline bool getU1f1s1();
  inline void setU1f1s1(bool value);

  // u1f0s8@22: Int8;  # bits[136, 144), union tag = 3
  inline  ::int8_t getU1f0s8();
  inline void setU1f0s8( ::int8_t value);

  // u1f1s8@23: Int8;  # bits[136, 144), union tag = 4
  inline  ::int8_t getU1f1s8();
  inline void setU1f1s8( ::int8_t value);

  // u1f0s16@24: Int16;  # bits[144, 160), union tag = 5
  inline  ::int16_t getU1f0s16();
  inline void setU1f0s16( ::int16_t value);

  // u1f1s16@25: Int16;  # bits[144, 160), union tag = 6
  inline  ::int16_t getU1f1s16();
  inline void setU1f1s16( ::int16_t value);

  // u1f0s32@26: Int32;  # bits[160, 192), union tag = 7
  inline  ::int32_t getU1f0s32();
  inline void setU1f0s32( ::int32_t value);

  // u1f1s32@27: Int32;  # bits[160, 192), union tag = 8
  inline  ::int32_t getU1f1s32();
  inline void setU1f1s32( ::int32_t value);

  // u1f0s64@28: Int64;  # bits[192, 256), union tag = 9
  inline  ::int64_t getU1f0s64();
  inline void setU1f0s64( ::int64_t value);

  // u1f1s64@29: Int64;  # bits[192, 256), union tag = 10
  inline  ::int64_t getU1f1s64();
  inline void setU1f1s64( ::int64_t value);

  // u1f0sp@30: Text;  # ptr[1], union tag = 11
  inline bool hasU1f0sp();
  inline  ::capnp::Text::Builder getU1f0sp();
  inline void setU1f0sp( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initU1f0sp(unsigned int size);

  // u1f1sp@31: Text;  # ptr[1], union tag = 12
  inline bool hasU1f1sp();
  inline  ::capnp::Text::Builder getU1f1sp();
  inline void setU1f1sp( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initU1f1sp(unsigned int size);

  // u1f2s0@32: Void;  # (none), union tag = 13
  inline  ::capnp::Void getU1f2s0();
  inline void setU1f2s0( ::capnp::Void value);

  // u1f2s1@33: Bool;  # bits[192, 193), union tag = 14
  inline bool getU1f2s1();
  inline void setU1f2s1(bool value);

  // u1f2s8@34: Int8;  # bits[192, 200), union tag = 15
  inline  ::int8_t getU1f2s8();
  inline void setU1f2s8( ::int8_t value);

  // u1f2s16@35: Int16;  # bits[192, 208), union tag = 16
  inline  ::int16_t getU1f2s16();
  inline void setU1f2s16( ::int16_t value);

  // u1f2s32@36: Int32;  # bits[192, 224), union tag = 17
  inline  ::int32_t getU1f2s32();
  inline void setU1f2s32( ::int32_t value);

  // u1f2s64@37: Int64;  # bits[192, 256), union tag = 18
  inline  ::int64_t getU1f2s64();
  inline void setU1f2s64( ::int64_t value);

  // u1f2sp@38: Text;  # ptr[1], union tag = 19
  inline bool hasU1f2sp();
  inline  ::capnp::Text::Builder getU1f2sp();
  inline void setU1f2sp( ::capnp::Text::Reader other);
  inline  ::capnp::Text::Builder initU1f2sp(unsigned int size);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Union1::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Union1::Builder builder) {
  return ::capnp::_::unionString<TestUnion::Union1>(builder._builder.asReader());
}

class TestUnion::Union2::Reader {
public:
  typedef Union2 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline Which which() const;

  // u2f0s64@54: Int64;  # bits[384, 448), union tag = 4
  inline  ::int64_t getU2f0s64() const;

  // u2f0s32@52: Int32;  # bits[320, 352), union tag = 3
  inline  ::int32_t getU2f0s32() const;

  // u2f0s16@50: Int16;  # bits[288, 304), union tag = 2
  inline  ::int16_t getU2f0s16() const;

  // u2f0s8@47: Int8;  # bits[264, 272), union tag = 1
  inline  ::int8_t getU2f0s8() const;

  // u2f0s1@45: Bool;  # bits[256, 257), union tag = 0
  inline bool getU2f0s1() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Union2::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Union2::Reader reader) {
  return ::capnp::_::unionString<TestUnion::Union2>(reader._reader);
}



class TestUnion::Union2::Builder {
public:
  typedef Union2 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline Which which();

  // u2f0s64@54: Int64;  # bits[384, 448), union tag = 4
  inline  ::int64_t getU2f0s64();
  inline void setU2f0s64( ::int64_t value);

  // u2f0s32@52: Int32;  # bits[320, 352), union tag = 3
  inline  ::int32_t getU2f0s32();
  inline void setU2f0s32( ::int32_t value);

  // u2f0s16@50: Int16;  # bits[288, 304), union tag = 2
  inline  ::int16_t getU2f0s16();
  inline void setU2f0s16( ::int16_t value);

  // u2f0s8@47: Int8;  # bits[264, 272), union tag = 1
  inline  ::int8_t getU2f0s8();
  inline void setU2f0s8( ::int8_t value);

  // u2f0s1@45: Bool;  # bits[256, 257), union tag = 0
  inline bool getU2f0s1();
  inline void setU2f0s1(bool value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Union2::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Union2::Builder builder) {
  return ::capnp::_::unionString<TestUnion::Union2>(builder._builder.asReader());
}

class TestUnion::Union3::Reader {
public:
  typedef Union3 Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline Which which() const;

  // u3f0s64@55: Int64;  # bits[448, 512), union tag = 4
  inline  ::int64_t getU3f0s64() const;

  // u3f0s32@53: Int32;  # bits[352, 384), union tag = 3
  inline  ::int32_t getU3f0s32() const;

  // u3f0s16@51: Int16;  # bits[304, 320), union tag = 2
  inline  ::int16_t getU3f0s16() const;

  // u3f0s8@48: Int8;  # bits[272, 280), union tag = 1
  inline  ::int8_t getU3f0s8() const;

  // u3f0s1@46: Bool;  # bits[257, 258), union tag = 0
  inline bool getU3f0s1() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Union3::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Union3::Reader reader) {
  return ::capnp::_::unionString<TestUnion::Union3>(reader._reader);
}



class TestUnion::Union3::Builder {
public:
  typedef Union3 Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline Which which();

  // u3f0s64@55: Int64;  # bits[448, 512), union tag = 4
  inline  ::int64_t getU3f0s64();
  inline void setU3f0s64( ::int64_t value);

  // u3f0s32@53: Int32;  # bits[352, 384), union tag = 3
  inline  ::int32_t getU3f0s32();
  inline void setU3f0s32( ::int32_t value);

  // u3f0s16@51: Int16;  # bits[304, 320), union tag = 2
  inline  ::int16_t getU3f0s16();
  inline void setU3f0s16( ::int16_t value);

  // u3f0s8@48: Int8;  # bits[272, 280), union tag = 1
  inline  ::int8_t getU3f0s8();
  inline void setU3f0s8( ::int8_t value);

  // u3f0s1@46: Bool;  # bits[257, 258), union tag = 0
  inline bool getU3f0s1();
  inline void setU3f0s1(bool value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestUnion::Union3::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestUnion::Union3::Builder builder) {
  return ::capnp::_::unionString<TestUnion::Union3>(builder._builder.asReader());
}

class TestUnionDefaults::Reader {
public:
  typedef TestUnionDefaults Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // s16s8s64s8Set@0: .TestUnion = (union0 = u0f0s16(321), union1 = u1f0s8(123), union2 = u2f0s64(12345678901234567), union3 = u3f0s8(55));  # ptr[0]
  inline bool hasS16s8s64s8Set() const;
  inline  ::capnproto_test::capnp::test::TestUnion::Reader getS16s8s64s8Set() const;

  // s0sps1s32Set@1: .TestUnion = (union0 = u0f1s0(void), union1 = u1f0sp("foo"), union2 = u2f0s1(true), union3 = u3f0s32(12345678));  # ptr[1]
  inline bool hasS0sps1s32Set() const;
  inline  ::capnproto_test::capnp::test::TestUnion::Reader getS0sps1s32Set() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestUnionDefaults::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestUnionDefaults::Reader reader) {
  return ::capnp::_::structString<TestUnionDefaults>(reader._reader);
}



class TestUnionDefaults::Builder {
public:
  typedef TestUnionDefaults Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // s16s8s64s8Set@0: .TestUnion = (union0 = u0f0s16(321), union1 = u1f0s8(123), union2 = u2f0s64(12345678901234567), union3 = u3f0s8(55));  # ptr[0]
  inline bool hasS16s8s64s8Set();
  inline  ::capnproto_test::capnp::test::TestUnion::Builder getS16s8s64s8Set();
  inline void setS16s8s64s8Set( ::capnproto_test::capnp::test::TestUnion::Reader other);
  inline  ::capnproto_test::capnp::test::TestUnion::Builder initS16s8s64s8Set();

  // s0sps1s32Set@1: .TestUnion = (union0 = u0f1s0(void), union1 = u1f0sp("foo"), union2 = u2f0s1(true), union3 = u3f0s32(12345678));  # ptr[1]
  inline bool hasS0sps1s32Set();
  inline  ::capnproto_test::capnp::test::TestUnion::Builder getS0sps1s32Set();
  inline void setS0sps1s32Set( ::capnproto_test::capnp::test::TestUnion::Reader other);
  inline  ::capnproto_test::capnp::test::TestUnion::Builder initS0sps1s32Set();
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestUnionDefaults::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestUnionDefaults::Builder builder) {
  return ::capnp::_::structString<TestUnionDefaults>(builder._builder.asReader());
}

class TestUsing::Reader {
public:
  typedef TestUsing Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // outerNestedEnum@1: .TestNestedTypes.NestedEnum = bar;  # bits[16, 32)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum getOuterNestedEnum() const;

  // innerNestedEnum@0: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[0, 16)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum getInnerNestedEnum() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestUsing::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestUsing::Reader reader) {
  return ::capnp::_::structString<TestUsing>(reader._reader);
}



class TestUsing::Builder {
public:
  typedef TestUsing Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // outerNestedEnum@1: .TestNestedTypes.NestedEnum = bar;  # bits[16, 32)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum getOuterNestedEnum();
  inline void setOuterNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum value);

  // innerNestedEnum@0: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[0, 16)
  inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum getInnerNestedEnum();
  inline void setInnerNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum value);
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestUsing::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestUsing::Builder builder) {
  return ::capnp::_::structString<TestUsing>(builder._builder.asReader());
}



// TestAllTypes::voidField@0: Void;  # (none)

inline  ::capnp::Void TestAllTypes::Reader::getVoidField() const {
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestAllTypes::Builder::getVoidField() {
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setVoidField( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::boolField@1: Bool;  # bits[0, 1)

inline bool TestAllTypes::Reader::getBoolField() const {
  return _reader.getDataField<bool>(
      0 * ::capnp::ELEMENTS);
}

inline bool TestAllTypes::Builder::getBoolField() {
  return _builder.getDataField<bool>(
      0 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setBoolField(bool value) {
  _builder.setDataField<bool>(
      0 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::int8Field@2: Int8;  # bits[8, 16)

inline  ::int8_t TestAllTypes::Reader::getInt8Field() const {
  return _reader.getDataField< ::int8_t>(
      1 * ::capnp::ELEMENTS);
}

inline  ::int8_t TestAllTypes::Builder::getInt8Field() {
  return _builder.getDataField< ::int8_t>(
      1 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setInt8Field( ::int8_t value) {
  _builder.setDataField< ::int8_t>(
      1 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::int16Field@3: Int16;  # bits[16, 32)

inline  ::int16_t TestAllTypes::Reader::getInt16Field() const {
  return _reader.getDataField< ::int16_t>(
      1 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestAllTypes::Builder::getInt16Field() {
  return _builder.getDataField< ::int16_t>(
      1 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setInt16Field( ::int16_t value) {
  _builder.setDataField< ::int16_t>(
      1 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::int32Field@4: Int32;  # bits[32, 64)

inline  ::int32_t TestAllTypes::Reader::getInt32Field() const {
  return _reader.getDataField< ::int32_t>(
      1 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestAllTypes::Builder::getInt32Field() {
  return _builder.getDataField< ::int32_t>(
      1 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setInt32Field( ::int32_t value) {
  _builder.setDataField< ::int32_t>(
      1 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::int64Field@5: Int64;  # bits[64, 128)

inline  ::int64_t TestAllTypes::Reader::getInt64Field() const {
  return _reader.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestAllTypes::Builder::getInt64Field() {
  return _builder.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setInt64Field( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::uInt8Field@6: UInt8;  # bits[128, 136)

inline  ::uint8_t TestAllTypes::Reader::getUInt8Field() const {
  return _reader.getDataField< ::uint8_t>(
      16 * ::capnp::ELEMENTS);
}

inline  ::uint8_t TestAllTypes::Builder::getUInt8Field() {
  return _builder.getDataField< ::uint8_t>(
      16 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setUInt8Field( ::uint8_t value) {
  _builder.setDataField< ::uint8_t>(
      16 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::uInt16Field@7: UInt16;  # bits[144, 160)

inline  ::uint16_t TestAllTypes::Reader::getUInt16Field() const {
  return _reader.getDataField< ::uint16_t>(
      9 * ::capnp::ELEMENTS);
}

inline  ::uint16_t TestAllTypes::Builder::getUInt16Field() {
  return _builder.getDataField< ::uint16_t>(
      9 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setUInt16Field( ::uint16_t value) {
  _builder.setDataField< ::uint16_t>(
      9 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::uInt32Field@8: UInt32;  # bits[160, 192)

inline  ::uint32_t TestAllTypes::Reader::getUInt32Field() const {
  return _reader.getDataField< ::uint32_t>(
      5 * ::capnp::ELEMENTS);
}

inline  ::uint32_t TestAllTypes::Builder::getUInt32Field() {
  return _builder.getDataField< ::uint32_t>(
      5 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setUInt32Field( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      5 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::uInt64Field@9: UInt64;  # bits[192, 256)

inline  ::uint64_t TestAllTypes::Reader::getUInt64Field() const {
  return _reader.getDataField< ::uint64_t>(
      3 * ::capnp::ELEMENTS);
}

inline  ::uint64_t TestAllTypes::Builder::getUInt64Field() {
  return _builder.getDataField< ::uint64_t>(
      3 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setUInt64Field( ::uint64_t value) {
  _builder.setDataField< ::uint64_t>(
      3 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::float32Field@10: Float32;  # bits[256, 288)

inline float TestAllTypes::Reader::getFloat32Field() const {
  return _reader.getDataField<float>(
      8 * ::capnp::ELEMENTS);
}

inline float TestAllTypes::Builder::getFloat32Field() {
  return _builder.getDataField<float>(
      8 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setFloat32Field(float value) {
  _builder.setDataField<float>(
      8 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::float64Field@11: Float64;  # bits[320, 384)

inline double TestAllTypes::Reader::getFloat64Field() const {
  return _reader.getDataField<double>(
      5 * ::capnp::ELEMENTS);
}

inline double TestAllTypes::Builder::getFloat64Field() {
  return _builder.getDataField<double>(
      5 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setFloat64Field(double value) {
  _builder.setDataField<double>(
      5 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::textField@12: Text;  # ptr[0]


inline bool TestAllTypes::Reader::hasTextField() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasTextField() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestAllTypes::Reader::getTextField() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestAllTypes::Builder::getTextField() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setTextField( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestAllTypes::Builder::initTextField(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestAllTypes::dataField@13: Data;  # ptr[1]


inline bool TestAllTypes::Reader::hasDataField() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasDataField() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::Data::Reader TestAllTypes::Reader::getDataField() const {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnp::Data::Builder TestAllTypes::Builder::getDataField() {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setDataField( ::capnp::Data::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Data>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::Data::Builder TestAllTypes::Builder::initDataField(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestAllTypes::structField@14: .TestAllTypes;  # ptr[2]


inline bool TestAllTypes::Reader::hasStructField() const {
  return !_reader.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasStructField() {
  return !_builder.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Reader TestAllTypes::Reader::getStructField() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::get(
      _reader, 2 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Builder TestAllTypes::Builder::getStructField() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::get(
      _builder, 2 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setStructField( ::capnproto_test::capnp::test::TestAllTypes::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::set(
      _builder, 2 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Builder TestAllTypes::Builder::initStructField() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::init(
      _builder, 2 * ::capnp::POINTERS);
}



// TestAllTypes::enumField@15: .TestEnum;  # bits[288, 304)

inline  ::capnproto_test::capnp::test::TestEnum TestAllTypes::Reader::getEnumField() const {
  return _reader.getDataField< ::capnproto_test::capnp::test::TestEnum>(
      18 * ::capnp::ELEMENTS);
}

inline  ::capnproto_test::capnp::test::TestEnum TestAllTypes::Builder::getEnumField() {
  return _builder.getDataField< ::capnproto_test::capnp::test::TestEnum>(
      18 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setEnumField( ::capnproto_test::capnp::test::TestEnum value) {
  _builder.setDataField< ::capnproto_test::capnp::test::TestEnum>(
      18 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::interfaceField@16: Void;  # (none)

inline  ::capnp::Void TestAllTypes::Reader::getInterfaceField() const {
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestAllTypes::Builder::getInterfaceField() {
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestAllTypes::Builder::setInterfaceField( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}


// TestAllTypes::voidList@17: List(Void);  # ptr[3]


inline bool TestAllTypes::Reader::hasVoidList() const {
  return !_reader.isPointerFieldNull(3 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasVoidList() {
  return !_builder.isPointerFieldNull(3 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Void>::Reader TestAllTypes::Reader::getVoidList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::get(
      _reader, 3 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Void>::Builder TestAllTypes::Builder::getVoidList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::get(
      _builder, 3 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setVoidList( ::capnp::List< ::capnp::Void>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::set(
      _builder, 3 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setVoidList(
    std::initializer_list< ::capnp::Void> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::set(
      _builder, 3 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::Void>::Builder TestAllTypes::Builder::initVoidList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::init(
      _builder, 3 * ::capnp::POINTERS, size);
}



// TestAllTypes::boolList@18: List(Bool);  # ptr[4]


inline bool TestAllTypes::Reader::hasBoolList() const {
  return !_reader.isPointerFieldNull(4 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasBoolList() {
  return !_builder.isPointerFieldNull(4 * ::capnp::POINTERS);
}

inline  ::capnp::List<bool>::Reader TestAllTypes::Reader::getBoolList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List<bool>>::get(
      _reader, 4 * ::capnp::POINTERS);
}

inline  ::capnp::List<bool>::Builder TestAllTypes::Builder::getBoolList() {
  return ::capnp::_::PointerHelpers< ::capnp::List<bool>>::get(
      _builder, 4 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setBoolList( ::capnp::List<bool>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List<bool>>::set(
      _builder, 4 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setBoolList(
    std::initializer_list<bool> value) {
  ::capnp::_::PointerHelpers< ::capnp::List<bool>>::set(
      _builder, 4 * ::capnp::POINTERS, value);
}

inline  ::capnp::List<bool>::Builder TestAllTypes::Builder::initBoolList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List<bool>>::init(
      _builder, 4 * ::capnp::POINTERS, size);
}



// TestAllTypes::int8List@19: List(Int8);  # ptr[5]


inline bool TestAllTypes::Reader::hasInt8List() const {
  return !_reader.isPointerFieldNull(5 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasInt8List() {
  return !_builder.isPointerFieldNull(5 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int8_t>::Reader TestAllTypes::Reader::getInt8List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::get(
      _reader, 5 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int8_t>::Builder TestAllTypes::Builder::getInt8List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::get(
      _builder, 5 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setInt8List( ::capnp::List< ::int8_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::set(
      _builder, 5 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setInt8List(
    std::initializer_list< ::int8_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::set(
      _builder, 5 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int8_t>::Builder TestAllTypes::Builder::initInt8List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::init(
      _builder, 5 * ::capnp::POINTERS, size);
}



// TestAllTypes::int16List@20: List(Int16);  # ptr[6]


inline bool TestAllTypes::Reader::hasInt16List() const {
  return !_reader.isPointerFieldNull(6 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasInt16List() {
  return !_builder.isPointerFieldNull(6 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int16_t>::Reader TestAllTypes::Reader::getInt16List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::get(
      _reader, 6 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int16_t>::Builder TestAllTypes::Builder::getInt16List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::get(
      _builder, 6 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setInt16List( ::capnp::List< ::int16_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::set(
      _builder, 6 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setInt16List(
    std::initializer_list< ::int16_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::set(
      _builder, 6 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int16_t>::Builder TestAllTypes::Builder::initInt16List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::init(
      _builder, 6 * ::capnp::POINTERS, size);
}



// TestAllTypes::int32List@21: List(Int32);  # ptr[7]


inline bool TestAllTypes::Reader::hasInt32List() const {
  return !_reader.isPointerFieldNull(7 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasInt32List() {
  return !_builder.isPointerFieldNull(7 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int32_t>::Reader TestAllTypes::Reader::getInt32List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::get(
      _reader, 7 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int32_t>::Builder TestAllTypes::Builder::getInt32List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::get(
      _builder, 7 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setInt32List( ::capnp::List< ::int32_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::set(
      _builder, 7 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setInt32List(
    std::initializer_list< ::int32_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::set(
      _builder, 7 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int32_t>::Builder TestAllTypes::Builder::initInt32List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::init(
      _builder, 7 * ::capnp::POINTERS, size);
}



// TestAllTypes::int64List@22: List(Int64);  # ptr[8]


inline bool TestAllTypes::Reader::hasInt64List() const {
  return !_reader.isPointerFieldNull(8 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasInt64List() {
  return !_builder.isPointerFieldNull(8 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int64_t>::Reader TestAllTypes::Reader::getInt64List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::get(
      _reader, 8 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int64_t>::Builder TestAllTypes::Builder::getInt64List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::get(
      _builder, 8 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setInt64List( ::capnp::List< ::int64_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::set(
      _builder, 8 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setInt64List(
    std::initializer_list< ::int64_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::set(
      _builder, 8 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int64_t>::Builder TestAllTypes::Builder::initInt64List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::init(
      _builder, 8 * ::capnp::POINTERS, size);
}



// TestAllTypes::uInt8List@23: List(UInt8);  # ptr[9]


inline bool TestAllTypes::Reader::hasUInt8List() const {
  return !_reader.isPointerFieldNull(9 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasUInt8List() {
  return !_builder.isPointerFieldNull(9 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint8_t>::Reader TestAllTypes::Reader::getUInt8List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::get(
      _reader, 9 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint8_t>::Builder TestAllTypes::Builder::getUInt8List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::get(
      _builder, 9 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setUInt8List( ::capnp::List< ::uint8_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::set(
      _builder, 9 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setUInt8List(
    std::initializer_list< ::uint8_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::set(
      _builder, 9 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::uint8_t>::Builder TestAllTypes::Builder::initUInt8List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::init(
      _builder, 9 * ::capnp::POINTERS, size);
}



// TestAllTypes::uInt16List@24: List(UInt16);  # ptr[10]


inline bool TestAllTypes::Reader::hasUInt16List() const {
  return !_reader.isPointerFieldNull(10 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasUInt16List() {
  return !_builder.isPointerFieldNull(10 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint16_t>::Reader TestAllTypes::Reader::getUInt16List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::get(
      _reader, 10 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint16_t>::Builder TestAllTypes::Builder::getUInt16List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::get(
      _builder, 10 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setUInt16List( ::capnp::List< ::uint16_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::set(
      _builder, 10 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setUInt16List(
    std::initializer_list< ::uint16_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::set(
      _builder, 10 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::uint16_t>::Builder TestAllTypes::Builder::initUInt16List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::init(
      _builder, 10 * ::capnp::POINTERS, size);
}



// TestAllTypes::uInt32List@25: List(UInt32);  # ptr[11]


inline bool TestAllTypes::Reader::hasUInt32List() const {
  return !_reader.isPointerFieldNull(11 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasUInt32List() {
  return !_builder.isPointerFieldNull(11 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint32_t>::Reader TestAllTypes::Reader::getUInt32List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::get(
      _reader, 11 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint32_t>::Builder TestAllTypes::Builder::getUInt32List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::get(
      _builder, 11 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setUInt32List( ::capnp::List< ::uint32_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::set(
      _builder, 11 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setUInt32List(
    std::initializer_list< ::uint32_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::set(
      _builder, 11 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::uint32_t>::Builder TestAllTypes::Builder::initUInt32List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::init(
      _builder, 11 * ::capnp::POINTERS, size);
}



// TestAllTypes::uInt64List@26: List(UInt64);  # ptr[12]


inline bool TestAllTypes::Reader::hasUInt64List() const {
  return !_reader.isPointerFieldNull(12 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasUInt64List() {
  return !_builder.isPointerFieldNull(12 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint64_t>::Reader TestAllTypes::Reader::getUInt64List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::get(
      _reader, 12 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint64_t>::Builder TestAllTypes::Builder::getUInt64List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::get(
      _builder, 12 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setUInt64List( ::capnp::List< ::uint64_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::set(
      _builder, 12 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setUInt64List(
    std::initializer_list< ::uint64_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::set(
      _builder, 12 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::uint64_t>::Builder TestAllTypes::Builder::initUInt64List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::init(
      _builder, 12 * ::capnp::POINTERS, size);
}



// TestAllTypes::float32List@27: List(Float32);  # ptr[13]


inline bool TestAllTypes::Reader::hasFloat32List() const {
  return !_reader.isPointerFieldNull(13 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasFloat32List() {
  return !_builder.isPointerFieldNull(13 * ::capnp::POINTERS);
}

inline  ::capnp::List<float>::Reader TestAllTypes::Reader::getFloat32List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List<float>>::get(
      _reader, 13 * ::capnp::POINTERS);
}

inline  ::capnp::List<float>::Builder TestAllTypes::Builder::getFloat32List() {
  return ::capnp::_::PointerHelpers< ::capnp::List<float>>::get(
      _builder, 13 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setFloat32List( ::capnp::List<float>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List<float>>::set(
      _builder, 13 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setFloat32List(
    std::initializer_list<float> value) {
  ::capnp::_::PointerHelpers< ::capnp::List<float>>::set(
      _builder, 13 * ::capnp::POINTERS, value);
}

inline  ::capnp::List<float>::Builder TestAllTypes::Builder::initFloat32List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List<float>>::init(
      _builder, 13 * ::capnp::POINTERS, size);
}



// TestAllTypes::float64List@28: List(Float64);  # ptr[14]


inline bool TestAllTypes::Reader::hasFloat64List() const {
  return !_reader.isPointerFieldNull(14 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasFloat64List() {
  return !_builder.isPointerFieldNull(14 * ::capnp::POINTERS);
}

inline  ::capnp::List<double>::Reader TestAllTypes::Reader::getFloat64List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List<double>>::get(
      _reader, 14 * ::capnp::POINTERS);
}

inline  ::capnp::List<double>::Builder TestAllTypes::Builder::getFloat64List() {
  return ::capnp::_::PointerHelpers< ::capnp::List<double>>::get(
      _builder, 14 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setFloat64List( ::capnp::List<double>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List<double>>::set(
      _builder, 14 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setFloat64List(
    std::initializer_list<double> value) {
  ::capnp::_::PointerHelpers< ::capnp::List<double>>::set(
      _builder, 14 * ::capnp::POINTERS, value);
}

inline  ::capnp::List<double>::Builder TestAllTypes::Builder::initFloat64List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List<double>>::init(
      _builder, 14 * ::capnp::POINTERS, size);
}



// TestAllTypes::textList@29: List(Text);  # ptr[15]


inline bool TestAllTypes::Reader::hasTextList() const {
  return !_reader.isPointerFieldNull(15 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasTextList() {
  return !_builder.isPointerFieldNull(15 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Text>::Reader TestAllTypes::Reader::getTextList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::get(
      _reader, 15 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Text>::Builder TestAllTypes::Builder::getTextList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::get(
      _builder, 15 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setTextList( ::capnp::List< ::capnp::Text>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::set(
      _builder, 15 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setTextList(
    std::initializer_list< ::capnp::Text::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::set(
      _builder, 15 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::Text>::Builder TestAllTypes::Builder::initTextList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::init(
      _builder, 15 * ::capnp::POINTERS, size);
}



// TestAllTypes::dataList@30: List(Data);  # ptr[16]


inline bool TestAllTypes::Reader::hasDataList() const {
  return !_reader.isPointerFieldNull(16 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasDataList() {
  return !_builder.isPointerFieldNull(16 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Data>::Reader TestAllTypes::Reader::getDataList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::get(
      _reader, 16 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Data>::Builder TestAllTypes::Builder::getDataList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::get(
      _builder, 16 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setDataList( ::capnp::List< ::capnp::Data>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::set(
      _builder, 16 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setDataList(
    std::initializer_list< ::capnp::Data::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::set(
      _builder, 16 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::Data>::Builder TestAllTypes::Builder::initDataList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::init(
      _builder, 16 * ::capnp::POINTERS, size);
}



// TestAllTypes::structList@31: List(.TestAllTypes);  # ptr[17]


inline bool TestAllTypes::Reader::hasStructList() const {
  return !_reader.isPointerFieldNull(17 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasStructList() {
  return !_builder.isPointerFieldNull(17 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader TestAllTypes::Reader::getStructList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::get(
      _reader, 17 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Builder TestAllTypes::Builder::getStructList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::get(
      _builder, 17 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setStructList( ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::set(
      _builder, 17 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Builder TestAllTypes::Builder::initStructList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::init(
      _builder, 17 * ::capnp::POINTERS, size);
}



// TestAllTypes::enumList@32: List(.TestEnum);  # ptr[18]


inline bool TestAllTypes::Reader::hasEnumList() const {
  return !_reader.isPointerFieldNull(18 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasEnumList() {
  return !_builder.isPointerFieldNull(18 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Reader TestAllTypes::Reader::getEnumList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::get(
      _reader, 18 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Builder TestAllTypes::Builder::getEnumList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::get(
      _builder, 18 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setEnumList( ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::set(
      _builder, 18 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setEnumList(
    std::initializer_list< ::capnproto_test::capnp::test::TestEnum> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::set(
      _builder, 18 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Builder TestAllTypes::Builder::initEnumList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::init(
      _builder, 18 * ::capnp::POINTERS, size);
}



// TestAllTypes::interfaceList@33: List(Void);  # ptr[19]


inline bool TestAllTypes::Reader::hasInterfaceList() const {
  return !_reader.isPointerFieldNull(19 * ::capnp::POINTERS);
}

inline bool TestAllTypes::Builder::hasInterfaceList() {
  return !_builder.isPointerFieldNull(19 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Void>::Reader TestAllTypes::Reader::getInterfaceList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::get(
      _reader, 19 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Void>::Builder TestAllTypes::Builder::getInterfaceList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::get(
      _builder, 19 * ::capnp::POINTERS);
}

inline void TestAllTypes::Builder::setInterfaceList( ::capnp::List< ::capnp::Void>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::set(
      _builder, 19 * ::capnp::POINTERS, value);
}

inline void TestAllTypes::Builder::setInterfaceList(
    std::initializer_list< ::capnp::Void> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::set(
      _builder, 19 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::Void>::Builder TestAllTypes::Builder::initInterfaceList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::init(
      _builder, 19 * ::capnp::POINTERS, size);
}




// TestDefaults::voidField@0: Void = void;  # (none)

inline  ::capnp::Void TestDefaults::Reader::getVoidField() const {
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestDefaults::Builder::getVoidField() {
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestDefaults::Builder::setVoidField( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}


// TestDefaults::boolField@1: Bool = true;  # bits[0, 1)

inline bool TestDefaults::Reader::getBoolField() const {
  return _reader.getDataField<bool>(
      0 * ::capnp::ELEMENTS, true);
}

inline bool TestDefaults::Builder::getBoolField() {
  return _builder.getDataField<bool>(
      0 * ::capnp::ELEMENTS, true);
}
inline void TestDefaults::Builder::setBoolField(bool value) {
  _builder.setDataField<bool>(
      0 * ::capnp::ELEMENTS, value, true);
}


// TestDefaults::int8Field@2: Int8 = -123;  # bits[8, 16)

inline  ::int8_t TestDefaults::Reader::getInt8Field() const {
  return _reader.getDataField< ::int8_t>(
      1 * ::capnp::ELEMENTS, -123);
}

inline  ::int8_t TestDefaults::Builder::getInt8Field() {
  return _builder.getDataField< ::int8_t>(
      1 * ::capnp::ELEMENTS, -123);
}
inline void TestDefaults::Builder::setInt8Field( ::int8_t value) {
  _builder.setDataField< ::int8_t>(
      1 * ::capnp::ELEMENTS, value, -123);
}


// TestDefaults::int16Field@3: Int16 = -12345;  # bits[16, 32)

inline  ::int16_t TestDefaults::Reader::getInt16Field() const {
  return _reader.getDataField< ::int16_t>(
      1 * ::capnp::ELEMENTS, -12345);
}

inline  ::int16_t TestDefaults::Builder::getInt16Field() {
  return _builder.getDataField< ::int16_t>(
      1 * ::capnp::ELEMENTS, -12345);
}
inline void TestDefaults::Builder::setInt16Field( ::int16_t value) {
  _builder.setDataField< ::int16_t>(
      1 * ::capnp::ELEMENTS, value, -12345);
}


// TestDefaults::int32Field@4: Int32 = -12345678;  # bits[32, 64)

inline  ::int32_t TestDefaults::Reader::getInt32Field() const {
  return _reader.getDataField< ::int32_t>(
      1 * ::capnp::ELEMENTS, -12345678);
}

inline  ::int32_t TestDefaults::Builder::getInt32Field() {
  return _builder.getDataField< ::int32_t>(
      1 * ::capnp::ELEMENTS, -12345678);
}
inline void TestDefaults::Builder::setInt32Field( ::int32_t value) {
  _builder.setDataField< ::int32_t>(
      1 * ::capnp::ELEMENTS, value, -12345678);
}


// TestDefaults::int64Field@5: Int64 = -123456789012345;  # bits[64, 128)

inline  ::int64_t TestDefaults::Reader::getInt64Field() const {
  return _reader.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, -123456789012345ll);
}

inline  ::int64_t TestDefaults::Builder::getInt64Field() {
  return _builder.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, -123456789012345ll);
}
inline void TestDefaults::Builder::setInt64Field( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, value, -123456789012345ll);
}


// TestDefaults::uInt8Field@6: UInt8 = 234;  # bits[128, 136)

inline  ::uint8_t TestDefaults::Reader::getUInt8Field() const {
  return _reader.getDataField< ::uint8_t>(
      16 * ::capnp::ELEMENTS, 234);
}

inline  ::uint8_t TestDefaults::Builder::getUInt8Field() {
  return _builder.getDataField< ::uint8_t>(
      16 * ::capnp::ELEMENTS, 234);
}
inline void TestDefaults::Builder::setUInt8Field( ::uint8_t value) {
  _builder.setDataField< ::uint8_t>(
      16 * ::capnp::ELEMENTS, value, 234);
}


// TestDefaults::uInt16Field@7: UInt16 = 45678;  # bits[144, 160)

inline  ::uint16_t TestDefaults::Reader::getUInt16Field() const {
  return _reader.getDataField< ::uint16_t>(
      9 * ::capnp::ELEMENTS, 45678);
}

inline  ::uint16_t TestDefaults::Builder::getUInt16Field() {
  return _builder.getDataField< ::uint16_t>(
      9 * ::capnp::ELEMENTS, 45678);
}
inline void TestDefaults::Builder::setUInt16Field( ::uint16_t value) {
  _builder.setDataField< ::uint16_t>(
      9 * ::capnp::ELEMENTS, value, 45678);
}


// TestDefaults::uInt32Field@8: UInt32 = 3456789012;  # bits[160, 192)

inline  ::uint32_t TestDefaults::Reader::getUInt32Field() const {
  return _reader.getDataField< ::uint32_t>(
      5 * ::capnp::ELEMENTS, 3456789012u);
}

inline  ::uint32_t TestDefaults::Builder::getUInt32Field() {
  return _builder.getDataField< ::uint32_t>(
      5 * ::capnp::ELEMENTS, 3456789012u);
}
inline void TestDefaults::Builder::setUInt32Field( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      5 * ::capnp::ELEMENTS, value, 3456789012u);
}


// TestDefaults::uInt64Field@9: UInt64 = 12345678901234567890;  # bits[192, 256)

inline  ::uint64_t TestDefaults::Reader::getUInt64Field() const {
  return _reader.getDataField< ::uint64_t>(
      3 * ::capnp::ELEMENTS, 12345678901234567890llu);
}

inline  ::uint64_t TestDefaults::Builder::getUInt64Field() {
  return _builder.getDataField< ::uint64_t>(
      3 * ::capnp::ELEMENTS, 12345678901234567890llu);
}
inline void TestDefaults::Builder::setUInt64Field( ::uint64_t value) {
  _builder.setDataField< ::uint64_t>(
      3 * ::capnp::ELEMENTS, value, 12345678901234567890llu);
}


// TestDefaults::float32Field@10: Float32 = 1234.5;  # bits[256, 288)

inline float TestDefaults::Reader::getFloat32Field() const {
  return _reader.getDataField<float>(
      8 * ::capnp::ELEMENTS, 1150963712u);
}

inline float TestDefaults::Builder::getFloat32Field() {
  return _builder.getDataField<float>(
      8 * ::capnp::ELEMENTS, 1150963712u);
}
inline void TestDefaults::Builder::setFloat32Field(float value) {
  _builder.setDataField<float>(
      8 * ::capnp::ELEMENTS, value, 1150963712u);
}


// TestDefaults::float64Field@11: Float64 = -1.23e47;  # bits[320, 384)

inline double TestDefaults::Reader::getFloat64Field() const {
  return _reader.getDataField<double>(
      5 * ::capnp::ELEMENTS, 14534676766106106624ul);
}

inline double TestDefaults::Builder::getFloat64Field() {
  return _builder.getDataField<double>(
      5 * ::capnp::ELEMENTS, 14534676766106106624ul);
}
inline void TestDefaults::Builder::setFloat64Field(double value) {
  _builder.setDataField<double>(
      5 * ::capnp::ELEMENTS, value, 14534676766106106624ul);
}


// TestDefaults::textField@12: Text = "foo";  # ptr[0]


inline bool TestDefaults::Reader::hasTextField() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasTextField() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestDefaults::Reader::getTextField() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS,
      DEFAULT_TEXT_FIELD.words, 3);
}

inline  ::capnp::Text::Builder TestDefaults::Builder::getTextField() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS,
      DEFAULT_TEXT_FIELD.words, 3);
}

inline void TestDefaults::Builder::setTextField( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestDefaults::Builder::initTextField(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestDefaults::dataField@13: Data = "bar";  # ptr[1]


inline bool TestDefaults::Reader::hasDataField() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasDataField() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::Data::Reader TestDefaults::Reader::getDataField() const {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(
      _reader, 1 * ::capnp::POINTERS,
      DEFAULT_DATA_FIELD.words, 3);
}

inline  ::capnp::Data::Builder TestDefaults::Builder::getDataField() {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::get(
      _builder, 1 * ::capnp::POINTERS,
      DEFAULT_DATA_FIELD.words, 3);
}

inline void TestDefaults::Builder::setDataField( ::capnp::Data::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Data>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::Data::Builder TestDefaults::Builder::initDataField(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Data>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestDefaults::structField@14: .TestAllTypes = (voidField = void, boolField = true, int8Field = -12, int16Field = 3456, int32Field = -78901234, int64Field = 56789012345678, uInt8Field = 90, uInt16Field = 1234, uInt32Field = 56789012, uInt64Field = 345678901234567890, float32Field = -1.25e-10, float64Field = 345.0, textField = "baz", dataField = "qux", structField = (textField = "nested", structField = (textField = "really nested")), enumField = baz, voidList = [void, void, void], boolList = [false, true, false, true, true], int8List = [12, -34, -128, 127], int16List = [1234, -5678, -32768, 32767], int32List = [12345678, -90123456, -2147483648, 2147483647], int64List = [123456789012345, -678901234567890, -9223372036854775808, 9223372036854775807], uInt8List = [12, 34, 0, 255], uInt16List = [1234, 5678, 0, 65535], uInt32List = [12345678, 90123456, 0, 4294967295], uInt64List = [123456789012345, 678901234567890, 0, 18446744073709551615], float32List = [0.0, 1234567.0, 1.0e37, -1.0e37, 1.0e-37, -1.0e-37], float64List = [0.0, 1.23456789012345e14, 1.0e306, -1.0e306, 1.0e-306, -1.0e-306], textList = ["quux", "corge", "grault"], dataList = ["garply", "waldo", "fred"], structList = [(textField = "x structlist 1"), (textField = "x structlist 2"), (textField = "x structlist 3")], enumList = [qux, bar, grault]);  # ptr[2]


inline bool TestDefaults::Reader::hasStructField() const {
  return !_reader.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasStructField() {
  return !_builder.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Reader TestDefaults::Reader::getStructField() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::get(
      _reader, 2 * ::capnp::POINTERS,
      DEFAULT_STRUCT_FIELD.words);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Builder TestDefaults::Builder::getStructField() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::get(
      _builder, 2 * ::capnp::POINTERS,
      DEFAULT_STRUCT_FIELD.words);
}

inline void TestDefaults::Builder::setStructField( ::capnproto_test::capnp::test::TestAllTypes::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::set(
      _builder, 2 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Builder TestDefaults::Builder::initStructField() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::init(
      _builder, 2 * ::capnp::POINTERS);
}



// TestDefaults::enumField@15: .TestEnum = corge;  # bits[288, 304)

inline  ::capnproto_test::capnp::test::TestEnum TestDefaults::Reader::getEnumField() const {
  return _reader.getDataField< ::capnproto_test::capnp::test::TestEnum>(
      18 * ::capnp::ELEMENTS, 5);
}

inline  ::capnproto_test::capnp::test::TestEnum TestDefaults::Builder::getEnumField() {
  return _builder.getDataField< ::capnproto_test::capnp::test::TestEnum>(
      18 * ::capnp::ELEMENTS, 5);
}
inline void TestDefaults::Builder::setEnumField( ::capnproto_test::capnp::test::TestEnum value) {
  _builder.setDataField< ::capnproto_test::capnp::test::TestEnum>(
      18 * ::capnp::ELEMENTS, value, 5);
}


// TestDefaults::interfaceField@16: Void;  # (none)

inline  ::capnp::Void TestDefaults::Reader::getInterfaceField() const {
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestDefaults::Builder::getInterfaceField() {
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestDefaults::Builder::setInterfaceField( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}


// TestDefaults::voidList@17: List(Void) = [void, void, void, void, void, void];  # ptr[3]


inline bool TestDefaults::Reader::hasVoidList() const {
  return !_reader.isPointerFieldNull(3 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasVoidList() {
  return !_builder.isPointerFieldNull(3 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Void>::Reader TestDefaults::Reader::getVoidList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::get(
      _reader, 3 * ::capnp::POINTERS,
      DEFAULT_VOID_LIST.words);
}

inline  ::capnp::List< ::capnp::Void>::Builder TestDefaults::Builder::getVoidList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::get(
      _builder, 3 * ::capnp::POINTERS,
      DEFAULT_VOID_LIST.words);
}

inline void TestDefaults::Builder::setVoidList( ::capnp::List< ::capnp::Void>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::set(
      _builder, 3 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setVoidList(
    std::initializer_list< ::capnp::Void> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::set(
      _builder, 3 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::Void>::Builder TestDefaults::Builder::initVoidList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::init(
      _builder, 3 * ::capnp::POINTERS, size);
}



// TestDefaults::boolList@18: List(Bool) = [true, false, false, true];  # ptr[4]


inline bool TestDefaults::Reader::hasBoolList() const {
  return !_reader.isPointerFieldNull(4 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasBoolList() {
  return !_builder.isPointerFieldNull(4 * ::capnp::POINTERS);
}

inline  ::capnp::List<bool>::Reader TestDefaults::Reader::getBoolList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List<bool>>::get(
      _reader, 4 * ::capnp::POINTERS,
      DEFAULT_BOOL_LIST.words);
}

inline  ::capnp::List<bool>::Builder TestDefaults::Builder::getBoolList() {
  return ::capnp::_::PointerHelpers< ::capnp::List<bool>>::get(
      _builder, 4 * ::capnp::POINTERS,
      DEFAULT_BOOL_LIST.words);
}

inline void TestDefaults::Builder::setBoolList( ::capnp::List<bool>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List<bool>>::set(
      _builder, 4 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setBoolList(
    std::initializer_list<bool> value) {
  ::capnp::_::PointerHelpers< ::capnp::List<bool>>::set(
      _builder, 4 * ::capnp::POINTERS, value);
}

inline  ::capnp::List<bool>::Builder TestDefaults::Builder::initBoolList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List<bool>>::init(
      _builder, 4 * ::capnp::POINTERS, size);
}



// TestDefaults::int8List@19: List(Int8) = [111, -111];  # ptr[5]


inline bool TestDefaults::Reader::hasInt8List() const {
  return !_reader.isPointerFieldNull(5 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasInt8List() {
  return !_builder.isPointerFieldNull(5 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int8_t>::Reader TestDefaults::Reader::getInt8List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::get(
      _reader, 5 * ::capnp::POINTERS,
      DEFAULT_INT8_LIST.words);
}

inline  ::capnp::List< ::int8_t>::Builder TestDefaults::Builder::getInt8List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::get(
      _builder, 5 * ::capnp::POINTERS,
      DEFAULT_INT8_LIST.words);
}

inline void TestDefaults::Builder::setInt8List( ::capnp::List< ::int8_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::set(
      _builder, 5 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setInt8List(
    std::initializer_list< ::int8_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::set(
      _builder, 5 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int8_t>::Builder TestDefaults::Builder::initInt8List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int8_t>>::init(
      _builder, 5 * ::capnp::POINTERS, size);
}



// TestDefaults::int16List@20: List(Int16) = [11111, -11111];  # ptr[6]


inline bool TestDefaults::Reader::hasInt16List() const {
  return !_reader.isPointerFieldNull(6 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasInt16List() {
  return !_builder.isPointerFieldNull(6 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int16_t>::Reader TestDefaults::Reader::getInt16List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::get(
      _reader, 6 * ::capnp::POINTERS,
      DEFAULT_INT16_LIST.words);
}

inline  ::capnp::List< ::int16_t>::Builder TestDefaults::Builder::getInt16List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::get(
      _builder, 6 * ::capnp::POINTERS,
      DEFAULT_INT16_LIST.words);
}

inline void TestDefaults::Builder::setInt16List( ::capnp::List< ::int16_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::set(
      _builder, 6 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setInt16List(
    std::initializer_list< ::int16_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::set(
      _builder, 6 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int16_t>::Builder TestDefaults::Builder::initInt16List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int16_t>>::init(
      _builder, 6 * ::capnp::POINTERS, size);
}



// TestDefaults::int32List@21: List(Int32) = [111111111, -111111111];  # ptr[7]


inline bool TestDefaults::Reader::hasInt32List() const {
  return !_reader.isPointerFieldNull(7 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasInt32List() {
  return !_builder.isPointerFieldNull(7 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int32_t>::Reader TestDefaults::Reader::getInt32List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::get(
      _reader, 7 * ::capnp::POINTERS,
      DEFAULT_INT32_LIST.words);
}

inline  ::capnp::List< ::int32_t>::Builder TestDefaults::Builder::getInt32List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::get(
      _builder, 7 * ::capnp::POINTERS,
      DEFAULT_INT32_LIST.words);
}

inline void TestDefaults::Builder::setInt32List( ::capnp::List< ::int32_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::set(
      _builder, 7 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setInt32List(
    std::initializer_list< ::int32_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::set(
      _builder, 7 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int32_t>::Builder TestDefaults::Builder::initInt32List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::init(
      _builder, 7 * ::capnp::POINTERS, size);
}



// TestDefaults::int64List@22: List(Int64) = [1111111111111111111, -1111111111111111111];  # ptr[8]


inline bool TestDefaults::Reader::hasInt64List() const {
  return !_reader.isPointerFieldNull(8 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasInt64List() {
  return !_builder.isPointerFieldNull(8 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int64_t>::Reader TestDefaults::Reader::getInt64List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::get(
      _reader, 8 * ::capnp::POINTERS,
      DEFAULT_INT64_LIST.words);
}

inline  ::capnp::List< ::int64_t>::Builder TestDefaults::Builder::getInt64List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::get(
      _builder, 8 * ::capnp::POINTERS,
      DEFAULT_INT64_LIST.words);
}

inline void TestDefaults::Builder::setInt64List( ::capnp::List< ::int64_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::set(
      _builder, 8 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setInt64List(
    std::initializer_list< ::int64_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::set(
      _builder, 8 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int64_t>::Builder TestDefaults::Builder::initInt64List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int64_t>>::init(
      _builder, 8 * ::capnp::POINTERS, size);
}



// TestDefaults::uInt8List@23: List(UInt8) = [111, 222];  # ptr[9]


inline bool TestDefaults::Reader::hasUInt8List() const {
  return !_reader.isPointerFieldNull(9 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasUInt8List() {
  return !_builder.isPointerFieldNull(9 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint8_t>::Reader TestDefaults::Reader::getUInt8List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::get(
      _reader, 9 * ::capnp::POINTERS,
      DEFAULT_U_INT8_LIST.words);
}

inline  ::capnp::List< ::uint8_t>::Builder TestDefaults::Builder::getUInt8List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::get(
      _builder, 9 * ::capnp::POINTERS,
      DEFAULT_U_INT8_LIST.words);
}

inline void TestDefaults::Builder::setUInt8List( ::capnp::List< ::uint8_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::set(
      _builder, 9 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setUInt8List(
    std::initializer_list< ::uint8_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::set(
      _builder, 9 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::uint8_t>::Builder TestDefaults::Builder::initUInt8List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint8_t>>::init(
      _builder, 9 * ::capnp::POINTERS, size);
}



// TestDefaults::uInt16List@24: List(UInt16) = [33333, 44444];  # ptr[10]


inline bool TestDefaults::Reader::hasUInt16List() const {
  return !_reader.isPointerFieldNull(10 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasUInt16List() {
  return !_builder.isPointerFieldNull(10 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint16_t>::Reader TestDefaults::Reader::getUInt16List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::get(
      _reader, 10 * ::capnp::POINTERS,
      DEFAULT_U_INT16_LIST.words);
}

inline  ::capnp::List< ::uint16_t>::Builder TestDefaults::Builder::getUInt16List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::get(
      _builder, 10 * ::capnp::POINTERS,
      DEFAULT_U_INT16_LIST.words);
}

inline void TestDefaults::Builder::setUInt16List( ::capnp::List< ::uint16_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::set(
      _builder, 10 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setUInt16List(
    std::initializer_list< ::uint16_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::set(
      _builder, 10 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::uint16_t>::Builder TestDefaults::Builder::initUInt16List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint16_t>>::init(
      _builder, 10 * ::capnp::POINTERS, size);
}



// TestDefaults::uInt32List@25: List(UInt32) = [3333333333];  # ptr[11]


inline bool TestDefaults::Reader::hasUInt32List() const {
  return !_reader.isPointerFieldNull(11 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasUInt32List() {
  return !_builder.isPointerFieldNull(11 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint32_t>::Reader TestDefaults::Reader::getUInt32List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::get(
      _reader, 11 * ::capnp::POINTERS,
      DEFAULT_U_INT32_LIST.words);
}

inline  ::capnp::List< ::uint32_t>::Builder TestDefaults::Builder::getUInt32List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::get(
      _builder, 11 * ::capnp::POINTERS,
      DEFAULT_U_INT32_LIST.words);
}

inline void TestDefaults::Builder::setUInt32List( ::capnp::List< ::uint32_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::set(
      _builder, 11 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setUInt32List(
    std::initializer_list< ::uint32_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::set(
      _builder, 11 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::uint32_t>::Builder TestDefaults::Builder::initUInt32List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint32_t>>::init(
      _builder, 11 * ::capnp::POINTERS, size);
}



// TestDefaults::uInt64List@26: List(UInt64) = [11111111111111111111];  # ptr[12]


inline bool TestDefaults::Reader::hasUInt64List() const {
  return !_reader.isPointerFieldNull(12 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasUInt64List() {
  return !_builder.isPointerFieldNull(12 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::uint64_t>::Reader TestDefaults::Reader::getUInt64List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::get(
      _reader, 12 * ::capnp::POINTERS,
      DEFAULT_U_INT64_LIST.words);
}

inline  ::capnp::List< ::uint64_t>::Builder TestDefaults::Builder::getUInt64List() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::get(
      _builder, 12 * ::capnp::POINTERS,
      DEFAULT_U_INT64_LIST.words);
}

inline void TestDefaults::Builder::setUInt64List( ::capnp::List< ::uint64_t>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::set(
      _builder, 12 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setUInt64List(
    std::initializer_list< ::uint64_t> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::set(
      _builder, 12 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::uint64_t>::Builder TestDefaults::Builder::initUInt64List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::uint64_t>>::init(
      _builder, 12 * ::capnp::POINTERS, size);
}



// TestDefaults::float32List@27: List(Float32) = [5555.5, Infinity, -Infinity, NaN];  # ptr[13]


inline bool TestDefaults::Reader::hasFloat32List() const {
  return !_reader.isPointerFieldNull(13 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasFloat32List() {
  return !_builder.isPointerFieldNull(13 * ::capnp::POINTERS);
}

inline  ::capnp::List<float>::Reader TestDefaults::Reader::getFloat32List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List<float>>::get(
      _reader, 13 * ::capnp::POINTERS,
      DEFAULT_FLOAT32_LIST.words);
}

inline  ::capnp::List<float>::Builder TestDefaults::Builder::getFloat32List() {
  return ::capnp::_::PointerHelpers< ::capnp::List<float>>::get(
      _builder, 13 * ::capnp::POINTERS,
      DEFAULT_FLOAT32_LIST.words);
}

inline void TestDefaults::Builder::setFloat32List( ::capnp::List<float>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List<float>>::set(
      _builder, 13 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setFloat32List(
    std::initializer_list<float> value) {
  ::capnp::_::PointerHelpers< ::capnp::List<float>>::set(
      _builder, 13 * ::capnp::POINTERS, value);
}

inline  ::capnp::List<float>::Builder TestDefaults::Builder::initFloat32List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List<float>>::init(
      _builder, 13 * ::capnp::POINTERS, size);
}



// TestDefaults::float64List@28: List(Float64) = [7777.75, Infinity, -Infinity, NaN];  # ptr[14]


inline bool TestDefaults::Reader::hasFloat64List() const {
  return !_reader.isPointerFieldNull(14 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasFloat64List() {
  return !_builder.isPointerFieldNull(14 * ::capnp::POINTERS);
}

inline  ::capnp::List<double>::Reader TestDefaults::Reader::getFloat64List() const {
  return ::capnp::_::PointerHelpers< ::capnp::List<double>>::get(
      _reader, 14 * ::capnp::POINTERS,
      DEFAULT_FLOAT64_LIST.words);
}

inline  ::capnp::List<double>::Builder TestDefaults::Builder::getFloat64List() {
  return ::capnp::_::PointerHelpers< ::capnp::List<double>>::get(
      _builder, 14 * ::capnp::POINTERS,
      DEFAULT_FLOAT64_LIST.words);
}

inline void TestDefaults::Builder::setFloat64List( ::capnp::List<double>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List<double>>::set(
      _builder, 14 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setFloat64List(
    std::initializer_list<double> value) {
  ::capnp::_::PointerHelpers< ::capnp::List<double>>::set(
      _builder, 14 * ::capnp::POINTERS, value);
}

inline  ::capnp::List<double>::Builder TestDefaults::Builder::initFloat64List(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List<double>>::init(
      _builder, 14 * ::capnp::POINTERS, size);
}



// TestDefaults::textList@29: List(Text) = ["plugh", "xyzzy", "thud"];  # ptr[15]


inline bool TestDefaults::Reader::hasTextList() const {
  return !_reader.isPointerFieldNull(15 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasTextList() {
  return !_builder.isPointerFieldNull(15 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Text>::Reader TestDefaults::Reader::getTextList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::get(
      _reader, 15 * ::capnp::POINTERS,
      DEFAULT_TEXT_LIST.words);
}

inline  ::capnp::List< ::capnp::Text>::Builder TestDefaults::Builder::getTextList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::get(
      _builder, 15 * ::capnp::POINTERS,
      DEFAULT_TEXT_LIST.words);
}

inline void TestDefaults::Builder::setTextList( ::capnp::List< ::capnp::Text>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::set(
      _builder, 15 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setTextList(
    std::initializer_list< ::capnp::Text::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::set(
      _builder, 15 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::Text>::Builder TestDefaults::Builder::initTextList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Text>>::init(
      _builder, 15 * ::capnp::POINTERS, size);
}



// TestDefaults::dataList@30: List(Data) = ["oops", "exhausted", "rfc3092"];  # ptr[16]


inline bool TestDefaults::Reader::hasDataList() const {
  return !_reader.isPointerFieldNull(16 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasDataList() {
  return !_builder.isPointerFieldNull(16 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Data>::Reader TestDefaults::Reader::getDataList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::get(
      _reader, 16 * ::capnp::POINTERS,
      DEFAULT_DATA_LIST.words);
}

inline  ::capnp::List< ::capnp::Data>::Builder TestDefaults::Builder::getDataList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::get(
      _builder, 16 * ::capnp::POINTERS,
      DEFAULT_DATA_LIST.words);
}

inline void TestDefaults::Builder::setDataList( ::capnp::List< ::capnp::Data>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::set(
      _builder, 16 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setDataList(
    std::initializer_list< ::capnp::Data::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::set(
      _builder, 16 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::Data>::Builder TestDefaults::Builder::initDataList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Data>>::init(
      _builder, 16 * ::capnp::POINTERS, size);
}



// TestDefaults::structList@31: List(.TestAllTypes) = [(textField = "structlist 1"), (textField = "structlist 2"), (textField = "structlist 3")];  # ptr[17]


inline bool TestDefaults::Reader::hasStructList() const {
  return !_reader.isPointerFieldNull(17 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasStructList() {
  return !_builder.isPointerFieldNull(17 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader TestDefaults::Reader::getStructList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::get(
      _reader, 17 * ::capnp::POINTERS,
      DEFAULT_STRUCT_LIST.words);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Builder TestDefaults::Builder::getStructList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::get(
      _builder, 17 * ::capnp::POINTERS,
      DEFAULT_STRUCT_LIST.words);
}

inline void TestDefaults::Builder::setStructList( ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::set(
      _builder, 17 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Builder TestDefaults::Builder::initStructList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::init(
      _builder, 17 * ::capnp::POINTERS, size);
}



// TestDefaults::enumList@32: List(.TestEnum) = [foo, garply];  # ptr[18]


inline bool TestDefaults::Reader::hasEnumList() const {
  return !_reader.isPointerFieldNull(18 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasEnumList() {
  return !_builder.isPointerFieldNull(18 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Reader TestDefaults::Reader::getEnumList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::get(
      _reader, 18 * ::capnp::POINTERS,
      DEFAULT_ENUM_LIST.words);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Builder TestDefaults::Builder::getEnumList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::get(
      _builder, 18 * ::capnp::POINTERS,
      DEFAULT_ENUM_LIST.words);
}

inline void TestDefaults::Builder::setEnumList( ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::set(
      _builder, 18 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setEnumList(
    std::initializer_list< ::capnproto_test::capnp::test::TestEnum> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::set(
      _builder, 18 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestEnum>::Builder TestDefaults::Builder::initEnumList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestEnum>>::init(
      _builder, 18 * ::capnp::POINTERS, size);
}



// TestDefaults::interfaceList@33: List(Void);  # ptr[19]


inline bool TestDefaults::Reader::hasInterfaceList() const {
  return !_reader.isPointerFieldNull(19 * ::capnp::POINTERS);
}

inline bool TestDefaults::Builder::hasInterfaceList() {
  return !_builder.isPointerFieldNull(19 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Void>::Reader TestDefaults::Reader::getInterfaceList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::get(
      _reader, 19 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::Void>::Builder TestDefaults::Builder::getInterfaceList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::get(
      _builder, 19 * ::capnp::POINTERS);
}

inline void TestDefaults::Builder::setInterfaceList( ::capnp::List< ::capnp::Void>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::set(
      _builder, 19 * ::capnp::POINTERS, value);
}

inline void TestDefaults::Builder::setInterfaceList(
    std::initializer_list< ::capnp::Void> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::set(
      _builder, 19 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::Void>::Builder TestDefaults::Builder::initInterfaceList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::Void>>::init(
      _builder, 19 * ::capnp::POINTERS, size);
}




// TestFieldZeroIsBit::bit@0: Bool;  # bits[0, 1)

inline bool TestFieldZeroIsBit::Reader::getBit() const {
  return _reader.getDataField<bool>(
      0 * ::capnp::ELEMENTS);
}

inline bool TestFieldZeroIsBit::Builder::getBit() {
  return _builder.getDataField<bool>(
      0 * ::capnp::ELEMENTS);
}
inline void TestFieldZeroIsBit::Builder::setBit(bool value) {
  _builder.setDataField<bool>(
      0 * ::capnp::ELEMENTS, value);
}


// TestFieldZeroIsBit::secondBit@1: Bool = true;  # bits[1, 2)

inline bool TestFieldZeroIsBit::Reader::getSecondBit() const {
  return _reader.getDataField<bool>(
      1 * ::capnp::ELEMENTS, true);
}

inline bool TestFieldZeroIsBit::Builder::getSecondBit() {
  return _builder.getDataField<bool>(
      1 * ::capnp::ELEMENTS, true);
}
inline void TestFieldZeroIsBit::Builder::setSecondBit(bool value) {
  _builder.setDataField<bool>(
      1 * ::capnp::ELEMENTS, value, true);
}


// TestFieldZeroIsBit::thirdField@2: UInt8 = 123;  # bits[8, 16)

inline  ::uint8_t TestFieldZeroIsBit::Reader::getThirdField() const {
  return _reader.getDataField< ::uint8_t>(
      1 * ::capnp::ELEMENTS, 123);
}

inline  ::uint8_t TestFieldZeroIsBit::Builder::getThirdField() {
  return _builder.getDataField< ::uint8_t>(
      1 * ::capnp::ELEMENTS, 123);
}
inline void TestFieldZeroIsBit::Builder::setThirdField( ::uint8_t value) {
  _builder.setDataField< ::uint8_t>(
      1 * ::capnp::ELEMENTS, value, 123);
}


inline TestLateUnion::TheUnion::Reader TestLateUnion::Reader::getTheUnion() const {
  return TestLateUnion::TheUnion::Reader(_reader);
}

inline TestLateUnion::TheUnion::Builder TestLateUnion::Builder::getTheUnion() {
  return TestLateUnion::TheUnion::Builder(_builder);
}

inline TestLateUnion::AnotherUnion::Reader TestLateUnion::Reader::getAnotherUnion() const {
  return TestLateUnion::AnotherUnion::Reader(_reader);
}

inline TestLateUnion::AnotherUnion::Builder TestLateUnion::Builder::getAnotherUnion() {
  return TestLateUnion::AnotherUnion::Builder(_builder);
}


// TestLateUnion::foo@0: Int32;  # bits[0, 32)

inline  ::int32_t TestLateUnion::Reader::getFoo() const {
  return _reader.getDataField< ::int32_t>(
      0 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestLateUnion::Builder::getFoo() {
  return _builder.getDataField< ::int32_t>(
      0 * ::capnp::ELEMENTS);
}
inline void TestLateUnion::Builder::setFoo( ::int32_t value) {
  _builder.setDataField< ::int32_t>(
      0 * ::capnp::ELEMENTS, value);
}


// TestLateUnion::bar@1: Text;  # ptr[0]


inline bool TestLateUnion::Reader::hasBar() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestLateUnion::Builder::hasBar() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestLateUnion::Reader::getBar() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestLateUnion::Builder::getBar() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestLateUnion::Builder::setBar( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestLateUnion::Builder::initBar(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestLateUnion::baz@2: Int16;  # bits[32, 48)

inline  ::int16_t TestLateUnion::Reader::getBaz() const {
  return _reader.getDataField< ::int16_t>(
      2 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestLateUnion::Builder::getBaz() {
  return _builder.getDataField< ::int16_t>(
      2 * ::capnp::ELEMENTS);
}
inline void TestLateUnion::Builder::setBaz( ::int16_t value) {
  _builder.setDataField< ::int16_t>(
      2 * ::capnp::ELEMENTS, value);
}


// TestLateUnion::AnotherUnion
inline TestLateUnion::AnotherUnion::Which TestLateUnion::AnotherUnion::Reader::which() const {
  return _reader.getDataField<Which>(6 * ::capnp::ELEMENTS);
}

inline TestLateUnion::AnotherUnion::Which TestLateUnion::AnotherUnion::Builder::which() {
  return _builder.getDataField<Which>(6 * ::capnp::ELEMENTS);
}


// TestLateUnion::AnotherUnion::qux@8: Text;  # ptr[2], union tag = 0


inline bool TestLateUnion::AnotherUnion::Reader::hasQux() const {
  return !_reader.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline bool TestLateUnion::AnotherUnion::Builder::hasQux() {
  return !_builder.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestLateUnion::AnotherUnion::Reader::getQux() const {
  KJ_IREQUIRE(which() == AnotherUnion::QUX,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 2 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestLateUnion::AnotherUnion::Builder::getQux() {
  KJ_IREQUIRE(which() == AnotherUnion::QUX,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 2 * ::capnp::POINTERS);
}

inline void TestLateUnion::AnotherUnion::Builder::setQux( ::capnp::Text::Reader value) {
  _builder.setDataField<AnotherUnion::Which>(
      6 * ::capnp::ELEMENTS, AnotherUnion::QUX);
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 2 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestLateUnion::AnotherUnion::Builder::initQux(unsigned int size) {
  _builder.setDataField<AnotherUnion::Which>(
      6 * ::capnp::ELEMENTS, AnotherUnion::QUX);
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 2 * ::capnp::POINTERS, size);
}



// TestLateUnion::AnotherUnion::corge@9: List(Int32);  # ptr[2], union tag = 1


inline bool TestLateUnion::AnotherUnion::Reader::hasCorge() const {
  return !_reader.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline bool TestLateUnion::AnotherUnion::Builder::hasCorge() {
  return !_builder.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int32_t>::Reader TestLateUnion::AnotherUnion::Reader::getCorge() const {
  KJ_IREQUIRE(which() == AnotherUnion::CORGE,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::get(
      _reader, 2 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int32_t>::Builder TestLateUnion::AnotherUnion::Builder::getCorge() {
  KJ_IREQUIRE(which() == AnotherUnion::CORGE,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::get(
      _builder, 2 * ::capnp::POINTERS);
}

inline void TestLateUnion::AnotherUnion::Builder::setCorge( ::capnp::List< ::int32_t>::Reader value) {
  _builder.setDataField<AnotherUnion::Which>(
      6 * ::capnp::ELEMENTS, AnotherUnion::CORGE);
  ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::set(
      _builder, 2 * ::capnp::POINTERS, value);
}

inline void TestLateUnion::AnotherUnion::Builder::setCorge(
    std::initializer_list< ::int32_t> value) {
  _builder.setDataField<AnotherUnion::Which>(
      6 * ::capnp::ELEMENTS, AnotherUnion::CORGE);
  ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::set(
      _builder, 2 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int32_t>::Builder TestLateUnion::AnotherUnion::Builder::initCorge(unsigned int size) {
  _builder.setDataField<AnotherUnion::Which>(
      6 * ::capnp::ELEMENTS, AnotherUnion::CORGE);
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::init(
      _builder, 2 * ::capnp::POINTERS, size);
}



// TestLateUnion::AnotherUnion::grault@10: Float32;  # bits[128, 160), union tag = 2

inline float TestLateUnion::AnotherUnion::Reader::getGrault() const {
  KJ_IREQUIRE(which() == AnotherUnion::GRAULT,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<float>(
      4 * ::capnp::ELEMENTS);
}

inline float TestLateUnion::AnotherUnion::Builder::getGrault() {
  KJ_IREQUIRE(which() == AnotherUnion::GRAULT,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<float>(
      4 * ::capnp::ELEMENTS);
}
inline void TestLateUnion::AnotherUnion::Builder::setGrault(float value) {
  _builder.setDataField<AnotherUnion::Which>(
      6 * ::capnp::ELEMENTS, AnotherUnion::GRAULT);
  _builder.setDataField<float>(
      4 * ::capnp::ELEMENTS, value);
}


// TestLateUnion::TheUnion
inline TestLateUnion::TheUnion::Which TestLateUnion::TheUnion::Reader::which() const {
  return _reader.getDataField<Which>(3 * ::capnp::ELEMENTS);
}

inline TestLateUnion::TheUnion::Which TestLateUnion::TheUnion::Builder::which() {
  return _builder.getDataField<Which>(3 * ::capnp::ELEMENTS);
}


// TestLateUnion::TheUnion::qux@4: Text;  # ptr[1], union tag = 0


inline bool TestLateUnion::TheUnion::Reader::hasQux() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestLateUnion::TheUnion::Builder::hasQux() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestLateUnion::TheUnion::Reader::getQux() const {
  KJ_IREQUIRE(which() == TheUnion::QUX,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestLateUnion::TheUnion::Builder::getQux() {
  KJ_IREQUIRE(which() == TheUnion::QUX,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestLateUnion::TheUnion::Builder::setQux( ::capnp::Text::Reader value) {
  _builder.setDataField<TheUnion::Which>(
      3 * ::capnp::ELEMENTS, TheUnion::QUX);
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestLateUnion::TheUnion::Builder::initQux(unsigned int size) {
  _builder.setDataField<TheUnion::Which>(
      3 * ::capnp::ELEMENTS, TheUnion::QUX);
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestLateUnion::TheUnion::corge@5: List(Int32);  # ptr[1], union tag = 1


inline bool TestLateUnion::TheUnion::Reader::hasCorge() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestLateUnion::TheUnion::Builder::hasCorge() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int32_t>::Reader TestLateUnion::TheUnion::Reader::getCorge() const {
  KJ_IREQUIRE(which() == TheUnion::CORGE,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::int32_t>::Builder TestLateUnion::TheUnion::Builder::getCorge() {
  KJ_IREQUIRE(which() == TheUnion::CORGE,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestLateUnion::TheUnion::Builder::setCorge( ::capnp::List< ::int32_t>::Reader value) {
  _builder.setDataField<TheUnion::Which>(
      3 * ::capnp::ELEMENTS, TheUnion::CORGE);
  ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline void TestLateUnion::TheUnion::Builder::setCorge(
    std::initializer_list< ::int32_t> value) {
  _builder.setDataField<TheUnion::Which>(
      3 * ::capnp::ELEMENTS, TheUnion::CORGE);
  ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::int32_t>::Builder TestLateUnion::TheUnion::Builder::initCorge(unsigned int size) {
  _builder.setDataField<TheUnion::Which>(
      3 * ::capnp::ELEMENTS, TheUnion::CORGE);
  return ::capnp::_::PointerHelpers< ::capnp::List< ::int32_t>>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestLateUnion::TheUnion::grault@6: Float32;  # bits[64, 96), union tag = 2

inline float TestLateUnion::TheUnion::Reader::getGrault() const {
  KJ_IREQUIRE(which() == TheUnion::GRAULT,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<float>(
      2 * ::capnp::ELEMENTS);
}

inline float TestLateUnion::TheUnion::Builder::getGrault() {
  KJ_IREQUIRE(which() == TheUnion::GRAULT,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<float>(
      2 * ::capnp::ELEMENTS);
}
inline void TestLateUnion::TheUnion::Builder::setGrault(float value) {
  _builder.setDataField<TheUnion::Which>(
      3 * ::capnp::ELEMENTS, TheUnion::GRAULT);
  _builder.setDataField<float>(
      2 * ::capnp::ELEMENTS, value);
}



// TestListDefaults::lists@0: .TestLists = (list0 = [(f = void), (f = void)], list1 = [(f = true), (f = false), (f = true), (f = true)], list8 = [(f = 123), (f = 45)], list16 = [(f = 12345), (f = 6789)], list32 = [(f = 123456789), (f = 234567890)], list64 = [(f = 1234567890123456), (f = 2345678901234567)], listP = [(f = "foo"), (f = "bar")], int32ListList = [[1, 2, 3], [4, 5], [12341234]], textListList = [["foo", "bar"], ["baz"], ["qux", "corge"]], structListList = [[(int32Field = 123), (int32Field = 456)], [(int32Field = 789)]]);  # ptr[0]


inline bool TestListDefaults::Reader::hasLists() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestListDefaults::Builder::hasLists() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestLists::Reader TestListDefaults::Reader::getLists() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestLists>::get(
      _reader, 0 * ::capnp::POINTERS,
      DEFAULT_LISTS.words);
}

inline  ::capnproto_test::capnp::test::TestLists::Builder TestListDefaults::Builder::getLists() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestLists>::get(
      _builder, 0 * ::capnp::POINTERS,
      DEFAULT_LISTS.words);
}

inline void TestListDefaults::Builder::setLists( ::capnproto_test::capnp::test::TestLists::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestLists>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestLists::Builder TestListDefaults::Builder::initLists() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestLists>::init(
      _builder, 0 * ::capnp::POINTERS);
}




// TestLists::list0@0: List(.TestLists.Struct0);  # ptr[0]


inline bool TestLists::Reader::hasList0() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasList0() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>::Reader TestLists::Reader::getList0() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>::Builder TestLists::Builder::getList0() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setList0( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>::Builder TestLists::Builder::initList0(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct0>>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestLists::list1@1: List(.TestLists.Struct1);  # ptr[1]


inline bool TestLists::Reader::hasList1() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasList1() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>::Reader TestLists::Reader::getList1() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>::Builder TestLists::Builder::getList1() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setList1( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>::Builder TestLists::Builder::initList1(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct1>>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestLists::list8@2: List(.TestLists.Struct8);  # ptr[2]


inline bool TestLists::Reader::hasList8() const {
  return !_reader.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasList8() {
  return !_builder.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>::Reader TestLists::Reader::getList8() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>>::get(
      _reader, 2 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>::Builder TestLists::Builder::getList8() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>>::get(
      _builder, 2 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setList8( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>>::set(
      _builder, 2 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>::Builder TestLists::Builder::initList8(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct8>>::init(
      _builder, 2 * ::capnp::POINTERS, size);
}



// TestLists::list16@3: List(.TestLists.Struct16);  # ptr[3]


inline bool TestLists::Reader::hasList16() const {
  return !_reader.isPointerFieldNull(3 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasList16() {
  return !_builder.isPointerFieldNull(3 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>::Reader TestLists::Reader::getList16() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>>::get(
      _reader, 3 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>::Builder TestLists::Builder::getList16() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>>::get(
      _builder, 3 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setList16( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>>::set(
      _builder, 3 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>::Builder TestLists::Builder::initList16(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct16>>::init(
      _builder, 3 * ::capnp::POINTERS, size);
}



// TestLists::list32@4: List(.TestLists.Struct32);  # ptr[4]


inline bool TestLists::Reader::hasList32() const {
  return !_reader.isPointerFieldNull(4 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasList32() {
  return !_builder.isPointerFieldNull(4 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>::Reader TestLists::Reader::getList32() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>>::get(
      _reader, 4 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>::Builder TestLists::Builder::getList32() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>>::get(
      _builder, 4 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setList32( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>>::set(
      _builder, 4 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>::Builder TestLists::Builder::initList32(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct32>>::init(
      _builder, 4 * ::capnp::POINTERS, size);
}



// TestLists::list64@5: List(.TestLists.Struct64);  # ptr[5]


inline bool TestLists::Reader::hasList64() const {
  return !_reader.isPointerFieldNull(5 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasList64() {
  return !_builder.isPointerFieldNull(5 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>::Reader TestLists::Reader::getList64() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>>::get(
      _reader, 5 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>::Builder TestLists::Builder::getList64() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>>::get(
      _builder, 5 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setList64( ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>>::set(
      _builder, 5 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>::Builder TestLists::Builder::initList64(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::Struct64>>::init(
      _builder, 5 * ::capnp::POINTERS, size);
}



// TestLists::listP@6: List(.TestLists.StructP);  # ptr[6]


inline bool TestLists::Reader::hasListP() const {
  return !_reader.isPointerFieldNull(6 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasListP() {
  return !_builder.isPointerFieldNull(6 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>::Reader TestLists::Reader::getListP() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>>::get(
      _reader, 6 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>::Builder TestLists::Builder::getListP() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>>::get(
      _builder, 6 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setListP( ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>>::set(
      _builder, 6 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>::Builder TestLists::Builder::initListP(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnproto_test::capnp::test::TestLists::StructP>>::init(
      _builder, 6 * ::capnp::POINTERS, size);
}



// TestLists::int32ListList@7: List(List(Int32));  # ptr[7]


inline bool TestLists::Reader::hasInt32ListList() const {
  return !_reader.isPointerFieldNull(7 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasInt32ListList() {
  return !_builder.isPointerFieldNull(7 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::List< ::int32_t>>::Reader TestLists::Reader::getInt32ListList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::int32_t>>>::get(
      _reader, 7 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::List< ::int32_t>>::Builder TestLists::Builder::getInt32ListList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::int32_t>>>::get(
      _builder, 7 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setInt32ListList( ::capnp::List< ::capnp::List< ::int32_t>>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::int32_t>>>::set(
      _builder, 7 * ::capnp::POINTERS, value);
}

inline void TestLists::Builder::setInt32ListList(
    std::initializer_list< ::capnp::List< ::int32_t>::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::int32_t>>>::set(
      _builder, 7 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::List< ::int32_t>>::Builder TestLists::Builder::initInt32ListList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::int32_t>>>::init(
      _builder, 7 * ::capnp::POINTERS, size);
}



// TestLists::textListList@8: List(List(Text));  # ptr[8]


inline bool TestLists::Reader::hasTextListList() const {
  return !_reader.isPointerFieldNull(8 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasTextListList() {
  return !_builder.isPointerFieldNull(8 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::List< ::capnp::Text>>::Reader TestLists::Reader::getTextListList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnp::Text>>>::get(
      _reader, 8 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::List< ::capnp::Text>>::Builder TestLists::Builder::getTextListList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnp::Text>>>::get(
      _builder, 8 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setTextListList( ::capnp::List< ::capnp::List< ::capnp::Text>>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnp::Text>>>::set(
      _builder, 8 * ::capnp::POINTERS, value);
}

inline void TestLists::Builder::setTextListList(
    std::initializer_list< ::capnp::List< ::capnp::Text>::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnp::Text>>>::set(
      _builder, 8 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::List< ::capnp::Text>>::Builder TestLists::Builder::initTextListList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnp::Text>>>::init(
      _builder, 8 * ::capnp::POINTERS, size);
}



// TestLists::structListList@9: List(List(.TestAllTypes));  # ptr[9]


inline bool TestLists::Reader::hasStructListList() const {
  return !_reader.isPointerFieldNull(9 * ::capnp::POINTERS);
}

inline bool TestLists::Builder::hasStructListList() {
  return !_builder.isPointerFieldNull(9 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::Reader TestLists::Reader::getStructListList() const {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>>::get(
      _reader, 9 * ::capnp::POINTERS);
}

inline  ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::Builder TestLists::Builder::getStructListList() {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>>::get(
      _builder, 9 * ::capnp::POINTERS);
}

inline void TestLists::Builder::setStructListList( ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>>::set(
      _builder, 9 * ::capnp::POINTERS, value);
}

inline void TestLists::Builder::setStructListList(
    std::initializer_list< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>::Reader> value) {
  ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>>::set(
      _builder, 9 * ::capnp::POINTERS, value);
}

inline  ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>::Builder TestLists::Builder::initStructListList(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::List< ::capnp::List< ::capnproto_test::capnp::test::TestAllTypes>>>::init(
      _builder, 9 * ::capnp::POINTERS, size);
}




// TestLists::Struct0::f@0: Void;  # (none)

inline  ::capnp::Void TestLists::Struct0::Reader::getF() const {
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestLists::Struct0::Builder::getF() {
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestLists::Struct0::Builder::setF( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}



// TestLists::Struct1::f@0: Bool;  # bits[0, 1)

inline bool TestLists::Struct1::Reader::getF() const {
  return _reader.getDataField<bool>(
      0 * ::capnp::ELEMENTS);
}

inline bool TestLists::Struct1::Builder::getF() {
  return _builder.getDataField<bool>(
      0 * ::capnp::ELEMENTS);
}
inline void TestLists::Struct1::Builder::setF(bool value) {
  _builder.setDataField<bool>(
      0 * ::capnp::ELEMENTS, value);
}



// TestLists::Struct16::f@0: UInt16;  # bits[0, 16)

inline  ::uint16_t TestLists::Struct16::Reader::getF() const {
  return _reader.getDataField< ::uint16_t>(
      0 * ::capnp::ELEMENTS);
}

inline  ::uint16_t TestLists::Struct16::Builder::getF() {
  return _builder.getDataField< ::uint16_t>(
      0 * ::capnp::ELEMENTS);
}
inline void TestLists::Struct16::Builder::setF( ::uint16_t value) {
  _builder.setDataField< ::uint16_t>(
      0 * ::capnp::ELEMENTS, value);
}



// TestLists::Struct32::f@0: UInt32;  # bits[0, 32)

inline  ::uint32_t TestLists::Struct32::Reader::getF() const {
  return _reader.getDataField< ::uint32_t>(
      0 * ::capnp::ELEMENTS);
}

inline  ::uint32_t TestLists::Struct32::Builder::getF() {
  return _builder.getDataField< ::uint32_t>(
      0 * ::capnp::ELEMENTS);
}
inline void TestLists::Struct32::Builder::setF( ::uint32_t value) {
  _builder.setDataField< ::uint32_t>(
      0 * ::capnp::ELEMENTS, value);
}



// TestLists::Struct64::f@0: UInt64;  # bits[0, 64)

inline  ::uint64_t TestLists::Struct64::Reader::getF() const {
  return _reader.getDataField< ::uint64_t>(
      0 * ::capnp::ELEMENTS);
}

inline  ::uint64_t TestLists::Struct64::Builder::getF() {
  return _builder.getDataField< ::uint64_t>(
      0 * ::capnp::ELEMENTS);
}
inline void TestLists::Struct64::Builder::setF( ::uint64_t value) {
  _builder.setDataField< ::uint64_t>(
      0 * ::capnp::ELEMENTS, value);
}



// TestLists::Struct8::f@0: UInt8;  # bits[0, 8)

inline  ::uint8_t TestLists::Struct8::Reader::getF() const {
  return _reader.getDataField< ::uint8_t>(
      0 * ::capnp::ELEMENTS);
}

inline  ::uint8_t TestLists::Struct8::Builder::getF() {
  return _builder.getDataField< ::uint8_t>(
      0 * ::capnp::ELEMENTS);
}
inline void TestLists::Struct8::Builder::setF( ::uint8_t value) {
  _builder.setDataField< ::uint8_t>(
      0 * ::capnp::ELEMENTS, value);
}



// TestLists::StructP::f@0: Text;  # ptr[0]


inline bool TestLists::StructP::Reader::hasF() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestLists::StructP::Builder::hasF() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestLists::StructP::Reader::getF() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestLists::StructP::Builder::getF() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestLists::StructP::Builder::setF( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestLists::StructP::Builder::initF(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}




// TestNestedTypes::nestedStruct@0: .TestNestedTypes.NestedStruct;  # ptr[0]


inline bool TestNestedTypes::Reader::hasNestedStruct() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestNestedTypes::Builder::hasNestedStruct() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::Reader TestNestedTypes::Reader::getNestedStruct() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::Builder TestNestedTypes::Builder::getNestedStruct() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestNestedTypes::Builder::setNestedStruct( ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::Builder TestNestedTypes::Builder::initNestedStruct() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct>::init(
      _builder, 0 * ::capnp::POINTERS);
}



// TestNestedTypes::outerNestedEnum@1: .TestNestedTypes.NestedEnum = bar;  # bits[0, 16)

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum TestNestedTypes::Reader::getOuterNestedEnum() const {
  return _reader.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      0 * ::capnp::ELEMENTS, 1);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum TestNestedTypes::Builder::getOuterNestedEnum() {
  return _builder.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      0 * ::capnp::ELEMENTS, 1);
}
inline void TestNestedTypes::Builder::setOuterNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum value) {
  _builder.setDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      0 * ::capnp::ELEMENTS, value, 1);
}


// TestNestedTypes::innerNestedEnum@2: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[16, 32)

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum TestNestedTypes::Reader::getInnerNestedEnum() const {
  return _reader.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      1 * ::capnp::ELEMENTS, 2);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum TestNestedTypes::Builder::getInnerNestedEnum() {
  return _builder.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      1 * ::capnp::ELEMENTS, 2);
}
inline void TestNestedTypes::Builder::setInnerNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum value) {
  _builder.setDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      1 * ::capnp::ELEMENTS, value, 2);
}



// TestNestedTypes::NestedStruct::outerNestedEnum@0: .TestNestedTypes.NestedEnum = bar;  # bits[0, 16)

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum TestNestedTypes::NestedStruct::Reader::getOuterNestedEnum() const {
  return _reader.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      0 * ::capnp::ELEMENTS, 1);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum TestNestedTypes::NestedStruct::Builder::getOuterNestedEnum() {
  return _builder.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      0 * ::capnp::ELEMENTS, 1);
}
inline void TestNestedTypes::NestedStruct::Builder::setOuterNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum value) {
  _builder.setDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      0 * ::capnp::ELEMENTS, value, 1);
}


// TestNestedTypes::NestedStruct::innerNestedEnum@1: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[16, 32)

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum TestNestedTypes::NestedStruct::Reader::getInnerNestedEnum() const {
  return _reader.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      1 * ::capnp::ELEMENTS, 2);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum TestNestedTypes::NestedStruct::Builder::getInnerNestedEnum() {
  return _builder.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      1 * ::capnp::ELEMENTS, 2);
}
inline void TestNestedTypes::NestedStruct::Builder::setInnerNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum value) {
  _builder.setDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      1 * ::capnp::ELEMENTS, value, 2);
}



// TestNewVersion::old1@0: Int64;  # bits[0, 64)

inline  ::int64_t TestNewVersion::Reader::getOld1() const {
  return _reader.getDataField< ::int64_t>(
      0 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestNewVersion::Builder::getOld1() {
  return _builder.getDataField< ::int64_t>(
      0 * ::capnp::ELEMENTS);
}
inline void TestNewVersion::Builder::setOld1( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      0 * ::capnp::ELEMENTS, value);
}


// TestNewVersion::old2@1: Text;  # ptr[0]


inline bool TestNewVersion::Reader::hasOld2() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestNewVersion::Builder::hasOld2() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestNewVersion::Reader::getOld2() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestNewVersion::Builder::getOld2() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestNewVersion::Builder::setOld2( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestNewVersion::Builder::initOld2(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestNewVersion::old3@2: .TestNewVersion;  # ptr[1]


inline bool TestNewVersion::Reader::hasOld3() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestNewVersion::Builder::hasOld3() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestNewVersion::Reader TestNewVersion::Reader::getOld3() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestNewVersion>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestNewVersion::Builder TestNewVersion::Builder::getOld3() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestNewVersion>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestNewVersion::Builder::setOld3( ::capnproto_test::capnp::test::TestNewVersion::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestNewVersion>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestNewVersion::Builder TestNewVersion::Builder::initOld3() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestNewVersion>::init(
      _builder, 1 * ::capnp::POINTERS);
}



// TestNewVersion::new1@3: Int64 = 987;  # bits[64, 128)

inline  ::int64_t TestNewVersion::Reader::getNew1() const {
  return _reader.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, 987ll);
}

inline  ::int64_t TestNewVersion::Builder::getNew1() {
  return _builder.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, 987ll);
}
inline void TestNewVersion::Builder::setNew1( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, value, 987ll);
}


// TestNewVersion::new2@4: Text = "baz";  # ptr[2]


inline bool TestNewVersion::Reader::hasNew2() const {
  return !_reader.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline bool TestNewVersion::Builder::hasNew2() {
  return !_builder.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestNewVersion::Reader::getNew2() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 2 * ::capnp::POINTERS,
      DEFAULT_NEW2.words, 3);
}

inline  ::capnp::Text::Builder TestNewVersion::Builder::getNew2() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 2 * ::capnp::POINTERS,
      DEFAULT_NEW2.words, 3);
}

inline void TestNewVersion::Builder::setNew2( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 2 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestNewVersion::Builder::initNew2(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 2 * ::capnp::POINTERS, size);
}




// TestObject::objectField@0: Object;  # ptr[0]


inline bool TestObject::Reader::hasObjectField() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestObject::Builder::hasObjectField() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}


template <typename T>
inline typename T::Reader TestObject::Reader::getObjectField() const {
  return ::capnp::_::PointerHelpers<T>::get(
      _reader, 0 * ::capnp::POINTERS);
}

template <typename T>
inline typename T::Builder TestObject::Builder::getObjectField() {
  return ::capnp::_::PointerHelpers<T>::get(
      _builder, 0 * ::capnp::POINTERS);
}

template <typename T, typename Param>
inline typename T::Reader TestObject::Reader::getObjectField(Param&& param) const {
  return ::capnp::_::PointerHelpers<T>::getDynamic(
      _reader, 0 * ::capnp::POINTERS, ::kj::fwd<Param>(param));
}

template <typename T, typename Param>
inline typename T::Builder TestObject::Builder::getObjectField(Param&& param) {
  return ::capnp::_::PointerHelpers<T>::getDynamic(
      _builder, 0 * ::capnp::POINTERS, ::kj::fwd<Param>(param));
}

template <typename T>
inline void TestObject::Builder::setObjectField(typename T::Reader value) {
  ::capnp::_::PointerHelpers<T>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

template <typename T, typename U>
inline void TestObject::Builder::setObjectField(std::initializer_list<U> value) {
  ::capnp::_::PointerHelpers<T>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

template <typename T, typename... Params>
inline typename T::Builder TestObject::Builder::initObjectField(Params&&... params) {
  return ::capnp::_::PointerHelpers<T>::init(
      _builder, 0 * ::capnp::POINTERS, ::kj::fwd<Params>(params)...);
}



// TestOldVersion::old1@0: Int64;  # bits[0, 64)

inline  ::int64_t TestOldVersion::Reader::getOld1() const {
  return _reader.getDataField< ::int64_t>(
      0 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestOldVersion::Builder::getOld1() {
  return _builder.getDataField< ::int64_t>(
      0 * ::capnp::ELEMENTS);
}
inline void TestOldVersion::Builder::setOld1( ::int64_t value) {
  _builder.setDataField< ::int64_t>(
      0 * ::capnp::ELEMENTS, value);
}


// TestOldVersion::old2@1: Text;  # ptr[0]


inline bool TestOldVersion::Reader::hasOld2() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestOldVersion::Builder::hasOld2() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOldVersion::Reader::getOld2() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOldVersion::Builder::getOld2() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestOldVersion::Builder::setOld2( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOldVersion::Builder::initOld2(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestOldVersion::old3@2: .TestOldVersion;  # ptr[1]


inline bool TestOldVersion::Reader::hasOld3() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestOldVersion::Builder::hasOld3() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestOldVersion::Reader TestOldVersion::Reader::getOld3() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestOldVersion>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestOldVersion::Builder TestOldVersion::Builder::getOld3() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestOldVersion>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestOldVersion::Builder::setOld3( ::capnproto_test::capnp::test::TestOldVersion::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestOldVersion>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestOldVersion::Builder TestOldVersion::Builder::initOld3() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestOldVersion>::init(
      _builder, 1 * ::capnp::POINTERS);
}




// TestOutOfOrder::foo@3: Text;  # ptr[3]


inline bool TestOutOfOrder::Reader::hasFoo() const {
  return !_reader.isPointerFieldNull(3 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasFoo() {
  return !_builder.isPointerFieldNull(3 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getFoo() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 3 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getFoo() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 3 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setFoo( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 3 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initFoo(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 3 * ::capnp::POINTERS, size);
}



// TestOutOfOrder::bar@2: Text;  # ptr[2]


inline bool TestOutOfOrder::Reader::hasBar() const {
  return !_reader.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasBar() {
  return !_builder.isPointerFieldNull(2 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getBar() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 2 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getBar() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 2 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setBar( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 2 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initBar(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 2 * ::capnp::POINTERS, size);
}



// TestOutOfOrder::baz@8: Text;  # ptr[8]


inline bool TestOutOfOrder::Reader::hasBaz() const {
  return !_reader.isPointerFieldNull(8 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasBaz() {
  return !_builder.isPointerFieldNull(8 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getBaz() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 8 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getBaz() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 8 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setBaz( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 8 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initBaz(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 8 * ::capnp::POINTERS, size);
}



// TestOutOfOrder::qux@0: Text;  # ptr[0]


inline bool TestOutOfOrder::Reader::hasQux() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasQux() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getQux() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getQux() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setQux( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initQux(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestOutOfOrder::quux@6: Text;  # ptr[6]


inline bool TestOutOfOrder::Reader::hasQuux() const {
  return !_reader.isPointerFieldNull(6 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasQuux() {
  return !_builder.isPointerFieldNull(6 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getQuux() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 6 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getQuux() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 6 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setQuux( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 6 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initQuux(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 6 * ::capnp::POINTERS, size);
}



// TestOutOfOrder::corge@4: Text;  # ptr[4]


inline bool TestOutOfOrder::Reader::hasCorge() const {
  return !_reader.isPointerFieldNull(4 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasCorge() {
  return !_builder.isPointerFieldNull(4 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getCorge() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 4 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getCorge() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 4 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setCorge( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 4 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initCorge(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 4 * ::capnp::POINTERS, size);
}



// TestOutOfOrder::grault@1: Text;  # ptr[1]


inline bool TestOutOfOrder::Reader::hasGrault() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasGrault() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getGrault() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getGrault() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setGrault( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initGrault(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestOutOfOrder::garply@7: Text;  # ptr[7]


inline bool TestOutOfOrder::Reader::hasGarply() const {
  return !_reader.isPointerFieldNull(7 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasGarply() {
  return !_builder.isPointerFieldNull(7 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getGarply() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 7 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getGarply() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 7 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setGarply( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 7 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initGarply(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 7 * ::capnp::POINTERS, size);
}



// TestOutOfOrder::waldo@5: Text;  # ptr[5]


inline bool TestOutOfOrder::Reader::hasWaldo() const {
  return !_reader.isPointerFieldNull(5 * ::capnp::POINTERS);
}

inline bool TestOutOfOrder::Builder::hasWaldo() {
  return !_builder.isPointerFieldNull(5 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestOutOfOrder::Reader::getWaldo() const {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 5 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::getWaldo() {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 5 * ::capnp::POINTERS);
}

inline void TestOutOfOrder::Builder::setWaldo( ::capnp::Text::Reader value) {
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 5 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestOutOfOrder::Builder::initWaldo(unsigned int size) {
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 5 * ::capnp::POINTERS, size);
}



inline TestUnion::Union0::Reader TestUnion::Reader::getUnion0() const {
  return TestUnion::Union0::Reader(_reader);
}

inline TestUnion::Union0::Builder TestUnion::Builder::getUnion0() {
  return TestUnion::Union0::Builder(_builder);
}

inline TestUnion::Union1::Reader TestUnion::Reader::getUnion1() const {
  return TestUnion::Union1::Reader(_reader);
}

inline TestUnion::Union1::Builder TestUnion::Builder::getUnion1() {
  return TestUnion::Union1::Builder(_builder);
}

inline TestUnion::Union2::Reader TestUnion::Reader::getUnion2() const {
  return TestUnion::Union2::Reader(_reader);
}

inline TestUnion::Union2::Builder TestUnion::Builder::getUnion2() {
  return TestUnion::Union2::Builder(_builder);
}

inline TestUnion::Union3::Reader TestUnion::Reader::getUnion3() const {
  return TestUnion::Union3::Reader(_reader);
}

inline TestUnion::Union3::Builder TestUnion::Builder::getUnion3() {
  return TestUnion::Union3::Builder(_builder);
}


// TestUnion::bit0@18: Bool;  # bits[128, 129)

inline bool TestUnion::Reader::getBit0() const {
  return _reader.getDataField<bool>(
      128 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Builder::getBit0() {
  return _builder.getDataField<bool>(
      128 * ::capnp::ELEMENTS);
}
inline void TestUnion::Builder::setBit0(bool value) {
  _builder.setDataField<bool>(
      128 * ::capnp::ELEMENTS, value);
}


// TestUnion::bit2@39: Bool;  # bits[130, 131)

inline bool TestUnion::Reader::getBit2() const {
  return _reader.getDataField<bool>(
      130 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Builder::getBit2() {
  return _builder.getDataField<bool>(
      130 * ::capnp::ELEMENTS);
}
inline void TestUnion::Builder::setBit2(bool value) {
  _builder.setDataField<bool>(
      130 * ::capnp::ELEMENTS, value);
}


// TestUnion::bit3@40: Bool;  # bits[131, 132)

inline bool TestUnion::Reader::getBit3() const {
  return _reader.getDataField<bool>(
      131 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Builder::getBit3() {
  return _builder.getDataField<bool>(
      131 * ::capnp::ELEMENTS);
}
inline void TestUnion::Builder::setBit3(bool value) {
  _builder.setDataField<bool>(
      131 * ::capnp::ELEMENTS, value);
}


// TestUnion::bit4@41: Bool;  # bits[132, 133)

inline bool TestUnion::Reader::getBit4() const {
  return _reader.getDataField<bool>(
      132 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Builder::getBit4() {
  return _builder.getDataField<bool>(
      132 * ::capnp::ELEMENTS);
}
inline void TestUnion::Builder::setBit4(bool value) {
  _builder.setDataField<bool>(
      132 * ::capnp::ELEMENTS, value);
}


// TestUnion::bit5@42: Bool;  # bits[133, 134)

inline bool TestUnion::Reader::getBit5() const {
  return _reader.getDataField<bool>(
      133 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Builder::getBit5() {
  return _builder.getDataField<bool>(
      133 * ::capnp::ELEMENTS);
}
inline void TestUnion::Builder::setBit5(bool value) {
  _builder.setDataField<bool>(
      133 * ::capnp::ELEMENTS, value);
}


// TestUnion::bit6@43: Bool;  # bits[134, 135)

inline bool TestUnion::Reader::getBit6() const {
  return _reader.getDataField<bool>(
      134 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Builder::getBit6() {
  return _builder.getDataField<bool>(
      134 * ::capnp::ELEMENTS);
}
inline void TestUnion::Builder::setBit6(bool value) {
  _builder.setDataField<bool>(
      134 * ::capnp::ELEMENTS, value);
}


// TestUnion::bit7@44: Bool;  # bits[135, 136)

inline bool TestUnion::Reader::getBit7() const {
  return _reader.getDataField<bool>(
      135 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Builder::getBit7() {
  return _builder.getDataField<bool>(
      135 * ::capnp::ELEMENTS);
}
inline void TestUnion::Builder::setBit7(bool value) {
  _builder.setDataField<bool>(
      135 * ::capnp::ELEMENTS, value);
}


// TestUnion::byte0@49: UInt8;  # bits[280, 288)

inline  ::uint8_t TestUnion::Reader::getByte0() const {
  return _reader.getDataField< ::uint8_t>(
      35 * ::capnp::ELEMENTS);
}

inline  ::uint8_t TestUnion::Builder::getByte0() {
  return _builder.getDataField< ::uint8_t>(
      35 * ::capnp::ELEMENTS);
}
inline void TestUnion::Builder::setByte0( ::uint8_t value) {
  _builder.setDataField< ::uint8_t>(
      35 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0
inline TestUnion::Union0::Which TestUnion::Union0::Reader::which() const {
  return _reader.getDataField<Which>(0 * ::capnp::ELEMENTS);
}

inline TestUnion::Union0::Which TestUnion::Union0::Builder::which() {
  return _builder.getDataField<Which>(0 * ::capnp::ELEMENTS);
}


// TestUnion::Union0::u0f0s0@4: Void;  # (none), union tag = 0

inline  ::capnp::Void TestUnion::Union0::Reader::getU0f0s0() const {
  KJ_IREQUIRE(which() == Union0::U0F0S0,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestUnion::Union0::Builder::getU0f0s0() {
  KJ_IREQUIRE(which() == Union0::U0F0S0,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f0s0( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F0S0);
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f0s1@5: Bool;  # bits[64, 65), union tag = 1

inline bool TestUnion::Union0::Reader::getU0f0s1() const {
  KJ_IREQUIRE(which() == Union0::U0F0S1,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<bool>(
      64 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Union0::Builder::getU0f0s1() {
  KJ_IREQUIRE(which() == Union0::U0F0S1,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<bool>(
      64 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f0s1(bool value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F0S1);
  _builder.setDataField<bool>(
      64 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f0s8@6: Int8;  # bits[64, 72), union tag = 2

inline  ::int8_t TestUnion::Union0::Reader::getU0f0s8() const {
  KJ_IREQUIRE(which() == Union0::U0F0S8,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int8_t>(
      8 * ::capnp::ELEMENTS);
}

inline  ::int8_t TestUnion::Union0::Builder::getU0f0s8() {
  KJ_IREQUIRE(which() == Union0::U0F0S8,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int8_t>(
      8 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f0s8( ::int8_t value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F0S8);
  _builder.setDataField< ::int8_t>(
      8 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f0s16@7: Int16;  # bits[64, 80), union tag = 3

inline  ::int16_t TestUnion::Union0::Reader::getU0f0s16() const {
  KJ_IREQUIRE(which() == Union0::U0F0S16,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int16_t>(
      4 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestUnion::Union0::Builder::getU0f0s16() {
  KJ_IREQUIRE(which() == Union0::U0F0S16,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int16_t>(
      4 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f0s16( ::int16_t value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F0S16);
  _builder.setDataField< ::int16_t>(
      4 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f0s32@8: Int32;  # bits[64, 96), union tag = 4

inline  ::int32_t TestUnion::Union0::Reader::getU0f0s32() const {
  KJ_IREQUIRE(which() == Union0::U0F0S32,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int32_t>(
      2 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestUnion::Union0::Builder::getU0f0s32() {
  KJ_IREQUIRE(which() == Union0::U0F0S32,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int32_t>(
      2 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f0s32( ::int32_t value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F0S32);
  _builder.setDataField< ::int32_t>(
      2 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f0s64@9: Int64;  # bits[64, 128), union tag = 5

inline  ::int64_t TestUnion::Union0::Reader::getU0f0s64() const {
  KJ_IREQUIRE(which() == Union0::U0F0S64,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestUnion::Union0::Builder::getU0f0s64() {
  KJ_IREQUIRE(which() == Union0::U0F0S64,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f0s64( ::int64_t value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F0S64);
  _builder.setDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f0sp@10: Text;  # ptr[0], union tag = 6


inline bool TestUnion::Union0::Reader::hasU0f0sp() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestUnion::Union0::Builder::hasU0f0sp() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestUnion::Union0::Reader::getU0f0sp() const {
  KJ_IREQUIRE(which() == Union0::U0F0SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestUnion::Union0::Builder::getU0f0sp() {
  KJ_IREQUIRE(which() == Union0::U0F0SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestUnion::Union0::Builder::setU0f0sp( ::capnp::Text::Reader value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F0SP);
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestUnion::Union0::Builder::initU0f0sp(unsigned int size) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F0SP);
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestUnion::Union0::u0f1s0@11: Void;  # (none), union tag = 7

inline  ::capnp::Void TestUnion::Union0::Reader::getU0f1s0() const {
  KJ_IREQUIRE(which() == Union0::U0F1S0,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestUnion::Union0::Builder::getU0f1s0() {
  KJ_IREQUIRE(which() == Union0::U0F1S0,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f1s0( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F1S0);
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f1s1@12: Bool;  # bits[64, 65), union tag = 8

inline bool TestUnion::Union0::Reader::getU0f1s1() const {
  KJ_IREQUIRE(which() == Union0::U0F1S1,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<bool>(
      64 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Union0::Builder::getU0f1s1() {
  KJ_IREQUIRE(which() == Union0::U0F1S1,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<bool>(
      64 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f1s1(bool value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F1S1);
  _builder.setDataField<bool>(
      64 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f1s8@13: Int8;  # bits[64, 72), union tag = 9

inline  ::int8_t TestUnion::Union0::Reader::getU0f1s8() const {
  KJ_IREQUIRE(which() == Union0::U0F1S8,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int8_t>(
      8 * ::capnp::ELEMENTS);
}

inline  ::int8_t TestUnion::Union0::Builder::getU0f1s8() {
  KJ_IREQUIRE(which() == Union0::U0F1S8,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int8_t>(
      8 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f1s8( ::int8_t value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F1S8);
  _builder.setDataField< ::int8_t>(
      8 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f1s16@14: Int16;  # bits[64, 80), union tag = 10

inline  ::int16_t TestUnion::Union0::Reader::getU0f1s16() const {
  KJ_IREQUIRE(which() == Union0::U0F1S16,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int16_t>(
      4 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestUnion::Union0::Builder::getU0f1s16() {
  KJ_IREQUIRE(which() == Union0::U0F1S16,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int16_t>(
      4 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f1s16( ::int16_t value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F1S16);
  _builder.setDataField< ::int16_t>(
      4 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f1s32@15: Int32;  # bits[64, 96), union tag = 11

inline  ::int32_t TestUnion::Union0::Reader::getU0f1s32() const {
  KJ_IREQUIRE(which() == Union0::U0F1S32,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int32_t>(
      2 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestUnion::Union0::Builder::getU0f1s32() {
  KJ_IREQUIRE(which() == Union0::U0F1S32,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int32_t>(
      2 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f1s32( ::int32_t value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F1S32);
  _builder.setDataField< ::int32_t>(
      2 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f1s64@16: Int64;  # bits[64, 128), union tag = 12

inline  ::int64_t TestUnion::Union0::Reader::getU0f1s64() const {
  KJ_IREQUIRE(which() == Union0::U0F1S64,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestUnion::Union0::Builder::getU0f1s64() {
  KJ_IREQUIRE(which() == Union0::U0F1S64,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union0::Builder::setU0f1s64( ::int64_t value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F1S64);
  _builder.setDataField< ::int64_t>(
      1 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union0::u0f1sp@17: Text;  # ptr[0], union tag = 13


inline bool TestUnion::Union0::Reader::hasU0f1sp() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestUnion::Union0::Builder::hasU0f1sp() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestUnion::Union0::Reader::getU0f1sp() const {
  KJ_IREQUIRE(which() == Union0::U0F1SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestUnion::Union0::Builder::getU0f1sp() {
  KJ_IREQUIRE(which() == Union0::U0F1SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestUnion::Union0::Builder::setU0f1sp( ::capnp::Text::Reader value) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F1SP);
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestUnion::Union0::Builder::initU0f1sp(unsigned int size) {
  _builder.setDataField<Union0::Which>(
      0 * ::capnp::ELEMENTS, Union0::U0F1SP);
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 0 * ::capnp::POINTERS, size);
}



// TestUnion::Union1
inline TestUnion::Union1::Which TestUnion::Union1::Reader::which() const {
  return _reader.getDataField<Which>(1 * ::capnp::ELEMENTS);
}

inline TestUnion::Union1::Which TestUnion::Union1::Builder::which() {
  return _builder.getDataField<Which>(1 * ::capnp::ELEMENTS);
}


// TestUnion::Union1::u1f0s0@19: Void;  # (none), union tag = 0

inline  ::capnp::Void TestUnion::Union1::Reader::getU1f0s0() const {
  KJ_IREQUIRE(which() == Union1::U1F0S0,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestUnion::Union1::Builder::getU1f0s0() {
  KJ_IREQUIRE(which() == Union1::U1F0S0,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f0s0( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F0S0);
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f0s1@20: Bool;  # bits[129, 130), union tag = 1

inline bool TestUnion::Union1::Reader::getU1f0s1() const {
  KJ_IREQUIRE(which() == Union1::U1F0S1,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<bool>(
      129 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Union1::Builder::getU1f0s1() {
  KJ_IREQUIRE(which() == Union1::U1F0S1,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<bool>(
      129 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f0s1(bool value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F0S1);
  _builder.setDataField<bool>(
      129 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f1s1@21: Bool;  # bits[129, 130), union tag = 2

inline bool TestUnion::Union1::Reader::getU1f1s1() const {
  KJ_IREQUIRE(which() == Union1::U1F1S1,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<bool>(
      129 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Union1::Builder::getU1f1s1() {
  KJ_IREQUIRE(which() == Union1::U1F1S1,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<bool>(
      129 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f1s1(bool value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F1S1);
  _builder.setDataField<bool>(
      129 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f0s8@22: Int8;  # bits[136, 144), union tag = 3

inline  ::int8_t TestUnion::Union1::Reader::getU1f0s8() const {
  KJ_IREQUIRE(which() == Union1::U1F0S8,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int8_t>(
      17 * ::capnp::ELEMENTS);
}

inline  ::int8_t TestUnion::Union1::Builder::getU1f0s8() {
  KJ_IREQUIRE(which() == Union1::U1F0S8,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int8_t>(
      17 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f0s8( ::int8_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F0S8);
  _builder.setDataField< ::int8_t>(
      17 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f1s8@23: Int8;  # bits[136, 144), union tag = 4

inline  ::int8_t TestUnion::Union1::Reader::getU1f1s8() const {
  KJ_IREQUIRE(which() == Union1::U1F1S8,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int8_t>(
      17 * ::capnp::ELEMENTS);
}

inline  ::int8_t TestUnion::Union1::Builder::getU1f1s8() {
  KJ_IREQUIRE(which() == Union1::U1F1S8,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int8_t>(
      17 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f1s8( ::int8_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F1S8);
  _builder.setDataField< ::int8_t>(
      17 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f0s16@24: Int16;  # bits[144, 160), union tag = 5

inline  ::int16_t TestUnion::Union1::Reader::getU1f0s16() const {
  KJ_IREQUIRE(which() == Union1::U1F0S16,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int16_t>(
      9 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestUnion::Union1::Builder::getU1f0s16() {
  KJ_IREQUIRE(which() == Union1::U1F0S16,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int16_t>(
      9 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f0s16( ::int16_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F0S16);
  _builder.setDataField< ::int16_t>(
      9 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f1s16@25: Int16;  # bits[144, 160), union tag = 6

inline  ::int16_t TestUnion::Union1::Reader::getU1f1s16() const {
  KJ_IREQUIRE(which() == Union1::U1F1S16,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int16_t>(
      9 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestUnion::Union1::Builder::getU1f1s16() {
  KJ_IREQUIRE(which() == Union1::U1F1S16,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int16_t>(
      9 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f1s16( ::int16_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F1S16);
  _builder.setDataField< ::int16_t>(
      9 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f0s32@26: Int32;  # bits[160, 192), union tag = 7

inline  ::int32_t TestUnion::Union1::Reader::getU1f0s32() const {
  KJ_IREQUIRE(which() == Union1::U1F0S32,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int32_t>(
      5 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestUnion::Union1::Builder::getU1f0s32() {
  KJ_IREQUIRE(which() == Union1::U1F0S32,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int32_t>(
      5 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f0s32( ::int32_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F0S32);
  _builder.setDataField< ::int32_t>(
      5 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f1s32@27: Int32;  # bits[160, 192), union tag = 8

inline  ::int32_t TestUnion::Union1::Reader::getU1f1s32() const {
  KJ_IREQUIRE(which() == Union1::U1F1S32,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int32_t>(
      5 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestUnion::Union1::Builder::getU1f1s32() {
  KJ_IREQUIRE(which() == Union1::U1F1S32,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int32_t>(
      5 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f1s32( ::int32_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F1S32);
  _builder.setDataField< ::int32_t>(
      5 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f0s64@28: Int64;  # bits[192, 256), union tag = 9

inline  ::int64_t TestUnion::Union1::Reader::getU1f0s64() const {
  KJ_IREQUIRE(which() == Union1::U1F0S64,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestUnion::Union1::Builder::getU1f0s64() {
  KJ_IREQUIRE(which() == Union1::U1F0S64,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f0s64( ::int64_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F0S64);
  _builder.setDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f1s64@29: Int64;  # bits[192, 256), union tag = 10

inline  ::int64_t TestUnion::Union1::Reader::getU1f1s64() const {
  KJ_IREQUIRE(which() == Union1::U1F1S64,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestUnion::Union1::Builder::getU1f1s64() {
  KJ_IREQUIRE(which() == Union1::U1F1S64,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f1s64( ::int64_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F1S64);
  _builder.setDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f0sp@30: Text;  # ptr[1], union tag = 11


inline bool TestUnion::Union1::Reader::hasU1f0sp() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestUnion::Union1::Builder::hasU1f0sp() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestUnion::Union1::Reader::getU1f0sp() const {
  KJ_IREQUIRE(which() == Union1::U1F0SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestUnion::Union1::Builder::getU1f0sp() {
  KJ_IREQUIRE(which() == Union1::U1F0SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestUnion::Union1::Builder::setU1f0sp( ::capnp::Text::Reader value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F0SP);
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestUnion::Union1::Builder::initU1f0sp(unsigned int size) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F0SP);
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestUnion::Union1::u1f1sp@31: Text;  # ptr[1], union tag = 12


inline bool TestUnion::Union1::Reader::hasU1f1sp() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestUnion::Union1::Builder::hasU1f1sp() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestUnion::Union1::Reader::getU1f1sp() const {
  KJ_IREQUIRE(which() == Union1::U1F1SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestUnion::Union1::Builder::getU1f1sp() {
  KJ_IREQUIRE(which() == Union1::U1F1SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestUnion::Union1::Builder::setU1f1sp( ::capnp::Text::Reader value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F1SP);
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestUnion::Union1::Builder::initU1f1sp(unsigned int size) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F1SP);
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestUnion::Union1::u1f2s0@32: Void;  # (none), union tag = 13

inline  ::capnp::Void TestUnion::Union1::Reader::getU1f2s0() const {
  KJ_IREQUIRE(which() == Union1::U1F2S0,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}

inline  ::capnp::Void TestUnion::Union1::Builder::getU1f2s0() {
  KJ_IREQUIRE(which() == Union1::U1F2S0,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f2s0( ::capnp::Void value = ::capnp::Void::VOID) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F2S0);
  _builder.setDataField< ::capnp::Void>(
      0 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f2s1@33: Bool;  # bits[192, 193), union tag = 14

inline bool TestUnion::Union1::Reader::getU1f2s1() const {
  KJ_IREQUIRE(which() == Union1::U1F2S1,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<bool>(
      192 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Union1::Builder::getU1f2s1() {
  KJ_IREQUIRE(which() == Union1::U1F2S1,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<bool>(
      192 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f2s1(bool value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F2S1);
  _builder.setDataField<bool>(
      192 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f2s8@34: Int8;  # bits[192, 200), union tag = 15

inline  ::int8_t TestUnion::Union1::Reader::getU1f2s8() const {
  KJ_IREQUIRE(which() == Union1::U1F2S8,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int8_t>(
      24 * ::capnp::ELEMENTS);
}

inline  ::int8_t TestUnion::Union1::Builder::getU1f2s8() {
  KJ_IREQUIRE(which() == Union1::U1F2S8,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int8_t>(
      24 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f2s8( ::int8_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F2S8);
  _builder.setDataField< ::int8_t>(
      24 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f2s16@35: Int16;  # bits[192, 208), union tag = 16

inline  ::int16_t TestUnion::Union1::Reader::getU1f2s16() const {
  KJ_IREQUIRE(which() == Union1::U1F2S16,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int16_t>(
      12 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestUnion::Union1::Builder::getU1f2s16() {
  KJ_IREQUIRE(which() == Union1::U1F2S16,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int16_t>(
      12 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f2s16( ::int16_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F2S16);
  _builder.setDataField< ::int16_t>(
      12 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f2s32@36: Int32;  # bits[192, 224), union tag = 17

inline  ::int32_t TestUnion::Union1::Reader::getU1f2s32() const {
  KJ_IREQUIRE(which() == Union1::U1F2S32,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int32_t>(
      6 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestUnion::Union1::Builder::getU1f2s32() {
  KJ_IREQUIRE(which() == Union1::U1F2S32,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int32_t>(
      6 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f2s32( ::int32_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F2S32);
  _builder.setDataField< ::int32_t>(
      6 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f2s64@37: Int64;  # bits[192, 256), union tag = 18

inline  ::int64_t TestUnion::Union1::Reader::getU1f2s64() const {
  KJ_IREQUIRE(which() == Union1::U1F2S64,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestUnion::Union1::Builder::getU1f2s64() {
  KJ_IREQUIRE(which() == Union1::U1F2S64,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union1::Builder::setU1f2s64( ::int64_t value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F2S64);
  _builder.setDataField< ::int64_t>(
      3 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union1::u1f2sp@38: Text;  # ptr[1], union tag = 19


inline bool TestUnion::Union1::Reader::hasU1f2sp() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestUnion::Union1::Builder::hasU1f2sp() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Reader TestUnion::Union1::Reader::getU1f2sp() const {
  KJ_IREQUIRE(which() == Union1::U1F2SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _reader, 1 * ::capnp::POINTERS);
}

inline  ::capnp::Text::Builder TestUnion::Union1::Builder::getU1f2sp() {
  KJ_IREQUIRE(which() == Union1::U1F2SP,
              "Must check which() before get()ing a union member.");
  return ::capnp::_::PointerHelpers< ::capnp::Text>::get(
      _builder, 1 * ::capnp::POINTERS);
}

inline void TestUnion::Union1::Builder::setU1f2sp( ::capnp::Text::Reader value) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F2SP);
  ::capnp::_::PointerHelpers< ::capnp::Text>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnp::Text::Builder TestUnion::Union1::Builder::initU1f2sp(unsigned int size) {
  _builder.setDataField<Union1::Which>(
      1 * ::capnp::ELEMENTS, Union1::U1F2SP);
  return ::capnp::_::PointerHelpers< ::capnp::Text>::init(
      _builder, 1 * ::capnp::POINTERS, size);
}



// TestUnion::Union2
inline TestUnion::Union2::Which TestUnion::Union2::Reader::which() const {
  return _reader.getDataField<Which>(2 * ::capnp::ELEMENTS);
}

inline TestUnion::Union2::Which TestUnion::Union2::Builder::which() {
  return _builder.getDataField<Which>(2 * ::capnp::ELEMENTS);
}


// TestUnion::Union2::u2f0s64@54: Int64;  # bits[384, 448), union tag = 4

inline  ::int64_t TestUnion::Union2::Reader::getU2f0s64() const {
  KJ_IREQUIRE(which() == Union2::U2F0S64,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int64_t>(
      6 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestUnion::Union2::Builder::getU2f0s64() {
  KJ_IREQUIRE(which() == Union2::U2F0S64,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int64_t>(
      6 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union2::Builder::setU2f0s64( ::int64_t value) {
  _builder.setDataField<Union2::Which>(
      2 * ::capnp::ELEMENTS, Union2::U2F0S64);
  _builder.setDataField< ::int64_t>(
      6 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union2::u2f0s32@52: Int32;  # bits[320, 352), union tag = 3

inline  ::int32_t TestUnion::Union2::Reader::getU2f0s32() const {
  KJ_IREQUIRE(which() == Union2::U2F0S32,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int32_t>(
      10 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestUnion::Union2::Builder::getU2f0s32() {
  KJ_IREQUIRE(which() == Union2::U2F0S32,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int32_t>(
      10 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union2::Builder::setU2f0s32( ::int32_t value) {
  _builder.setDataField<Union2::Which>(
      2 * ::capnp::ELEMENTS, Union2::U2F0S32);
  _builder.setDataField< ::int32_t>(
      10 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union2::u2f0s16@50: Int16;  # bits[288, 304), union tag = 2

inline  ::int16_t TestUnion::Union2::Reader::getU2f0s16() const {
  KJ_IREQUIRE(which() == Union2::U2F0S16,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int16_t>(
      18 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestUnion::Union2::Builder::getU2f0s16() {
  KJ_IREQUIRE(which() == Union2::U2F0S16,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int16_t>(
      18 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union2::Builder::setU2f0s16( ::int16_t value) {
  _builder.setDataField<Union2::Which>(
      2 * ::capnp::ELEMENTS, Union2::U2F0S16);
  _builder.setDataField< ::int16_t>(
      18 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union2::u2f0s8@47: Int8;  # bits[264, 272), union tag = 1

inline  ::int8_t TestUnion::Union2::Reader::getU2f0s8() const {
  KJ_IREQUIRE(which() == Union2::U2F0S8,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int8_t>(
      33 * ::capnp::ELEMENTS);
}

inline  ::int8_t TestUnion::Union2::Builder::getU2f0s8() {
  KJ_IREQUIRE(which() == Union2::U2F0S8,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int8_t>(
      33 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union2::Builder::setU2f0s8( ::int8_t value) {
  _builder.setDataField<Union2::Which>(
      2 * ::capnp::ELEMENTS, Union2::U2F0S8);
  _builder.setDataField< ::int8_t>(
      33 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union2::u2f0s1@45: Bool;  # bits[256, 257), union tag = 0

inline bool TestUnion::Union2::Reader::getU2f0s1() const {
  KJ_IREQUIRE(which() == Union2::U2F0S1,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<bool>(
      256 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Union2::Builder::getU2f0s1() {
  KJ_IREQUIRE(which() == Union2::U2F0S1,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<bool>(
      256 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union2::Builder::setU2f0s1(bool value) {
  _builder.setDataField<Union2::Which>(
      2 * ::capnp::ELEMENTS, Union2::U2F0S1);
  _builder.setDataField<bool>(
      256 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union3
inline TestUnion::Union3::Which TestUnion::Union3::Reader::which() const {
  return _reader.getDataField<Which>(3 * ::capnp::ELEMENTS);
}

inline TestUnion::Union3::Which TestUnion::Union3::Builder::which() {
  return _builder.getDataField<Which>(3 * ::capnp::ELEMENTS);
}


// TestUnion::Union3::u3f0s64@55: Int64;  # bits[448, 512), union tag = 4

inline  ::int64_t TestUnion::Union3::Reader::getU3f0s64() const {
  KJ_IREQUIRE(which() == Union3::U3F0S64,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int64_t>(
      7 * ::capnp::ELEMENTS);
}

inline  ::int64_t TestUnion::Union3::Builder::getU3f0s64() {
  KJ_IREQUIRE(which() == Union3::U3F0S64,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int64_t>(
      7 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union3::Builder::setU3f0s64( ::int64_t value) {
  _builder.setDataField<Union3::Which>(
      3 * ::capnp::ELEMENTS, Union3::U3F0S64);
  _builder.setDataField< ::int64_t>(
      7 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union3::u3f0s32@53: Int32;  # bits[352, 384), union tag = 3

inline  ::int32_t TestUnion::Union3::Reader::getU3f0s32() const {
  KJ_IREQUIRE(which() == Union3::U3F0S32,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int32_t>(
      11 * ::capnp::ELEMENTS);
}

inline  ::int32_t TestUnion::Union3::Builder::getU3f0s32() {
  KJ_IREQUIRE(which() == Union3::U3F0S32,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int32_t>(
      11 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union3::Builder::setU3f0s32( ::int32_t value) {
  _builder.setDataField<Union3::Which>(
      3 * ::capnp::ELEMENTS, Union3::U3F0S32);
  _builder.setDataField< ::int32_t>(
      11 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union3::u3f0s16@51: Int16;  # bits[304, 320), union tag = 2

inline  ::int16_t TestUnion::Union3::Reader::getU3f0s16() const {
  KJ_IREQUIRE(which() == Union3::U3F0S16,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int16_t>(
      19 * ::capnp::ELEMENTS);
}

inline  ::int16_t TestUnion::Union3::Builder::getU3f0s16() {
  KJ_IREQUIRE(which() == Union3::U3F0S16,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int16_t>(
      19 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union3::Builder::setU3f0s16( ::int16_t value) {
  _builder.setDataField<Union3::Which>(
      3 * ::capnp::ELEMENTS, Union3::U3F0S16);
  _builder.setDataField< ::int16_t>(
      19 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union3::u3f0s8@48: Int8;  # bits[272, 280), union tag = 1

inline  ::int8_t TestUnion::Union3::Reader::getU3f0s8() const {
  KJ_IREQUIRE(which() == Union3::U3F0S8,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField< ::int8_t>(
      34 * ::capnp::ELEMENTS);
}

inline  ::int8_t TestUnion::Union3::Builder::getU3f0s8() {
  KJ_IREQUIRE(which() == Union3::U3F0S8,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField< ::int8_t>(
      34 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union3::Builder::setU3f0s8( ::int8_t value) {
  _builder.setDataField<Union3::Which>(
      3 * ::capnp::ELEMENTS, Union3::U3F0S8);
  _builder.setDataField< ::int8_t>(
      34 * ::capnp::ELEMENTS, value);
}


// TestUnion::Union3::u3f0s1@46: Bool;  # bits[257, 258), union tag = 0

inline bool TestUnion::Union3::Reader::getU3f0s1() const {
  KJ_IREQUIRE(which() == Union3::U3F0S1,
              "Must check which() before get()ing a union member.");
  return _reader.getDataField<bool>(
      257 * ::capnp::ELEMENTS);
}

inline bool TestUnion::Union3::Builder::getU3f0s1() {
  KJ_IREQUIRE(which() == Union3::U3F0S1,
              "Must check which() before get()ing a union member.");
  return _builder.getDataField<bool>(
      257 * ::capnp::ELEMENTS);
}
inline void TestUnion::Union3::Builder::setU3f0s1(bool value) {
  _builder.setDataField<Union3::Which>(
      3 * ::capnp::ELEMENTS, Union3::U3F0S1);
  _builder.setDataField<bool>(
      257 * ::capnp::ELEMENTS, value);
}



// TestUnionDefaults::s16s8s64s8Set@0: .TestUnion = (union0 = u0f0s16(321), union1 = u1f0s8(123), union2 = u2f0s64(12345678901234567), union3 = u3f0s8(55));  # ptr[0]


inline bool TestUnionDefaults::Reader::hasS16s8s64s8Set() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestUnionDefaults::Builder::hasS16s8s64s8Set() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestUnion::Reader TestUnionDefaults::Reader::getS16s8s64s8Set() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestUnion>::get(
      _reader, 0 * ::capnp::POINTERS,
      DEFAULT_S16S8S64S8_SET.words);
}

inline  ::capnproto_test::capnp::test::TestUnion::Builder TestUnionDefaults::Builder::getS16s8s64s8Set() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestUnion>::get(
      _builder, 0 * ::capnp::POINTERS,
      DEFAULT_S16S8S64S8_SET.words);
}

inline void TestUnionDefaults::Builder::setS16s8s64s8Set( ::capnproto_test::capnp::test::TestUnion::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestUnion>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestUnion::Builder TestUnionDefaults::Builder::initS16s8s64s8Set() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestUnion>::init(
      _builder, 0 * ::capnp::POINTERS);
}



// TestUnionDefaults::s0sps1s32Set@1: .TestUnion = (union0 = u0f1s0(void), union1 = u1f0sp("foo"), union2 = u2f0s1(true), union3 = u3f0s32(12345678));  # ptr[1]


inline bool TestUnionDefaults::Reader::hasS0sps1s32Set() const {
  return !_reader.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline bool TestUnionDefaults::Builder::hasS0sps1s32Set() {
  return !_builder.isPointerFieldNull(1 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestUnion::Reader TestUnionDefaults::Reader::getS0sps1s32Set() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestUnion>::get(
      _reader, 1 * ::capnp::POINTERS,
      DEFAULT_S0SPS1S32_SET.words);
}

inline  ::capnproto_test::capnp::test::TestUnion::Builder TestUnionDefaults::Builder::getS0sps1s32Set() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestUnion>::get(
      _builder, 1 * ::capnp::POINTERS,
      DEFAULT_S0SPS1S32_SET.words);
}

inline void TestUnionDefaults::Builder::setS0sps1s32Set( ::capnproto_test::capnp::test::TestUnion::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestUnion>::set(
      _builder, 1 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestUnion::Builder TestUnionDefaults::Builder::initS0sps1s32Set() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestUnion>::init(
      _builder, 1 * ::capnp::POINTERS);
}




// TestUsing::outerNestedEnum@1: .TestNestedTypes.NestedEnum = bar;  # bits[16, 32)

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum TestUsing::Reader::getOuterNestedEnum() const {
  return _reader.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      1 * ::capnp::ELEMENTS, 1);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum TestUsing::Builder::getOuterNestedEnum() {
  return _builder.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      1 * ::capnp::ELEMENTS, 1);
}
inline void TestUsing::Builder::setOuterNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum value) {
  _builder.setDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedEnum>(
      1 * ::capnp::ELEMENTS, value, 1);
}


// TestUsing::innerNestedEnum@0: .TestNestedTypes.NestedStruct.NestedEnum = quux;  # bits[0, 16)

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum TestUsing::Reader::getInnerNestedEnum() const {
  return _reader.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      0 * ::capnp::ELEMENTS, 2);
}

inline  ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum TestUsing::Builder::getInnerNestedEnum() {
  return _builder.getDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      0 * ::capnp::ELEMENTS, 2);
}
inline void TestUsing::Builder::setInnerNestedEnum( ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum value) {
  _builder.setDataField< ::capnproto_test::capnp::test::TestNestedTypes::NestedStruct::NestedEnum>(
      0 * ::capnp::ELEMENTS, value, 2);
}



}  // namespace
}  // namespace
}  // namespace
#endif  // CAPNP_INCLUDED_cf321c6d9838c2958f78108066479a59
