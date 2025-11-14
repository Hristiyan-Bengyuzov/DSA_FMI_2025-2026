// https://leetcode.com/problems/binary-tree-postorder-traversal/description/
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
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root)
			return res;

		postorderTraversal(root->left);
		postorderTraversal(root->right);
		res.push_back(root->val);

		return res;
	}
};