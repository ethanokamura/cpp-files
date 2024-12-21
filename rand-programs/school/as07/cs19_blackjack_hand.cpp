#include "cs19_blackjack_hand.h"
#include <string>
#include <compare>
#include <set>
#include <unordered_map>

using namespace cs19;

BlackjackHand::BlackjackHand(const BlackjackHand &that) {
  for (std::string card : that._hand)
    this->_hand.insert(card);
}

BlackjackHand::BlackjackHand(std::initializer_list<std::string> cards) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      std::string card = "";
      card += _val[j];
      card += _suit[i];
      this->_deck.insert(std::pair<std::string, int>(card, 1));
    }
  }
  for (std::string card : cards)
    *this += card;
}

BlackjackHand& BlackjackHand::operator+=(const std::string card) {
  auto it = this->_deck.find(card);
  if (it == this->_deck.end() || it->second != 1) {
    throw std::invalid_argument("invalid arg");
  } else if (!*this) {
    throw std::logic_error("logic err");
  } else {
    this->_hand.insert(card);
    it->second = 0;
  }
  return *this;
}

std::string BlackjackHand::to_string() const {
  std::string temp;
  for (std::string card : this->_hand)
    temp += card + ' ';
  temp = temp.substr(0, temp.length() - 1);
  return '[' + temp + ']';
};

std::size_t BlackjackHand::size() const {
  return this->_hand.size();
}

BlackjackHand::operator bool() const {
  return (this->numeric_value() <= 21 && this->numeric_value() != -1);
}

  auto BlackjackHand::operator<=>(const BlackjackHand &that) const {
    if (this->numeric_value() == 21 && that.numeric_value() == 21 && this->size() != that.size())
      return this->card_count() <=> that.card_count();
    return this->numeric_value() <=> that.numeric_value();
  }

bool BlackjackHand::operator==(const BlackjackHand &that) const {
  return this->numeric_value() == that.numeric_value() ? true : false;
}

bool BlackjackHand::operator!=(const BlackjackHand &that) const {
  if (this->numeric_value() == 21 && that.numeric_value() && this->size() != that.size())
    return true;
  return this->numeric_value() != that.numeric_value() ? true : false;
}

int BlackjackHand::numeric_value() const {
  int val = 0;
  bool has_ace = false;
  if (this->size() == 0) return 0;
  for (std::string card : this->_hand) {
    char c = card[0];
    if (c == '2') val += 2;
    else if (c == '3') val += 3;
    else if (c == '4') val += 4;
    else if (c == '5') val += 5;
    else if (c == '6') val += 6;
    else if (c == '7') val += 7;
    else if (c == '8') val += 8;
    else if (c == '9') val += 9;
    else if (c == 'T' || c == 'J' || c == 'Q' || c == 'K') val += 10;
    else val += 1;
  }
  for (std::string card : this->_hand)
    if (card[0] == 'A' && !has_ace) has_ace = true;
  if (has_ace && val <= 11) return val+10;
  if (val > 21) return -1;
  return val;
}
