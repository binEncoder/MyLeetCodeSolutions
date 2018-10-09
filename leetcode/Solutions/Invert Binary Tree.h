#pragma once

#include "common.h"


class Solution_InvertBinaryTree {
public:
	/* best beat 100% */
	TreeNode* invertTree(TreeNode* root) {
		if (!root)	return NULL;
		if (!root->left && !root->right)	return root;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};