#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
  int x = 0, i = 0;
  while (haystack.length() - i >= needle.length()) {
    if (haystack[i] == needle[0]) {
      for (int j = 0; j <= needle.length(); j++) {
        if (haystack[i + j] == needle[j]) {
          x++;
          if (x == needle.length()) return i;
        } else {
          x = 0;
        }
      }
    }
    i++;
  }
  return -1;
}

int main() {
  cout << "index: " << strStr("mississippi", "issipi") << '\n';
  cout << "index: " << strStr("babbb", "bbb") << '\n';
  return 0;
}
