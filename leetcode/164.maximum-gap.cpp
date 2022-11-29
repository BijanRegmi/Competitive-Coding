/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (42.76%)
 * Likes:    2529
 * Dislikes: 317
 * Total Accepted:    156.4K
 * Total Submissions: 365.6K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an integer array nums, return the maximum difference between two
 * successive elements in its sorted form. If the array contains less than two
 * elements, return 0.
 *
 * You must write an algorithm that runs in linear time and uses linear extra
 * space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or
 * (6,9) has the maximum difference 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maximumGap(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int max = 0;
    for (int i = nums.size() - 1; i > 0; i--) {
      max = std::max(max, nums[i] - nums[i - 1]);
    }
    return max;
  }
};
// @lc code=end
