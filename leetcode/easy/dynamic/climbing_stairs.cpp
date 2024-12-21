#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;

int climbStairs(int n) {
  if (n < 2) return 1;
  static unordered_map<int, int> hashmap;
  if (hashmap.find(n) != hashmap.end()) {
    return hashmap[n];
  } else {
    int res = climbStairs(n - 1) + climbStairs(n - 2);
    hashmap[n] = res;
    return res;
  }
  return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
  assert(climbStairs(0) == 1);
  assert(climbStairs(1) == 1);
  assert(climbStairs(2) == 2);
  assert(climbStairs(3) == 3);
  assert(climbStairs(4) == 5);
  assert(climbStairs(5) == 8);
  assert(climbStairs(6) == 13);

  return 0;
}