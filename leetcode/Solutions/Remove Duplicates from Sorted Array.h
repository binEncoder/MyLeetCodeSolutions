#pragma once

#include "common.h"

class Solution_RemoveDuplicatesFromSortedArray {
public:
	int removeDuplicates(vector<int>& nums) {
		int ret = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			// ���� || �߼�����Ķ�·���ԣ����⵱retΪ0ʱ�жϺ�һ����
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
		// distance�����������������ľ���, [)����

		// unique����ɾ����������Χ��������ظ�( �����������򣬽��ظ�Ԫ���������������� )Ԫ�أ�
		// ������ȥ�غ���ҿ����������
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}


	int removeDuplicatesOA3(vector<int>& nums) {
		return distance(nums.begin(), removeDuplicates(nums.begin(), nums.end(), nums.begin()));
	}

	template<typename InIt, typename OutIt>		// �о������OutIt�е�����
	OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
		while (first != last) {
			*output++ = *first;

			/* upper_bound( arg1, arg2, arg3 ) */
			/* upper_bound ������arg1��arg2����ɵ�
			���ұյ���������( [arg1, arg2) )���׸�����arg3��Ԫ�ض�Ӧ�ĵ�����λ�� */
			first = upper_bound(first, last, *first);
		}
		return output;
	}
};