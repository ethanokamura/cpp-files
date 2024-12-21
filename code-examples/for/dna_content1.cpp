#include <iostream>

int main() { 
  std::string dna; // READ DNA STRING
  int gc = 0, l = 0; // COUNT
  while (std::getline(std::cin, dna)) {
    for (char base: dna) { // LOOP THROUGH DNA STRAND
      switch (base) {
        case 'C': ++gc, ++l; break;
        case 'G': ++gc, ++l; break;
        case 'A': ++l; break;
        case 'T': ++l; break;
      }
    }
  }
  std::cout << 100.0 * gc / l << std::endl; // CONVERT TO PERCENT
  return 0;
}
