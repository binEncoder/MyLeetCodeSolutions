#pragma once
#include "common.h"


class Solution_ReverseLinkedList {
	using ListPtr = ListNode *;
public:
	// best beat 100%
	ListNode* reverseList(ListNode* head) {
		ListPtr slow = NULL, fast = head;
		while (fast) {
			ListPtr tmp = fast->next;
			fast->next = slow;
			slow = fast;
			fast = tmp;
		}
		return slow;
	}
};
