#pragma once

#include "common.h"
class Solution_TwoSum {
public:
	// 遍历2次
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		vector<int> res;
		auto idx = nums.size();
		for (idx = 0; idx < nums.size(); idx++) {
			map[nums[idx]] = idx;
		}

		for (idx = 0; idx < nums.size(); idx++) {
			const int anotherNum = target - nums[idx];
			if ((map.find(anotherNum) != map.end())
				&& (idx != map[anotherNum])) {			//增加条件，每个元素只允许使用一次，即下标不能相同
				res.push_back(idx);
				res.push_back(map[anotherNum]);
				break;
			}
		}
		return res;
	}

	// 遍历1次
	vector<int> twoSumLoopOneTime(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		vector<int> res;
		auto idx = nums.size();
		for (idx = 0; idx < nums.size(); idx++) {
			const int anotherNum = target - nums[idx];
			if ((map.find(anotherNum) != map.end())
				&& (idx != map[anotherNum])	//增加条件，每个元素只允许使用一次，即下标不能相同
			){
				res.push_back(idx);
				res.push_back(map[anotherNum]);
				break;
			}
			map[nums[idx]] = idx;			//将添加数据放在后方，避免出现相同value时覆盖key，从而输出空
		}
		return res;
	}
};

/*
Solution_TwoSum s;
vector<int> inputData = { 3,3 };
int target = 6;
vector<int> res = s.twoSumLoopOneTime(inputData, target);
//vector<int> res = s.twoSum(inputData, target);
for each (auto var in res) {
	cout << var << " ";
}
return 0;
*/