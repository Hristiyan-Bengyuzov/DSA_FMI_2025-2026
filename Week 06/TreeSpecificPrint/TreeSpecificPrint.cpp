// https://www.hackerrank.com/contests/sda-2019-2020-test3/challenges/tree-specific-print
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
		printHelper(root, dividedBy);
	}

private:
	Node* root;

	void printHelper(Node* root, int dividedBy) {
		if (!root)
			return;

		if (!isLeaf(root) && root->value % dividedBy == 0)
		{
			cout << root->value << " ";
		}

		printHelper(root->left, dividedBy);
		printHelper(root->right, dividedBy);
	}

	bool isLeaf(Node* root) {
		return !root->left && !root->right;
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