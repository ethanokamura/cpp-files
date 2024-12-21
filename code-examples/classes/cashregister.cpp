#include <iostream>

class CashRegister{
  public:
    CashRegister();
    void Clear();
    void AddItem(double price);
    int GetCount();
    double GetTotal();
    void Display();
  private:
    int _itemCount;
    double _totalPrice;
};

CashRegister::CashRegister() {
  Clear();
}

void CashRegister::Clear() {
  _itemCount = 0;
  _totalPrice = 0.0;
}

void CashRegister::AddItem(double price) {
  _totalPrice += price;
  _itemCount++;
}

int CashRegister::GetCount() {
  return _itemCount;
}

double CashRegister::GetTotal () {
  return _totalPrice;
}

void CashRegister::Display () {
  std::cout << "Rung up: " << _itemCount << " item(s)" << std::endl;
  std::cout << "Total: $" << _totalPrice << std::endl;
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
