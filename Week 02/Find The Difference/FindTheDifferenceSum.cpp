// https://leetcode.com/problems/find-the-difference/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// Space O(1)
	// Time O(s + t)
	char findTheDifference(string s, string t) {
		int sumS = 0, sumT = 0;

		for (char c : s)
			sumS += c;

		for (char c : t)
			sumT += c;

		return sumT - sumS;
	}
};