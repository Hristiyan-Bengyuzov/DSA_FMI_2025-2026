// https://leetcode.com/problems/linked-list-cycle-ii/description/
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (!head)
			return nullptr;

		auto* fast = head;
		auto* slow = head;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
				break;
		}

		if (!fast || !fast->next)
			return nullptr;

		auto* curr = head;
		while (curr != slow)
		{
			curr = curr->next;
			slow = slow->next;
		}

		return curr;
	}
};