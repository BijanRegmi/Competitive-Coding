/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (44.22%)
 * Likes:    6082
 * Dislikes: 298
 * Total Accepted:    331.1K
 * Total Submissions: 748.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 *
 * The distance between two adjacent cells is 1.
 *
 *
 * Example 1:
 *
 *
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 *
 *
 * Example 2:
 *
 *
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
  int R, C;

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    this->R = mat.size() - 1;
    this->C = mat[0].size() - 1;
    vector<vector<int>> result(R);

    for (int i = 0; i <= R; i++) {
      std::vector<int> tmp(C);
      for (int j = 0; j <= C; j++) {
        cout << "i: " << i << " j: " << j << endl;
        tmp[j] = distance(mat, i, j);
        cout << "tmp: " << tmp[j] << endl;
      }
      result[i] = tmp;
    }
    return result;
  }

  int distance(vector<vector<int>> &mat, int r, int c) {
    if (mat[r][c] == 0)
      return 0;

    std::queue<std::pair<int, int>> b;
    std::pair<int, int> curr = {r, c};
    b.push(curr);

    std::set<std::pair<int, int>> visited;

    int dist = 0;
    while (b.size()) {
      dist++;
      curr = b.front();
      b.pop();

      visited.insert(curr);
      if (mat[curr.first][curr.second] == 0) {
        return dist;
      }

      if (visited.count({curr.first + 1, curr.second}) || curr.first + 1 < 0 ||
          curr.first + 1 > R || curr.second < 0 || curr.second > C)
        b.push({curr.first + 1, curr.second});

      if (visited.count({curr.first - 1, curr.second}) || curr.first - 1 < 0 ||
          curr.first - 1 > R || curr.second < 0 || curr.second > C)
        b.push({curr.first - 1, curr.second});

      if (visited.count({curr.first, curr.second + 1}) || curr.first < 0 ||
          curr.first > R || curr.second + 1 < 0 || curr.second + 1 > C)
        b.push({curr.first, curr.second + 1});

      if (visited.count({curr.first, curr.second - 1}) || curr.first < 0 ||
          curr.first > R || curr.second - 1 < 0 || curr.second - 1 > C)
        b.push({curr.first, curr.second - 1});
    }
    return dist;
  }
};

int main() {
  // [[0,0,0],[0,1,0],[1,1,1]]
  Solution s;
  vector<int> r1 = {0, 0, 0};
  vector<int> r2 = {0, 1, 0};
  vector<int> r3 = {1, 1, 1};
  vector<vector<int>> nums = {r1, r2, r3};
  auto res = s.updateMatrix(nums);
  for (auto row : res) {
    for (int n : row) {
      cout << n << " ";
    }
    cout << endl;
  }
}
// @lc code=end
