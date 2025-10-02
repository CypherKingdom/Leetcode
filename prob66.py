"""
	Easy - Plus One
	https://leetcode.com/problems/plus-one/description
"""

class Solution:
	def plusOne(self, digits: List[int]) -> List[int]:
		return [int(i) for i in str(int("".join([str(element) for element in digits])) + 1)]