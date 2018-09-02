#pragma once

#include "common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution_RemoveDuplicatesFromSortedList {
public:
	// 97.8%
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *p = head, *freeP = NULL, *ret = head;
		while (p != NULL && p->next != NULL ) {
			if (p->val == p->next->val) {
				freeP = p->next;
				p->next = p->next->next;
				free(freeP);				/* vs 2017下可以编译通过，但是运行失败？提交通过 */
			}
			else {
				p = p->next;
			}
		}
		return ret;
	}
};