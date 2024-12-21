#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int singleNumber1(vector<int>& nums) {
  if (nums.size() == 1) return nums[0];
  unordered_map<int,int> table;
  for (int i : nums)
    table[i]++;
  for (auto const& it : table)
    if (it.second == 1)
      return it.first;
  return -1;
}

int singleNumber2(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  while (nums.size() > 1) {
    if (nums[nums.size() - 1] == nums[nums.size() - 2]) {
      nums.pop_back();
      nums.pop_back();
    } else {
      return nums[nums.size() - 1];
    }
  }
  return nums[0];
}

int singleNumber3(vector<int>& nums) {
  if (nums.size() == 1) return nums[0];
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 2; i++) {
    if (nums[i] == nums[i + 1]) i++;
    else return nums[i];
  }
  return nums[nums.size() - 1];
}

int singleNumber(vector<int>& nums) {
  int n = 0;
  for (int i : nums)
    n ^= i;
  return n;
}

int main() {
  vector<int> v1{2,2,1};
  vector<int> v2{4,1,2,1,2};
  vector<int> v3{1};
  vector<int> v4{4,1,2,1,2,4,5};
  assert(singleNumber(v1) == 1);
  assert(singleNumber(v2) == 4);
  assert(singleNumber(v3) == 1);
  assert(singleNumber(v4) == 5);
  return 0;
}