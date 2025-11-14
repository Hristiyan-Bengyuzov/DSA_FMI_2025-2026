// https://leetcode.com/problems/maximum-average-subarray-i/description/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Time O(n)
// Space O(1)
class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double sum = 0;
		for (size_t i = 0; i < k; i++)
			sum += nums[i];

		double maxAverage = sum / k;

		for (size_t i = k; i < nums.size(); i++)
		{
			sum += nums[i] - nums[i - k];
			maxAverage = max(maxAverage, sum / k);
		}

		return maxAverage;
	}
};
