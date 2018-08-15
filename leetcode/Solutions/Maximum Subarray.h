#pragma once

#include "common.h"

class Solution_MaximumSubarray {
public:
	// 41%
	int maxSubArray(vector<int>& nums) {
		int ret = INT_MIN, f = 0;
		for (auto num : nums) {
			f = max(f + num, num);
			ret = max(f, ret);
		}
		return ret;
	}

	// 100% 《数据结构与算法分析》 P21
	int maxSubArray(vector<int>& nums) {
		int ans = INT_MIN, cur = 0;
		size_t i = 0, length = nums.size();
		while (i < length) {
			cur += nums[i];
			ans = max(cur, ans);
			if (cur < 0)
				cur = 0;
			i++;
		}
		return ans;
	}
};

// 牛客网：最大子矩阵
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define  MAX(a,b)  (a)>(b)?(a):(b)
#define ROR(x,n,type) (x)>>(n) | (x)<<(sizeof(type)*8 - n)

int maxSubVector(int *arr, int length) {
	int ans = ROR(1, 1, int);
	int cur = 0;
	int i = 0;
	while (i < length) {
		cur += arr[i];
		ans = MAX(cur, ans);
		if (cur < 0)
			cur = 0;
		i++;
	}
	return ans;
}

static void copyVector(int *dest, int *src, int n) {
	assert(dest);
	assert(src);
	assert(n >= 0);
	int i;
	for (i = 0; i < n; i++)
		dest[i] = src[i];
}

static void addVector(int *arr_a, int *arr_b, int n) {
	assert(arr_a);
	assert(arr_b);
	assert(n >= 0);
	int i;
	for (i = 0; i < n; i++)
		arr_a[i] += arr_b[i];
}

// O(row*row*col)
int maxSubMatrix(int *matrix, int row, int col) {
	int *help = (int *)malloc(sizeof(int)*col);
	assert(help);
	int i, j, ans = ROR(1, 1, int);
	for (i = 0; i < row; i++) {
		copyVector(help, matrix + i * col, col);
		int tmp = maxSubVector(help, col);
		ans = MAX(ans, tmp);
		for (j = i + 1; j < col; j++) {
			addVector(help, matrix + j * col, col);
			int tmp = maxSubVector(help, col);
			ans = MAX(ans, tmp);
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		assert(n > 0);
		int *matrix = (int *)malloc(sizeof(int)*n*n);
		assert(matrix);
		int i, j;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf(" %d", matrix + i * n + j);
		printf("%d\n", maxSubMatrix(matrix, n, n));
		free(matrix);
		matrix = NULL;
	}
	return 0;
}
#endif