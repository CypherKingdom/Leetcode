"""
	Easy - Remove Duplicates from Sorted Array
	https://leetcode.com/problems/remove-duplicates-from-sorted-array/description
"""

class Solution:
	def removeDuplicates(self, nums: List[int]) -> int:
		myset = set()
		for element in nums:
			myset.add(element)
		rest = len(nums) - len(myset)
		tmp = sorted(list(myset)) + [_ for _ in range(rest)]
		for i in range(len(nums)):
			nums[i] = tmp[i]
		return len(myset)