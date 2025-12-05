// https://leetcode.com/problems/isomorphic-strings/description/
#include <iostream>
#include <unordered_map>


using namespace std;

class Solution {
public:
	bool isIsomorphic(string& s, string& t) {
		if (s.size() != t.size())
			return false;

		unordered_map<char, char> sMap, tMap;

		for (size_t i = 0; i < s.size(); i++)
		{
			char sChar = s[i];
			char tChar = t[i];

			if (sMap.count(sChar) && sMap[sChar] != tChar)
				return false;

			if (tMap.count(tChar) && tMap[tChar] != sChar)
				return false;

			sMap[sChar] = tChar;
			tMap[tChar] = sChar;
		}

		return true;
	}
};