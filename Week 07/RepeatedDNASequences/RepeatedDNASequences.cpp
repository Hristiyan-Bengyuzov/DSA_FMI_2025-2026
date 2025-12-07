// https://leetcode.com/problems/repeated-dna-sequences/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		const int SUBSTRING_LEN = 10;
		unordered_map<string, int> dnaOccurences;
		int size = s.size() - SUBSTRING_LEN;

		for (int i = 0; i <= size; i++)
		{
			string substr = s.substr(i, SUBSTRING_LEN);
			dnaOccurences[substr]++;
		}

		vector<string> result;

		for (auto& entry : dnaOccurences)
		{
			if (entry.second > 1)
				result.push_back(entry.first);
		}

		return result;
	}
};