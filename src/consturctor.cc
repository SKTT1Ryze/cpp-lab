#include <cassert>
#include <iostream>

#include "../include/constructor.hpp"

using namespace std;

IConstructor::IConstructor(int x, int y) : a{x}, b{y} {}

IConstructor::IConstructor(int x) : a(x) { this->b = 2; }

IConstructor::IConstructor(IConstructor& other) {
  this->a = other.a;
  this->b = other.b;
}

IConstructor::IConstructor(IConstructor&& other) {
  this->a = other.a;
  this->b = other.b;
}

/**
INoob::INoob(int x, int y) {
  this->a = x;
  this->b = y;
}
**/

void executeConstructor() {
  /* direct initialization:
   * https://en.cppreference.com/w/cpp/language/direct_initialization */
  auto cons0 = new IConstructor();
  assert(cons0->a == 1);
  assert(cons0->b == 2);

  auto cons1 = new IConstructor(3, 4);
  assert(cons1->a == 3);
  assert(cons1->b == 4);

  auto cons2 = new IConstructor(5);
  assert(cons2->a == 5);
  assert(cons2->b == 2);

  /* copy initialization:
   * https://en.cppreference.com/w/cpp/language/copy_initialization */
  auto cons3 = *cons2;
  assert(cons3.a == 5);
  assert(cons3.b == 2);

  auto cons4 = std::move(cons3);
  assert(cons4.a == 5);
  assert(cons4.b == 2);
}
