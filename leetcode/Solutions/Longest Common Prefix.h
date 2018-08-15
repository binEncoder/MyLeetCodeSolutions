#pragma once

#include "common.h"

class Solution_LongestCommonPrefix {
public:
	string longestCommonPrefix(vector<string>& strs) {
		size_t itemNum = strs.size();
		if (!itemNum) {
			return "";
		}
		int maxCommonLen = 0;
		bool isCommon = true;
		auto idx = strs[0].length();
		while (idx) {
			for (size_t i = 1; i < itemNum; i++) {
				if (strs[i][maxCommonLen] != strs[0][maxCommonLen]) {
					isCommon = false;
				}
			}
			if (!isCommon) {
				break;
			}
			else {
				maxCommonLen++;
			}
			idx--;
		}
		return strs[0].substr(0,maxCommonLen);
	}

	string longestCommonPrefixOA(vector<string> &strs) {
		if (strs.empty()) return "";
		for (size_t idx = 0; idx < strs[0].size(); ++idx) { 
			for (size_t i = 1; i < strs.size(); ++i) {
				if (strs[i][idx] != strs[0][idx]) return strs[0].substr(0, idx);
			}
		}
		return strs[0];
	}
};