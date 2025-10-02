/*
	Easy - Roman to Integer
	https://leetcode.com/problems/roman-to-integer/description
*/

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> romanMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
		int n = s.size();
		if (n == 0)
			return 0;

		int sum = romanMap[s[n - 1]]; // Start with the value of the last character

		for (int i = n - 2; i >= 0; --i)
		{
			if (romanMap[s[i]] < romanMap[s[i + 1]])
				sum -= romanMap[s[i]];
			else
				sum += romanMap[s[i]];
		}
		return sum;
	}
};