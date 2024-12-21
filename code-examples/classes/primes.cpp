#include <iostream>
#include <vector>

using namespace std;

class FE{
public:
 FE();
  void addValue(int); // value added to array if room, adds one to size
  int maxValue(); // return max value or -1

private:
  int size; // size always between 0 and 100
  int values[100];
};

int FE::maxValue() {
  int max = 0;

  if (size == 0) return -1;

  for (int i=0; i<size; i++) {
    if (max<i) i=max;
  }
  return max;
}
 

int main () {
  int primes[]={2,3,5,7,11};
  for (int i = 0; i < 2; i++){
    primes[4 - i] = primes[i];
  }

  for (int i = 0; i < 5; i++) {
    cout << primes[i] << " ";
  }
  cout << endl;
  
  return 0;
}
