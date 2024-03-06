#include "../include/move.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

vector<int> moveVector(vector<int>&& v) { return std::move(v); }
vector<int> moveVectorV2(vector<int>&& v) { return v; }
vector<int> copyVector(vector<int>& v) { return v; }

void executeMove() {
  vector<int> v{1, 2, 3, 4, 5};
  vector<int> v2(std::move(v));  // binds an rvalue reference to v
  assert(v.empty());
  auto v3 = moveVector(std::move(v2));
  assert(v2.empty());
  vector<int> v4 = std::move(v3);
  assert(v3.empty());
  vector<int> v5 = copyVector(v4);
  assert(!v4.empty());
  vector<int> v6 = moveVectorV2(std::move(v5));
  assert(v5.empty());

  int i2 = 42;
  int&& rri = std::move(i2);  // binds directly to i2
  assert(i2 == 42);
  assert(rri == 42);
}
