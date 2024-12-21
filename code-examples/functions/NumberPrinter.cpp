#include <iostream>

// 11/01/2022
// Convert Numbers to Words

std::string DigitsName(int n) { // 0-9  
  if (n == 9) return "nine";
  else if (n == 8) return "eight";
  else if (n == 7) return "seven";
  else if (n == 6) return "six";
  else if (n == 5) return "five";
  else if (n == 4) return "four";
  else if (n == 3) return "three";
  else if (n == 2) return "two";
  else if (n == 1) return "one";
  else return "zero";
}
std::string TeensName(int n) { // 11-19
  if (n == 19) return "nineteen";
  else if (n == 18) return "eighteen";
  else if (n == 17) return "seventeen";
  else if (n == 16) return "sixteen";
  else if (n == 15) return "fifteen";
  else if (n == 14) return "fourteen";
  else if (n == 13) return "thirteen";
  else if (n == 12) return "twelve";
  else if (n == 11) return "eleven";
  else return "eleven";
}
std::string TensName(int n) { // 20-90
  if (90 <= n) return "ninety";
  else if (80 <= n) return "eighty";
  else if (70 <= n) return "seventy";
  else if (60 <= n) return "sixty";
  else if (50 <= n) return "fifty";
  else if (40 <= n) return "forty";
  else if (30 <= n) return "thirty";
  else if (20 <= n) return "twenty";
  else if (10 <= n) return "ten";
  else return "twenty";
}
std::string HundredsName(int n) { // 100-900
  int x = n / 100;
  std::string result = DigitsName(x) + " hundred";
  return result;
}

int main () {

  std::cout << "n: ";
  int n;
  std::cin >> n;

  while (0 <= n && n <= 999) {
    std::string result;

    if (n>99) {
      result += HundredsName(n) + " ";
      n %= 100;
    }

    if (20<n) {
      result += TensName(n) + " ";
      n %= 10; 
      if (n!=0) result += DigitsName(n);
    } 
  
    else if (9<n && n<20) result += TeensName(n);
    else if (n<=9) result += DigitsName(n);
  
    std::cout << result << std::endl;
    std::cout << "n: ";
    std::cin >> n;
  }
  return 0;
}
