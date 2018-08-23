/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_ConvertSortedArrayToBinarySearchTree{
  public:
    /*
    Your input
        [-10,-3,0,5,9]
    Your answer
        free(): invalid pointer: 0x000000000141dec8 ***
    Expected answer
        [0,-10,5,null,-3,null,9]

    答案没问题，可能是重复释放某一内存的问题……
    */
    TreeNode *sortedArrayToBST(vector<int> &nums)    {
        size_t len = nums.size();
        if (len == 0)
            return NULL;
        TreeNode *items = (TreeNode *)malloc(sizeof(TreeNode) * len);
        for (size_t i = 0; i < len; i++){
            (items + i)->val = nums[i];
            (items + i)->left = NULL;
            (items + i)->right = NULL;
        }
        size_t mid = len / 2, i;
        TreeNode *root = items + mid;

        for (i = mid; i > 0; i--){
            (items + i)->left = (items + i - 1);
        }
        (items + i)->left = NULL;

        for (i = mid; i < len - 1; i++){
            (items + i)->right = (items + i + 1);
        }
        (items + i)->right = NULL;
        return root;
    }

    TreeNode *sortedArrayToBSTOA(vector<int> &num)    {
        return sortedArrayToBSTOA(num.begin(), num.end());
    }
    template <typename RandomAccessIterator>
    TreeNode *sortedArrayToBSTOA(RandomAccessIterator first,
                               RandomAccessIterator last){
        const auto length = distance(first, last);
        if (length <= 0)
            return nullptr;
        auto mid = first + length / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right = sortedArrayToBST(mid + 1, last);
        return root;
    }
};