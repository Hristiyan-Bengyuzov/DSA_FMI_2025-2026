// https://leetcode.com/problems/move-zeroes/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// Space O(1)
	// Time O(n)
	void moveZeroes(vector<int>& nums) {
		size_t counter = 0;

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				swap(nums[counter++], nums[i]);
			}
		}
	}
};