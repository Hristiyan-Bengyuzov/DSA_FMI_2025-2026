// https://leetcode.com/problems/longest-increasing-subsequence/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);

		for (size_t i = 1; i < nums.size(); i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
				{
					dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
		}

		return *max_element(dp.begin(), dp.end());
	}
};