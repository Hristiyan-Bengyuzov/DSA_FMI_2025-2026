// https://leetcode.com/problems/sqrtx/description/
#include<iostream>

class Solution {
public:
	int mySqrt(int x) {
		long long l = 0, r = x, res = 0;

		while (l <= r)
		{
			long long mid = l + (r - l) / 2;
			long long squared = mid * mid;

			if (squared == x)
				return mid;

			if (squared < x) {
				res = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		return res;
	}
};