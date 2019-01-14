/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_DeleteNode_in_a_LinkedList {
public:
    // 只要求数据一样的话，可以转换为删除后面一个节点，并把后面那个节点的数据( val、next )赋给当前节点
    void deleteNode(ListNode* node) {
        ListNode* ptr = node->next;
        node->val = ptr->val;
        node->next = ptr->next;
        delete ptr;
    }
};