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
class Solution_SymmetricTree {
public:
	// 98.26%
	bool isSymmetricOA(TreeNode *root) {
		if (root == nullptr) return true;
		return isSymmetricOA(root->left, root->right);
	}
	bool isSymmetricOA(TreeNode *p, TreeNode *q) {
		if (p == nullptr && q == nullptr) return true;
		if (p == nullptr || q == nullptr) return false;
		return p->val == q->val
			&& isSymmetricOA(p->left, q->right)
			&& isSymmetricOA(p->right, q->left);
	}

	// 98.26%
	bool isSymmetricOA2(TreeNode* root) {
		if (!root) return true;
		stack<TreeNode*> s;
		s.push(root->left);
		s.push(root->right);
		while (!s.empty()) {
			auto p = s.top(); s.pop();
			auto q = s.top(); s.pop();
			if (!p && !q) continue;
			if (!p || !q) return false;
			if (p->val != q->val) return false;
			s.push(p->left);
			s.push(q->right);
			s.push(p->right);
			s.push(q->left);
		}
		return true;
	}
};