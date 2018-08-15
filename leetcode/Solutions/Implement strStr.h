#pragma once

#include "common.h"

class Solution_ImplementFunc_strStr {
public:
	// 时间复杂度O(M*N)，M、N分别为输入参数的长度
	// 空间复杂度O(1)
	int strStr(string haystack, string needle) {
		int ret = -1;
		const size_t srcSize = haystack.size();
		const size_t destSize = needle.size();

		if ( (srcSize < destSize) ) {
			;
		}
		else if (needle.empty()) {
			return 0;
		}
		else {
			for (size_t idx = 0; idx < srcSize; idx++) {
				if ((haystack[idx] == needle[0]) && (srcSize - idx >= destSize)) {
					if (!haystack.compare(idx, destSize, needle)) {
						ret = idx;
						break;
					}
				}
			}
		}
		return ret;
	}

	// 类似的解法
	int strStrOA1(const string& haystack, const string& needle) {
		if (needle.empty()) return 0;
		const int N = haystack.size() - needle.size() + 1;
		for (int i = 0; i < N; i++) {
			int j = i;
			int k = 0;
			while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]) {
				j++;
				k++;
			}
			if (k == needle.size()) return i;
		}
		return -1;
	}

	// KMP算法，空间复杂度O(M)，时间复杂度O(M+N)
	int strStrOA2(const string& haystack, const string& needle) {
		return kmp(haystack.c_str(), needle.c_str());
	}
private:
	/*
	 * @brief 计算部分匹配表，即 next 数组.
	 * @param[in] pattern 模式串
	 * @param[out] next next数组
	 */
	static void compute_prefix(const char *pattern, int next[]) {
		int j = -1;
		const int patternLen = strlen(pattern);
		next[0] = j;
		for ( int i = 1; i < patternLen; i++) {
			while (j > -1 && pattern[j + 1] != pattern[i]) {
				j = next[j];
			} 
			if (pattern[i] == pattern[j + 1]) {
				j++;
			} 
			next[i] = j;
		}
	}

	/*
	 * @brief KMP 算法.
	 * @param[in] pattern 模式串
	 * @return 成功则返回第一次匹配的位置，失败则返回-1
	 */
	static int kmp(const char *text, const char *pattern) {
		int j = -1, ret = -1;
		const int textLen = strlen(text);
		const int patternLen = strlen(pattern);
		
		if (textLen == 0 && patternLen == 0) {
			return 0;
		}
		if (patternLen == 0) return 0;		// 冗余判断

		int *next = (int*)malloc(sizeof(int) * patternLen);
		
		compute_prefix(pattern, next);
		
		for (int i = 0; i < textLen; i++) {
			while (j > -1 && pattern[j + 1] != text[i]){
				j = next[j];
			}
			if (text[i] == pattern[j + 1]) {
				j++;
			} 
			if (j == patternLen - 1) {
				ret = i - j;
				break;
			}
		}
		free(next);
		return ret;
	}
};