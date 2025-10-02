"""
	Easy - Minimum Depth of Binary Tree
	https://leetcode.com/problems/minimum-depth-of-binary-tree/description
"""

# Definition for a binary tree node.
class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

class Solution:
	def minDepth(self, root: Optional[TreeNode]) -> int:
		if not root:
			return 0
		if not root.left and root.right:
			return 1 + self.minDepth(root.right)
		if root.left and not root.right:
			return 1 + self.minDepth(root.left)
		left = 1 + self.minDepth(root.left)
		right = 1 + self.minDepth(root.right)
		return min(left, right)