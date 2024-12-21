/**
 * @file as02_redux.cpp
 * @author A student in CS 19, someone@jeff.cis.cabrillo.edu
 * 
 * Re-implementing `as02` using our `is_palindromic()` function template.
 */
#include <cassert>
#include <iostream>
#include <string>
#include "template.h"
#include <vector>
#include <set>
#include <list>
 
int main() {
  // TODO
  assert(cs19::is_palindromic(std::string("kayak")));
  assert(cs19::is_palindromic(std::string("kaak")));
  assert(!cs19::is_palindromic(std::string("canoe")));
  assert(cs19::is_palindromic(std::string("!")));
  assert(cs19::is_palindromic(std::string("??")));
  assert(!cs19::is_palindromic(std::string("!?")));
  assert(cs19::is_palindromic(std::string("")));
  assert(!cs19::is_palindromic(std::list{'c', 'a', 't'}));
  assert(cs19::is_palindromic(std::list{1.1, 0.0, 1.1}));
  assert(!cs19::is_palindromic(std::vector{1, 2, 3}));
  assert(cs19::is_palindromic(std::vector{true, false, true}));
  assert(cs19::is_palindromic(std::set{1, 1, 1}));
  assert(!cs19::is_palindromic(std::set{0, 1, 2}));
  std::cout << "is_palindromic passed successfully\n";
  assert(cs19::zip(std::string("kyk"), std::string("aa")) == "kayak");
  std::vector odds{1, 3};
  std::vector evens{2, 4};
  std::vector all{1, 2, 3, 4};
  assert(cs19::zip(odds, evens) == all);
 
  assert(cs19::is_palindromic(cs19::zip(std::string("kyk"), std::string("aa"))));
  if (cs19::is_palindromic(std::string("kayak")))
    std::cout << "Looks good so far!\n";
  else
    std::cout << "Definitely got some work to do...\n";
}