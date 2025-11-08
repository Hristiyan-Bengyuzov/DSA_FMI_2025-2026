// https://leetcode.com/problems/next-greater-node-in-linked-list/description/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> nodes;
		stack<int> stack;

		while (head)
		{
			nodes.push_back(head->val);
			head = head->next;
		}

		vector<int> res(nodes.size());

		for (size_t i = 0; i < nodes.size(); i++)
		{
			while (!stack.empty() && nodes[i] > nodes[stack.top()])
			{
				res[stack.top()] = res[i];
				stack.pop();
			}

			stack.push(i);
		}

		return res;
	}
};