#include <iostream>

int main() {
  int x,y,z;

  std::cout << "Enter 3 integers: " << std::endl;
  std::cin >> x >> y >> z;  

  if (x < y && y < z) {
    std::cout << "increasing \n";
  } else if (y < x && z < y) {
    std::cout << "decreasing \n";
  } else {
    std::cout << "neither \n";
  }

  int num = 0;
  std::string str = "";
  
  std::cout << "Type a number: ";
  std::cin >> n;

  if (n % 5 == 0 && n % 3 == 0) {
    str = "fizzbuzz";
  } else if (n % 3 == 0) {
    str = "fizz";
  } else if (n % 5 == 0) {
    str = "buzz";
  } else {
    std::cout << n << std::endl;
  }
  
  if (str.size() != 0) {
    std::cout << str << std::endl;
  }

  return 0;
}
