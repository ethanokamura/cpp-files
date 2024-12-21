#include <iostream>
#include <vector>

using namespace std;

static const auto io_sync_off = []() {
  // turn off sync
  std::ios::sync_with_stdio(false);
  // untie in/out streams
  std::cin.tie(nullptr);
  return nullptr;
}();

int maxProfit(vector<int>& prices) {
  if (prices.size() == 1) return 0;
  int buy, sell;
  int profit = 0;
  for (int i = 0; i < prices.size(); i++) {
    if (prices[i] < buy || i == 0)
      buy = sell = prices[i];
    if (sell < prices[i]) {
      sell = prices[i];
      if (sell - buy > profit)
        profit = sell - buy;
    }
  }
  return profit;
}

int main() {
  vector<int> v1 {2,4,1};
  vector<int> v2 {2,6,4,1};
  vector<int> v3 {1};
  cout << maxProfit(v1) << '\n';
  cout << maxProfit(v2) << '\n';
  cout << maxProfit(v3) << '\n';
  return 0;
}