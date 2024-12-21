/**
 * @file readability.cpp
 *
 *  Estimating English Text Readability
 *  Formula: 4.71 * (characters/words) + 0.5 * (words/sentences) -21.43;
 *
 * @author Ethan Okamura, ethanokamura3@gmail.com
 */

#include <cctype>
#include <iostream>
#include <sstream>

int main() {
  int numChars = 0, numSentences = 0;
  double numWords = 0.0;
  bool isWord = false;

  for (std::string line; std::getline(std::cin, line);) {
    std::istringstream line_stream(line);
    for (std::string token; line_stream >> token;) {
      if (isWord) numWords++;  // Add to sum of valid words ✅
      isWord = false;
    }
  }
  std::cout << "c:" << numChars << " w:" << numWords << " s:" << numSentences
            << '\n';
  std::cout << 4.71 * (numChars / numWords) + 0.5 * (numWords / numSentences) -
                   21.43
            << '\n';
  return 0;
}