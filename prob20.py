"""
	Easy - Valid Parentheses
	https://leetcode.com/problems/valid-parentheses/description
"""

class Solution:
	def isValid(self, s: str) -> bool:
		mymap = {'(': ')', '[': ']', '{': '}'}
		mystack = []
		for char in s:
			if char in mymap.keys():
				mystack.append(char)
			elif char in mymap.values() and mystack != []:
				key = mymap[mystack.pop()]
				if char != key:
					return False
			else:
				return False
		return True if mystack == [] else False