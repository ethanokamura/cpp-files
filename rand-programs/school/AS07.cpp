#include <iostream>
#include <string>
#include <vector>
// return "[card1 card2]";
std::string to_string(std::vector<std::string> _hand) {
  std::string temp;
  int size = _hand.size();
  temp += '[';
  for (int i = 0; i < size; i++) {
    (i !=  size - 1) ? (temp += _hand.at(i) + ' ') : temp += _hand.at(i);
  }
  temp += ']';
  return temp;
}

int main() {
  std::vector<std::string> hand;
  hand.push_back("AH");
  hand.push_back("QD");
  hand.push_back("QD");
  std::cout << to_string(hand) << '\n';
  return 0;
}