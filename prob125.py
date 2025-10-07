"""
	Easy - Valid Palindrome
	https://leetcode.com/problems/valid-palindrome/description
"""

class Solution:
	def isPalindrome(self, s: str) -> bool:
		result = "".join(filter(str.isalnum, s)).lower()
		return result == result[::-1]