#include <iostream>

int main() {
  std::string dna;    // READ DNA STRING
  int gc = 0, l = 0;  // COUNT
  while (std::getline(std::cin, dna)) {
    for (char c : dna) {  // LOOP THROUGH DNA STRAND
      if (c == 'C')
        ++gc, ++l;
      else if (c == 'G')
        ++gc, ++l;
      else if (c == 'A')
        ++l;
      else if (c == 'T')
        ++l;
    }
  }
  std::cout << 100.0 * gc / l << std::endl;  // CONVERT TO PERCENT
  return 0;
}
