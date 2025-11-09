// https://leetcode.com/problems/maximum-average-subarray-i/description/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Time O(n)
// Space O(k)
class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		queue<int> q;
		double sum = 0;
		double maxAverage = std::numeric_limits<double>::lowest();

		for (size_t i = 0; i < nums.size(); i++)
		{
			q.push(nums[i]);
			sum += nums[i];

			if (q.size() == k)
			{
				maxAverage = max(maxAverage, sum / k);
				sum -= q.front();
				q.pop();
			}
		}

		return maxAverage;
	}
};