#include <iomanip>
#include <iostream>

// Ethan Okamura
// Assignment 1 (Due 09.27.22)
// Calculating Cost of a Trip

int main() {
  double mpg;
  double totalMi;
  double costPerGallon;

  std::cout << "How much does each gallon cost?: ";
  std::cin >> costPerGallon;
  std::cout << "How many miles per gallon does your car get?: ";
  std::cin >> mpg;
  std::cout << "How far are you going (in miles)?: ";
  std::cin >> totalMi;

  double totalCost = totalMi / mpg * costPerGallon;

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Your trip will cost $" << totalCost << " total." << std::endl;

  return 0;
}
