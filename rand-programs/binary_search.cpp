#include <time.h>

#include <cstdlib>
#include <iostream>

int binary_search(int target, int low, int high) {
  while (low != high) {
    int mid = (low + high) / 2;
    if (mid > target)
      high = mid - 1;
    else if (mid < target)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

int linear_search(int target, int max) {
  for (int i = 0; i < max; i++)
    if (i == target) return i;
  return -1;
}

int main() {
  srand(time(0));
  int target = rand() % 100 + 1;
  binary_search(target, 1, 100);
  return 0;
}