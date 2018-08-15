#pragma once

#include "common.h"

class Solution_LengthOfLastWord {
public:
	// 100% ����OA���˽ⷨ��ȫ�Կո���Ϊ���ʱ�־�������ַ�����Hello world!�������һ�����ʱ���Ϊ����Ϊ6
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
