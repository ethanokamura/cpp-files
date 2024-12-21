#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0 || (n == 0 && m == 0)) return;
    if (m == 0) nums1 = nums2;
    for (int i = m; i < m+n; i++) {
      nums1[i] = nums2[i - m];
    }
    sort(nums1.begin(), nums1.end());
  }

  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0 || (n == 0 && m == 0)) return;
    if (m == 0) nums1 = nums2;
    for (int i = m; i < m+n; i++) {
      nums1[i] = nums2[i - m];
    }
    sort(nums1.begin(), nums1.end());
  }
};


void print_solution(vector<int> v) {
  cout << "{ ";
  for (int i : v)
    cout << i << ' ';
  cout << "}\n";
}

int main() {
  Solution solution;
  vector<int> nums1 = {1,2,3,0,0,0};
  vector<int> nums2 = {2,5,6};
  int m = 3;
  int n = 3;
  solution.merge(nums1, m, nums2, n);
  print_solution(nums1);

  nums1 = {1};
  m = 1;
  nums2 = {};
  n = 0;
  solution.merge(nums1, m, nums2, n);
  print_solution(nums1);

  nums1 = {0};
  m = 0;
  nums2 = {1};
  n = 1;
  solution.merge(nums1, m, nums2, n);
  print_solution(nums1);
}