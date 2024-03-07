#include "../include/virtualFunction.h"

#include <cassert>

using namespace vfunction;

int Base::f() { return 1; }

int Derived::f() { return 2; }

void executeVirtualFuncton() {
  Base b;
  Derived d;

  // virtual function call through reference
  Base& br = b;  // the type of br is Base&
  Base& dr = d;  // the type of dr is Base& as well
  assert(br.f() == 1);
  assert(dr.f() == 2);

  // virtual function call through pointer
  Base* bp = &b;  // the type of bp is Base*
  Base* dp = &d;  // the type of dp is Base* as well
  assert(bp->f() == 1);
  assert(dp->f() == 2);

  assert(br.Base::f() == 1);
  assert(dr.Base::f() == 1);
}
