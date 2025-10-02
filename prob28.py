"""
	Easy - Find the Index of the First Occurrence in a String
	https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description
"""

class Solution:
	def strStr(self, haystack: str, needle: str) -> int:
		if not needle:
			return 0
		for i in range(len(haystack) - len(needle) + 1):
			for j in range(len(needle)):
				if haystack[i + j] != needle[j]:
					break
			else:  # This executes only if the loop completed without breaking
				return i
		return -1