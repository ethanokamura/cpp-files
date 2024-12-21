#include <iostream>
#include <vector>

int max_index(std::vector<int> v) {
  int index = 0;
  int max = v.at(0);
  for (int i = 1; i < v.size(); i++) {
    if (v.at(i) > max) {
      max = v.at(i);
      index = i;
    }
  }
  return index;
}

int main() {
  std::vector<int> values;
  int input;
  while (std::cin >> input) values.push_back(input);

  std::cout << "-------------------\n";
  int max = max_index(values);
  for (int i = 0; i < values.size(); i++) {
    std::cout << values.at(i);
    if (i == max) std::cout << " <- MAX";
    std::cout << '\n';
  }
  return 0;
}