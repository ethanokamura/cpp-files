#include <iostream>

// Ethan Okamura
// 10/11/2022
// Class Exercise

int main() {

  std::string word;
  std::cout<< "Type a word: ";
  std::cin >> word;
  std::cout << std::endl;

  int vowels = 0;

  for (int i = 0; i < word.size(); i++) {
    word[i] = tolower(word[i]);
    if(
      word[i] == 'a' ||
      word[i] == 'e' || 
      word[i] == 'i' ||
      word[i] == 'o' ||
      word[i] == 'u'
      ) 
    vowels++;
  }

  vowels == 1
  ? std::cout << "There is " << vowels << " vowel in that word!" << std::endl
  : std::cout << "There are " << vowels << " vowels in that word!" << std::endl;

  return 0;

}
