/*
 * @lc app=leetcode id=19 lang=javascript
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (40.07%)
 * Likes:    13915
 * Dislikes: 576
 * Total Accepted:    1.8M
 * Total Submissions: 4.5M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
	let curr = head
	let t = 1
	while ((curr = curr.next)) t++

	if (t == 1) return null

	let p = t - n
	if (p == 0) return head.next
	curr = head
	for (let i = 1; i < p; i++) curr = curr.next

	curr.next = curr.next.next
	return head
	/* let fast = head,
		slow = head

	while (n--) fast = fast.next
	if (!fast) return head.next
	while ((fast = fast.next)) slow = slow.next
	slow.next = slow.next.next
	return head */
}

/* function ListNode(val, next) {
	this.val = val === undefined ? 0 : val
	this.next = next === undefined ? null : next
}

let node = undefined
for (let i = 5; i; i--) node = new ListNode(i, node)
console.log(removeNthFromEnd(node, 2)) */
// @lc code=end
