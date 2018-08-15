#pragma once

#include "common.h"

class Solution_PlusOne {
public:
	// 9.23%
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;			// ½øÎ»
		for (auto itor = digits.rbegin(); itor != digits.rend(); itor++) {
			*itor += carry;
			if (*itor == 10) {
				*itor -= 10;
				carry = 1;
			}
			else {
				carry = 0;
				break;			// 100%
			}
		}
		if (carry) {
			digits.insert(digits.begin(), carry);
		}
		return digits;
	}
};