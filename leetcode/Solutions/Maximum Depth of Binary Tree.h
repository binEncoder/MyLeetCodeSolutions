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

class Solution_MaximumDepthOfBinaryTree {
public:
	// 98.78%
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	// 98.78%
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		int res = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			++res;
			int n = q.size();
			for (int i = 0; i < n; ++i) {
				TreeNode *t = q.front(); q.pop();
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
		return res;
	}
};