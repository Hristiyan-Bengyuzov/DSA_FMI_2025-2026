// https://leetcode.com/problems/maximum-average-subarray-i/description/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Doesn't pass all tests cause it's too slow
// Time O(n * k)
// Space O(1)
class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double maxAverage = numeric_limits<double>::lowest();

		for (size_t i = 0; i <= nums.size() - k; i++)
		{
			double sum = 0;
			for (size_t j = 0; j < k; j++)
				sum += nums[i + j];
			maxAverage = max(maxAverage, sum / k);
		}

		return maxAverage;
	}
};