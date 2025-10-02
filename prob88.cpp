/*
	Easy - Merge Sorted Array
	https://leetcode.com/problems/merge-sorted-array/description
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