/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.90%)
 * Likes:    13838
 * Dislikes: 228
 * Total Accepted:    1.4M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define deb(x) cout << #x << ": " << x << std::endl;

#define debb(x, y)                                                             \
  cout << #x << ": " << x << "  " << #y << ": " << y << std::endl;

#define debarr(x)                                                              \
  cout << #x << "[";                                                           \
  for (auto a : x)                                                             \
    cout << " " << a;                                                          \
  cout << " ]" << endl;

class Solution {
  vector<vector<int>> result;

public:
  vector<vector<int>> permute(vector<int> &nums) {
    permute(nums, 0);
    return result;
  }

  void permute(vector<int> &nums, int start) {
    if (start == nums.size() - 1) {
      vector<int> comb(nums);
      result.push_back(comb);
    }
    for (int i = start; i < nums.size(); i++) {
      swap(nums[i], nums[start]);
      permute(nums, start + 1);
      swap(nums[i], nums[start]);
    }
  }
};

/* int main() {
  Solution s;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = s.permute(nums);

  for (auto x : result) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
} */

// @lc code=end
