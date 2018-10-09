#pragma once

#include "common.h"

/* best beat 100% */
class MyQueue_ImplementQueueUsingStacks{
public:
	/** Initialize your data structure here. */
	MyQueue_ImplementQueueUsingStacks() {
		;
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		pushStack.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int ret = peek();
		popStack.pop();
		return ret;
	}

	/** Get the front element. */
	int peek() {
		int ret = 0;
		if (popStack.size() == 0) {
			while (pushStack.size()) {
				popStack.push(pushStack.top());
				pushStack.pop();
			}
		}
		ret = popStack.top();
		return ret;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return pushStack.empty() && popStack.empty();
	}
private:
	stack<int> pushStack;
	stack<int> popStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */