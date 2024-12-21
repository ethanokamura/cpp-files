#include <iostream>
#include <cassert>

/**
 * Find the Index of the First Occurrence in a String
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 */

using namespace std;

int strStr(string haystack, string needle);

int main() {
  assert(strStr("sadbutsad", "sad") == 0);
  assert(strStr("leetcode", "leeto") == -1);
  assert(strStr("mississippi", "issippi") == 4);
  assert(strStr("babbb", "bbb") == 2);
  assert(strStr("mississippi", "issippo") == -1);
  return 0;
}
