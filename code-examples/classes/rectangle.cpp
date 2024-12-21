#include <iostream>

// Ethan Okamura
// 11/29/2022
// Rectangle Class
// Class Exercise

class Rectangle {
  public:
    Rectangle(double l, double w);
    void Display(double factor);
    double GetPerimeter();
    double GetArea();
    double Resize(double factor);

  private:
    double _l;
    double _w;
};

Rectangle::Rectangle(double l, double w) {
  _l = l;
  _w = w;
}
double Rectangle::GetPerimeter() {
  return _l*2 + _w*2;
}
double Rectangle::GetArea() {
  return _l*_w;
}
double Rectangle::Resize(double factor) {
  _l *= factor;
  _w *= factor;
  return _l * _w;
}
void Rectangle::Display(double factor) {
  std::cout << "Perimeter: " << GetPerimeter() << std::endl;
  std::cout << "Area: " << GetArea() << std::endl;
  std::cout << "Resized area: " << Resize(factor) << std::endl;
}

int main () {
  double x;
  double l, w;

  std::cout << "Enter Length: ";
  std::cin >> l;
  std::cout << "Enter Width: ";
  std::cin >> w;
  std::cout << "Enter Factor: ";
  std::cin >> x;

  Rectangle r (l, w);
  r.Display(x);

  return 0;
}
