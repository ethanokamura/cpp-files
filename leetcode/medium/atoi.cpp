#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_num(char c) { return c >= 48 && c <= 57; }

int myAtoi(string s) {
  vector<int> v;
  bool is_negative = false;
  bool is_positive = false;
  bool first_num = false;
  bool zero_detected = false;
  for (char c : s) {
    if (v.size() == 0) {
      if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == '.') return 0;
      if (c == 45) is_negative = true;
      if (c == 43) is_positive = true;
      if (is_positive && is_negative) return 0;
    }
    if (v.size() == 0) {
      if (c == 45) is_negative = true;
      if (c == 48) zero_detected = true;
    }
    if (is_num(c) && c != 48 && !first_num) first_num = true;
    if (is_num(c) && first_num) v.push_back(c - 48);
    if ((v.size() > 0 || zero_detected) && !is_num(c)) break;
  }
  if (v.empty()) return 0;
  long long n = 0;
  for (size_t i = 0; i < v.size(); i++) {
    if (pow(10, v.size() - i - 1) < 2147483647)
      n += v[i] * pow(10, v.size() - i - 1);
    else
      return is_negative ? numeric_limits<int>::min()
                         : numeric_limits<int>::max();
  }
  return is_negative ? -n : n;
}

int main() {
  cout << myAtoi("20000000000000000000") << '\n';
  cout << myAtoi("-91283472332") << '\n';
  cout << myAtoi("3.14159") << '\n';
  cout << myAtoi("0000000000012345678") << '\n';
  cout << myAtoi("  -0012a42") << '\n';
  cout << myAtoi("00000-42a1234") << '\n';
  return 0;
}