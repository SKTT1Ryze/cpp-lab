#include "../include/move.h"

#include <cassert>
#include <iostream>

void executeMove() {
  std::vector<int> v{1, 2, 3, 4, 5};
  std::vector<int> v2(std::move(v));  // binds an rvalue reference to v
  assert(v.empty());
}
