#include "../include/abstractClass.hpp"

using namespace abstract;

void executeAbstractClass() {
  // Abstract a;   // Error: abstract class
  Concrete b;       // OK
  Abstract& a = b;  // OK to reference abstract base
  a.f();            // virtual dispatch to Concrete::f()
  // Abstract2 a2; // Error: abstract class (final overrider of g() is pure)
}
