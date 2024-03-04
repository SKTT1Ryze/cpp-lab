#include <iostream>

#include "../include/constructor.h"

using namespace std;

IConstructor::IConstructor(int x, int y) : a{x}, b{y} {}

/**
INoob::INoob(int x, int y) {
  this->a = x;
  this->b = y;
}
**/

void executeConstructor() {
  auto cons0 = new IConstructor();

  cout << "a = " << cons0->a << ", b = " << cons0->b << endl;
}
