class IConstructor {
 public:
  int a;
  int b;

  // if there are not any constructor provided, the compiler will generate the
  // default constructor which set all members to default value.

  IConstructor() {
    // initialization in the function body
    a = 1;
    b = 2;
  }

  // initialization in the initializer list
  //
  //
  // INoob() : a(1), b(2) {}

  // initialization with parameter list
  IConstructor(int x, int y);
};

void executeConstructor();
