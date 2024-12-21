#include <iostream>
#include <iomanip>

// 10/27/2022

double Volume(double l, double h) {
  double b = l*l;
  double v = (h/3) * b;
  return v;
}

int main () {
  double l;
  double h;
  
  std::cout << "Enter the length of a side on a Pyramid: ";
  std::cin >> l;
  std::cout << "Enter the height of the Pyramid: ";
  std::cin >> h;

  std::cout << "The vol. of this pyramid is: " << Volume(l, h) << std::endl;

  return 0;
}
