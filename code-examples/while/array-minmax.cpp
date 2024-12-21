#include <iostream>

// 11/08/22
// FIND MAX IN ARRAY
// Class Exercise

int MaxIndex(int a[], const int SIZE) {
  int index = 0;
  int max = a[0];

  for (int i = 1; i < SIZE; i++) {
    if (a[i] > max) {
      max = a[i];
      index = i;
    }
  }
  return index;
}

int main () {

  const int CAPACITY = 100;
  int values[CAPACITY];
  int size = 0;
  std::cout << "Input up to " << CAPACITY << " ints (ctrl-d to stop): " << std::endl;

  while (size < CAPACITY && std::cin >> values[size]) {
    size++;
  }

  int maxIndex = MaxIndex(values, size);
  std::cout << "INDEX:" << std::endl;

  for (int i=0; i < size; i++) {
    std::cout << i << ": " << values[i];
    if (i == maxIndex) std::cout << " <-- MAX";
    std::cout << std::endl;
  }

  return 0;
}
