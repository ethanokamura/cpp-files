#include <iostream>

// Oct 18, 2022
// Find duplicates:

int main () {

  int x;
  int y;
  std::string z = "x";

  std::cout << "Columns: ";
  std::cin >> x;
  std::cout << "Rows: ";
  std::cin >> y;
  std::cout << "Character: ";
  std::cin >> z;
  std::cout << std::endl;

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      std::cout << " " + z + " ";
    }
    std::cout << std::endl;
  }
  
  std::cout << std::endl;

  return 0;
}
