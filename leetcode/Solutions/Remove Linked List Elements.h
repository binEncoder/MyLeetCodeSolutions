#include "common.h"

class Solution_RemoveLinkedListElements {
public:
	// best beat 100%
    ListNode* removeElements(ListNode* head, int val) {
        if( !head )		return NULL;
		ListNode *fast = head, *curr = head, *ret = NULL;
		while( fast ){
			if( !ret && fast->val != val )		ret = fast;
			if( fast->val == val ){
				curr->next = fast->next;
				free(fast);
				fast = curr->next;
				continue;
			}

			curr = fast;
			fast = fast?fast->next:NULL;
		}
		return ret;
    }
};

int main(int argc, char *argv[]){
	Solution_RemoveLinkedListElements s;
	int input = 1, itemsNum = 2;
	struct ListNode *nodes = (ListNode *)malloc(sizeof(ListNode)*itemsNum);
	for( int i = 0; i < itemsNum; i++ ){
		(nodes+i)->val = i+1;
		(nodes+i)->next = (i == itemsNum - 1)?NULL:nodes+i+1;
	}
	ListNode *head = s.removeElements(nodes, input);
	while(head){
		cout<<head->val<<endl;
		head = head->next;
	}

	return 0;
}
