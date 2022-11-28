/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (61.28%)
 * Likes:    7426
 * Dislikes: 1061
 * Total Accepted:    2.3M
 * Total Submissions: 3.7M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    // Over engineered solution
    /* int n = nums.size();
    sort(nums.begin(), nums.end());
    auto s = std::unique(nums.begin(), nums.end());
    nums.erase(s, nums.end());
    return n != nums.size(); */

    set<int> s;
    for (int i : nums) {
      if (s.count(i))
        return true;
      s.insert(i);
    }
    return false;
  }
};
// @lc code=end
