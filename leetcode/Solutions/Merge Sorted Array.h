#pragma once

#include "common.h"

class Solution_MergeSortedArray {
public:
	// 98.80%
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		auto index = nums1.begin();
		int tmp = m;
		while (tmp) {
			index++;
			tmp--;
		}
		for (auto var : nums2) {
			index = nums1.insert(index, var);
		}
		nums1.resize(m + n);
		sort(nums1.begin(), nums1.end());
	}

	// 98.80%
	void mergeOA(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int ia = m - 1, ib = n - 1, icur = m + n - 1;
		while (ia >= 0 && ib >= 0) {
			nums1[icur--] = nums1[ia] >= nums2[ib] ? nums1[ia--] : nums2[ib--];
		}
		while (ib >= 0) {
			nums1[icur--] = nums2[ib--];
		}
	}
};