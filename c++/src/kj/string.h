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

#ifndef KJ_STRING_H_
#define KJ_STRING_H_

#include <initializer_list>
#include "array.h"
#include <string.h>

namespace kj {

class StringPtr;
class String;

// =======================================================================================
// StringPtr -- A NUL-terminated ArrayPtr<const char> containing UTF-8 text.
//
// NUL bytes are allowed to appear before the end of the string.  The only requirement is that
// a NUL byte appear immediately after the last byte of the content.  This terminator byte is not
// counted in the string's size.

class StringPtr {
public:
  inline StringPtr(): content("", 1) {}
  inline StringPtr(decltype(nullptr)): content("", 1) {}
  inline StringPtr(const char* value): content(value, strlen(value) + 1) {}
  inline StringPtr(const char* value, size_t size): content(value, size + 1) {
    KJ_IREQUIRE(value[size] == '\0', "StringPtr must be NUL-terminated.");
  }
  inline StringPtr(const char* begin, const char* end): StringPtr(begin, end - begin) {}
  inline StringPtr(const String& value);

  inline operator ArrayPtr<const char>() const;
  inline ArrayPtr<const char> asArray() const;
  // Result does not include NUL terminator.

  inline const char* cStr() const { return content.begin(); }
  // Returns NUL-terminated string.

  inline size_t size() const { return content.size() - 1; }
  // Result does not include NUL terminator.

  inline char operator[](size_t index) const { return content[index]; }

  inline const char* begin() const { return content.begin(); }
  inline const char* end() const { return content.end() - 1; }

  inline bool operator==(decltype(nullptr)) const { return content.size() <= 1; }
  inline bool operator!=(decltype(nullptr)) const { return content.size() > 1; }

  inline bool operator==(const StringPtr& other) const;
  inline bool operator!=(const StringPtr& other) const { return !(*this == other); }
  inline bool operator< (const StringPtr& other) const;
  inline bool operator> (const StringPtr& other) const { return other < *this; }
  inline bool operator<=(const StringPtr& other) const { return !(other < *this); }
  inline bool operator>=(const StringPtr& other) const { return !(*this < other); }

  inline StringPtr slice(size_t start) const;
  inline ArrayPtr<const char> slice(size_t start, size_t end) const;
  // A string slice is only NUL-terminated if it is a suffix, so slice() has a one-parameter
  // version that assumes end = size().

private:
  inline StringPtr(ArrayPtr<const char> content): content(content) {}

  ArrayPtr<const char> content;
};

inline bool operator==(const char* a, const StringPtr& b) { return b == a; }
inline bool operator!=(const char* a, const StringPtr& b) { return b != a; }

// =======================================================================================
// String -- A NUL-terminated Array<char> containing UTF-8 text.
//
// NUL bytes are allowed to appear before the end of the string.  The only requirement is that
// a NUL byte appear immediately after the last byte of the content.  This terminator byte is not
// counted in the string's size.
//
// To allocate a String, you must call kj::heapString().  We do not implement implicit copying to
// the heap because this hides potential inefficiency from the developer.

class String {
public:
  String() = default;
  inline String(decltype(nullptr)): content(nullptr) {}
  inline String(char* value, size_t size, const ArrayDisposer& disposer);
  // Does not copy.  `size` does not include NUL terminator, but `value` must be NUL-terminated.

  inline operator ArrayPtr<char>();
  inline operator ArrayPtr<const char>() const;
  inline ArrayPtr<char> asArray();
  inline ArrayPtr<const char> asArray() const;
  // Result does not include NUL terminator.

  inline const char* cStr() const;

  inline size_t size() const;
  // Result does not include NUL terminator.

  inline char operator[](size_t index) const;
  inline char& operator[](size_t index);

  inline char* begin();
  inline char* end();
  inline const char* begin() const;
  inline const char* end() const;

  inline bool operator==(decltype(nullptr)) const { return content.size() <= 1; }
  inline bool operator!=(decltype(nullptr)) const { return content.size() > 1; }

  inline bool operator==(const StringPtr& other) const { return StringPtr(*this) == other; }
  inline bool operator!=(const StringPtr& other) const { return !(*this == other); }

private:
  Array<char> content;
};

inline bool operator==(const char* a, const String& b) { return b == a; }
inline bool operator!=(const char* a, const String& b) { return b != a; }

String heapString(size_t size);
// Allocate a String of the given size on the heap, not including NUL terminator.  The NUL
// terminator will be initialized automatically but the rest of the content is not initialized.

String heapString(const char* value);
String heapString(const char* value, size_t size);
String heapString(StringPtr value);
String heapString(const String& value);
String heapString(ArrayPtr<const char> value);
// Allocates a copy of the given value on the heap.

// =======================================================================================
// Magic str() function which transforms parameters to text and concatenates them into one big
// String.

namespace _ {  // private

inline size_t sum(std::initializer_list<size_t> nums) {
  size_t result = 0;
  for (auto num: nums) {
    result += num;
  }
  return result;
}

inline char* fill(char* ptr) { return ptr; }

template <typename First, typename... Rest>
char* fill(char* __restrict__ target, const First& first, Rest&&... rest) {
  auto i = first.begin();
  auto end = first.end();
  while (i != end) {
    *target++ = *i++;
  }
  return fill(target, kj::fwd<Rest>(rest)...);
}

template <typename... Params>
String concat(Params&&... params) {
  // Concatenate a bunch of containers into a single Array.  The containers can be anything that
  // is iterable and whose elements can be converted to `char`.

  String result = heapString(sum({params.size()...}));
  fill(result.begin(), kj::fwd<Params>(params)...);
  return result;
}

inline String concat(String&& arr) {
  return kj::mv(arr);
}

struct Stringifier {
  // This is a dummy type with only one instance: STR (below).  To make an arbitrary type
  // stringifiable, define `operator*(Stringifier, T)` to return an iterable container of `char`.
  // The container type must have a `size()` method.  Be sure to declare the operator in the same
  // namespace as `T` **or** in the global scope.
  //
  // A more usual way to accomplish what we're doing here would be to require that you define
  // a function like `toString(T)` and then rely on argument-dependent lookup.  However, this has
  // the problem that it pollutes other people's namespaces and even the global namespace.  For
  // example, some other project may already have functions called `toString` which do something
  // different.  Declaring `operator*` with `Stringifier` as the left operand cannot conflict with
  // anything.

  inline ArrayPtr<const char> operator*(ArrayPtr<const char> s) const { return s; }
  inline ArrayPtr<const char> operator*(const Array<const char>& s) const { return s; }
  inline ArrayPtr<const char> operator*(const Array<char>& s) const { return s; }
  template<size_t n>
  inline ArrayPtr<const char> operator*(const CappedArray<char, n>& s) const { return s; }
  inline ArrayPtr<const char> operator*(const char* s) const { return arrayPtr(s, strlen(s)); }
  inline ArrayPtr<const char> operator*(const String& s) const { return s.asArray(); }
  inline ArrayPtr<const char> operator*(const StringPtr& s) const { return s.asArray(); }

  inline FixedArray<char, 1> operator*(char c) const {
    FixedArray<char, 1> result;
    result[0] = c;
    return result;
  }

  StringPtr operator*(bool b) const;

  CappedArray<char, sizeof(short) * 4> operator*(short i) const;
  CappedArray<char, sizeof(unsigned short) * 4> operator*(unsigned short i) const;
  CappedArray<char, sizeof(int) * 4> operator*(int i) const;
  CappedArray<char, sizeof(unsigned int) * 4> operator*(unsigned int i) const;
  CappedArray<char, sizeof(long) * 4> operator*(long i) const;
  CappedArray<char, sizeof(unsigned long) * 4> operator*(unsigned long i) const;
  CappedArray<char, sizeof(long long) * 4> operator*(long long i) const;
  CappedArray<char, sizeof(unsigned long long) * 4> operator*(unsigned long long i) const;
  CappedArray<char, 24> operator*(float f) const;
  CappedArray<char, 32> operator*(double f) const;
  CappedArray<char, sizeof(const void*) * 4> operator*(const void* s) const;

  template <typename T>
  Array<char> operator*(ArrayPtr<T> arr) const;
  template <typename T>
  Array<char> operator*(const Array<T>& arr) const;
};
static constexpr Stringifier STR = Stringifier();

}  // namespace _ (private)

template <typename T>
auto toCharSequence(T&& value) -> decltype(_::STR * kj::fwd<T>(value)) {
  // Returns an iterable of chars that represent a textual representation of the value, suitable
  // for debugging.
  //
  // Most users should use str() instead, but toCharSequence() may occasionally be useful to avoid
  // heap allocation overhead that str() implies.
  //
  // To specialize this function for your type, see KJ_STRINGIFY.

  return _::STR * kj::fwd<T>(value);
}

CappedArray<char, sizeof(unsigned short) * 4> hex(unsigned short i);
CappedArray<char, sizeof(unsigned int) * 4> hex(unsigned int i);
CappedArray<char, sizeof(unsigned long) * 4> hex(unsigned long i);
CappedArray<char, sizeof(unsigned long long) * 4> hex(unsigned long long i);

template <typename... Params>
String str(Params&&... params) {
  // Magic function which builds a string from a bunch of arbitrary values.  Example:
  //     str(1, " / ", 2, " = ", 0.5)
  // returns:
  //     "1 / 2 = 0.5"
  // To teach `str` how to stringify a type, see `Stringifier`.

  return _::concat(toCharSequence(kj::fwd<Params>(params))...);
}

inline String str(String&& s) { return mv(s); }
// Overload to prevent redundant allocation.

template <typename T>
String strArray(T&& arr, const char* delim) {
  size_t delimLen = strlen(delim);
  KJ_STACK_ARRAY(decltype(_::STR * arr[0]), pieces, arr.size(), 8, 32);
  size_t size = 0;
  for (size_t i = 0; i < arr.size(); i++) {
    if (i > 0) size += delimLen;
    pieces[i] = _::STR * arr[i];
    size += pieces[i].size();
  }

  String result = heapString(size);
  char* pos = result.begin();
  for (size_t i = 0; i < arr.size(); i++) {
    if (i > 0) {
      memcpy(pos, delim, delimLen);
      pos += delimLen;
    }
    pos = _::fill(pos, pieces[i]);
  }
  return result;
}

namespace _ {  // private

template <typename T>
inline Array<char> Stringifier::operator*(ArrayPtr<T> arr) const {
  return strArray(arr, ", ");
}

template <typename T>
inline Array<char> Stringifier::operator*(const Array<T>& arr) const {
  return strArray(arr, ", ");
}

}  // namespace _ (private)

#define KJ_STRINGIFY(...) operator*(::kj::_::Stringifier, __VA_ARGS__)
// Defines a stringifier for a custom type.  Example:
//
//    class Foo {...};
//    inline StringPtr KJ_STRINGIFY(const Foo& foo) { return foo.name(); }
//
// This allows Foo to be passed to str().
//
// The function should be declared either in the same namespace as the target type or in the global
// namespace.  It can return any type which is an iterable container of chars.

// =======================================================================================
// Inline implementation details.

inline StringPtr::StringPtr(const String& value): content(value.begin(), value.size() + 1) {}

inline StringPtr::operator ArrayPtr<const char>() const {
  return content.slice(0, content.size() - 1);
}

inline ArrayPtr<const char> StringPtr::asArray() const {
  return content.slice(0, content.size() - 1);
}

inline bool StringPtr::operator==(const StringPtr& other) const {
  return content.size() == other.content.size() &&
      memcmp(content.begin(), other.content.begin(), content.size() - 1) == 0;
}

inline bool StringPtr::operator<(const StringPtr& other) const {
  bool shorter = content.size() < other.content.size();
  int cmp = memcmp(content.begin(), other.content.begin(),
                   shorter ? content.size() : other.content.size());
  return cmp < 0 || (cmp == 0 && shorter);
}

inline StringPtr StringPtr::slice(size_t start) const {
  return StringPtr(content.slice(start, content.size()));
}
inline ArrayPtr<const char> StringPtr::slice(size_t start, size_t end) const {
  return content.slice(start, end);
}

inline String::operator ArrayPtr<char>() {
  return content == nullptr ? ArrayPtr<char>(nullptr) : content.slice(0, content.size() - 1);
}
inline String::operator ArrayPtr<const char>() const {
  return content == nullptr ? ArrayPtr<const char>(nullptr) : content.slice(0, content.size() - 1);
}

inline ArrayPtr<char> String::asArray() {
  return content == nullptr ? ArrayPtr<char>(nullptr) : content.slice(0, content.size() - 1);
}
inline ArrayPtr<const char> String::asArray() const {
  return content == nullptr ? ArrayPtr<const char>(nullptr) : content.slice(0, content.size() - 1);
}

inline const char* String::cStr() const { return content == nullptr ? "" : content.begin(); }

inline size_t String::size() const { return content == nullptr ? 0 : content.size() - 1; }

inline char String::operator[](size_t index) const { return content[index]; }
inline char& String::operator[](size_t index) { return content[index]; }

inline char* String::begin() { return content == nullptr ? nullptr : content.begin(); }
inline char* String::end() { return content == nullptr ? nullptr : content.end() - 1; }
inline const char* String::begin() const { return content == nullptr ? nullptr : content.begin(); }
inline const char* String::end() const { return content == nullptr ? nullptr : content.end() - 1; }

inline String::String(char* value, size_t size, const ArrayDisposer& disposer)
    : content(value, size + 1, disposer) {
  KJ_IREQUIRE(value[size] == '\0', "String must be NUL-terminated.");
}

inline String heapString(const char* value) {
  return heapString(value, strlen(value));
}
inline String heapString(StringPtr value) {
  return heapString(value.begin(), value.size());
}
inline String heapString(const String& value) {
  return heapString(value.begin(), value.size());
}
inline String heapString(ArrayPtr<const char> value) {
  return heapString(value.begin(), value.size());
}

}  // namespace kj

#endif  // KJ_STRING_H_
