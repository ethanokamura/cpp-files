#ifndef _BLACKJACK_HAND_H
#define _BLACKJACK_HAND_H

#include <compare>
#include <set>
#include <string>
#include <unordered_map>

namespace paperwrld {
class BlackjackHand {
 public:
  BlackjackHand(const BlackjackHand &that);
  BlackjackHand(std::initializer_list<std::string> cards);
  BlackjackHand &operator+=(const std::string card);
  std::string to_string() const;
  std::size_t size() const;
  operator bool() const;
  auto operator<=>(const BlackjackHand &that) const;
  bool operator==(const BlackjackHand &that) const;
  bool operator!=(const BlackjackHand &that) const;
  int numeric_value() const;

 private:
  char _val[13] = {'2', '3', '4', '5', '6', '7', '8',
                   '9', 'T', 'J', 'Q', 'K', 'A'};
  char _suit[4] = {'H', 'D', 'S', 'C'};
  std::set<std::string> _hand;
  std::unordered_map<std::string, int> _deck;
  int card_count() const { return -this->size(); }
};
}  // namespace paperwrld
#endif  // _BLACKJACK_HAND_H
