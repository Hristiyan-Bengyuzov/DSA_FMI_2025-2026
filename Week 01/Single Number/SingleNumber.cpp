// https://leetcode.com/problems/single-number/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	// Space O(1)
	// Time O(n)
	int singleNumber(vector<int>& nums) {
		int missing = 0;
		for (int num : nums)
			missing ^= num;
		return missing;
	}
};