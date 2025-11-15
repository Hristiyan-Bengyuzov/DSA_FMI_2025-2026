// https://leetcode.com/problems/binary-tree-right-side-view/description/
#include <iostream>
#include <vector>
#include <queue>

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
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;

		if (!root)
			return res;

		queue<TreeNode*> queue;
		queue.push(root);

		while (!queue.empty())
		{
			size_t levelSize = queue.size();

			for (size_t i = 0; i < levelSize; i++)
			{
				TreeNode* node = queue.front(); queue.pop();

				if (i == levelSize - 1)
					res.push_back(node->val);
				
				if (node->left)
					queue.push(node->left);

				if (node->right)
					queue.push(node->right);
			}
		}

		return res;
	}
};