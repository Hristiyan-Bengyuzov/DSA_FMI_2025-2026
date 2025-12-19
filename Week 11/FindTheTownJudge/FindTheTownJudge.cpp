// https://leetcode.com/problems/find-the-town-judge/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> counts(n + 1, 0);

		for (auto& trustPair : trust)
		{
			counts[trustPair[0]]--;
			counts[trustPair[1]]++;
		}

		for (size_t i = 1; i <= n; i++)
		{
			if (counts[i] == n - 1)
				return i;
		}

		return -1;
	}
};