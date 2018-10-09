#pragma once

#include "common.h"

class Solution_PowerOfTwo {
public:
	/* 过滤掉不符合的负数 */
	/* best beat 97.69% */
	bool isPowerOfTwo(int n) {
		return (n >= 1) ? (numOfBinOne(n) == 1) : false;
	}

	bool isPowerOfTwoOA(int n) {
		if ( n < 1)
			return false;
		return (n & n - 1) == 0;
	}
private:
	size_t numOfBinOne(int n) {
		size_t ret = 0;
		while (n) {
			n = n & (n - 1);
			ret++;
		}
		return ret;
	}
};