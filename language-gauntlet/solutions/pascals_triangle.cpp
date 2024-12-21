#include <iostream>
#include <vector>

/**
 * Pascal's triangle
 * https://leetcode.com/problems/pascals-triangle/description/
 */

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> triangle(numRows);
  int res = 1;
  for (int i = 0; i < numRows; i++) {
    triangle[i].push_back(1);
    for (int j = 0; j < i; j++) {
      res *= (i - j);
      res /= (j + 1);
      triangle[i].push_back(res);
    }
  }
  return triangle;
}

int main() {
  vector<vector<int>> triangle = generate(10);
  for (int i = 0; i < triangle.size(); i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      cout << triangle[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}