/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Medium (73.54%)
 * Likes:    3943
 * Dislikes: 151
 * Total Accepted:    252.5K
 * Total Submissions: 343.3K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string s, you can transform every letter individually to be
 * lowercase or uppercase to create another string.
 *
 * Return a list of all possible strings we could create. Return the output in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "a1b2"
 * Output: ["a1b2","a1B2","A1b2","A1B2"]
 *
 *
 * Example 2:
 *
 *
 * Input: s = "3z4"
 * Output: ["3z4","3Z4"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 12
 * s consists of lowercase English letters, uppercase English letters, and
 * digits.
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cctype>
#include <vector>
using namespace std;
class Solution {
  vector<string> result;

public:
  vector<string> letterCasePermutation(string s) {
    permute(s, 0);
    return result;
  }

  void permute(string str, int start) {
    if (start == str.size()) {
      result.push_back(str);
      return;
    }
    bool u = (str[start] >= 65 && str[start] <= 90);
    bool l = (str[start] >= 97 && str[start] <= 122);

    if (u || l) {
      str[start] = tolower(str[start]);
      permute(str, start + 1);
      str[start] = toupper(str[start]);
      permute(str, start + 1);
    } else {
      permute(str, start + 1);
    }
  }
};

/* int main() {
  Solution s;
  auto res = s.letterCasePermutation("abc");
  for (string str : res) {
    cout << str << endl;
  }
} */
// @lc code=end
