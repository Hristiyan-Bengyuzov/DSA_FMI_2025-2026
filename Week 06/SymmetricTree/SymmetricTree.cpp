// https://leetcode.com/problems/symmetric-tree/description/
#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
	bool isSymetricHelper(TreeNode* left, TreeNode* right) {
		if (!left && !right)
			return true;

		if (!left || !right)
			return false;

		if (left->val != right->val)
			return false;

		return isSymetricHelper(left->left, right->right) && isSymetricHelper(left->right, right->left);
	}

public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;

		return isSymetricHelper(root->left, root->right);
	}
};