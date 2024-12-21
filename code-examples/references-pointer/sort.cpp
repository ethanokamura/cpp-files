#include <iostream>

// Swaps 2 ints
void Swap(int &x, int &y) {
  int placeholder = x;
  x = y;
  y = placeholder;
}

// Sort 3 ints in acending order
void Sort(int &a, int &b, int &c) {
  if (c < b) Swap(b,c);
  if (b < a) Swap(a,b);
}

int main () {

  int a, b, c;
  std::cout << "Enter 3 integers: " << std::endl;
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  
  if (!std::cin.fail()) {
    while (b < a || c < b) {
      Sort(a,b,c);
    }
    std::cout << "In ascending order: " << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
  } else {
    std::cout << "Invalid Input " << std::endl;
  }

  return 0;
}
