#include <iostream>
#include <unordered_map>
#include <set>
#include <fstream>
#include <sstream>

bool is_letter(char c) {
  if (c >= 'a' && c <= 'z') return true;
  return false;
}

std::string edit_word(std::string str) {
  std::string temp = "";
  int size = str.length();
  int x = 0;
  for (int i = size; i > 0; i--) {
    if (is_letter(str[i]) || (str[i] >= 'A' && str[i] <= 'Z')) {
      x = i;
      break;
    }
  }
  bool start = false;
  for (int i = 0; i < x+1; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') str[i] += ('a' - 'A');
    if (is_letter(str[i])) start = true;

    if (start) temp += str[i];
  }
  return temp;
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

  std::string word;
  while (std::cin >> word) {
    word = edit_word(word);
    if (phoneme_map.count(word) == 0 && word[0] == '\'')
      word = word.substr(1, word.length());
    auto range = phoneme_map.equal_range(word);
    if (phoneme_map.count(word) > 0) {
      for (auto itr = range.first; itr != range.second; ++itr) {
      std::string modified_word = "";
        std::istringstream line_stream(itr->second);  // grab each line of phonemes
        for (std::string phoneme; line_stream >> phoneme;) {
          auto ipa_itr = ipa_map.find(phoneme);
          if (ipa_itr != ipa_map.end())  // add symbol if found
            modified_word += ipa_itr->second;
          else
            modified_word += phoneme;
        }
        _set.insert(modified_word);
      }
    }
    for (std::string str : _set)
      std::cout << str << '\n';
    _set.clear();
  }
  return 0;
}
