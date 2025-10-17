// https://leetcode.com/problems/contains-duplicate/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// Space O(1)
	// Time O(nlogn)
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1])
			{
				return true;
			}
		}
		return false;
	}
};