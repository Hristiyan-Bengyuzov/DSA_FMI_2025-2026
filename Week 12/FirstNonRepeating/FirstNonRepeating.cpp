// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	string firstNonRepeating(string& s) {
		string res;
		unordered_map<char, int> freq;
		queue<char> q;

		for (char& c : s) {
			freq[c]++;
			q.push(c);

			while (!q.empty() && freq[q.front()] > 1)
			{
				q.pop();
			}

			res += (q.empty() ? '#' : q.front());
		}

		return res;
	}
};