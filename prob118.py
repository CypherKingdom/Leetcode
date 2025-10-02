"""
	Easy - Pascal's Triangle
	https://leetcode.com/problems/pascals-triangle/description
"""

class Solution:
	def generate(self, numRows: int) -> List[List[int]]:
		if numRows < 6:
			list1 = [[int(item) for item in str(11 ** _)] for _ in range(numRows)]
			return list1
		else:
			list1 = [[int(item) for item in str(11 ** _)] for _ in range(5)]
			for _ in range(numRows - 5):
				list1 = list1 + [[1] + [list1[-1][i] + list1[-1][i + 1] \
				for i in range(len(list1[-1]) - 1)] + [1]]
			return list1