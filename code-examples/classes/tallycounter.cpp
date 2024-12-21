#include <iostream>

// Ethan Okamura
// 11/29/2022
// TallyCounter Class
// Class Exercise

class TallyCounter {
  public:
    TallyCounter();
    void Clear();
    void Increment(int n);
    void Display();
  private:
    int _count;
};

TallyCounter::TallyCounter() {
  Clear();
}
void TallyCounter::Clear() {
  _count = 0;
}
void TallyCounter::Increment(int n) {
  _count += n;
  if (_count <= 10000) {
    _count = 0;
  }
}
void TallyCounter::Display () {
  std::cout << "Count: " << _count << "(type r to clear)" << std::endl;
}

int main () {
  TallyCounter counter;

  char input;
  while(std::cin >> input) { 
    counter.Increment(1);
    if (input == 'r' || input == 'R') counter.Clear();
    counter.Display();
  };

  return 0;
}
