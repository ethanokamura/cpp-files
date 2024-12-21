#include <iostream>
#include "slot_machine.h"

int main(int argc, char** argv) {
  srand(time(0));
  int dollars {0};
  if (argc > 0) dollars = std::stoi(argv[1]);
  char choice;
  std::cout << "Welcome to the PerfectLine slot machine!\n\n";
  SlotMachine slot{dollars};
  std::cout << "Try to get as much money as possible! Hit any amount of 7's to get some money back!\n";
  std::cout << "You have $" << dollars << " to start with...\n\n";
  std::cout << "Would you like to play? (y/n): ";
  std::cin >> choice;
  std::cout << std::endl;
  if (choice == 'y' || choice == 'Y') {
    std::cout << "\033[2J\033[1;1H";
    slot.play();
  }
  std::cout << "\033[2J\033[1;1H";
  slot.printExit();
  return 0;
}
