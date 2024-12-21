#include <iostream>
#include <vector>

class CashRegister{
  public:
    CashRegister();
    void Clear();
    void AddItem(double price);
    int GetCount();
    void GetTotal();
    void Display();
  private:
    std::vector<double> _prices;
    
};

CashRegister::CashRegister() {
  Clear();
}

void CashRegister::Clear() {
  _prices.clear();
}

void CashRegister::AddItem(double price) {
  _prices.push_back(price);
}

int CashRegister::GetCount() {
  return _prices.size();
}

void CashRegister::GetTotal () {
  double total = 0;
  for (int i = 0; i < _prices.size(); i++) { 
    std::cout << "Item #" << i + 1 << ": " << _prices.at(i) << std::endl;
    total += _prices.at(i); 
  }
  std::cout << "Total: " << total << std::endl;
}

void CashRegister::Display () {
  std::cout << "Rung up: " << GetCount() << " item(s)" << std::endl;
  GetTotal();
}

int main () {
  CashRegister cr;
  CashRegister cr2;

  cr.AddItem(2.50);
  cr.AddItem(2.50);
  cr.AddItem(2.50);
  cr.AddItem(2.50);

  cr2.AddItem(0.99);
  cr2.AddItem(0.99);
  cr2.AddItem(0.99);
  cr2.AddItem(0.99);
  cr2.AddItem(0.99);

  cr.Display();
  cr2.Display();

  return 0;
}
