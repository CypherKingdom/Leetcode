"""
	Easy - Length of Last Word
	https://leetcode.com/problems/length-of-last-word/description
"""

class Solution:
	def lengthOfLastWord(self, s: str) -> int:
		count = 0
		in_word = 0
		i = len(s) - 1
		while (i >= 0):
			if s[i] == ' ' and in_word != 0:
				break
			elif s[i] != ' ':
				in_word = 1
				count = count + 1
			i = i - 1
		return count