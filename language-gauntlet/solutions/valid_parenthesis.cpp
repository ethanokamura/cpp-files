#include <iostream>
#include <string>
#include <vector>
#include <cassert>

/**
 * Find the valid parenthesis
 * https://leetcode.com/problems/valid-parentheses/description/
 */

using namespace std;

bool isValid(string s) {
  vector<char> v;
  if (s.length() == 1) return false;
  for (int i = 0; i < s.length(); i++) {
    if (v.size() > 0) {
      if ((s[i] == ')' && v[v.size() - 1] != '(') ||
          (s[i] == ']' && v[v.size() - 1] != '[') ||
          (s[i] == '}' && v[v.size() - 1] != '{'))
        return false;
      if ((s[i] == ')' && v[v.size() - 1] == '(') ||
          (s[i] == ']' && v[v.size() - 1] == '[') ||
          (s[i] == '}' && v[v.size() - 1] == '{'))
        v.pop_back();
      else
        v.push_back(s[i]);
    } else {
      v.push_back(s[i]);
    }
  }
  return v.size() == 0;
}

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
