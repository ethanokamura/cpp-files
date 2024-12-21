#include <cassert>
#include <iostream>
#include <unordered_map>

/**
 * Climbing Stairs
 * https://leetcode.com/problems/climbing-stairs/description/
 */

using namespace std;

int climbStairs(int n);

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