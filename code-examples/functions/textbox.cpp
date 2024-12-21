#include <iostream>

// 10/25/2022
// functions

void TextBox (std::string s, char c) {
  
  std::cout << c;
  for (int i = 0; i < s.length() +2; i++) {
    std::cout << "-";
  } std::cout << c <<std::endl;

  std::cout<< "| " << s << " |" <<std::endl;

  std::cout << c;
  for (int i = 0; i < s.length() +2; i++) {
    std::cout << "-";
  } std::cout << c <<std::endl;

  return;
}

int main () {
  std::string name;
  char c;
  std::cout<< "what is your name: ";
  getline(std::cin, name);
  std::cout<< "what is your character: ";
  std::cin >> c;

  TextBox(name, c);

  return 0;
}
