// https://leetcode.com/problems/design-linked-list/
#include <iostream>

class MyLinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node(int data) : data(data), next(nullptr) {}
	};

public:
	Node* head;
	Node* tail;
	size_t size;

	MyLinkedList() {
		head = tail = nullptr;
		size = 0;
	}

	int get(int index) {
		if (index < 0 || index >= size)
			return -1;

		auto* curr = head;
		for (size_t i = 0; i < index; i++)
			curr = curr->next;

		return curr->data;
	}

	void addAtHead(int val) {
		Node* newNode = new Node(val);

		if (!head)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	void addAtTail(int val) {
		Node* newNode = new Node(val);

		if (!head)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
		size++;
	}

	void addAtIndex(int index, int val) {
		if (index < 0 || index > size)
			return;

		if (index == 0)
		{
			addAtHead(val);
			return;
		}

		if (index == size)
		{
			addAtTail(val);
			return;
		}

		Node* newNode = new Node(val);
		auto* curr = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			curr = curr->next;
		}

		newNode->next = curr->next;
		curr->next = newNode;
		size++;
	}

	void deleteAtIndex(int index) {
		if (index < 0 || index >= size || !head)
			return;

		if (index == 0)
		{
			Node* toDelete = head;
			head = head->next;
			if (size == 1)
				tail = nullptr;
			delete toDelete;
			size--;
			return;
		}

		Node* curr = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			curr = curr->next;
		}

		Node* toDelete = curr->next;
		curr->next = curr->next->next;

		if (toDelete == tail)
			tail = curr;

		delete toDelete;
		size--;
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */