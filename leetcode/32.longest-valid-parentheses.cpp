/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (32.72%)
 * Likes:    10119
 * Dislikes: 323
 * Total Accepted:    580.6K
 * Total Submissions: 1.8M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', return the length
 * of the longest valid (well-formed) parentheses substring.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 *
 * Example 2:
 *
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 *
 * Example 3:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
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
  int longestValidParentheses(string s) {
    if (s.size() == 0)
      return 0;
    vector<int> m(s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '(')
        continue;

      if (s[i - 1] == '(') {
        if (i - 2 >= 0)
          m[i] = m[i - 2] + 2;
        else
          m[i] = 2;
        continue;
      }

      // s[i-1] == ')'
      if (i - m[i - 1] - 1 < 0)
        continue;

      if (s[i - m[i - 1] - 1] == '(') {
        if (i - m[i - 1] - 2 >= 0)
          m[i] = m[i - m[i - 1] - 2] + m[i - 1] + 2;
        else
          m[i] = m[i - 1] + 2;
      }
    }
    return *max_element(m.begin(), m.end());
  }
};

/* int main() {
  Solution s;
  cout << s.longestValidParentheses("((()())");
} */
// @lc code=end
