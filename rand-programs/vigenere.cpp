/*
  Ethan Okamura
  ethanokamura3@gmail.com
  CS19: Assignment 6
  Due 12/16/2022
  Vigenere Cipher

  A program based on the Ceasar Cipher shown in class.
  This cipher takes a keyword rather than a single int value to shift.
  Each letter shifts the secret phrase by the number of its placement
  ie: A = 0, B = 1, C = 2, Z = 25
  The keyword is broken down letter by letter and its value is repeated for each
  letter in the secret phrase Keyword: ABC ( 0 1 2 ) <- shifting value Phrase:
  HelloWorld Encrypted Phrase: HFNLPYOSND ( 0 1 2 0 1 2 0 1 2 0 ) <- amount to
  shift each letter

  The encrytion gets rid of all empty spaces and special characters
  returning an alpha numeric string in all uppers.
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using std::string;

class Caesar {
 public:
  Caesar(string keyword);
  string encrypt(string);
  string decrypt(string);
  string simplify(string);

 private:
  char shift(char, int);
  std::vector<int> _shifts;
};

Caesar::Caesar(string keyword) {
  _shifts.clear();
  for (int i = 0; i < keyword.size(); i++) {
    _shifts.push_back((int)(keyword[i] - 'A'));
  }
}

// precondition: plaintext is UPPERCASE letters only
string Caesar::encrypt(string plaintext) {
  string ciphertext = "";
  int n = 0;
  int size = plaintext.size();
  for (int i = 0; i < size; i++) {
    ciphertext = ciphertext + shift(plaintext[i], _shifts.at(n));
    if (n == (_shifts.size() - 1)) n = -1;
    n++;
  }
  return ciphertext;
}

string Caesar::decrypt(string ciphertext) {
  string plaintext = "";
  int n = 0;
  int size = ciphertext.size();
  for (int i = 0; i < size; i++) {
    plaintext = plaintext + shift(ciphertext[i], -_shifts.at(n));
    if (n == (_shifts.size() - 1)) n = -1;
    n++;
  }
  return plaintext;
}

// return edited copy of string with only UPPERCASE letters
string Caesar::simplify(string text) {
  string simplified = "";
  int size = text.size();
  for (int i = 0; i < size; i++) {
    if (isalpha(text[i])) {
      simplified = simplified + (char)toupper(text[i]);
    }
  }
  return simplified;
}

char Caesar::shift(char c, int shamt) {
  // cout << " char was:" << c << " with value:" << c -'A' << endl;
  int result = (c - 'A' + shamt);          // -'A' (-65 ASCII id)
  if (result >= 26) result = result - 26;  // wrap around
  if (result < 0) result = result + 26;    // wrap around
  return result + 'A';                     // +'A' (+65 ASCII id)
}

int main(int argc, char *argv[]) {
  // std::cout << "argc is " << argc << std::endl;
  // for(int i = 0; i< argc; i++){
  // std::cout << i << ": " << argv[i] << std::endl;
  // }

  if (argc != 3) {
    std::cerr << "USAGE: " << argv[0] << " -d|e keyword" << std::endl;
    exit(1);
  }

  std::string keyword = argv[2];  // set to 3rd argument

  bool encrypt;
  string option(argv[1]);  // -d or -e
  string line;             // input
  string encodedLine;      // encoded input

  if (option == "-e") {
    encrypt = true;
  } else {
    encrypt = false;
  }

  Caesar cipher(keyword);  // sends key to constructor

  while (std::getline(std::cin, line)) {
    if (encrypt) {
      encodedLine = cipher.encrypt(cipher.simplify(line));
    } else {
      encodedLine = cipher.decrypt(line);
    }
    std::cout << encodedLine << std::endl;
  }

  return 0;
}
