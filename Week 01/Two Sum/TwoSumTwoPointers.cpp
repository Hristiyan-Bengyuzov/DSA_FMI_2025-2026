// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// Space O(n)
	// Time O(nlogn)
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<pair<int, int>> numsIndices(nums.size());

		for (size_t i = 0; i < nums.size(); i++)
			numsIndices[i] = { nums[i], i };

		sort(numsIndices.begin(), numsIndices.end());
		int l = 0, r = numsIndices.size() - 1;

		while (l < r)
		{
			int sum = numsIndices[l].first + numsIndices[r].first;

			if (sum == target)
				return { numsIndices[l].second, numsIndices[r].second };

			if (sum < target)
				l++;
			else
				r--;
		}

		return {};
	}
};
