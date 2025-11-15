// https://www.hackerrank.com/contests/sda-2019-2020-test3/challenges/print-specific-level
#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <queue>
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

	void printKDistant(int level) {
		if (!root)
			return;

		int currLevel = 0;
		queue<Node*> queue;
		queue.push(root);

		while (!queue.empty())
		{
			size_t levelSize = queue.size();
			bool onLevel = currLevel++ == level;

			for (size_t i = 0; i < levelSize; i++)
			{
				Node* node = queue.front(); queue.pop();

				if (onLevel)
					cout << node->value << " ";

				if (node->right)
					queue.push(node->right);

				if (node->left)
					queue.push(node->left);
			}

			if (onLevel)
				break;
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
	int value, level;
	BST tree;
	for (int i = 0; i < n; i++) {
		cin >> value;
		tree.insert(value);
	}

	cin >> level;
	tree.printKDistant(level);
	return 0;
}