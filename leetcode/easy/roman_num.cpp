#include <iostream>

using namespace std;

int romanToInt(string s) {
  int v = 0;
  for (size_t i = 0; i < s.length(); i++) {
    char c = s[i];
    char l;
    if (c == 'M')
      v += (l == 'C') ? 800 : 1000;
    else if (c == 'D')
      v += (l == 'C') ? 300 : 500;
    else if (c == 'C')
      v += (l == 'X') ? 80 : 100;
    else if (c == 'L')
      v += (l == 'X') ? 30 : 50;
    else if (c == 'X')
      v += (l == 'I') ? 8 : 10;
    else if (c == 'V')
      v += (l == 'I') ? 3 : 5;
    else if (c == 'I')
      v += 1;
    l = c;
  }
  return v;
}

int main() {
  string s = "MDI";
  std::cout << s << " == " << romanToInt(s) << '\n';
  s = "LVIII";
  std::cout << s << " == " << romanToInt(s) << '\n';
  s = "MCMXCIV";
  std::cout << s << " == " << romanToInt(s) << '\n';
  return 0;
}