#include <cassert>
#include <iostream>

using namespace std;

int mySqrt(int x) {
  if (x <= 1) return x;
  int l = 0;
  int r = x;
  while (l <= r) {
    int m = l + (r-l)/2;
    if (m > x/m) r = m - 1;
    else if (m < x/m) l = m + 1;
    else return m;
  }
  return r;
}

int main() {
  assert(mySqrt(16) == 4);
  assert(mySqrt(4) == 2);
  assert(mySqrt(8) == 2);
  assert(mySqrt(169) == 13);
  assert(mySqrt(3) == 1);
  assert(mySqrt(1) == 1);
  return 0;
}