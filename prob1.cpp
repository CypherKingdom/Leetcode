/*
    Easy: Two Sum
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.

    Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]

    Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/

/*
    Solution 1:
    The efficient approach is to use a hash table (unordered_map in C++).
    Key Process:
    Build a hash table:
    The function stores the value of each number in the array as the key and its index as the value for fast lookups.
    Find the complement:
    Iterates through the array and calculates the complement of each number as target - nums[i].
    Checks if the complement exists in the hash table and ensures that it is not the same index (i) as the current number.
    Returns the indices {i, numMap[complement]} as soon as the pair is found.
    Efficiency:
    The hash table allows for quick lookups, reducing the time complexity to O(n), where n is the size of the array.
    Edge Case:
    If no solution is found, the function returns an empty vector {}.
*/

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++)
            numMap[nums[i]] = i;

        // Find the complement
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i)
                return {i, numMap[complement]};
        }
        return {}; // No solution found
    }
};

/*
    Solution 2:
    One brute force approach is to consider every pair of elements and check if their sum equals the target.
    This can be done using nested loops, where the outer loop iterates from the first element to the second-to-last element,
    and the inner loop iterates from the next element to the last element. However, this approach has a time complexity of O(n^2).
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
    }
};