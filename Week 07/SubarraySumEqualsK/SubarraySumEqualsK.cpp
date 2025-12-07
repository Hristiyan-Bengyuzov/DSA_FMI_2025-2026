// https://leetcode.com/problems/subarray-sum-equals-k/description/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int currSum = 0;
		unordered_map<int, int> prefixSumCounts;
		int res = 0;

		prefixSumCounts[0] = 1;

		for (int& num : nums)
		{
			currSum += num;
			int diff = currSum - k;

			if (prefixSumCounts.count(diff))
			{
				res += prefixSumCounts[diff];
			}

			prefixSumCounts[currSum]++;
		}

		return res;
	}
};