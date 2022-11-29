/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (36.57%)
 * Likes:    12465
 * Dislikes: 1496
 * Total Accepted:    802.3K
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums, return the smallest missing positive
 * integer.
 *
 * You must implement an algorithm that runs in O(n) time and uses constant
 * extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,0]
 * Output: 3
 * Explanation: The numbers in the range [1,2] are all in the array.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Explanation: 1 is in the array but 2 is missing.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * Explanation: The smallest positive integer 1 is missing.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    /* sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int c = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= 0)
        continue;
      if (nums[i] != c)
        return c;
      c++;
    }
    return c; */

    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] > 0 && nums[i] <= nums.size() &&
             nums[i] != nums[nums[i] - 1])
        swap(nums[i], nums[nums[i] - 1]);
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1)
        return i + 1;
    }
    return nums.size() + 1;
  }
};

/* int main() {
  Solution s;
  vector<int> nums = {3, 4, -1, 1};
  cout << s.firstMissingPositive(nums);
} */
// @lc code=end
