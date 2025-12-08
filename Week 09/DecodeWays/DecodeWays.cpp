// https://leetcode.com/problems/decode-ways/
#include <iostream>
#include <vector>

using namespace std;

int charToInt(char c) {
	return c - '0';
}

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0')
			return 0;

		size_t n = s.size();
		vector<int> dp(n + 1);

		dp[0] = 1;
		dp[1] = 1;

		for (size_t i = 2; i <= n; i++)
		{
			if (s[i - 1] != '0')
			{
				dp[i] += dp[i - 1];
			}

			int num = charToInt(s[i - 2]) * 10 + charToInt(s[i - 1]);

			if (num >= 10 && num <= 26)
			{
				dp[i] += dp[i - 2];
			}
		}

		return dp[n];
	}
};