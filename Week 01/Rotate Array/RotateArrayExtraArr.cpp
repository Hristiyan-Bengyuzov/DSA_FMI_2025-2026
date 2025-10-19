// https://leetcode.com/problems/rotate-array/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	// Space O(n)
	// Time O(n)
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		vector<int> res(n);

		for (size_t i = 0; i < n; i++)
		{
			res[(i + k) % n] = nums[i];
		}
		nums = res;
	}
};