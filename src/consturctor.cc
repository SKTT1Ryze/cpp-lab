#include <iostream>

#include "../include/constructor.h"

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
  cout << "a = " << cons0->a << ", b = " << cons0->b << endl;

  auto cons1 = new IConstructor(3, 4);
  cout << "a = " << cons1->a << ", b = " << cons1->b << endl;

  auto cons2 = new IConstructor(5);
  cout << "a = " << cons2->a << ", b = " << cons2->b << endl;

  /* copy initialization:
   * https://en.cppreference.com/w/cpp/language/copy_initialization */
  auto cons3 = *cons2;
  cout << "a = " << cons3.a << ", b = " << cons3.b << endl;

  auto cons4 = std::move(cons3);
  cout << "a = " << cons4.a << ", b = " << cons4.b << endl;
}
