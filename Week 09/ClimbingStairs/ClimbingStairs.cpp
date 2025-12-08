// https://leetcode.com/problems/climbing-stairs/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 0 || n == 1 || n == 2)
			return n;

		vector<int> steps(n + 1);
		steps[1] = 1;
		steps[2] = 2;

		for (size_t i = 3; i <= n; i++)
		{
			steps[i] = steps[i - 1] + steps[i - 2];
		}

		return steps[n];
	}
};