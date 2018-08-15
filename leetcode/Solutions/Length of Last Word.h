#pragma once

#include "common.h"

class Solution_LengthOfLastWord {
public:
	// 100% 劣于OA，此解法完全以空格作为单词标志，而像字符串“Hello world!”的最后一个单词被认为长度为6
	int lengthOfLastWord(string s) {
		int ret = 0;
		bool beginFlag = false;
		for (auto itor = s.rbegin(); itor != s.rend(); itor++) {
			if ( !beginFlag && (*itor != ' ')) {		// isalpha(*itor)
				beginFlag = true;
			}
			if (beginFlag && (*itor == ' ')) {
				break;
			}
			if (beginFlag) {
				++ret;
			}
		}
		return ret;
	}

	// 100%
	int lengthOfLastWordOA(const string& s) {
		auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
		auto last = find_if_not(first, s.rend(), ::isalpha);
		return distance(first, last);
	}
};
