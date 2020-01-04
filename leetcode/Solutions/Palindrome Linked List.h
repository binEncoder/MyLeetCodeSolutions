#pragma once

#include "common.h"

/* best beat 56.48% */
class Solution_PalindromeLinkedList {
public:
	bool isPalindrome(ListNode* head) {
		string obj;
		char num[5];
		int val = 0, len = 0, midNum = 0, idx = 0;
		ListNode* tmp = head;
		while (tmp) {
			sprintf(num, "%d", abs(tmp->val)%7);
			val ^= tmp->val;
			obj += string(num);
			tmp = tmp->next;
			++len;
		}

		tmp = head;
		while (tmp) {
			if (idx == (len / 2)) {
				midNum = tmp->val;
			}
			tmp = tmp->next;
			++idx;
		}

		if (len & 1) {
			return isPalindrome(obj.c_str()) && ((val ^ midNum) == 0);
		}
		return isPalindrome(obj.c_str()) && (val == 0) ;
	}
private:
	bool isPalindrome(const char *pstr) {
		size_t len = strlen(pstr);
		if (len <= 1) {
			return true;
		}
		size_t left = 0, right = len - 1;
		while (left < right) {
			if (*(pstr + left) != *(pstr + right)) {
				return false;
			}
			++left;		--right;
		}
		return true;
	}
};


/* 神使用递归…… best beat 98.71%
public:
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		temp = head;
		return check(head);
	}

	bool check(ListNode* p) {
		if (NULL == p) return true;
		bool isPal = check(p->next) & (temp->val == p->val);
		temp = temp->next;
		return isPal;
	}
 */


/* test code */
/*
Solution obj;
static const int nodeNumDef = 1;
int arr[nodeNumDef] = { -129 };
ListNode *nodes[nodeNumDef];
for (int nodeNum = nodeNumDef-1; nodeNum >= 0; --nodeNum) {
	nodes[nodeNum] = new ListNode(arr[nodeNum]);
	nodes[nodeNum]->next = (nodeNum == (nodeNumDef - 1)) ? NULL : nodes[nodeNum + 1];
}

cout<<obj.isPalindrome(nodes[0])<<endl;
for (int num = 0; num < nodeNumDef; num++) {
	delete nodes[num];
}
 */