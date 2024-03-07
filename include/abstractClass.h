namespace abstract {
struct Abstract {
  virtual void f() = 0;  // pure virtual
};                       // "Abstract" is abstract

struct Concrete : Abstract {
  void f() override {}  // non-pure virtual
  virtual void g() {}   // non-pure virtual
};                      // "Concrete" is non-abstract

struct Abstract2 : Concrete {
  void g() override = 0;  // pure virtual overrider
};                        // "Abstract2" is abstract
}  // namespace abstract

void executeAbstractClass();
