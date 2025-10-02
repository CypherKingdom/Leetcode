"""
	Easy - Remove Element
	https://leetcode.com/problems/remove-element/description
"""

class Solution:
	def removeElement(self, nums: List[int], val: int) -> int:
		if not nums:
			return 0

		index = 0
		for current in range(len(nums)):
			if nums[current] != val:
				nums[index] = nums[current]
				index += 1
		return index