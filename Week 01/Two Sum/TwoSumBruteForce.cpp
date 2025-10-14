// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	// Space O(1)
	// Time O(n^2)
	vector<int> twoSum(vector<int>& nums, int target) {
		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					return { static_cast<int>(i), static_cast<int>(j) };
				}
			}
		}

		return {};
	}
};
