// https://leetcode.com/problems/minimum-cost-for-tickets/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	const int MAX_DAYS = 365;

public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		vector<int> dp(MAX_DAYS + 1);
		vector<bool> isTravelDay(MAX_DAYS + 1, false);

		for (int& day : days) {
			isTravelDay[day] = true;
		}

		for (int i = 1; i <= MAX_DAYS; i++)
		{
			if (isTravelDay[i])
			{
				int firstCost = dp[i - 1] + costs[0];
				int secondCost = dp[max(0, i - 7)] + costs[1];
				int thirdCost = dp[max(0, i - 30)] + costs[2];
				dp[i] = min(firstCost, min(secondCost, thirdCost));
			}
			else
			{
				dp[i] = dp[i - 1];
			}
		}

		return dp[MAX_DAYS];
	}
};