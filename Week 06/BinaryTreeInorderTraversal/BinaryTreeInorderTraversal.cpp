// https://leetcode.com/problems/binary-tree-inorder-traversal/
#include <iostream>
#include <vector>

using namespace std;

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
	vector<int> res;

public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root)
			return res;

		inorderTraversal(root->left);
		res.push_back(root->val);
		inorderTraversal(root->right);

		return res;
	}
};