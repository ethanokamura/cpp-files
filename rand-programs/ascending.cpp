#include <iostream>
// 1. Create a swap function
// 2. Create a sort function
// 3. Print in both accending and decending order

void swap(int& a, int& b) {
  int x = a;
  a = b;
  b = x;
}

void sort_ascending(int& a, int& b, int& c) {
  if (c < b) swap(b, c);
  if (b < a) swap(a, b);
}

void sort_descending(int& a, int& b, int& c) {
  if (c > b) swap(b, c);
  if (b > a) swap(a, b);
}

int main() {
  int a, b, c;
  std::cout << "enter 3 integers:\n";
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;

  while (b < a || c < b) sort_ascending(a, b, c);
  std::cout << "in ascending order: " << a << ", " << b << ", " << c
            << std::endl;

  while (b > a || c > b) sort_descending(a, b, c);
  std::cout << "in descending order: " << a << ", " << b << ", " << c
            << std::endl;

  return 0;
}
