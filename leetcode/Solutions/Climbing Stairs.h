#pragma once

#include "common.h"

class Solution_ClimbingStairs {
public:
	int climbStairs(int n) {
		if (n <= 2)
			return n;
		else if (n < 0)
			return 0;
		else {
			int f[2] = { 1,2 };
			for (int i = 2; i < n; i++) {
				int tmp = f[0] + f[1];
				f[0] = f[1];
				f[1] = tmp;
			}
			return f[1];
		}
	}
};