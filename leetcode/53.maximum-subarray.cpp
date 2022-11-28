/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (50.08%)
 * Likes:    26568
 * Dislikes: 1192
 * Total Accepted:    2.9M
 * Total Submissions: 5.7M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the subarray which has the largest sum and
 * return its sum.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max = std::numeric_limits<int>::min(), curr = 0;
    for (int n : nums) {
      curr = std::max(curr + n, n);
      max = std::max(max, curr);
    }
    return max;
  }
};
/* int main() {
  vector<int> nums = {5, 4, -1, 7, 8};
  vector<int> n = {1, 2};
  Solution s;
  std::cout << s.maxSubArray(n) << " " << s.maxSubArray(nums);
} */
// @lc code=end
