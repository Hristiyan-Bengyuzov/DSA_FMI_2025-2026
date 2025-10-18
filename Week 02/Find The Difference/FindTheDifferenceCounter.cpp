// https://leetcode.com/problems/find-the-difference/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// Space O(1)
	// Time O(s + t)
	char findTheDifference(string& s, string& t) {
		const size_t LETTERS_COUNT = 26;
		int sCounter[LETTERS_COUNT] = {};
		int tCounter[LETTERS_COUNT] = {};

		for (char c : s)
			sCounter[c - 'a']++;

		for (char c : t)
			tCounter[c - 'a']++;

		for (size_t i = 0; i < LETTERS_COUNT; i++)
		{
			if (sCounter[i] != tCounter[i])
			{
				return i + 'a';
			}
		}

		return '?';
	}
};