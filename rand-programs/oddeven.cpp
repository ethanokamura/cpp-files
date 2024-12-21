/*
  Ethan Okamura
  ethanokamura3@gmail.com
  CS19: Assignment 4 (Resubmission)
  Due 11/24/2022
  EvenOrOdd

  Take in an unknown amount of strings.
  Decide if there is an even or odd amount of legal characters in each string.
  Add the total of legal characters for even and odd sized strings.
  Compare the totals and output the one with the higher value.
  If number of even and odd characters are equal output nothing.
*/

#include <cctype>
#include <iostream>
#include <vector>

std::vector<std::string> EvenOrOdd(std::vector<std::string> v) {
  int sum = 0;
  int evenSum = 0;
  int oddSum = 0;

  std::vector<std::string> even;
  std::vector<std::string> odd;
  std::vector<std::string> empty;

  // Unload each string in the vector
  for (int i = 0; i < v.size(); i++) {
    std::string word;
    std::string temp = v.at(i);

    // Check each character in string for legal characters
    for (int j = 0; j < temp.size(); j++) {
      temp[j] = tolower(temp[j]);
      if (isalnum(temp[j])) sum++;
      word += temp[j];
    }
    // Add to the correct parent string
    if (sum % 2 == 0) {
      even.push_back(word);
      evenSum += sum;
    } else {
      odd.push_back(word);
      oddSum += sum;
    }

    sum = 0;
  }

  // Return the correct string
  if (evenSum < oddSum)
    return odd;
  else if (oddSum < evenSum)
    return even;
  else
    return empty;
}

int main() {
  std::string temp;
  std::vector<std::string> v;

  while (std::cin >> temp) {
    v.push_back(temp);
  }

  std::vector<std::string> vEvenOdd = EvenOrOdd(v);

  // If Vec is not blank, print characters from even or odd strings
  if (0 < vEvenOdd.size()) {
    for (int i = 0; i < vEvenOdd.size(); i++) {
      std::cout << vEvenOdd[i] << std::endl;
    }
  }

  return 0;
}
