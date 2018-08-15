#pragma once

#include "common.h"
class Solution_TwoSum {
public:
	// ����2��
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
				&& (idx != map[anotherNum])) {			//����������ÿ��Ԫ��ֻ����ʹ��һ�Σ����±겻����ͬ
				res.push_back(idx);
				res.push_back(map[anotherNum]);
				break;
			}
		}
		return res;
	}

	// ����1��
	vector<int> twoSumLoopOneTime(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		vector<int> res;
		auto idx = nums.size();
		for (idx = 0; idx < nums.size(); idx++) {
			const int anotherNum = target - nums[idx];
			if ((map.find(anotherNum) != map.end())
				&& (idx != map[anotherNum])	//����������ÿ��Ԫ��ֻ����ʹ��һ�Σ����±겻����ͬ
			){
				res.push_back(idx);
				res.push_back(map[anotherNum]);
				break;
			}
			map[nums[idx]] = idx;			//��������ݷ��ں󷽣����������ͬvalueʱ����key���Ӷ������
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