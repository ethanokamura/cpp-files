#include "slot_machine.h"

// default constructor
SlotMachine::SlotMachine() : _dollars(0), _slotCount(5) {
  _slots = new char[0];
}

// dollar constructor
SlotMachine::SlotMachine(int dollars) : _dollars(dollars), _slotCount(5) {
  _slots = new char[5];
}

// default destructor
SlotMachine::~SlotMachine() {
  delete _slots;
}

// main function
void SlotMachine::play() {
  while (true) {
    double costToPlay = 20;
    _dollars -= costToPlay;
    spin();
    std::cout << "You still have $" << _dollars << '\n';
    std::cout << "Would you like to continue playing? (y/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 'n') break;
    if (_dollars <= 0) break;
    std::cout << "\033[2J\033[1;1H";
  }
}

// function to print an exit message
void SlotMachine::printExit() {
  std::cout << "PerfectLine Slot Machine\n\n";
  std::cout << "You ended with $" << _dollars << ". Goodbye!\n\n";
}

// function for each spin
void SlotMachine::spin() {
  std::cout << "PerfectLine Slot Machine\n\n";
  std::cout << "spin all 7's:   $1000\nspin three 7's:  $500\neach 7 spun:      $50\n\n\n";
  std::cout << "current balance: $" << _dollars << "\n\n";

  printMachine();
  int sevens {0};
  for (int i = 1; i < _slotCount; i++)
    if (_symbols[7] == _slots[i]) sevens++;
  int profit {};
  if (sevens == _slotCount) {
    std::cout << "Ultra Jackpot!!!\n";
    profit = 1000;
  } else if (sevens == (_slotCount / 2) + 1) {
    std::cout << "Triple 7 Jackpot!\n";
    profit = 500;
  } else if (sevens > 0) {
    profit = sevens * 50;
    std::cout << "No jackpot, but you recieved $" << profit << "!\n";
  } else {
    std::cout << "nothing...\n";
  }
  _dollars += profit;
}

// print the machine
void SlotMachine::printMachine() {
  std::cout << std::setw(_slotCount + 3) << std::setfill('-') << '\n';
  std::string placeholder = "-";
  char value {};
  for (int i = 0; i < _slotCount; i++) {
    for (int j = 0; j < 10; j++) {
      value = _symbols[std::rand() % 8];
      std::cout << '\r' << placeholder << value << std::flush;
      std::cout << std::setw(_slotCount - i + 1) << std::setfill('-');
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    placeholder += value;
    _slots[i] = value;
  }
  std::cout << std::endl;
  std::cout << std::setw(_slotCount + 3) << std::setfill('-') << '\n';
  std::cout << std::endl;
}