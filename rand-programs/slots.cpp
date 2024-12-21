#include <stdlib.h>  // srand, rand
#include <time.h>

#include <iostream>

using namespace std;

int main() {
  string symbols[8] = {"$", "@", "%", "!", "#", "", "&", "7"};
  string replay;
  bool gameOn = true;
  int bank = 1000;
  int wager = 0;

  // input name
  string username;
  cout << "Enter username: ";
  cin >> username;

  while (gameOn) {
    cout << "Bank: " << bank << endl;
    cout << "Place your bet " << username << ": ";
    cin >> wager;

    if (wager > bank) {
      cout << "Not enough money!" << endl;
      continue;
    }

    srand(time(NULL));
    string slot1 = symbols[(rand() % 7)];
    string slot2 = symbols[(rand() % 7)];
    string slot3 = symbols[(rand() % 7)];

    cout << slot1 << slot2 << slot3;

    if ((slot1 == slot2) && (slot2 == slot3)) {
      cout << " Jackpot baby!" << endl;
      bank += wager * 3;
    } else if ((slot1 == slot2) || (slot1 == slot3) || (slot2 == slot3)) {
      cout << " Duce!" << endl;
      bank += wager * 2;
    } else {
      cout << " Nada" << endl;
      bank -= wager;
    }

    if (bank <= 0) {
      cout << "Sorry " << username << " you lose!" << endl;
      gameOn = false;
    }

    if (bank > 0) {
      string continuePlaying;
      cout << "Go again? (y/n): ";
      cin >> continuePlaying;

      if ((continuePlaying == "N") || (continuePlaying == "n")) {
        gameOn = false;
      }
    }
  }

  cout << "Good job " << username << " you made: " << bank << endl;
  cout << "Enter any key to exit: ";
  cin >> replay;

  return 0;
}