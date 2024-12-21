#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string s) {
  vector<char> v;
  if (s.length() == 1) return false;
  for (int i = 0; i < s.length(); i++) {
    if (v.size() > 0) {
      if ((s[i] == ')' && v[v.size() - 1] != '(') ||
          (s[i] == ']' && v[v.size() - 1] != '[') ||
          (s[i] == '}' && v[v.size() - 1] != '{'))
        return false;
      if ((s[i] == ')' && v[v.size() - 1] == '(') ||
          (s[i] == ']' && v[v.size() - 1] == '[') ||
          (s[i] == '}' && v[v.size() - 1] == '{'))
        v.pop_back();
      else
        v.push_back(s[i]);
    } else {
      v.push_back(s[i]);
    }
  }
  return v.size() == 0;
}

int main() {
  vector<string> v = {"()", "[]", "{}", "({[]})", "(]", "(})", "{]}"};
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << (isValid(v[i]) ? " is valid" : " is not valid") << '\n';
  }
  return 0;
}
