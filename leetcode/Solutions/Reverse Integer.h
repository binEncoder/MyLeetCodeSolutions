#pragma once
#include "common.h"

#include <cstdint>			// for INT32_MAX ...
#include <climits>			// for INT_MAX ...

class Solution_ReverseInteger {
public:
	int reverse(int x) {
		int r = 0;
		for (; x; x /= 10) {
			if( (x > 0) && (r > INT32_MAX / 10) ){
				r = 0;
				break;
			}
			if ((x < 0) && (r < INT32_MIN / 10)) {
				r = 0;
				break;
			}
			r = r * 10 + x % 10;
		}
		return r;
	}

	// OA means Official Answer
	int reverseOA(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;

			// 处理溢出数据情况
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			
			rev = rev * 10 + pop;
		}
		return rev;
	}
};