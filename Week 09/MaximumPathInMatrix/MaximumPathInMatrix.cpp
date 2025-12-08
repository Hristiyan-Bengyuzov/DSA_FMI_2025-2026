// https://www.hackerrank.com/contests/sda-2022-2023-test7-123-43/challenges/1-454
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMaximumPath(vector<vector<int>>& matrix, vector<vector<bool>>& allowDiag) {
	int n = matrix.size();

	vector<vector<int>> dp(n, vector<int>(n));

	dp[0][0] = matrix[0][0];
	for (size_t i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + matrix[i][0];
		dp[0][i] = dp[0][i - 1] + matrix[0][i];
	}

	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			int maxSum = max(dp[i - 1][j], dp[i][j - 1]);

			if (allowDiag[i][j])
			{
				maxSum = max(maxSum, dp[i - 1][j - 1]);
			}

			dp[i][j] = matrix[i][j] + maxSum;
		}
	}

	return dp[n - 1][n - 1];
}


int main()
{
	size_t n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	size_t diagCellsCount;
	cin >> diagCellsCount;

	vector<vector<bool>> allowDiag(n, vector<bool>(n, false));

	for (size_t i = 0; i < diagCellsCount; i++)
	{
		size_t x, y;
		cin >> x >> y;
		allowDiag[x][y] = true;
	}

	cout << getMaximumPath(matrix, allowDiag);
}
