// https://leetcode.com/problems/odd-even-linked-list/description/
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
	ListNode* oddEvenList(ListNode* head) {
		if (!head)
			return nullptr;

		ListNode* oddDummy = new ListNode(0);
		ListNode* evenDummy = new ListNode(0);

		auto* odd = oddDummy;
		auto* even = evenDummy;
		auto* curr = head;
		bool isOdd = true;

		while (curr)
		{
			if (isOdd)
			{
				odd->next = curr;
				odd = odd->next;
			}
			else
			{
				even->next = curr;
				even = even->next;
			}

			isOdd = !isOdd;
			curr = curr->next;
		}

		// disconnect even from the rest of the things curr might be pointing to
		even->next = nullptr;

		odd->next = evenDummy->next;
		auto* res = oddDummy->next;
		delete oddDummy;
		delete evenDummy;

		return res;
	}
};
