// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		if (cost.size() == 0)
			return 0;

		vector<int> dp(cost.size());

		dp[0] = cost[0];
		dp[1] = cost[1];

		for (size_t i = 2; i < cost.size(); i++)
		{
			dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
		}

		return min(dp[dp.size() - 1], dp[dp.size() - 2]);
	}
};