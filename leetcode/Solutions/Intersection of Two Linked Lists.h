struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_IntersectionOfTwoLinkedLists {
public:
	void calcListLength(ListNode *l1, uint *len1, ListNode *l2, uint *len2){
		if( !l1 )	*len1 = 0;
		if( !l2 )	*len2 = 0;
		uint len[3] = { 0, 0, 0 };
		while( l1 && l2 ){
			len[1]++;	len[2]++;
			l1 = l1->next;
			l2 = l2->next;
		}
		while( l1 ){	len[1]++;	l1 = l1->next;	}
		while( l2 ){	len[2]++;	l2 = l2->next;	}
		*len1 = len[1];
		*len2 = len[2];
	}
	// best beat 82.31%
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		uint len1, len2;
		ListNode *ret = NULL;
		calcListLength(headA, &len1, headB, &len2);
		if( len1 && len2 ){
			uint steps = (len1 > len2)?(len1 - len2):(len2 - len1);
			for( uint i = 0; i < steps; i++ ){
				if( len1 > len2 ){
					headA = headA->next;
				}
				else{
					headB = headB->next;
				}
			}
			while( headA && headB ){
				if( headA == headB ){
					ret = headA;
					break;
				}
				headA = headA->next;
				headB = headB->next;
			}
		}
		return ret;
    }

	// best beat 5%，相当于强行环状连表，找相同，看着简便，其实可能跑了几圈循环，虽然还是O(n)
	ListNode *getIntersectionNodeOA1(ListNode *headA, ListNode *headB){
		typedef ListNode * ListPtr;
		ListPtr pa = headA, pb = headB;
		while( pa != pb ){
			pa = (pa != NULL)?pa->next:headA;
			pb = (pb != NULL)?pb->next:headB;
		}
		return pa;
	}
};
