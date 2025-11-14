// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;

		if (!root)
			return res;

		queue<TreeNode*> queue;
		queue.push(root);

		while (!queue.empty())
		{
			int levelSize = queue.size();
			vector<int> currLevel;

			for (size_t i = 0; i < levelSize; i++)
			{
				TreeNode* node = queue.front(); queue.pop();
				currLevel.push_back(node->val);

				if (node->left)
					queue.push(node->left);

				if (node->right)
					queue.push(node->right);
			}

			res.push_back(currLevel);
		}

		return res;
	}
};