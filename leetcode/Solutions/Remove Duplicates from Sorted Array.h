#pragma once

#include "common.h"

class Solution_RemoveDuplicatesFromSortedArray {
public:
	int removeDuplicates(vector<int>& nums) {
		int ret = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			// 利用 || 逻辑运算的短路特性，避免当ret为0时判断后一条件
			if ((ret == 0) || (nums[ret - 1 ] != nums[i]) ) {
				nums[ret++] = nums[i];
			}
		}
		return ret;
	}

	int removeDuplicatesOA1(vector<int>& nums) {
		if (nums.empty()) return 0;
		int index = 0;
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums[index] != nums[i])
				nums[++index] = nums[i];
		}
		return index + 1;
	}

	int removeDuplicatesOA2(vector<int>& nums) {
		// distance函数计算两迭代器的距离, [)区间

		// unique函数删除迭代器范围间的连续重复( 可先令其有序，将重复元素连续以满足条件 )元素，
		// 并返回去重后的右开区间迭代器
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}


	int removeDuplicatesOA3(vector<int>& nums) {
		return distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()));
	}

	template<typename InIt, typename OutIt>		// 感觉这里的OutIt有点冗余
	OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
		while (first != last) {
			*output++ = *first;

			/* upper_bound( arg1, arg2, arg3 ) */
			/* upper_bound 返回由arg1、arg2所组成的
			左开右闭迭代器区间( [arg1, arg2) )内首个大于arg3的元素对应的迭代器位置 */
			first = upper_bound(first, last, *first);
		}
		return output;
	}
};