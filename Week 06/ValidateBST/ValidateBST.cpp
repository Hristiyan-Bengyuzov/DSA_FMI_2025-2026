// https://leetcode.com/problems/validate-binary-search-tree/description/
#include <iostream>
#include <limits>

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
	bool isValidHelper(TreeNode* root, long long min, long long max) {
		if (!root)
			return true;

		if (root->val <= min || root->val >= max)
			return false;

		return isValidHelper(root->left, min, root->val) && isValidHelper(root->right, root->val, max);
	}

public:
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;

		return isValidHelper(root, LLONG_MIN, LLONG_MAX);
	}
};