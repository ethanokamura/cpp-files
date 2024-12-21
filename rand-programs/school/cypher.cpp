#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// atoi Array to Int

class Caesar{
  public:
    Caesar(int shamt); // Specify shift amount
    string encrypt(string);
    string decrypt(string);
    string simplify(string);
  private:
    char shift(char, int);
    int shamt; // (Shift amount)
};

Caesar::Caesar(int shiftAmount){
  shamt = shiftAmount;
}

// precondition: plaintext is UPPERCASE letters only
string Caesar::encrypt(string plaintext){
  string ciphertext="";
  int size = plaintext.size();
  for(int i=0; i< size; i++){
    ciphertext = ciphertext + shift(plaintext[i], shamt);
  }
  return ciphertext;
}

string Caesar::decrypt(string ciphertext){
  string plaintext="";
  int size = ciphertext.size();
  for(int i=0; i< size; i++){
    plaintext = plaintext + shift(ciphertext[i], -shamt);
  }
  return plaintext;
}

// return edited copy of string with only UPPERCASE letters
string Caesar::simplify(string text){
  string simplified="";
  int size = text.size();
  for(int i=0; i<size; i++){
    if (isalpha(text[i])){
      simplified = simplified + (char) toupper(text[i]);
    }
  }
  return simplified;
}

char Caesar::shift(char c, int shamt){
  // cout << " char was:" << c << " with value:" << c -'A' << endl;
  int result = (c - 'A' + shamt); // -'A' (-65 ASCII id)
  if (result >= 26) result = result - 26; // wrap around
  if (result < 0) result = result + 26; // wrap around
  return result + 'A'; // +'A' (+65 ASCII id)
}

int main(int argc, char *argv[]){
  /*
    cout << "argc is " << argc << endl;
    for(int i = 0; i< argc; i++){
    cout << i << ": " << argv[i] << endl;
    }
  */
  if (argc != 3){
    cerr << "USAGE: " << argv[0] << " -d|e shiftAmount" << endl;
    exit(1);
  }
  
  int shamt = atoi( argv[2] );
  
  bool encrypt;
  string option( argv[1] ); // -d or -e
  string line; // input
  string encodedLine; // encoded input
  
  if (option == "-e") { encrypt = true; } 
  else { encrypt = false; }
  
  Caesar cipher(shamt); // Amount to shift is sent to constructor
  
  while( getline(cin, line) ){
    if (encrypt) { encodedLine = cipher.encrypt(cipher.simplify(line)); } 
    else { encodedLine = cipher.decrypt(line); }
    cout << encodedLine << endl;
  }
  
  return 0;
}
