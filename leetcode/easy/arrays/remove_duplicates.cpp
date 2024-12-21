#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(vector<int>& nums) {
  int n = 0;
  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[n] != nums[i]) {
      n++;
      nums[n] = nums[i];
    }
  }
  return n + 1;
}

int main() {
  vector<int> v = {0, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << remove_duplicates(v) << " unique values\n";
  for (int n : v) cout << n << ", ";
  cout << '\n';
  return 0;
}
