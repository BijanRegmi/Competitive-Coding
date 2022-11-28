/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (62.79%)
 * Likes:    7590
 * Dislikes: 250
 * Total Accepted:    1.8M
 * Total Submissions: 2.9M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

// @lc code=start
#include <bits/stdc++.h>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
  bool isAnagram(string s, string t) {
    int n1 = s.size();
    int n2 = t.size();
    if (n1 != n2)
      return false;

    map<char, int> s1, s2;

    for (char c : s)
      s1[c]++;
    for (char c : t)
      s2[c]++;
    return s1 == s2;
  }
};
// @lc code=end
