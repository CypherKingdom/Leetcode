"""
	Easy - Nth Highest Salary
	https://leetcode.com/problems/nth-highest-salary/description
"""

import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
	result = employee.drop_duplicates(subset=['salary'])
	result = result.sort_values(by='salary', ascending=False)
	if len(result['salary']) < N or N <= 0:
		return pd.DataFrame({f'getNthHighestSalary({N})': [None]})
	nth_salary = result.iloc[N-1]['salary']	
	return pd.DataFrame({f'getNthHighestSalary({N})': [nth_salary]})