// https://leetcode.com/problems/partition-list/
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head)
			return nullptr;

		ListNode* smallerDummy = new ListNode(0);
		ListNode* biggerDummy = new ListNode(0);
		ListNode* smaller = smallerDummy;
		ListNode* bigger = biggerDummy;
		ListNode* curr = head;

		while (curr)
		{
			if (curr->val < x)
			{
				smaller->next = curr;
				smaller = smaller->next;
			}
			else
			{
				bigger->next = curr;
				bigger = bigger->next;
			}

			curr = curr->next;
		}

		bigger->next = nullptr;
		smaller->next = biggerDummy->next;

		ListNode* res = smallerDummy->next;
		delete smallerDummy;
		delete biggerDummy;

		return res;
	}
};