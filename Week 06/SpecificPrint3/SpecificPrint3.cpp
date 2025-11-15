// https://www.hackerrank.com/contests/sda-test3-2022-2023-rdsafgtvh/challenges/--149
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

	void printSpecific() {
		if (!root)
			return;

		printHelper(root);
	}

private:
	Node* root;

	void printHelper(Node* node) {
		if (!node)
			return;

		if (node->left && node->right)
			cout << node->value << " ";
		printHelper(node->left);
		printHelper(node->right);
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
	int treesCount, value, nodesCount;
	cin >> treesCount;
	for (int i = 0; i < treesCount; i++) {
		BST tree;
		cin >> nodesCount;

		for (size_t i = 0; i < nodesCount; i++)
		{
			cin >> value;
			tree.insert(value);
		}

		tree.printSpecific();
		cout << std::endl;
	}
	return 0;
}