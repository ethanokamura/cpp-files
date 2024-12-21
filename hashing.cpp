#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// f(x)
int convert_fn(char c) { return static_cast<int>(c); }

// h(s)
int hash_fn(string str) {
  int n = str.length();
  long long hashed_value{};
  for (int i = 0; i < n; i++) {
    hashed_value += convert_fn(str[i]) * pow(131, n - (i + 1));
  }
  return hashed_value % static_cast<int>(pow(10, 9) + 7);
}

bool valid_hash(string old_password, int hash_varient) {
  char min_c = static_cast<char>(0);
  char max_c = static_cast<char>(127);
  string min_str = old_password + min_c;
  string max_str = old_password + max_c;
  int min = hash_fn(min_str);
  int max = hash_fn(max_str);
  return hash_varient <= max && hash_varient >= min;
}

vector<int> authEvents(vector<vector<string>> events) {
  vector<int> res;

  int hash{};
  string passwd;
  for (size_t i = 0; i < events.size(); i++) {
    if (events[i][0] == "setPassword") {
      passwd = events[i][1];
    } else if (events[i][0] == "authorize") {
      if (valid_hash(passwd, stoi(events[i][1])) ||
          hash_fn(passwd) == stoi(events[i][1])) {
        res.push_back(1);
      } else {
        res.push_back(0);
      }
    }
  }
  return res;
}

int main() {
  vector<vector<string>> events = {
      {"setPassword", "cAr1"},
      // { "setPassword", "cAr1a" },
      {"authorize", "223691457"},
      {"authorize", "303580761"},
      {"authorize", "100"},
      {"setPassword", "d"},
      {"authorize", "100"},

  };

  std::cout << hash_fn("d") << '\n';
  std::cout << hash_fn("cAr1a") << '\n';

  vector<int> res = authEvents(events);

  for (int i : res) {
    std::cout << i << '\n';
  }

  return 0;
}