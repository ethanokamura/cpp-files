#include <iostream>
#include <vector>

using namespace std;

vector<int> plus_one(vector<int>& digits) {
  int last = digits[digits.size() - 1];
  int nines = 0;
  while (digits.size() > 0 && digits[digits.size() - 1] == 9) {
    nines++;
    digits.pop_back();
  }
  if (digits.size() == 0) {
    last = 0;
  } else {
    last = digits[digits.size() - 1];
    digits.pop_back();
  }
  last++;
  digits.push_back(last);
  for (int i = 0; i < nines; i++) digits.push_back(0);
  return digits;
}

int main() {
  vector<int> v = {5, 9, 1, 9, 9};
  cout << '[';
  for (int i : plus_one(v)) cout << i << " ";
  cout << "]\n";
  return 0;
}
