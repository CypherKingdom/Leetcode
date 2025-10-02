"""
	Easy - Path Sum
	https://leetcode.com/problems/path-sum/description
"""

# Definition for a binary tree node.
class TreeNode:
	def __init__(self, val=0, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right

class Solution:
	def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
		if not root:
			return False
		if not root.left and not root.right:
			return root.val == targetSum
		remaining = targetSum - root.val
		left_result = self.hasPathSum(root.left, remaining) if root.left else False
		right_result = self.hasPathSum(root.right, remaining) if root.right else False
		return left_result or right_result