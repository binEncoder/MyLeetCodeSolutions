#pragma once

#include "common.h"

class Solution_SqrtX {
public:
#if 0
	// 10.05%
	int mySqrt(int x) {
		int ret = 1;
		while (ret*ret <= x) {
			ret += 1;
			if (ret * ret < ret)
				break;
		}
		ret -= 1;
		return ret;
	}
#endif

	// 97.82%
	int mySqrt(int x) {
		int begin = 0, end = (x > 1) ? x/2: x, mind;
		for (; begin <= end; ) {
			mind = (begin + end) / 2;

			if ( (mind > 0) && (x / mind < mind) ) {
				end = mind - 1;
				continue;
			}
			else {
				begin = mind + 1;
			}
		}
		return begin - 1;
	}

	// 97.82%
	int mySqrtOA(int x) {
		int left = 1, right = x / 2;
		int last_mid;
		if (x < 2) return x;
		while (left <= right) {
			const int mid = left + (right - left) / 2;
			if (x / mid > mid) {
				left = mid + 1;
				last_mid = mid;
			}
			else if (x / mid < mid) {
				right = mid - 1;
			}
			else {
				return mid;
			}
		}
		return last_mid;
	}
};