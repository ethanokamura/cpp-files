#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  srand(time(NULL));
  string input;
  vector<string> word_list;
  {
    ifstream file("./d4d/random_words.txt");
    while (file >> input)
      word_list.push_back(input);
  }
  size_t list_size = word_list.size();
  size_t size = 10;
  std::string file_name = "./data/strings/";
  if (argv[1]) size = std::stoi(argv[1]);
  if (argv[2]) file_name += argv[2];
  else file_name += "junk.txt";
  ofstream file(file_name);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < (rand() % size); j++) {
      string word = word_list[rand() % list_size];
      file << word << ' ';
    }
    file << '\n';
  }
  file.close();
  return 0;
}