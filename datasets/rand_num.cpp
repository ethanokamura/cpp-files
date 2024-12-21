#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  srand(time(NULL));
  size_t size = 10;
  std::string file_name = "./data/ints/";
  if (argv[1]) size = std::stoi(argv[1]);
  if (argv[2]) file_name += argv[2];
  else file_name += "junk.txt";
  ofstream file(file_name);
  for (int i = 0; i < size; i++) {
    int value = rand() % 100000000;
    file << std::setfill('0') << std::setw(9) << value << '\n';
  }
  file.close();
  return 0;
}