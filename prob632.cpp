/*
    Hard: Smallest Range Covering Elements from K Lists
    You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
    We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

    Example 1:
    Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    Output: [20,24]
    Explanation:
    List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    List 2: [0, 9, 12, 20], 20 is in range [20,24].
    List 3: [5, 18, 22, 30], 22 is in range [20,24].
    Example 2:
    Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
    Output: [1,1]

    Constraints:
    nums.length == k
    1 <= k <= 3500
    1 <= nums[i].length <= 50
    -105 <= nums[i][j] <= 105
    nums[i] is sorted in non-decreasing order.
*/

/*
    Key Functions:
    make_range(vector<int> v)
    Determines:
        The minimum value (min) in the vector v.
        The index (z) of this minimum value.
        The maximum value (max) in the vector.
    Returns a pair:
    ((min, z), max) where:
        min is the smallest value.
        z is the index of min.
        max is the largest value in v.
    smallestRange(vector<vector<int>> &nums)
    Purpose: Finds the smallest range that contains at least one number from each sorted list in nums.
    Key Steps:
    Initialization:
    A vector v to store one element from each list.
    A vector index to track the current position in each list.
    Calculate an initial range using make_range.
    Iterative Update:
    The algorithm continuously updates the index of the list containing the current minimum value (z).
    Recalculates the range using make_range and compares it to the existing range:
    Updates the range if the new range is smaller or if it's equal in size but has a smaller starting value.
    Stopping Condition:
    The loop ends when the current list (z) containing the minimum value is fully traversed.
    Return Value:
    Returns the smallest range as a pair: {range.first.first, range.second}.
    Efficiency
    Time Complexity:
    Calculating the range for each iteration involves traversing all lists, resulting in O(n × k), 
    where n is the number of lists and k is the average size of the lists.
    Space Complexity:
    Additional vectors v and index are used, resulting in O(n) space.
*/

using namespace std;
#include <vector>

class Solution
{
public:
    pair<pair<int, int>, int> make_range(vector<int> v)
    {
        int min = v[0], z = 0, max = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (max < v[i])
                max = v[i];
            if (min > v[i])
            {
                min = v[i];
                z = i;
            }
        }
        return make_pair(make_pair(min, z), max);
    }
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> v(nums.size());
        vector<int> index(nums.size(), 0);
        pair<pair<int, int>, int> range, new_range;

        for (int i = 0; i < nums.size(); i++)
            v[i] = nums[i][index[i]];
        range = make_range(v);
        index[range.first.second]++;
        while (index[range.first.second] < nums[range.first.second].size())
        {
            for (int i = 0; i < nums.size(); i++)
                v[i] = nums[i][index[i]];
            new_range = make_range(v);
            if ((range.second - range.first.first) > (new_range.second - new_range.first.first) ||
                ((range.second - range.first.first) == (new_range.second - new_range.first.first) &&
                 range.first.first > new_range.first.first))
                range = new_range;
            index[new_range.first.second]++;
            if (index[new_range.first.second] >= nums[new_range.first.second].size())
                break;
        }
        return {range.first.first, range.second};
    }
};