"""
	Easy - Convert Sorted Array to Binary Search Tree
	https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description
"""

# Definition for a binary tree node.
class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

class Solution:
	def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
		if not nums:
			return None
		def build(L: int, R: int) -> Optional[TreeNode]:
			if L > R:
				return None
			mid = (L + R) // 2
			root = TreeNode(nums[mid])
			root.left = build(L, mid - 1)
			root.right = build(mid + 1, R)
			return root
		return build(0, len(nums) - 1)