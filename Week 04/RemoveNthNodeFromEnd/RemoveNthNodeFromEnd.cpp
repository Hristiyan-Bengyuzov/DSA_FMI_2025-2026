// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
	int getLen(ListNode* head) {
		if (!head)
			return 0;

		auto* curr = head;
		int len = 0;
		while (curr)
		{
			len++;
			curr = curr->next;
		}

		return len;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head)
			return nullptr;

		int len = getLen(head);
		int deleteInd = len - n;

		if (deleteInd == 0)
		{
			auto* toDelete = head;
			head = head->next;
			delete toDelete;
			return head;
		}

		auto* curr = head;
		for (size_t i = 0; i < deleteInd - 1; i++)
		{
			curr = curr->next;
		}

		auto* toDelete = curr->next;
		curr->next = curr->next->next;
		delete toDelete;
		return head;
	}
};
