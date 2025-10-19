// https://leetcode.com/problems/rotate-array/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	// Gets a time exceeded on one test
	// Space O(1)
	// Time O(n * k)
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();

		for (size_t i = 0; i < k; i++)
		{
			int last = nums[nums.size() - 1];
			for (int i = nums.size() - 1; i > 0; i--)
			{
				nums[i] = nums[i - 1];
			}
			nums[0] = last;
		}
	}
};