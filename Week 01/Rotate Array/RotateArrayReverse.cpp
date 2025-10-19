// https://leetcode.com/problems/rotate-array/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reverse(vector<int>& nums, int start, int end) {
		while (start < end) {
			swap(nums[start], nums[end]);
			start++;
			end--;
		}
	}


	// Space O(1)
	// Time O(n)
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		reverse(nums, 0, n - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, n - 1);
	}
};