#include <iostream>
#include <vector>

using namespace std;

int remove_element(vector<int>& nums, int val) {
  int n = 1;
  size_t i = 0;
  size_t size = nums.size();
  if (size == 0) return 0;
  while (i < size - n) {
    if (nums[i] == val && nums[size - n] != val) swap(nums[i], nums[size - n]);
    if (nums[size - n] == val) n++;
    if (nums[i] != val) i++;
  }
  if (nums[i] == val) i--;
  return i + 1;
}

int main() {
  vector<int> v = {4, 5};
  std::cout << remove_element(v, 4) << " values left\n";
  for (int n : v) cout << n << ", ";
  cout << '\n';
  return 0;
}
