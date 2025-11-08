// https://leetcode.com/problems/asteroid-collision/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> stack;

		for (const int& asteroid : asteroids)
		{
			bool destroyed = false;

			while (!stack.empty() && asteroid < 0 && stack.top() > 0)
			{
				if (abs(asteroid) > stack.top())
				{
					stack.pop();
				}
				else if (abs(asteroid) == stack.top())
				{
					stack.pop();
					destroyed = true;
					break;
				}
				else
				{
					destroyed = true;
					break;
				}
			}

			if (!destroyed)
				stack.push(asteroid);
		}

		vector<int> res(stack.size());
		for (int i = stack.size() - 1; i >= 0; i--)
		{
			res[i] = stack.top();
			stack.pop();
		}

		return res;
	}
};