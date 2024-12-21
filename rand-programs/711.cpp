#include <cmath>    // adds stuff like floor, ceil, and pow
#include <cstdlib>  // adds random
#include <ctime>    // adds time
#include <iostream>

int main() {
  // seed random (sets what random is based on)
  srand(time(0));

  // input name
  std::string name;
  std::cout << "whats your name: " << std::endl;
  std::cin >> name;

  // user input and came conditions
  char choice;
  char canRoll = true;
  bool gameOn = true;

  while (gameOn) {
    // shows prompt
    if (canRoll) {
      std::cout << "Do you wanna roll? [y/n]: ";
      std::cin >> choice;
    }

    if (choice == 'y') {
      canRoll = false;
      int r1 = (rand() % 6) + 1;
      int r2 = (rand() % 6) + 1;
      int sum = r1 + r2;
      std::cout << "You rolled a " << r1 << ", and a " << r2 << std::endl;

      // winning conditions
      if (sum == 7 || sum == 11) {
        // sends msg and ends game
        std::cout << name << " won!" << std::endl;
        gameOn = false;
      } else
        canRoll = true;

    } else {
      std::cout << "Goodbye";
      gameOn = false;
    }
  }

  return 0;
}