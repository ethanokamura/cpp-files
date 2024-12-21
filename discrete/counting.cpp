#include <iostream>
#include <string>

using namespace std;

long long factorial(unsigned int n) {
  if (n == 0 || n == 1) return 1;
  long long res = 1;
  for (int i = 1; i <= n; i++) res *= i;
  return res;
}

int choose(int n, int k) {
  int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

long long permutations(int n, int k) { return factorial(n) / factorial(n - k); }

int rderangement(int n) {
  if (n == 0) return 1;
  if (n == 1) return 0;
  return (n - 1) * (rderangement(n - 1) + rderangement(n - 2));
}

int derangement(int n) {
  int d[n + 1] = {0};
  // base case
  d[1] = 0;
  d[2] = 1;
  for (int i = 3; i <= n; i++) d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
  return d[n];
}

int main() {
  string line;
  while (getline(cin, line)) {
    string str;
    string command;
    bool is_num = (line[0] >= 48 && line[0] <= 57);
    int x = -1;
    int y = -1;
    for (char c : line) {
      if (c == ' ') {
        if (is_num) {
          x = stoi(str);
          is_num = false;
        } else {
          command = str;
        }
        str = "";
      } else {
        str += c;
      }
    }
    y = stoi(str);

    if (command == "choose") {
      if (x < y)
        cout << "invalid args: n < k\n";
      else
        cout << x << " choose " << y << " has " << choose(x, y) << " choices\n";
    } else if (command == "permute") {
      if (x < y)
        cout << "invalid args: n < k\n";
      else
        cout << x << " permutes " << y << " has " << permutations(x, y)
             << " permutations\n";
    } else if (command == "rderangement") {
      cout << y << " has " << rderangement(y) << " derangements\n";
    } else if (command == "derangement") {
      cout << y << " has " << derangement(y) << " derangements\n";
    } else {
      cout << "invalid args\n";
    }
  }

  return 0;
}