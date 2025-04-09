/*
    Easy: Merge Sorted Array
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
    representing the number of elements in nums1 and nums2 respectively.
    Merge nums1 and nums2 into a single array sorted in non-decreasing order.
    The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
    To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
    and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

    Example 1:
    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
    Example 2:
    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
    Explanation: The arrays we are merging are [1] and [].
    The result of the merge is [1].
    Example 3:
    Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    Output: [1]
    Explanation: The arrays we are merging are [] and [1].
    The result of the merge is [1].
    Note that because m = 0, there are no elements in nums1.
    The 0 is only there to ensure the merge result can fit in nums1.

    Constraints:
    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109
*/

/*
    Key Functions:
    merge1 (Merge Step):
        Merges two sorted subarrays (from index lo to mid and mid + 1 to hi) into a single sorted array.
        Uses an auxiliary array aux to store intermediate results.
        Compares elements from both subarrays and writes the smaller one back to the original array a.
    mergesort (Recursive Sort):
        Divides the array a into two halves recursively.
        Calls itself to sort both halves and then merges them using the merge1 function.
        Base case: If the subarray has zero or one element (hi <= lo), it is already sorted.
    merge (Combining Two Arrays):
        Handles merging two arrays nums1 and nums2 into one sorted array.
        Uses helper arrays a (to hold all elements of nums1 and nums2) and aux (for temporary storage during sorting).
        First, extracts the first m elements from nums1 and all n elements from nums2 into a temporary array nums3.
        Transfers nums3 into a and sorts it using the mergesort function.
        Clears nums1 and fills it with the sorted elements from a.
    Efficiency:
    Merge Sort:
    Time complexity: O((m + n) log(m + n)) due to recursive divide-and-conquer steps.
    Space complexity: O(m + n) because of the auxiliary array.
    Purpose of merge:
    Designed to merge two sorted arrays (nums1 and nums2) in an efficient and organized way.
*/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void merge1(int *a, int *aux, int lo, int mid, int hi)
    {

        for (int k = lo; k <= hi; k++)
            aux[k] = a[k];
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++)
        {
            if (i > mid)
                a[k] = aux[j++];
            else if (j > hi)
                a[k] = aux[i++];
            else if (aux[j] < aux[i])
                a[k] = aux[j++];
            else
                a[k] = aux[i++];
        }
    }

    void mergesort(int *a, int *aux, int lo, int hi)
    {
        if (hi <= lo)
            return;
        int mid = (lo + hi) / 2;
        mergesort(a, aux, lo, mid);
        mergesort(a, aux, mid + 1, hi);
        merge1(a, aux, lo, mid, hi);
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums3;
        int *a, *aux, k = 0, c = 0;
        a = new int[m + n];
        aux = new int[m + n];
        for (auto e : nums1)
            if (c >= m)
                break;
            else
            {
                nums3.push_back(e);
                c++;
            }
        for (auto e : nums2)
            nums3.push_back(e);
        for (auto e : nums3)
        {
            a[k] = e;
            k++;
        }
        mergesort(a, aux, 0, m + n - 1);
        nums1.clear();
        for (int i = 0; i < m + n; i++)
            nums1.push_back(a[i]);
    }
};