#include <iostream>
#include <sstream>

int sum_of_array(int* arr, unsigned int SIZE) {
  int sum = 0;
  for (int i = 0; i < SIZE; i++) sum += arr[i];
  return sum;
}

int main() {
  const unsigned int SIZE = 6;
  int* arr = new int[SIZE]{0, 1, 2, 3, 4, 5};
  std::ostringstream oss;
  std::string array_string = "[ ";
  for (int i = 0; i < SIZE; i++) oss << arr[i] << (i != SIZE - 1 ? ", " : "");
  array_string += oss.str() + " ]";
  std::cout << "sum of array: " << array_string
            << " is: " << sum_of_array(arr, SIZE) << '\n';
  return 0;
}
