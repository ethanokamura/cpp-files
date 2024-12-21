#include <iostream>
#include <ctime>
#include <cstdlib>

// 11/10/2022
// ARRAY PRACTICE
// Class Exercise

int main () {

  srand(time(0));

  const int SIZE = 10;
  int array [SIZE];

  std::cout << "Vanilla Array: ";
  for (int i = 0; i < SIZE; i++) {
    array[i] = rand() % 100;
    std::cout << i << ":" << array[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Even Index: ";
  for (int i = 0; i < SIZE; i+=2) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Even Numbers: ";
  for (int i = 0; i < SIZE; i++) {
    if (array[i] % 2 == 0) std::cout << array[i] << " "; // NOT IDEAL ENDS IN ", "
  }
  std::cout << std::endl;

  std::cout << "Reverse Index: ";
  for (int i = (SIZE-1); i >= 0; i--) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
  
  std::cout << "First/Last: " << array[0] << " " << array[SIZE-1] << std::endl;

  return 0;
}
