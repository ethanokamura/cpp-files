#include <iostream> 
#include <cmath> 
#include <iomanip>

int main () {
  std::string storeName;
  double priceOfBooks;
  double pricePerBook; 
  int numberOfBooks;
  double tax = 0.085;
  double shipping = 2.00;

  std::cout<< "What is the name of your store?: ";
  std::cin >> storeName;
  std::cout << "Hi welcome to " << storeName << std::endl;
  std::cout << "How many books would you like?: " ;
  std::cin >> numberOfBooks;
  std::cout << std::endl;
  std::cout << "How much does each book cost?:  " << std::endl;
  std::cin >> pricePerBook;
  std::cout << std::endl;
  priceOfBooks = numberOfBooks * pricePerBook;
  double taxPrice = priceOfBooks * tax;
  double shippingPrice = numberOfBooks * shipping;
  double total = shippingPrice + taxPrice + priceOfBooks;

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Cost of taxes && shipping:  $" << taxPrice + shippingPrice << std::endl;
  std::cout << "Total amount due:  $" << total << std::endl;

  return 0;
}