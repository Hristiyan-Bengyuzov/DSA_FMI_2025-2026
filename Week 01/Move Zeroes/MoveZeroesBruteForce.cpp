// https://leetcode.com/problems/plus-one/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// Space O(n)
	// Time O(n)
	void moveZeroes(vector<int>& nums) {
		vector<int> res;

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				res.push_back(nums[i]);
			}
		}

		size_t zeroesCount = nums.size() - res.size();
		for (size_t i = 0; i < zeroesCount; i++)
		{
			res.push_back(0);
		}

		for (size_t i = 0; i < nums.size(); i++)
			nums[i] = res[i];
	}
};