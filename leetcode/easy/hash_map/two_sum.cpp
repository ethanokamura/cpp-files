#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @title: TWO SUM
 * @date 02/19/2024
 * @brief
 * 1. Given an array of integers nums and an integer target, return indices of
 * the two numbers such that they add up to target.
 * 2. You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 * 3. You can return the answer in any order.
 */

using namespace std;

/**
 * create a map with key value pairs: value in array and index of value
 * iterate through array
 * store num target - value at current index
 * check to see if num exists in the hashmap
 * if it does exist: add indicies to the target_indecies
 * otherwise, insert the pair
 * return the indecies
 */
vector<int> two_sum(vector<int>& nums, int target) {
  unordered_map<int, int> table;
  int complement{};
  for (int i = 0; i < nums.size(); i++) {
    complement = target - nums.at(i);
    if (table.find(complement) != table.end()) {
      return {table[complement],i};
    }
    table[nums.at(i)] = i;
  }
  return {};
}

string print_vector(vector<int> answers) {
  string str;
  for (int i : answers) str += std::to_string(i);
  return str;
}

int main() {
  vector<int> test1 = {2, 7, 11, 15};
  vector<int> test2 = {3, 2, 4};
  vector<int> test3 = {3, 3};

  vector<vector<int>> results;
  results.push_back(two_sum(test1, 9));  // Output: [0,1]
  results.push_back(two_sum(test2, 6));  // Output: [1,2]
  results.push_back(two_sum(test3, 6));  // Output: [0,1]
  results.push_back(two_sum(test1, 3));  // Does Not Exist

  for (auto v : results) {
    if (v.size() != 0)
      cout << '[' << v.at(0) << "," << v.at(1) << "]\n";
    else
      cout << "Does Not Exist\n";
  }

  return 0;
}