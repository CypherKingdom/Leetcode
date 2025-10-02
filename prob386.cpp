/*
	Medium - Lexicographical Numbers
	https://leetcode.com/problems/lexicographical-numbers/description
*/

using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<string> input;
		vector<int> output(n);
		for(int i=1;i<=n;i++)
			input.push_back(to_string(i));
		sort(input.begin(), input.end());
		for(int i =0;i<n;i++)
			output[i] = stoi(input[i]);
		return output;
	}
};