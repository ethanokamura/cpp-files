#include <iostream>
#include <vector>
#include <cassert>

/**
 * Remove duplicates from a sorted array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 */

using namespace std;

int removeDuplicates(vector<int>& nums);

int main() {
  vector<int> v = {0, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> s = {0, 3, 4, 5, 6, 7, 8, 9, 10};
  assert(removeDuplicates(v) == 9);
  for (int i = 0; i < s.size(); i++)
    assert(v[i] == s[i]);
  v = {0, 3, 3, 3, 3, 3};
  s = {0, 3};
  assert(removeDuplicates(v) == 2);
  for (int i = 0; i < s.size(); i++)
    assert(v[i] == s[i]);
  v = {0, 3, 3, 3, 3, 5};
  s = {0, 3, 5};
  assert(removeDuplicates(v) == 3);
  for (int i = 0; i < s.size(); i++)
    assert(v[i] == s[i]);
  v = {0};
  s = {0};
  assert(removeDuplicates(v) == 1);
  for (int i = 0; i < s.size(); i++)
    assert(v[i] == s[i]);
  return 0;
}