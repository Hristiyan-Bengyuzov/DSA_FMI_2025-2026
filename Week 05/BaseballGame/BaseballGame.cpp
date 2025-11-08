// https://leetcode.com/problems/baseball-game/description/
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	int calPoints(vector<string>& operations) {
		stack<int> scores;

		for (const string& operation : operations) {
			if (operation == "+")
			{
				int top1 = scores.top(); scores.pop();
				int top2 = scores.top();
				scores.push(top1);
				scores.push(top1 + top2);
			}
			else if (operation == "D")
			{
				scores.push(scores.top() * 2);
			}
			else if (operation == "C")
			{
				scores.pop();
			}
			else
			{
				scores.push(stoi(operation));
			}
		}

		int res = 0;
		while (!scores.empty()) {
			res += scores.top();
			scores.pop();
		}

		return res;
	}
};