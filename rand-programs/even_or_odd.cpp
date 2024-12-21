#include <cctype>
#include <iostream>
#include <vector>

std::vector<std::string> EvenOrOdd(std::vector<std::string> v) {
  int sum = 0;
  std::vector<std::string> even, odd, empty;

  // Unload each string in the vector
  for (std::string str : v) {
    std::string word;
    // Check each character in string for legal characters
    for (char c : str) {
      c = tolower(c);
      if (isalnum(c)) sum++;
      word += c;
    }
    // Add to the correct parent string
    if (sum % 2 == 0)
      even.push_back(word);
    else
      odd.push_back(word);
    sum = 0;
  }

  // Return the correct string
  if (even.size() < odd.size())
    return odd;
  else if (odd.size() < even.size())
    return even;
  else
    return empty;
}

int main() {
  std::string str;
  std::vector<std::string> v;

  while (std::cin >> str) v.push_back(str);

  // If Vec is not blank, print characters from even or odd strings
  if (!EvenOrOdd(v).empty())
    for (std::string str : EvenOrOdd(v)) std::cout << str << '\n';

  return 0;
}
