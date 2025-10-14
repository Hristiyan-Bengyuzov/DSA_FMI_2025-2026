// https://leetcode.com/problems/valid-palindrome-ii/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// Helper
	// Space O(1)
	// Time O(n)
	bool isPalindrome(string& s, int l, int r) {
		while (l < r)
		{
			if (s[l] != s[r])
				return false;

			l++;
			r--;
		}

		return true;
	}

	// Space O(1)
	// Time O(n), because helper is called only once
	bool validPalindrome(string s) {
		int l = 0, r = s.size() - 1;

		while (l < r)
		{
			if (s[l] != s[r])
				return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);

			l++;
			r--;
		}

		return true;
	}
};