// https://www.hackerrank.com/contests/sda-2021-2021-test-3-november16/challenges/challenge-1692
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* leftNode;
	Node* rightNode;
	Node(int d) {
		data = d;
		leftNode = NULL;
		rightNode = NULL;
	}
};

class Solution {
private:
	bool isOddLeaf(Node* node) {
		return node && !node->leftNode && !node->rightNode && node->data % 2 != 0;
	}

public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->leftNode, data);
				root->leftNode = cur;
			}
			else {
				cur = insert(root->rightNode, data);
				root->rightNode = cur;
			}

			return root;
		}
	}


	int getSumOddLeaves(Node* root) {
		if (!root)
			return 0;

		int sum = isOddLeaf(root) ? root->data : 0;
		return sum + getSumOddLeaves(root->leftNode) + getSumOddLeaves(root->rightNode);
	}
};

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	cout << myTree.getSumOddLeaves(root);
	return 0;
}