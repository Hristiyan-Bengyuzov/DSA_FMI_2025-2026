// https://leetcode.com/problems/group-anagrams/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> map;

		for (const string& str : strs)
		{
			string sortedStr = str;
			sort(sortedStr.begin(), sortedStr.end());

			map[sortedStr].push_back(str);
		}

		vector<vector<string>> res;

		for (auto& entry : map) {
			res.push_back(entry.second);
		}

		return res;
	}
};