#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  string prefix;
  // find smallest val O(N)
  string first = *min_element(strs.begin(), strs.end());
  // find largest val O(N)
  string last = *max_element(strs.begin(), strs.end());
  // compare largest and smallest O(size of min)
  for (int i = 0; i < min(first.size(), last.size()); i++) {
    if (first[i] != last[i]) return prefix;
    prefix += first[i];
  }
  return prefix;
}

int main() {
  vector<string> v{"flower", "flow", "flight"};
  vector<string> v2{"dog", "racecar", "car"};

  cout << longestCommonPrefix(v) << '\n';
  cout << longestCommonPrefix(v2) << '\n';
  return 0;
}