#pragma once

#include "common.h"


class Solution_RemoveElement {
public:
	int removeElement(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());
		nums.erase( 
			lower_bound(nums.begin(), nums.end(), val), 
			upper_bound(nums.begin(), nums.end(), val)
		);
		return nums.size();
	}

	int removeElementOA1(vector<int>& nums, int val) {
		int index = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != val) {
				nums[index++] = nums[i];
			}
		}
		return index;
	}

	int removeElementOA2(vector<int>& nums, int val) {
		// remove����ɾ�� [arg1, arg2)��������arg3��ֵ��ȵ�Ԫ�أ��������µġ���β��������
		return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
	}
};