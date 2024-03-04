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
  // maybe faster then above
  //
  // INoob() : a(1), b(2) {}

  // initialization with parameter list
  IConstructor(int x, int y);

  // overload of the constructor
  IConstructor(int x);

  /* Copy Constructor:
   * https://en.cppreference.com/w/cpp/language/copy_constructor */

  // copy constructor version I
  IConstructor(IConstructor& other);

  // copy constructor version II
  //
  // IConstructor(IConstructor& other, int y = 1);

  // copy constructor version III
  //
  // IConstructor(IConstructor& other, int x, int y);

  // note: If no user-defined copy constructors are provided for a class type,
  // the compiler will always declare a copy constructor as a non-explicit
  // inline public member of its class. In this case, we should be careful if
  // the object need to be deep copy.

  /* Move Constructor */

  // move constructor version I
  IConstructor(IConstructor&& other);

  // move constructor version II
  // IConstructor(IConstructor&& other, int x = 1);

  // note: If no user-defined move constructors are provided for a class type,
  // then the compiler **may** declare a move constructor as a non-explicit
  // inline public member of its class with the signature T::T(T&&).

  // TODO: difference between common constructor, copy constructor and move
  // constructor.
};

void executeConstructor();
