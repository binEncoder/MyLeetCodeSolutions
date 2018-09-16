#pragma once

#include "common.h"
class Solution_CountPrimes {
public:
	int countPrimes(int n) {
		if (n <= 2)	return 0;
		vector<bool> isPrime(n, false);
		int ret = 0;
		for (int i = 2; i < n; i++) {
			if (isPrime[i] == false) {
				++ret;
				for (int j = i; j*i < n; j++) {
					isPrime[i*j] = true;
				}
			}
		}
		return ret;
	}

	int countPrimesOA(int n) {
		if (n <= 2) return 0;
		vector<bool> passed(n, false);
		int sum = 1;
		int upper = sqrt(n);
		for (int i = 3; i<n; i += 2) {
			if (!passed[i]) {
				sum++;
				//avoid overflow
				if (i > upper) continue;
				for (int j = i*i; j < n; j += i) {
					passed[j] = true;
				}
			}
		}
		return sum;
	}
};
