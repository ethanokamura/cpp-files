#include <iomanip>  // for setprecision
#include <iostream>

// Assign a barcode based on the last digit in the zipcode
std::string code(int id) {
  if (id == 9)
    return "|:|::";
  else if (id == 8)
    return "|::|:";
  else if (id == 7)
    return "|:::|";
  else if (id == 6)
    return ":||::";
  else if (id == 5)
    return ":|:|:";
  else if (id == 4)
    return ":|::|";
  else if (id == 3)
    return "::||:";
  else if (id == 2)
    return "::|:|";
  else if (id == 1)
    return ":::||";
  else
    return "||:::";  // default value (0)
}

int main() {
  int zipcode = 0;
  int checkDigit = 0;  // "Add up all digits, and choose the check digit to make
                       // the sum a multiple of 10"
  std::string barcode = "";  // This will be the actual barcode
  std::string endStr = "";

  std::cout << "Enter a 5 zipcode zipcode: ";
  std::cin >> zipcode;

  if (!std::cin.fail() && zipcode < 100000 &&
      10000 <= zipcode) {  // check if it is indeed a valid integer that is 5
                           // digits in length
    for (int i = 5; 0 < i;
         i--) {  // for each digit in zipcode do this code and decrement
      int n = zipcode % 10;  // grab the value of the last digit in the int and
                             // set it equal to n
      zipcode /= 10;    // shave off the last digit. ie 12345 would turn to 1234
      checkDigit += n;  // add n to the sum of check digit for later
      barcode = code(n) +
                endStr;  // add the ID created by the function above to the
                         // barcode. add the previously created barcode to the
                         // butt. without this the barcode prints backwards
      endStr =
          barcode;  // set the ending barcode to the current value of barcode
    }
    checkDigit =
        10 - checkDigit %
                 10;  // Add the sum, find the end digit and subtract it from 10
                      // to get the remainder. this is now your check digit
    std::cout << "|" << barcode + code(checkDigit) << "|"
              << std::endl;  // print out the full barcode including the check
                             // digit at the end
  } else {
    std::cout << "Invalid Zipcode" << std::endl;
  }

  return 0;
}
