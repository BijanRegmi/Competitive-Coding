/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (51.76%)
 * Likes:    15562
 * Dislikes: 466
 * Total Accepted:    2M
 * Total Submissions: 3.9M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 45
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int climbStairs(int n) { return steps(n, 1) + steps(n, 2); }

  int steps(int n, int step) {
    if (n <= 0)
      return 0;

    if (n == 1 && step == 1)
      return 1;

    if (n == 1 && step == 2) {
      return 0;
    }

    return steps(n - 1, 1) + steps(n - 2, 2);
  }
};
// @lc code=end
