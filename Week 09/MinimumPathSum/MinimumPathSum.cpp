// https://leetcode.com/problems/minimum-path-sum/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		vector<vector<int>> dp(n, vector<int>(m));

		dp[0][0] = grid[0][0];

		for (size_t i = 1; i < n; i++)
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}

		for (size_t j = 1; j < m; j++)
		{
			dp[0][j] = dp[0][j - 1] + grid[0][j];
		}

		for (size_t i = 1; i < n; i++)
		{
			for (size_t j = 1; j < m; j++)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}

		return dp[n - 1][m - 1];
	}
};