/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_BalancedBinaryTree {
public:
    size_t TreeDepth(TreeNode* root) {
		if (!root) return 0;
		else return 1+max(TreeDepth(root->left), TreeDepth(root->right));
	}

	bool isBalanced(TreeNode* root) {
		if (!root)     return true;
		size_t leftDepth = 0, rightDepth = 0;
		leftDepth = TreeDepth(root->left);
		rightDepth = TreeDepth(root->right);
		if (
			((leftDepth - rightDepth) < 2)  || 
			((rightDepth - leftDepth ) < 2)
			) {
			return isBalanced(root->left)&& isBalanced(root->right);
		}
		return false;
	}
};