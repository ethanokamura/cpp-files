#include <iomanip>
#include <iostream>

int main() {
  double mpg;
  double totalMi;
  double costPerGallon;

  std::cout << "How much does each gallon cost?\n";
  std::cin >> costPerGallon;
  std::cout << "How many miles per gallon does your car get?\n";
  std::cin >> mpg;
  std::cout << "How far are you going (in miles)?\n";
  std::cin >> totalMi;

  double totalCost = totalMi / mpg * costPerGallon;

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Your trip will cost $" << totalCost << " total.\n";

  return 0;
}