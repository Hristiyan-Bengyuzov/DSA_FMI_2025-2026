// https://leetcode.com/problems/valid-parentheses/description/
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isValid(string& s) {
		stack<char> stack;
		unordered_map<char, char> matching = {
			{ ')', '('},
			{ '}', '{'},
			{ ']', '['},
		};

		for (const char& c : s)
		{
			if (matching.count(c))
			{
				if (stack.empty() || matching[c] != stack.top())
					return false;
				stack.pop();
			}
			else
			{
				stack.push(c);
			}
		}

		return stack.empty();
	}
};