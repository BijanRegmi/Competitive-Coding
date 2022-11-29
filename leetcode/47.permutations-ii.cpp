/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (56.83%)
 * Likes:    6792
 * Dislikes: 119
 * Total Accepted:    734.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  vector<vector<int>> result;
  set<vector<int>> seen;

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    permute(nums, 0);
    return result;
  }

  void permute(vector<int> &nums, int start) {
    if (start == nums.size() - 1) {
      vector<int> comb(nums);
      result.push_back(comb);

      /* cout << "Add: [";
      for (int n : comb)
        cout << n << " ";
      cout << "]\n"; */

      return;
    }

    for (int i = start; i < nums.size(); i++) {
      if ((i != start) && (nums[i] == nums[start])) {
        /* cout << "Dup: [";
        for (int n : nums)
          cout << n << " ";
        cout << "] i: " << i << " start: " << start << endl; */

        continue;
      }

      swap(nums[i], nums[start]);
      /* cout << "SWP: [";
      for (int n : nums)
        cout << n << " ";
      cout << "] i: " << i << " start: " << start << endl; */

      if (seen.count(nums)) {
        /* cout << "See: [";
        for (int n : nums)
          cout << n << " ";
        cout << "] i: " << i << " start: " << start << endl; */

        swap(nums[i], nums[start]);
        continue;
      }

      permute(nums, start + 1);

      vector<int> comb(nums);
      seen.insert(comb);
      /* cout << "Mrk: [";
      for (int n : comb)
        cout << n << " ";
      cout << "] i: " << i << " start: " << start << endl; */

      swap(nums[i], nums[start]);
    }
  }
};

/* int main() {
  Solution s;
  vector<int> nums = {2, 2, 1, 1};
  vector<vector<int>> result = s.permuteUnique(nums);

  for (auto x : result) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
} */
// @lc code=end
