#pragma once

#include "common.h"

class Solution_ContainsDuplicateII {
public:
	// best beat 5.63%
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int size = (int)nums.size();
		while (k) {
			for (int i = 0; i < size - k; i++) {
				if (nums[i] == nums[i + k]) {
					return true;
				}
			}
			--k;
		}
		return false;
	}

	bool containsNearbyDuplicateOA(vector<int>& nums, int k) {
		set<int> cand;
		for (int i = 0; i < nums.size(); i++) {
			if (i > k) cand.erase(nums[i - k - 1]);
			if (!cand.insert(nums[i]).second) return true;
		}
		return false;
	}

	bool containsNearbyDuplicateOA2(vector<int>& nums, int k) {
		unordered_map<int, int> hashMap;
		for (int i = 0; i < nums.size(); ++i) {
			if (hashMap.find(nums[i]) != hashMap.end() && i - hashMap[nums[i]] <= k)  return true;
			hashMap[nums[i]] = i;
		}
		return false;
	}
};