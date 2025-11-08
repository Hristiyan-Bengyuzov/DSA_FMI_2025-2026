// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stack;

		unordered_map<string, int(*)(int, int)> operation = {
			{ "+", [](int a, int b) { return a + b; }},
			{ "-", [](int a, int b) { return a - b; }},
			{ "*", [](int a, int b) { return a * b; }},
			{ "/", [](int a, int b) { return a / b; }}
		};

		for (const string& token : tokens) {
			if (operation.count(token))
			{
				int last = stack.top(); stack.pop();
				int first = stack.top(); stack.pop();
				stack.push(operation[token](first, last));
			}
			else
			{
				stack.push(stoi(token));
			}
		}

		return stack.top();
	}
};

int main() {
	Solution s;
	vector<string> v = { "4","13","5","/","+" };
	cout << s.evalRPN(v);
}