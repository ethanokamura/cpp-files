#include <iostream>
#include <vector>


std::vector<int> Append (std::vector<int> v1, std::vector<int> v2) {
  std::vector<int> result;

  for (int i = v1.size(); i > 0; i--) {
    result.push_back(v1[i]);
  }
  for (int i = v2.size(); i > 0; i--) {
    result.push_back(v2[i]);
  }

  return result;
}

void PrintVector (std::vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

int main () {
  std::vector<int> v1;
  std::vector<int> v2;

  v1.push_back(2);
  v1.push_back(7);
  v2.push_back(3);
  v2.push_back(-2);

  std::cout << "Appended Vector: ";
  PrintVector(Append(v1,v2));
  std::cout << "v1: ";
  PrintVector(v1);
  std::cout << "v2: ";
  PrintVector(v2);

  return 0;
}
