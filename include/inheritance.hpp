void executeInheritance();

struct B {
  int n;
};
class X : public virtual B {};
class Y : virtual public B {};
class Z : public B {};

struct AA : X, Y, Z {
  AA();
};

struct Base {
 protected:
  int i;

 private:
  void g(Base& b, struct Derived& d);
};

struct Derived : Base {
  friend void h(Base& b, Derived& d);
  void f(Base& b, Derived& d)  // member function of a derived class
  {
    ++d.i;  // OK: the type of d is Derived
    ++i;    // OK: the type of the implied '*this' is Derived
    //      ++b.i;                  // error: can't access a protected member
    //      through
    // Base (otherwise it would be possible to change
    // other derived classes, like a hypothetical
    // Derived2, base implementation)
  }
};
