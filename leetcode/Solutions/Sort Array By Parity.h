#pragma once

#include "common.h"
bool compareFunction(int a, int b) {
	if (a % 2 == 0 && b % 2 != 0) {
		return true;
	}
	else if (a % 2 != 0 && b % 2 == 0) {
		return false;
	}
	else {
		return a >= b ? true : false;
	}
}
class Solution_SortArrayByParity {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		sort(A.begin(), A.end(), compareFunction);
		return A;
	}
};