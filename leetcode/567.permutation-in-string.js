/*
 * @lc app=leetcode id=567 lang=javascript
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (43.67%)
 * Likes:    7616
 * Dislikes: 252
 * Total Accepted:    514K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */

// @lc code=start
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
	let n1 = s1.length
	let n2 = s2.length

	// create histogram for s1
	let hist1 = {}
	for (let i = 0; i < n1; i++) hist1[s1[i]] = hist1[s1[i]] + 1 || 1
	let h1k = Object.keys(hist1)

	let hist2 = {}
	for (let l = 0, r = 0; r < n2; r++) {
		// If the current char is not in s1 reset the histogram and continue
		if (!hist1[s2[r]]) {
			l = r
			l++
			hist2 = {}
			continue
		}

		hist2[s2[r]] = hist2[s2[r]] + 1 || 1

		// Compare the histograms only if the window size is same as s1 length
		if (r - l + 1 == n1) {
			let flag = true
			for (let key of h1k) {
				if (hist1[key] != hist2[key]) {
					flag = false
					break
				}
			}
			if (flag) return true

			// If histograms dont match decrease left window freq and increase left
			hist2[s2[l]] = hist2[s2[l]] - 1 || 0
			l++
		}
	}
	return false
}
/* console.log(checkInclusion("ab", "eidbsaobao")) */
// @lc code=end
