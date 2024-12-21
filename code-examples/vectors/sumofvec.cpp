#include <iostream>
#include <vector>

// 11/15/2022
// MULTIPLY VALUES IN AN ARRAY
// Class Exercise

int SumOfVector(std::vector<int> v) {
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }

  return sum;
}

int main () {
  int temp;
  std::vector<int> vec;

  while (std::cin >> temp) {
    vec.push_back(temp);
  }

  std::cout << "sum is " << SumOfVector(vec) << std::endl;

  return 0;
}
