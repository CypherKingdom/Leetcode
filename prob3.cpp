/*
    Medium: Longest Substring Without Repeating Characters
    Given a string s, find the length of the longest substring without duplicate characters.

    Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

    Constraints:
    - 0 <= s.length <= 5 * 104
    - s consists of English letters, digits, symbols and spaces.
*/

/*
    Solution 1:
    Using a sliding window approach.
    Key Steps:
    Uses an unordered map lastSeen to track the last position of each character in the string.
    Iterates through the string with two pointers, i and j, which define the window of the substring.
    Adjusts the j pointer if a repeating character is found within the window to ensure no repetition.
    Updates the maxlen variable to track the length of the longest substring.
    Efficiency: Runs in O(n) time due to the sliding window and hash map operations.
*/

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> lastSeen;
        int maxlen = 0;
        for (int i = 0, j = 0; i < s.length(); i++)
        {
            if (lastSeen.find(s[i]) != lastSeen.end() && lastSeen[s[i]] >= j)
                j = lastSeen[s[i]] + 1;
            lastSeen[s[i]] = i;

            if (i - j + 1 > maxlen)
                maxlen = i - j + 1;
        }
        return maxlen;
    }
};

/*
    Solution 2:
    A more explicit string manipulation approach.
    Key Steps:
    Defines helper functions sub_string (to extract a substring) and is_present (to check if a character is in a substring).
    Maintains a substring new_s to track characters in the current window.
    Iterates through the input string with two indices, i and j, adjusting them based on character repetition.
    Updates the size variable to track the longest substring length using the max_int helper function.
    Efficiency: Runs in O(n^2) time due to nested loops and repeated substring manipulations.
*/

class Solution
{
public:
    string sub_string(string s, int i, int j)
    {
        string news = "";
        for (int z = i; z <= j; z++)
            news += s[z];
        return news;
    }
    bool is_present(string s, char c)
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] == c)
                return true;
        return false;
    }
    int max_int(int x, int y) { return (x >= y) ? x : y; }

    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;
        string new_s = "";
        new_s += s[0];
        int size = 1, i = 0, j = 0;
        while (j != s.size() - 1)
        {
            if (!is_present(new_s, s[j + 1]))
            {
                new_s += s[j + 1];
                j++;
                size = max_int(size, j - i + 1);
            }
            else
            {
                if (j - i == 0)
                {
                    j++;
                    i++;
                    new_s = sub_string(s, i, j);
                }
                else
                {
                    i++;
                    new_s = sub_string(s, i, j);
                }
            }
        }
        return size;
    }
};