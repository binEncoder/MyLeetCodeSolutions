/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */

class Solution_BinaryTreePaths {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if( root ) binaryTreePaths(result, root, to_string(root->val));
        return result;
    }
private:
    void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
        if(!root->left && !root->right) result.push_back(t);

        if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
        if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
    }
};