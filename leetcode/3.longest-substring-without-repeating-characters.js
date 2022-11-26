/*
 * @lc app=leetcode id=3 lang=javascript
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.80%)
 * Likes:    30484
 * Dislikes: 1306
 * Total Accepted:    4.1M
 * Total Submissions: 12M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
	/* const n = s.length
	let i, j
	let max = 0

	for (i = 0; i < n; i++) {
		let hist = {}
		for (j = i; j < n && !hist[s[j]]; j++) {
			hist[s[j]] = true
		}
		max = Math.max(max, Object.keys(hist).length)
	}
	return max */
	const n = s.length
	let hist = {}
	let max = 0
	for (let left = 0, right = 0; right < n; right++) {
		if (hist[s[right]] >= left) {
			left = hist[s[right]] + 1
		}
		max = Math.max(max, right - left + 1)
		hist[s[right]] = right
	}
	return max
}
/* console.log(lengthOfLongestSubstring("abcabcbb")) */
// @lc code=end
