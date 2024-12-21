#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <fstream>
#include <sstream>

bool end_of_word(char c) {
  if (c != '\'' && !(c >= 'a' && c <= 'z'))
    return true;
  return false;
}
bool is_letter(char c) {
  if (c >= 'a' && c <= 'z')
    return true;
  return false;
}

int main() {
  std::unordered_multimap<std::string, std::string> phoneme_map;
  std::unordered_map<std::string, std::string> ipa_map;
  std::set<std::string> _set;
  std::string key1, key2, value1, value2;
  {
    std::ifstream phoneme_file("/srv/datasets/cmudict/cmudict.dict");
      while (phoneme_file >> key1
              && phoneme_file.seekg(1, std::ios_base::cur)
          && std::getline(phoneme_file, value1)) {
      std::string temp = "";
      for (char c : key1) {
        if (c == '(') break;
        temp += c;
      }
      phoneme_map.insert(std::pair<std::string, std::string>(temp, value1));
    }
  }

  {
    std::ifstream ipa_file("/srv/datasets/arpabet-to-ipa");
    while (ipa_file >> key2 && ipa_file >> value2)
      ipa_map.insert(std::pair<std::string, std::string>(key2, value2));
  }
  // Check for duplicate output words
  std::string line;
while (std::getline(std::cin, line)) {
    std::string modified_line = "";
    std::string word = "";
    for (char c : line) {
      if (c >= 'A' && c <= 'Z') c += ('a' - 'A');
      if (end_of_word(c)) {
        if (!word.empty()) {  // if end of word and word isnt blank
          auto range = phoneme_map.equal_range(word);  // check list for word
          if (phoneme_map.count(word) > 0) {  // if word exists in the map
            for (auto itr = range.first; itr != range.second; ++itr) {
              std::string ipa_word = "";  // define and reset ipa_word
              std::istringstream line_stream(itr->second);
              for (std::string phoneme; line_stream >> phoneme;) {
                auto ipa_itr = ipa_map.find(phoneme);
                if (ipa_itr != ipa_map.end())  // add symbol if found
                  ipa_word += ipa_itr->second;
              }
              _set.insert(ipa_word);
            }
            int x = _set.size() - 1;
            for (std::string _word : _set) {
              modified_line += _word;
              if (x > 0) modified_line += '/';
              x--;
            }
            _set.clear();
          } else {
            modified_line += word;  // add regular word if its not in cmudict
          }
          word = "";  // reset word
        }
      } else {
        word += c;
      }
      if (!is_letter(c) && c != '\'') modified_line += c;
    }
    std::cout << modified_line << '\n';
  }
  return 0;
}
