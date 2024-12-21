#include <iostream>

int main() { 
  std::string dna; // READ DNA STRING
  int gc = 0, l = 0; // COUNT
  while (std::getline(std::cin, dna)) {
    for (int i = 0; i < dna.size(); i++) { // LOOP THROUGH DNA STRAND
      if (dna[i] == 'C') ++gc, ++l;
      else if (dna[i] == 'G') ++gc, ++l;
      else if (dna[i] == 'A') ++l;
      else if (dna[i] == 'T') ++l;
    }
  }
  std::cout << 100.0 * gc / l << std::endl; // CONVERT TO PERCENT
  return 0;
}
