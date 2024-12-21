// While loop introduction/practice!
// 1. Write a block of code that takes in multiple integer values
//   - use if statements to find minimum and maximum values inputted by the user!
// 2. Write a block of code that then takes the min and max values and determines the total number of digits in the integer
#include <iostream>

int main () {
  int input = 0;
  std::cout << "enter at least one integer, press (ctrl-d) to quit:\n";
  std::cin >> input;

  int max = input;
  int min = input;
  while (std::cin >> input) {
    if (input > max) max = input;
    if (input < min) min = input;
  }

  std::cout << "the max is " << max << " and the min is " << min << ".\n";
  
  int max_digits = 0;
  int min_digits = 0;

  if (max < 0)
    max = -max;
  if (min < 0)
    min = -min;

  while (max > 0) {
    max /= 10;
    max_digits++;
  }

  while (min > 0) {
    min /= 10;
    min_digits++;
  }

  std::cout << "there are " << max_digits << " digits in the maximum number!\n";
  std::cout << "there are " << min_digits << " digits in the minimum number!\n";

  return 0;
}
