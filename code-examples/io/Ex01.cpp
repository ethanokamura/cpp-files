#include <iostream> 
#include <cmath> 
#include <iomanip>

using namespace std;

//  Write a program that asks for the lengths of the side of a rectangle

int main () {
  
  double w;
  double h;
  double area;
  double perimeter;
  double diagonal;

  cout << "Enter width: ";
  cin >> w;
  cout << "Enter height: ";
  cin >> h;

  area = w * h;
  perimeter = (2 * w) + (2 * h);
  double x = pow(w, 2) + pow(h, 2);
  diagonal = sqrt(x);

  cout << "Area: " << fixed << setprecision(2) << area << endl;
  cout << "Perimeter: " << fixed << setprecision(2) << perimeter << endl;
  cout << "Diagonal length: " << fixed << setprecision(2) << diagonal << endl;

}
