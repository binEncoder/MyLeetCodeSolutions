#pragma once

#include "common.h"

class MyStack_ImplementStackUsingQueues{
public:
	/** Initialize your data structure here. */
	MyStack_ImplementStackUsingQueues() {
		;
	}

	/** Push element x onto stack. */
	void push(int x) {
		obj.push_back(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret = top();
		obj.pop_back();
		return ret;
	}

	/** Get the top element. */
	int top() {
		return obj.at(obj.size() - 1);
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return obj.size() == 0;
	}
private:
	vector<int> obj;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */