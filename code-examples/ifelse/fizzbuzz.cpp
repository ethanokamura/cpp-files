#include <iostream>
// FIZZBUZZ

int main() {
  int n;
  std::string str;

  std::cout << "Type a number: ";
  std::cin >> n;

  if (n % 5 == 0 && n % 3 == 0) str = "fizzbuzz";
  else if (n % 3 == 0) str = "fizz";
  else if (n % 5 == 0) str = "buzz";
  else std::cout << n << std::endl;
  
  if (str.size() != 0) std::cout << str << std::endl;

  return 0;
}
