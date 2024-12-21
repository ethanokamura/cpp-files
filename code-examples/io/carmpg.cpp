#include <iostream>
#include <iomanip>

// Ethan Okamura

int main() {

  double gallonsInTank = 0.0;
  double mpg = 0.0;

  std::cout << "How many gallons are in your tank?: " << std::endl;
  std::cin >> gallonsInTank;
  std::cout << "How many miles per gallon does your car get?: " << std::endl;
  std::cin >> mpg;

  double totalMi = gallonsInTank * mpg;
  
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "You can drive " << totalMi << " more miles!" << std::endl;
  
  return 0;
}
