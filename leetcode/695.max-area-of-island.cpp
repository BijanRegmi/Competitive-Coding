/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (71.69%)
 * Likes:    8279
 * Dislikes: 183
 * Total Accepted:    647.2K
 * Total Submissions: 902.8K
 * Testcase Example:
 * '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 *
 * The area of an island is the number of cells with a value 1 in the island.
 *
 * Return the maximum area of an island in grid. If there is no island, return
 * 0.
 *
 *
 * Example 1:
 *
 *
 * Input: grid =
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected
 * 4-directionally.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
  int R, C;

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    this->R = grid.size() - 1;
    this->C = grid[0].size() - 1;

    int maxArea = 0, area;
    for (int r = 0; r <= R; r++) {
      for (int c = 0; c <= C; c++) {
        area = getArea(grid, r, c);
        maxArea = max(area, maxArea);
      }
    }
    return maxArea;
  }
  int getArea(vector<vector<int>> &grid, int r, int c) {
    // Check bounds
    if (r < 0 || r > R || c < 0 || c > C)
      return 0;

    if (!grid[r][c])
      return 0;

    grid[r][c] = 0;

    return 1 + getArea(grid, r + 1, c) + getArea(grid, r - 1, c) +
           getArea(grid, r, c + 1) + getArea(grid, r, c - 1);
  }
};
// @lc code=end
