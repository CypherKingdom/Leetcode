/*
	Easy - Longest Common Prefix
	https://leetcode.com/problems/longest-common-prefix/description
*/

#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result = "";
		if(strs.empty()) return result;
		else if(strs.size() == 1) return strs[0];
		else {
			int n = strs.size(), k, mini = INT_MAX, count;
			for(int i = 1; i < n; i++){
				k = 0;
				count = 0;
				while(k < min(strs[0].size(), strs[i].size())){
					if(strs[i][0] != strs[0][0]) return "";
					else if(strs[i][k] == strs[0][k]){
						result += strs[i][k];
						count++;
						k++;
					}
					else break;
				}
				if(count < mini) mini = count;
			}
			if(mini == INT_MAX) return "";
			return result.substr(0, mini);
		}
	}
};