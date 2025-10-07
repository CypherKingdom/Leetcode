"""
	Easy - Best Time to Buy and Sell Stock
	https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description
"""

class Solution:
	def maxProfit(self, prices: List[int]) -> int:
		min_price = prices[0]
		max_profit = 0

		for price in prices[1:]:
			if price - min_price > max_profit:
				max_profit = price - min_price

			if price < min_price:
				min_price = price

		return max_profit