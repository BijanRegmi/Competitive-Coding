/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (60.70%)
 * Likes:    6031
 * Dislikes: 579 Total Accepted:    607.4K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * An image is represented by an m x n integer grid image where image[i][j]
 * represents the pixel value of the image.
 *
 * You are also given three integers sr, sc, and color. You should perform a
 * flood fill on the image starting from the pixel image[sr][sc].
 *
 * To perform a flood fill, consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color), and so on. Replace the color of all of the
 * aforementioned pixels with color.
 *
 * Return the modified image after performing the flood fill.
 *
 *
 * Example 1:
 *
 *
 * Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: From the center of the image with position (sr, sc) = (1, 1)
 * (i.e., the red pixel), all pixels connected by a path of the same color as
 * the starting pixel (i.e., the blue pixels) are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected to the starting pixel.
 *
 *
 * Example 2:
 *
 *
 * Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
 * Output: [[0,0,0],[0,0,0]]
 * Explanation: The starting pixel is already colored 0, so no changes are made
 * to the image.
 *
 *
 *
 * Constraints:
 *
 *
 * m == image.length
 * n == image[i].length
 * 1 <= m, n <= 50
 * 0 <= image[i][j], color < 2^16
 * 0 <= sr < m
 * 0 <= sc < n
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
#include <set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
  set<pair<int, int>> visited;
  int color;
  int start;
  int R, C;

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    this->R = image.size() - 1;
    this->C = image[0].size() - 1;
    this->color = color;
    this->start = image[sr][sc];

    nestedfill(image, sr, sc);
    return image;
  }
  void nestedfill(vector<vector<int>> &image, int r, int c) {
    // Check bounds
    if (r < 0 || r > R || c < 0 || c > C)
      return;

    pair<int, int> cord = {r, c};
    if (visited.count(cord) || image[r][c] != start)
      return;

    image[r][c] = color;
    visited.insert(cord);
    nestedfill(image, r + 1, c);
    nestedfill(image, r, c + 1);
    nestedfill(image, r - 1, c);
    nestedfill(image, r, c - 1);
  }
};

/*int main() {
  Solution s;

  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  vector<vector<int>> image2 = {{0, 0, 0}, {0, 0, 0}};
  s.floodFill(image2, 0, 0, 0);

  for (auto x : image2) {
    for (int y : x)
      cout << y << " ";
    cout << endl;
  }
}*/
// @lc code=end
