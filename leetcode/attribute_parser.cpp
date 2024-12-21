#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

string get_tags_path(vector<string> tags) {
    string path;
    for (string tag : tags) { path += tag + '.'; }
    path = path.substr(0, path.length() - 1);
    return path;
}

int main() {
  // input details
  int input_lines {};
  int query_lines {};
  cin >> input_lines >> query_lines;

  // global vars
  int index {1};
  vector<string> tags;
  unordered_map<string, unordered_map<string, string>> attribute_map;
  
  // input
  string line;
  while (getline(cin, line) && index <= input_lines) {
    // parse
    stringstream ss(line);
    string token;
    int tokens {};

    // values
    string tag_name;
    string key;
    while (ss >> token) {
      if (tokens == 0) {
        tag_name = token.substr(1, token.length());
        if (token[1] == '/') tags.pop_back();
        else tags.push_back(tag_name);
      } else if (tokens == 3) {
        if (token.length() > 2 && token[0] == '"' && !key.empty()) {
          string query = get_tags_path(tags);
          string value;
          if (token[token.length() - 1] == '>') {
            value = token.substr(1, token.length() - 3);
          } else {
            value = token.substr(1, token.length() - 2);
          }
          attribute_map[query][key] = value;
          key = "";
        }
        tokens = 0;
      } else if (tokens == 1) {
        key = token;
      }
      tokens++;
    }
    index++;
  }
  
  index = 1;
  
  while (getline(cin, line) && index <= query_lines) {
    string query;
    string attribute;
    bool first {true};
    for (char c : line) {
      if (c == '~') {
        first = false;
      } else {
        if (first) query+= c;
        else attribute += c;
      }
    }
    auto it = attribute_map[query].find(attribute);
    if (it != attribute_map[query].end()) {
      cout << attribute_map[query][attribute] << '\n';
    } else {
      cout << "Not Found!\n";
    }
    index++;
  }
  
  return 0;
}