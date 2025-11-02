// https://leetcode.com/problems/palindrome-linked-list/
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
	ListNode* reverse(ListNode* head) {
		if (!head)
			return nullptr;

		ListNode* prev = nullptr;
		ListNode* curr = head;
		ListNode* next = nullptr;

		while (curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		return prev;
	}

	bool isPalindrome(ListNode* head) {
		if (!head)
			return true;

		auto* slow = head;
		auto* fast = head;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		// first and second half
		auto* first = head;
		auto* second = reverse(slow);

		while (second)
		{
			if (first->val != second->val)
				return false;
			first = first->next;
			second = second->next;
		}

		return true;
	}
};