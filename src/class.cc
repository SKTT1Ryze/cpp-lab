#include "../include/class.h"

#include <iostream>

using namespace std;

int INoob::getA() { return this->a; }

int INoob::getB() { return this->b; }

void executeClass() {
  auto noob = new INoob();
  noob->a = 1;

  cout << "a = " << noob->getA() << endl;
}
