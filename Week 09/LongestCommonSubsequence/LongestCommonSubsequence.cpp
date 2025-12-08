// https://leetcode.com/problems/longest-common-subsequence/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		size_t n = text1.size();
		size_t m = text2.size();
		vector<vector<int>> dp(n, vector<int>(m));

		dp[0][0] = (text1[0] == text2[0] ? 1 : 0);

		for (size_t i = 1; i < n; i++)
		{
			dp[i][0] = dp[i - 1][0];
			if (text1[i] == text2[0])
			{
				dp[i][0] = 1;
			}
		}

		for (size_t j = 1; j < m; j++)
		{
			dp[0][j] = dp[0][j - 1];
			if (text2[j] == text1[0])
			{
				dp[0][j] = 1;
			}
		}

		for (size_t i = 1; i < n; i++)
		{
			for (size_t j = 1; j < m; j++)
			{
				if (text1[i] == text2[j])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		return dp[n - 1][m - 1];
	}
};