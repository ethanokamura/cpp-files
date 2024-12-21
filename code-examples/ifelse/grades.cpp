#include <iostream>
#include <iomanip> // used to output grade percentage in class

// Ethan Okamura
// Letter Grade Assignment
// 09.27.22 (in class)

int main() {

  double grade;
  int choice;
  char letterGrade;
  std::string passOrFail;

  std::cout << "What is your overall score in the class?: ";
  std::cin >> grade;
  std::cout << std::endl;
  
  std::cout << "Do you want pass/fail?" << std::endl;
  std::cout << "1 for pass/fail or 2 for letter grade: ";
  std::cin >> choice;
  std::cout << std::endl;

  if (grade <= 100 && 90 <= grade) letterGrade = 'A';
  else if (grade < 90 && 80 <= grade) letterGrade = 'B';
  else if (grade < 80 && 70 <= grade) letterGrade = 'C';
  else if (grade < 70 && 60 <= grade) letterGrade = 'D';
  else letterGrade = 'F';

  70 <= grade ? passOrFail = "passed" : passOrFail = "failed";

  if (choice == 1) {
    std::cout << "You " << passOrFail << " the class!" << std::endl;
  } else {
    if ((letterGrade = 'A') || (letterGrade = 'F')) {
      std::cout << "You recieved an " << letterGrade << " (" << grade << "%)" << " in the class!" << std::endl;
    } else {
      std::cout << "You recieved a " << letterGrade << " in the class!" << std::endl;
    }
  }

  return 0;
}
