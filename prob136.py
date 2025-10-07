"""
	Easy - Single Number
	https://leetcode.com/problems/single-number/description
"""

class Solution:
	def singleNumber(self, nums: List[int]) -> int:
		dictionary = {}
		for i in nums:
			dictionary[i] = 0
		for i in nums:
			dictionary[i] += 1
		for key, value in dictionary.items():
			if 1 == value:
				return key