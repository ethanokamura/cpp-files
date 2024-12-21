#include <iomanip>  // for setprecision
#include <iostream>

// Ethan Okamura
// Assignment 2
// Taxes in 1913

int main() {
  double income;
  double incomeTaxed = 0;  // The amount above the bracket that will be taxed
  double amountDue = 0;    // Sum of taxed income

  // Using the loop this array allows me to deduct a predefined amount from each
  // bracket I can then move the income that needs to be taxed down a bracket
  int amountDeducted[] = {0, 50000, 75000, 100000, 250000, 500000};

  // The bracket ID will allow me to find which bracket the remaining income
  // falls under
  int bracketID;

  std::cout << "1913 Tax Calculator Resubmission" << std::endl;
  std::cout << "What is your total income?: ";
  std::cin >> income;
  std::cout << std::endl;

  // Use if/else statements to assign an ID to the correct starting bracket.
  // The for loop will increment down from the starting bracket.
  if (500000 < income)
    bracketID = 6;
  else if (income <= 500000 && 250000 < income)
    bracketID = 5;
  else if (income <= 250000 && 100000 < income)
    bracketID = 4;
  else if (income <= 100000 && 75000 < income)
    bracketID = 3;
  else if (income <= 75000 && 50000 < income)
    bracketID = 2;
  else
    bracketID = 1;

  /*
    The for loop:
      Set i to the ID of the starting bracket then increment down until you
    reach 0 line 49: Deduct the predeterminded amount based on the ID of the
    bracket. ie ID = 6 then amountDeducted = 500000 i - 1 because the array
    includes 0, the ID does not incomeTaxed is the amount of income above the
    current bracket. ie if you make 550000 income taxed is 50000 line 48: The
    tax rate aligns with the ID of the bracket, therefore if you divid the ID
    (i) by 100, it will represent the tax rate Add the amount taxed
    (incomeTaxed) * the tax rate to the total amount due. Again, the amount due
    acts as a sum line 49: Finally subtract from the total income to move on to
    the next bracket. If bracket id is 1, it will subtract the remaining income
    and stop the loop
  */

  for (int i = bracketID; i > 0; i--) {
    incomeTaxed = income - amountDeducted[i - 1];
    amountDue += incomeTaxed * i / 100;
    income -= incomeTaxed;
  }

  std::cout << std::fixed << std::setprecision(2);  // Round to 2 decimals :)
  std::cout << "You owe $" << amountDue << "." << std::endl;

  return 0;
}
