#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

class SlotMachine {
 private:
  char symbols[8] = { '$', '@', '%', '!', '#', '*', '&', '7' };
  int _tokens, _slotCount;
  std::vector<char> slots;
  void Spin(int slotCount);
  void PrintMachine(std::vector<char> slots);
 public:
	double cash;
	int tickets;
	SlotMachine();
	void BuyTokens();
	void Play();
};

int main() {
	srand(time(0));
	SlotMachine slot;
	slot.cash = 1.5;
	std::cout << "Welcome to the CodeSantaCruz Arcade!\n";
	std::cout << "Would you like to buy _tokens? (y/n):\n";
	char input;
	std::cin >> input;
	if (input == 'y') {
		slot.BuyTokens();
		slot.Play();
	}
	std::cout << "You ended with " << slot.tickets << " tickets!\n";
	return 0;
}