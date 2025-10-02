/*
	Medium - Longest Palindromic Substring
	https://leetcode.com/problems/longest-palindromic-substring/description
*/

#include <string>
using namespace std;

class Solution
{
public:
	string expandAroundCenter(const string &s, int left, int right)
	{
		while (left >= 0 && right < s.length() && s[left] == s[right])
		{
			left--;
			right++;
		}
		// Substring from left+1 to right-1 (length = right - left - 1)
		return s.substr(left + 1, right - left - 1);
	}

	string longestPalindrome(string s)
	{
		string res = "";
		for (int i = 0; i < s.length(); ++i)
		{
			// Odd-length palindrome
			string odd = expandAroundCenter(s, i, i);
			if (odd.length() > res.length())
				res = odd;

			// Even-length palindrome
			string even = expandAroundCenter(s, i, i + 1);
			if (even.length() > res.length())
				res = even;
		}
		return res;
	}
};