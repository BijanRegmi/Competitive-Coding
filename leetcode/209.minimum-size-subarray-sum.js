/*
 * @lc app=leetcode id=209 lang=javascript
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (44.55%)
 * Likes:    8305
 * Dislikes: 231
 * Total Accepted:    633.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a subarray whose sum is greater than or equal
 * to target. If there is no such subarray, return 0 instead.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */

// @lc code=start
/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
	let n = nums.length

	let min = Infinity
	let current = 0
	for (let l = 0, r = 0; r < n;) {
		current += nums[r]
		if (current < target) {
			r++
		} else {
			current -= nums[l]
			current -= nums[r]
			min = Math.min(min, r - l + 1)
			l++
		}
	}

	/* for (let r = 0, l = 0; r < n; r++) {
		current += nums[r]
		while (current >= target) {
			min = Math.min(min, r - l + 1)
			current -= nums[l]
			l++
		}
	} */

	return min == Infinity ? 0 : min
}
/* console.log(minSubArrayLen(7, [2, 3, 1, 2, 4, 3]))
console.log(minSubArrayLen(11, [1, 1, 1, 1, 1, 1, 1, 1])) */
// @lc code=end
