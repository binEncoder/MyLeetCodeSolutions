/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_MinimumDepthOfBinaryTree{
  public:
    int minDepth(const TreeNode *root){
        return minDepth(root, false);
    }

  private:
    static int minDepth(const TreeNode *root, bool hasbrother){
        if (!root)
            return hasbrother ? INT_MAX : 0;
        return 1 + min(minDepth(root->left, root->right != NULL),
                       minDepth(root->right, root->left != NULL));
    }

    int minDepthOA(TreeNode *root) {
        if (!root) return 0;
        else if (!root->left and !root->right) return 1;
        else if (root->left and root->right) return 1 + std::min(minDepthOA(root->left), minDepthOA(root->right));
        else return 1 + (root->left ? minDepthOA(root->left) : minDepthOA(root->right));
    }
};