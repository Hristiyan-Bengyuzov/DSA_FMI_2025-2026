// https://leetcode.com/problems/daily-temperatures/description/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> res(temperatures.size());
		stack<int> stack;

		for (size_t i = 0; i < temperatures.size(); i++)
		{
			while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
			{
				int prevInd = stack.top(); stack.pop();
				res[prevInd] = i - prevInd;
			}

			stack.push(i);
		}

		return res;
	}
};