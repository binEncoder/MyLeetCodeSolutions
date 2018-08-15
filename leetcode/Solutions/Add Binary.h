#pragma once

#include "common.h"

class Solution_AddBinary {
public:
	// 100% 明显劣于OA( 不方便阅读 ) - 时间复杂度O(N)，空间复杂度O(1)
	string addBinary(string a, string b) {
		bool addToStrA = (a.size() >= b.size()) ? true : false;
		char carry = 0;
		auto ia = a.rbegin(), ib = b.rbegin();
		for (; ia != a.rend() && ib != b.rend(); ia++, ib++) {
			if (addToStrA) {
				*ia += *ib - '0' + carry;
				if (*ia >= '2') {
					*ia -= 2;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
			else {
				*ib += *ia - '0' + carry;
				if (*ib >= '2') {
					*ib -= 2;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
		}

		if (carry == 0) {
			return addToStrA ? a : b;
		}
		else {
			if (addToStrA) {
				while (ia != a.rend()) {
					*ia += + carry;
					if (*ia >= '2') {
						*ia -= 2;
						carry = 1;
					}
					else {
						carry = 0;
					}
					ia++;
				}
				if (carry) {
					a.insert(a.begin(), '1');
				}
				return a;
			}
			else {
				while (ib != b.rend()) {
					*ib += +carry;
					if (*ib >= '2') {
						*ib -= 2;
						carry = 1;
					}
					else {
						carry = 0;
					}
					ib++;
				}
				if (carry) {
					b.insert(b.begin(), '1');
				}
				return b;
			}
		}
	}

	// 100% 时间复杂度O(N)，空间复杂度O(N)
	string addBinaryOA(string a, string b) {
		string result;
		const size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0;
		for (size_t i = 0; i < n; i++) {
			const int ai = i < a.size() ? a[i] - '0' : 0;
			const int bi = i < b.size() ? b[i] - '0' : 0;
			const int val = (ai + bi + carry) % 2;
			carry = (ai + bi + carry) / 2;
			result.insert(result.begin(), val + '0');
		}
		if (carry == 1) {
			result.insert(result.begin(), '1');
		}
		return result;
	}
};