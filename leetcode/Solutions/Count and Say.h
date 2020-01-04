#pragma once

#include "common.h"

/*	1.     1				起始
 *	2.     11				1个1						11
 *	3.     21				2个1						21
 *	4.     1211				1个2，1个1				1211
 *	5.     111221			1个1，1个2，2个1			111221
 * 
 */

class Solution_CountAndSay{
public:

	// 较优做法
	string countAndSay(int n) {
		if (n <= 0) return "";
		string res = "1";
		while (--n) {
			string cur = "";
			for (int i = 0; i < res.size(); ++i) {
				int cnt = 1;
				while (i + 1 < res.size() && res[i] == res[i + 1]) {
					++cnt;
					++i;
				}
				cur += to_string(cnt) + res[i];
			}
			res = cur;
		}
		return res;
	}

	string countAndSayOA(int n) {
		string s("1");
		while (--n)
			s = getNext(s);
		return s;
	}

	string getNext(const string &s) {
		stringstream ss;
		for (auto i = s.begin(); i != s.end(); ) {
			auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
			ss << distance(i, j) << *i;
			i = j;
		}
		return ss.str();
	}
};
