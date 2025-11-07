#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	stack<char> toStack(string& s) {
		stack<char> res;

		for (const char& c : s) {
			if (c == '#')
			{
				if (!res.empty())
					res.pop();
			}
			else
			{
				res.push(c);
			}
		}

		return res;
	}

	bool backspaceCompare(string& s, string& t) {
		stack<char> sStack = toStack(s);
		stack<char> tStack = toStack(t);

		while (!sStack.empty() && !tStack.empty())
		{
			if (sStack.top() != tStack.top())
				return false;

			sStack.pop();
			tStack.pop();
		}

		return sStack.empty() && tStack.empty();
	}
};