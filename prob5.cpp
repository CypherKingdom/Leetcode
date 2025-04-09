/*
    Medium: Longest Palindromic Substring
    Given a string s, return the longest palindromic substring in s.

    Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
    Example 2:
    Input: s = "cbbd"
    Output: "bb"

    Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

#include <iostream>
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