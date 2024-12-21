#include <cmath>  // adds stuff like floor, ceil, and pow
#include <iostream>

// C++ uses PEMDAS!!
// % gets the remainder from division equation
// (7 % 3 = 1)

// << is pushing out
// >> is taking in

// cin == stream extraction operator
// you can have multiple inputs: cin >> x >> y;
// and multiple outputs: cout << "x + y = " << x + y;

using namespace std;

int main() {
  int x = 100;      // whole numbers
  double a = 4.20;  // allows for floating numbers
  float f = 4.20f;
  long l = 420L;
  char c = 'a';
  bool b = true;

  double roundUp = ceil(a);     // 5
  double roundDown = floor(a);  // 4
  double powr = pow(x, (0.5));  // 10

  double kush = x * a;  // == 420

  // Placement of "++" tells script when to increment
  int y = x++;  // x = 11, y = 10
  int z = ++x;  // x = 11, z = 11

  string name;

  cout << "whats your name: " << endl;
  cin >> name;

  cout << "ayo " << name << " its " << kush << "PM trust me :)"
       << endl;  // "ayo its 420"
  return 0;
}