"""
	Easy - Second Highest Salary
	https://leetcode.com/problems/second-highest-salary/description
"""

import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
	# Get unique salaries and sort in descending order
	unique_salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)
	
	# Check if there's a second highest salary
	if len(unique_salaries) < 2:
		return pd.DataFrame({'SecondHighestSalary': [None]})
	
	second_highest = unique_salaries.iloc[1]
	return pd.DataFrame({'SecondHighestSalary': [second_highest]})