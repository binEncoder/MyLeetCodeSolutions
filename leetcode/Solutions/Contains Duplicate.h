#pragma once

#include "common.h"

class Solution_ContainsDuplicate {
public:
	// best beat 73.49%
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> num_times;
		for (auto item : nums) {
			if (num_times.end() == num_times.find(item)) {
				num_times.insert({ item, 1 });
			}
			else {
				return true;
			}
		}
		return false;
	}

	// �鿴vector��Ԫ�������뽫vector����Ԫ�ط���set(Ԫ�ز��ظ�)�к�������Ĵ�С
	bool containsDuplicateOA(vector<int>& nums) {
		return nums.size() > set<int>(nums.begin(), nums.end()).size();
	}

	// ���򣬲�ѯ����Ԫ���Ƿ���ͬ
	bool containsDuplicateOA2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i<int(nums.size()) - 1; i++) {
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
	}
};