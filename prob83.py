"""
	Easy - Remove Duplicates from Sorted List
	https://leetcode.com/problems/remove-duplicates-from-sorted-list/description
"""

# Definition for singly-linked list.
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

class Solution:
	def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
		if head and head.next:
			prev = head
			cur = head.next
			while cur:
				if prev.val == cur.val:
					prev.next = cur.next
					cur = cur.next
					continue
				prev = cur
				cur = cur.next
		return head