#include <time.h>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

class SlotMachine {
 public:
  // default constructor
  SlotMachine();
  // dollar constructor
  SlotMachine(int dollars);
  // default destructor
  ~SlotMachine();
  // main function
  void play();
  // function to print an exit message
  void printExit();

 private:
  // slot machine symbols
  char _symbols[8]{'$', '@', '%', '!', '#', '*', '&', '7'};
  int _dollars, _slotCount;
  // slot array
  char* _slots;
  // function for each spin
  void spin();
  // print the machine
  void printMachine();
};