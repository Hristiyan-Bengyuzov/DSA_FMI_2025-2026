// https://leetcode.com/problems/plus-one/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// Space O(1)
	// Time O(n)
	vector<int> plusOne(vector<int>& digits) {
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] < 9)
			{
				digits[i]++;
				return digits;
			}

			digits[i] = 0;
		}

		digits.insert(digits.begin(), 1);
		return digits;
	}
};