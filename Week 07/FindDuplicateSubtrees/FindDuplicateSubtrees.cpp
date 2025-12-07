// https://leetcode.com/problems/find-duplicate-subtrees/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

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
	vector<TreeNode*> res;
	unordered_map<string, int> treeOccurences;

public:
	string getDuplicates(TreeNode* root) {
		if (!root)
			return ".";

		string left = getDuplicates(root->left);
		string right = getDuplicates(root->right);

		string tree = to_string(root->val) + "," + left + "," + right;

		if (treeOccurences.count(tree) && treeOccurences[tree] == 1)
		{
			res.push_back(root);
		}

		treeOccurences[tree]++;
		return tree;
	}


	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		getDuplicates(root);
		return res;
	}
};