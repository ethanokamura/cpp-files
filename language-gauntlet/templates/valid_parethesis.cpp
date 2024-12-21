#include <iostream>
#include <string>
#include <vector>
#include <cassert>

/**
 * Find the valid parenthesis
 * https://leetcode.com/problems/valid-parentheses/description/
 */

using namespace std;

bool isValid(string s);

int main() {
  assert(isValid("()") == true);
  assert(isValid("[]") == true);
  assert(isValid("{}") == true);
  assert(isValid("({[]})") == true);
  assert(isValid("(})") == false);
  assert(isValid("{]}") == false);
  assert(isValid("(]") == false);
  assert(isValid("()]") == false);
  assert(isValid("{]}") == false);
  assert(isValid("{([{{()}}])") == false);
  return 0;
}