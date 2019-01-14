/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BST first!!!
class Solution_LowestCommonAncestor_of_a_BinarySearchTree {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = nullptr;
        ret = root;
        while(ret){
            if( ret->val < p->val && ret->val < q->val ){
                ret = ret->right;
            }
            else if( ret->val > p->val && ret->val > q->val ){
                ret = ret->left;
            }
            else{
                break;
            }
        }
        return ret;
    }
};