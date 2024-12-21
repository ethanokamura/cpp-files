#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
  if (x < 0 || (x != 0 && x % 10 == 0)) return false;
  if (x < 10) return true;
  long long r = 0;
  while (x > r) {
    r = r * 10 + x % 10;
    x /= 10;
  }
  return (x == r) || (x == r / 10);
}

int main() {
  int x = 1000021;
  if (isPalindrome(x)) cout << "is palindrome\n";

  return 0;
}