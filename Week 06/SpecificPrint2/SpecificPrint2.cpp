// https://www.hackerrank.com/contests/sda-2021-2021-test-3-november16/challenges/tree-specific-print
#include <cmath>
#include <cstdio>
#include <vector>
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

	void printSpecific(int dividedBy) {
		if (!root)
			return;

		printHelper(root, dividedBy);
	}

private:
	Node* root;

	void printHelper(Node* node, int dividedBy) {
		if (!node)
			return;

		if (!isLeaf(node) && node->value % dividedBy == 0)
			cout << node->value << " ";
		printHelper(node->left, dividedBy);
		printHelper(node->right, dividedBy);
	}

	bool isLeaf(Node* node) {
		return node && !node->left && !node->right;
	}

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
	int dividedBy;
	cin >> dividedBy;
	tree.printSpecific(dividedBy);
	return 0;
}