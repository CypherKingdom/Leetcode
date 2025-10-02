"""
	Easy - Combine Two Tables
	https://leetcode.com/problems/combine-two-tables/description
"""

import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
	result = pd.merge(person, address, how='left', on='personId')
	# result['city'] = result['city'].fillna(pd.NA)
	# result['state'] = result['state'].fillna(pd.NA)
	resultFinal = result[['firstName', 'lastName', 'city', 'state']]
	return resultFinal