/*
 * @lc app=leetcode id=344 lang=javascript
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (76.25%)
 * Likes:    6505
 * Dislikes: 1024
 * Total Accepted:    1.9M
 * Total Submissions: 2.5M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 *
 * You must do this by modifying the input array in-place with O(1) extra
 * memory.
 *
 *
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is a printable ascii character.
 *
 *
 */

// @lc code=start
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function(s) {
	let lo = 0,
		hi = s.length - 1

	while (lo < hi) {
		let tmp = s[lo]
		s[lo] = s[hi]
		s[hi] = tmp
		lo++
		hi--
	}
}
// @lc code=end
