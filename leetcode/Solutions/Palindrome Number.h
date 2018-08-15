#pragma once

#include "common.h"

class Solution_PalindromeNumber {
public:
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
	bool isPalindrome(int x) {
		bool ret = false;
		// 利用之前的回文数字得出结论
		if ((x >= 0) && (x == reverseOA(x))) {
			ret = true;
		}
		return ret;
	}

	bool isPalindromeOA(int x) {
		// Special cases:
		// As discussed above, when x < 0, x is not a palindrome.
		// Also if the last digit of the number is 0, in order to be a palindrome,
		// the first digit of the number also needs to be 0.
		// Only 0 satisfy this property.
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}

		int revertedNumber = 0;
		while (x > revertedNumber) {
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		// When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
		// For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
		// since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
		return x == revertedNumber || x == revertedNumber / 10;
	}
};