#include "../include/valueCategory.hpp"

#include <type_traits>
#include <utility>

template <class T>
struct is_prvalue : std::true_type {};
template <class T>
struct is_prvalue<T&> : std::false_type {};
template <class T>
struct is_prvalue<T&&> : std::false_type {};

template <class T>
struct is_lvalue : std::false_type {};
template <class T>
struct is_lvalue<T&> : std::true_type {};
template <class T>
struct is_lvalue<T&&> : std::false_type {};

template <class T>
struct is_xvalue : std::false_type {};
template <class T>
struct is_xvalue<T&> : std::false_type {};
template <class T>
struct is_xvalue<T&&> : std::true_type {};

void executeValueCategory() {
  int a{42};
  int& b{a};
  int&& r{std::move(a)};

  static_assert(is_prvalue<decltype((42))>::value,
                "Expression `42` is prvalue");

  static_assert(is_lvalue<decltype((a))>::value, "Expression `a` is lvalue");

  static_assert(is_lvalue<decltype((b))>::value, "Expression `b` is lvalue");

  static_assert(is_xvalue<decltype((std::move(a)))>::value,
                "Expression `std::move(a)` is xvalue");

  static_assert(std::is_rvalue_reference<decltype(r)>::value,
                "Type of variable `r` is rvalue reference");

  static_assert(std::is_lvalue_reference<decltype(b)>::value,
                "Type of variable `b` is lvalue reference");

  static_assert(is_lvalue<decltype((r))>::value, "Expression `r` is lvalue");
}

int& a_ref() {
  static int a{3};
  return a;
}

void foo() {
  a_ref() = 5;  // `a_ref()` is lvalue, function call whose return type is
                // lvalue reference
}
