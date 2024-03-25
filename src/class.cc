#include "../include/class.hpp"

#include <cassert>
#include <iostream>

using namespace std;

int INoob::getA() { return this->a; }

int INoob::getB() { return this->b; }

void executeClass() {
  auto noob = new INoob();
  noob->a = 1;
  assert(noob->getA() == 1);
}
