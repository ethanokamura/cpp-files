#include <time.h>

#include <cstdlib>
#include <iostream>

int main() {
  srand(time(0));
  int guesses = 0;
  int target = rand() % 100 + 1;

  while (guesses < 7) {
    int guess;
    std::cout << "guess a number between 1 and 100:\n";
    std::cin >> guess;
    guesses++;
    if (target == guess) {
      std::cout << "you win! the number was: " << target << '\n';
      break;
    } else if (guess < target) {
      std::cout << "too low\n";
    } else if (guess > target) {
      std::cout << "too high\n";
    }
  }

  if (guesses == 7) std::cout << "you lose, the number was: " << target << '\n';

  return 0;
}