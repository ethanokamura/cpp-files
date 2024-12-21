#include <iostream>
#include <iomanip>

// Ethan Okamura, 
// Brian Rodriguez, 
// Orion Ellefson

int main() {

  int x,y,z;

  std::cout << "Enter 3 integers: " << std::endl;
  std::cin >> x >> y >> z;  

  if (x < y && y < z) {
    std::cout << "increasing" << std::endl;
  } else if (y < x && z < y) {
    std::cout << "decreasing" << std::endl;
  } else {
    std::cout << "neither" << std::endl;
  }

  return 0;
}
