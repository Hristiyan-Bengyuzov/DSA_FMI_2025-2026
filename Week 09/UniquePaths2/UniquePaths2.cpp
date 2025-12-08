// https://leetcode.com/problems/unique-paths-ii/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid[0][0])
			return 0;

		size_t n = obstacleGrid.size();
		size_t m = obstacleGrid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));

		dp[0][0] = 1;

		for (size_t i = 1; i < n; i++)
		{
			if (obstacleGrid[i][0])
				break;

			dp[i][0] = dp[i - 1][0];
		}

		for (size_t j = 1; j < m; j++)
		{
			if (obstacleGrid[0][j])
				break;

			dp[0][j] = dp[0][j - 1];
		}

		for (size_t i = 1; i < n; i++)
		{
			for (size_t j = 1; j < m; j++)
			{
				if (obstacleGrid[i][j])
				{
					continue;
				}

				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[n - 1][m - 1];
	}
};