#include <iostream>
#include <vector>
#include <cassert>

/**
 * Best Time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 */

using namespace std;

int maxProfit(vector<int>& prices);

int main() {
  vector<int> v1 {2,4,1};
  vector<int> v2 {2,6,4,1};
  vector<int> v3 {1};
  vector<int> v4 {7,1,5,3,6,4};
  vector<int> v5 {7,6,4,3,1};
  assert(maxProfit(v1) == 2);
  assert(maxProfit(v2) == 4);
  assert(maxProfit(v3) == 0);
  assert(maxProfit(v4) == 5);
  assert(maxProfit(v5) == 0);
  return 0;
}