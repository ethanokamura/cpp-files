#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  for (int i = 0; i < nums.size(); i++)
    if (nums[i] >= target) return i;
  return nums.size();
}

int binarySearchInsert(vector<int>& nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] > target)
      r = m - 1;
    else if (nums[m] < target)
      l = m + 1;
    else
      return m;
  }
  return r + 1;
}

int main() {
  vector<int> v = {-3, 4, 5, 6, 7, 8, 20, 25, 400};
  std::cout << "index: " << binarySearchInsert(v, 8) << '\n';
  return 0;
}