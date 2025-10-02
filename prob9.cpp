/*
	Easy - Palindrome Number
	https://leetcode.com/problems/palindrome-number/description
*/

using namespace std;
#include <string>

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)
			return false;
		string result = to_string(x);
		int n = result.size();
		for (int i = 0; i < n / 2; i++)
			if (result[i] != result[n - i - 1])
				return false;
		return true;
	}
};