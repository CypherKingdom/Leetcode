"""
	Easy - Rank Scores
	https://leetcode.com/problems/rank-scores/description
"""

import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
	result = scores[['score']].sort_values('score', ascending=False)
	rank = 0
	prev = None
	ranks = []
	for i, score in enumerate(result['score']):
		if score != prev:
			rank += 1
			prev = score
		ranks += [rank]
	result['rank'] = ranks
	return result