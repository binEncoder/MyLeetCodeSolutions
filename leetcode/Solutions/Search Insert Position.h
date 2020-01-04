#pragma once

#include "common.h"

class Solution_SearchInsertPosition {
public:

	// 时间复杂度 O(N)
	int searchInsert(vector<int>& nums, int target) {
		int ret = 0;
		for (auto item : nums) {
			if (item >= target)	break;
			ret++;
		}
		return ret;
	}

	// 二分查找，时间复杂度 O(logN)
	int searchInsertOA(vector<int>& nums, int target) {
		return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
	}
	/*
	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance(first, last) / 2);
			if (value > *mid) first = ++mid;
			else last = mid;
		}
		return first;
	}
	*/

};