#include <iostream>
#include <sstream>
#include <string>

std::string trimWord(std::string s) {
  std::string temp;
  for (char c : s) {
    if (isalpha(c))
      temp += tolower(c);
  }
  return temp;
}

int isPalindrome(std::string word) {
  if (word.length() < 2) {
    return false;
  }
  int left{};
  int right{word.length() - 1};
  while (left < right) {
    if (word[left] != word[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

void findLongestPalindrome(std::string line, std::string &longestPalindrome,
                           int &wordCount, int &palindromeCount) {
  std::string input;
  std::stringstream ss(line);
  while (ss >> input) {
    input = trimWord(input);
    if (!input.empty()) {
      wordCount++;
      if (isPalindrome(input)) {
        palindromeCount++;
        if (input.length() > longestPalindrome.length()) {
          longestPalindrome = input;
        }
      }
    }
  }
}

int main() {
  std::string line;
  int wordCount{};
  int palindromeCount{};
  std::string longestPalindrome;
  while (std::getline(std::cin, line)) {
    findLongestPalindrome(line, longestPalindrome, wordCount, palindromeCount);
  }
  std::cout << wordCount << " words\n";
  std::cout << palindromeCount << " palindromes\n";
  if (!longestPalindrome.empty()) {
    std::cout << longestPalindrome << "\n";
  }
  return 0;
}