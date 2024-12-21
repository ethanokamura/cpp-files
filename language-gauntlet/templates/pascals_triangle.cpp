#include <iostream>
#include <vector>

/**
 * Pascal's triangle
 * https://leetcode.com/problems/pascals-triangle/description/
 */

using namespace std;

vector<vector<int>> generate(int numRows);

int main() {
  vector<vector<int>> triangle = generate(10);
  for (int i = 0; i < triangle.size(); i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      cout << triangle[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}