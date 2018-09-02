#pragma once

#include "common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_BinaryTreeLevelOrderTraversalII {
public:
	// 98.05% 先求出树的深度，然后层序遍历，添加元素，利用 "Maximum Depth of Binary Tree.h"文件中的相关算法
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root) return ret;
		int depth = maxDepth(root), level = depth;
		ret.resize(depth);
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {

			--level;

			int n = q.size();
			for (int i = 0; i < n; ++i) {
				TreeNode *t = q.front(); q.pop();

				ret[level].push_back(t->val);

				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return ret;
	}

	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	// 98.05%
	vector<vector<int> > levelOrderBottomOA(TreeNode *root) {
		vector<vector<int>> result;
		traverse(root, 1, result);

		// reverse明显是反序
		std::reverse(result.begin(), result.end());
		return result;
	}
	void traverse(TreeNode *root, size_t level, vector<vector<int>> &result) {
		if (!root) return;
		if (level > result.size())
			result.push_back(vector<int>());
		result[level - 1].push_back(root->val);
		traverse(root->left, level + 1, result);
		traverse(root->right, level + 1, result);
	}
};