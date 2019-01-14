/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

https://www.cnblogs.com/grandyang/p/4641968.html

/**
 * 我们只能在二叉树中来搜索p和q，然后从路径中找到最后一个相同的节点即为父节点，我们可以用递归来实现。
 * 在递归函数中，我们首先看当前结点是否为空，若为空则直接返回空；若root为p或q中的任意一个，也直接返回当前结点。
 * 否则的话就对其左右子结点分别调用递归函数，由于这道题限制了( p和q一定都在二叉树中存在 )，
 * 如果当前结点不等于p或q，p和q要么分别位于左右子树中，要么同时位于左子树，或者同时位于右子树。
 * 我们分别来讨论：
 * 若p和q分别位于左右子树中，那么对左右子结点调用递归函数，会分别返回p和q结点的位置，而当前结点正好就是p和q的最小共同父结点，直接返回当前结点即可。
 * 若p和q同时位于左子树，这里有两种情况：
 *      left会返回p和q中较高的那个位置，而right会返回空，所以我们最终返回非空的left即可；
 *      会返回p和q的最小父结点，就是说当前结点的左子树中的某个结点才是p和q的最小父结点，会被返回。
 * 若p和q同时位于右子树，同样这里有两种情况：
 *      一种情况是right会返回p和q中较高的那个位置，而left会返回空，所以我们最终返回非空的right即可；
 *      还有一种情况是会返回p和q的最小父结点，就是说当前结点的右子树中的某个结点才是p和q的最小父结点，会被返回。
 */
class Solution_LowestCommonAncestor_of_a_BinaryTree{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        if (!root || p == root || q == root){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right){
            return root;
        }
        return left ? left : right;
    }

    /**
     * 上述代码可以进行优化一下。
     * 如果当前结点不为空，且既不是p也不是q，那么根据上面的分析，p和q的位置就有三种情况：
     *      p和q要么分别位于左右子树中，要么同时位于左子树，或者同时位于右子树。
     * 我们需要优化的情况就是：
     *      当p和q同时为于左子树或右子树中，而且返回的结点并不是p或q。
     * 如果当前结点不为空，且既不是p也不是q，那么就是p和q的最小父结点了，已经求出来了，就不用再对右结点调用递归函数了
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || p == root || q == root) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       if (left && left != p && left != q) return left;
       TreeNode *right = lowestCommonAncestor(root->right, p , q);
　　　　if (left && right) return root;
       return left ? left : right;
    }
};