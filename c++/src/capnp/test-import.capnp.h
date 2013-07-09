// Generated code, DO NOT EDIT

#ifndef CAPNP_INCLUDED_c7ea02c068349fc4119b97d33ae61bed
#define CAPNP_INCLUDED_c7ea02c068349fc4119b97d33ae61bed

#include <capnp/generated-header-support.h>
#include "test.capnp.h"



struct TestImport {
  TestImport() = delete;

  class Reader;
  class Builder;

private:
};




namespace capnp {
namespace schemas {
extern const ::capnp::_::RawSchema s_bc55b08b672b5d97;
}  // namespace schemas
namespace _ {  // private
CAPNP_DECLARE_STRUCT(
    ::TestImport, bc55b08b672b5d97,
    0, 1, POINTER);
}  // namespace capnp
}  // namespace _ (private)




class TestImport::Reader {
public:
  typedef TestImport Reads;

  Reader() = default;
  inline explicit Reader(::capnp::_::StructReader base): _reader(base) {}

  inline size_t totalSizeInWords() const {
    return _reader.totalSize() / ::capnp::WORDS;
  }

  // field@0: import "src/capnp/test.capnp".TestAllTypes;  # ptr[0]
  inline bool hasField() const;
  inline  ::capnproto_test::capnp::test::TestAllTypes::Reader getField() const;
private:
  ::capnp::_::StructReader _reader;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::_::PointerHelpers;
  friend class ::capnp::MessageBuilder;
  friend ::kj::String KJ_STRINGIFY(TestImport::Reader reader);
};

inline ::kj::String KJ_STRINGIFY(TestImport::Reader reader) {
  return ::capnp::_::structString<TestImport>(reader._reader);
}



class TestImport::Builder {
public:
  typedef TestImport Builds;

  Builder() = default;
  inline explicit Builder(::capnp::_::StructBuilder base): _builder(base) {}
  inline operator Reader() const { return Reader(_builder.asReader()); }
  inline Reader asReader() const { return *this; }

  inline size_t totalSizeInWords() { return asReader().totalSizeInWords(); }

  // field@0: import "src/capnp/test.capnp".TestAllTypes;  # ptr[0]
  inline bool hasField();
  inline  ::capnproto_test::capnp::test::TestAllTypes::Builder getField();
  inline void setField( ::capnproto_test::capnp::test::TestAllTypes::Reader other);
  inline  ::capnproto_test::capnp::test::TestAllTypes::Builder initField();
private:
  ::capnp::_::StructBuilder _builder;
  template <typename T, ::capnp::Kind k>
  friend struct ::capnp::ToDynamic_;
  friend ::kj::String KJ_STRINGIFY(TestImport::Builder builder);
};

inline ::kj::String KJ_STRINGIFY(TestImport::Builder builder) {
  return ::capnp::_::structString<TestImport>(builder._builder.asReader());
}



// TestImport::field@0: import "src/capnp/test.capnp".TestAllTypes;  # ptr[0]


inline bool TestImport::Reader::hasField() const {
  return !_reader.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline bool TestImport::Builder::hasField() {
  return !_builder.isPointerFieldNull(0 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Reader TestImport::Reader::getField() const {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::get(
      _reader, 0 * ::capnp::POINTERS);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Builder TestImport::Builder::getField() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::get(
      _builder, 0 * ::capnp::POINTERS);
}

inline void TestImport::Builder::setField( ::capnproto_test::capnp::test::TestAllTypes::Reader value) {
  ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::set(
      _builder, 0 * ::capnp::POINTERS, value);
}

inline  ::capnproto_test::capnp::test::TestAllTypes::Builder TestImport::Builder::initField() {
  return ::capnp::_::PointerHelpers< ::capnproto_test::capnp::test::TestAllTypes>::init(
      _builder, 0 * ::capnp::POINTERS);
}




#endif  // CAPNP_INCLUDED_c7ea02c068349fc4119b97d33ae61bed
