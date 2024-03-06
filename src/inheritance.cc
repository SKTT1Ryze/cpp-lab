#include "../include/inheritance.h"

#include <cassert>

AA::AA() {
  X::n = 1;  // modifies the virtual B subobject's member
  Y::n = 2;  // modifies the same virtual B subobject's member
  Z::n = 3;  // modifies the non-virtual B subobject's member
}

void Base::g(Base& b, Derived& d)  // member function of Base
{
  ++i;    // OK
  ++b.i;  // OK
  ++d.i;  // OK
}

void h(Base& b, Derived& d)  // Friend of Derived
{
  ++d.i;  // OK: friend of Derived can access a protected
          // member through an object of Derived
  //  ++b.i;                  // error: friend of Derived is not a friend of
  //  Base
}

void x(Base& b, Derived& d)  // non-member non-friend
{
  //  ++b.i;                  // error: no access from non-member
  //  ++d.i;                  // error: no access from non-member
}

void executeInheritance() {
  auto aa = AA();
  assert(aa.X::n == 2);
  assert(aa.Y::n == 2);
  assert(aa.Z::n == 3);
}
