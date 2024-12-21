#include <iostream>

// Determind letter grade based on percentage

char LetterGrade(double grade) {
  if (grade <= 100 && 90 <= grade) {
    return 'A';
  } else if (grade < 90 && 80 <= grade) {
    return 'B';
  } else if (grade < 80 && 70 <= grade) {
    return 'C';
  } else if (grade < 70 && 60 <= grade) {
    return 'D';
  }
  return 'F';
}

std::string PassFail(double grade) {
  std::string str;
  (70 <= grade) ? str = "passed" : str = "failed";
  return str;
}

int main() {
  double grade;
  bool passFail;
  char choice;

  std::cout << "What is your grade?: ";
  std::cin >> grade;

  std::cout << "Do you want pass/fail? (if so type 'y'): ";
  std::cin >> choice;

  choice == 'y' ? passFail = true : passFail = false;

  if (passFail) {
    std::cout << "You " << PassFail(grade) << " the class!\n";
  } else {
    char letter = LetterGrade(grade);
    if ((letter == 'A') || (letter == 'F')) {
      std::cout << "You recieved an " << letter << " (" << grade << "%) in the class!\n";
    } else {
      std::cout << "You recieved a " << letter << " (" << grade << "%) in the class!\n";
    }
  }

  return 0;
}
