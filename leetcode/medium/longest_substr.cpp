#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  string temp;
  int n = 0;
  for (int i = 0; i < s.length(); i++) {
    if (temp.find(s[i]) != string::npos) {
      if (n < temp.length()) n = temp.length();
      temp = "";
    } else if (i == s.length() - 1) {
      temp += s[i];
      if (n < temp.length()) n = temp.length();
    }
    temp += s[i];
  }
  return n;
}

int main() {
  assert(lengthOfLongestSubstring("au") == 2);
  assert(lengthOfLongestSubstring("dvdf") == 3);
  assert(lengthOfLongestSubstring("awerts") == 6);
  return 0;
}