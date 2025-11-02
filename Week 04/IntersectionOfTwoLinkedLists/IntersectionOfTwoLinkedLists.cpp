// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int getLen(ListNode* head) {
		if (!head)
			return 0;

		auto* curr = head;
		int count = 0;
		while (curr)
		{
			count++;
			curr = curr->next;
		}

		return count;
	}


	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (!headA || !headB)
			return nullptr;

		int lenA = getLen(headA);
		int lenB = getLen(headB);
		ListNode* longer = nullptr;
		ListNode* shorter = nullptr;
		int diff = 0;

		if (lenA > lenB)
		{
			diff = lenA - lenB;
			longer = headA;
			shorter = headB;
		}
		else
		{
			diff = lenB - lenA;
			longer = headB;
			shorter = headA;
		}

		for (size_t i = 0; i < diff; i++)
		{
			longer = longer->next;
		}

		while (longer && shorter)
		{
			if (longer == shorter)
				return longer;
			longer = longer->next;
			shorter = shorter->next;
		}
		
		return nullptr;
	}
};