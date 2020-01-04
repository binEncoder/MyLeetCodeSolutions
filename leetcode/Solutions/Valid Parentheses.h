#pragma once

#include "common.h"

class Solution_ValidParentheses
{
public:
	bool isValid(string s) {
		string left = "([{";
		string right = ")]}";
		stack<char> chars;
		bool ret = false;
		for( auto var : s){
			// 表示在left字符串中找不到var字符
			if (left.find(var) != string::npos) {
				chars.push(var);
			}

			if (right.find(var) != string::npos) {
				
				if (chars.empty())	
					return false;

				auto popRet = chars.top();
				chars.pop();

				if (popRet == left[right.find(var)])	
					continue;
				else 
					return false;
			}
		}
		ret = chars.empty();
		return ret;
	}
};