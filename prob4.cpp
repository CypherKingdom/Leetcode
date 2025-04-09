/*
    Hard: Median of Two Sorted Arrays
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
    The overall run time complexity should be O(log (m+n)).

    Example 1:
    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.
    Example 2:
    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

    Constraints:
    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106
*/

/*
    Key Steps:
    The smaller array (nums1 or nums2) is selected to perform the binary search for optimization.
    Using binary search, the arrays are partitioned into two halves: the left part contains smaller elements, 
    while the right part contains larger ones.
    The partition is adjusted iteratively to ensure the maximum element from the left half is 
    smaller or equal to the minimum element from the right half.

    Conditions:
    The median is calculated differently for arrays with an odd or even total number of elements.
    For even-length combined arrays, the median is the average of the largest value from 
    the left partition and the smallest value from the right partition.
    For odd-length combined arrays, the median is the maximum value from the left partition.
    Edge Cases: Handles edge cases where partitions reach the boundaries of arrays, using INT_MIN and INT_MAX as placeholders.
    Efficiency: The algorithm runs in O(log(min(n, m))) time, where n and m are the sizes of the input arrays.
*/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = (n + m + 1) / 2 - mid1;

            int l1 = (mid1 == 0 ? INT_MIN : nums1[mid1 - 1]);
            int r1 = (mid1 == n ? INT_MAX : nums1[mid1]);

            int l2 = (mid2 == 0 ? INT_MIN : nums2[mid2 - 1]);
            int r2 = (mid2 == m ? INT_MAX : nums2[mid2]);

            if (l1 <= r2 && l2 <= r1)
                return ((n + m) % 2 == 0) ? (max(l1, l2) + min(r1, r2)) / 2.0 : max(l1, l2);
            (l1 > r2) ? high = mid1 - 1 : low = mid1 + 1;
        }
        return 0;
    }
};