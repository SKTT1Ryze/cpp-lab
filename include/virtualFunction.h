namespace vfunction {
struct Base {
  virtual int f();
};

struct Derived : Base {
  int f() override;  // `override` is optional
};
}  // namespace vfunction

void executeVirtualFuncton();
