// https://www.hackerrank.com/contests/sda-2020-2021-test6-dbr8t-r/challenges/traversal-level-order
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int value;
	Node(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST {

public:
	BST() {
		root = NULL;
	}

	void insert(int value) {
		root = insert(root, value);
	}

	void printSFB() {
		if (!root)
			return;

		deque<Node*> deque;
		deque.push_back(root);
		bool leftToRight = true;

		while (!deque.empty())
		{
			size_t levelSize = deque.size();

			for (size_t i = 0; i < levelSize; i++)
			{
				if (leftToRight)
				{
					Node* node = deque.front(); deque.pop_front();
					cout << node->value << " ";

					if (node->left)
						deque.push_back(node->left);

					if (node->right)
						deque.push_back(node->right);
				}
				else
				{
					Node* node = deque.back(); deque.pop_back();
					cout << node->value << " ";

					if (node->right)
						deque.push_front(node->right);

					if (node->left)
						deque.push_front(node->left);
				}
			}

			leftToRight = !leftToRight;
		}
	}

private:
	Node* root;

	Node* insert(Node* curNode, int value) {
		if (curNode == NULL) {
			curNode = new Node(value);
		}
		else if (curNode->value < value) {
			curNode->right = insert(curNode->right, value);
		}
		else if (curNode->value > value) {
			curNode->left = insert(curNode->left, value);
		}

		return curNode;
	}
};

int main() {
	int n;
	cin >> n;
	int value;
	BST tree;
	for (int i = 0; i < n; i++) {
		cin >> value;
		tree.insert(value);
	}

	tree.printSFB();
	return 0;
}