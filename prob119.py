"""
	Easy - Pascal's Triangle II
	https://leetcode.com/problems/pascals-triangle-ii/description
"""

class Solution:
	def getRow(self, rowIndex: int) -> List[int]:
		if rowIndex + 1 < 6:
			list1 = [[int(item) for item in str(11 ** _)] for _ in range(rowIndex + 1)]
			return list1[rowIndex]
		else:
			list1 = [[int(item) for item in str(11 ** _)] for _ in range(5)]
			for _ in range(rowIndex + 1 - 5):
				list1 = list1 + [[1] + [list1[-1][i] + list1[-1][i + 1] \
				for i in range(len(list1[-1]) - 1)] + [1]]
			return list1[rowIndex]