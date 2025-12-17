// https://leetcode.com/problems/merge-k-sorted-lists/description/
#include <iostream>
#include <vector>
#include <queue>

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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* dummy = new ListNode(0);
		ListNode* curr = dummy;
		priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

		for (ListNode* node : lists) {
			if (node)
				pq.push({ node->val, node });
		}

		while (!pq.empty())
		{
			ListNode* node = pq.top().second;
			pq.pop();

			if (node->next)
				pq.push({ node->next->val, node->next });

			curr->next = node;
			curr = curr->next;
		}

		ListNode* res = dummy->next;
		delete dummy;
		return res;
	}
};