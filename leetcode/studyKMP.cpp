#include "common.h"

/* 暴力算法 */
#define				NORMAL_FUNC					CONFIG_DISABLE				

/* KMP算法，当 子串相似度较高时 较"暴力算法"有明显性能提升 */
#define				KMP_FUNC					CONFIG_ENABLE				

/* 改进的KMP算法，目前发现的最佳模式匹配算法 */
#define				BETTER_KMP_FUNC				CONFIG_DISABLE

#if( NORMAL_FUNC + KMP_FUNC + BETTER_KMP_FUNC > CONFIG_ENABLE)
	#error "config macro error"
#endif

#if( NORMAL_FUNC == CONFIG_ENABLE )
/* 朴素模式匹配 */
int strStr(const char *src, const char *pattern) {
	if (!pattern || !strlen(pattern)) {
		return 0;
	}
	const int srcLen = strlen(src);
	const int patternLen = strlen(pattern);
	int i = 0, j = 0;
	while ((i < srcLen) && (j < patternLen)) {
		if (*(src + i) == *(pattern + j)) {			/* 相等则继续比较 */
			i++;	j++;
		}
		else {
			printf(" i = %d\t j = %d\n", i, j);
			i = i - j + 1;		/* 不等后主串从上一次开始位置+1的位置进行比较 */
								/* i = i - j 相当于回到本次比较的起始位置， 
								 * i = i - j + 1 自然是往右移动1个元素 
								 */
			j = 0;				/* 不等后“模式串”从头开始比较 */
		}
	}

	/* 此条件满足，表明已比较完所有pattern的元素，均与src串相等 */
	return (j == patternLen) ? (i - j) : (-1);
}
#endif

#if ( KMP_FUNC == CONFIG_ENABLE )
/*
 * next[j]的值( k )表示：当 子串[j] != 主串[i]时，j指针下一次的移动位置
 */
int* getNextArray(const char *pattern) {
	int len = strlen(pattern);
	int *next = (int *)malloc(sizeof(int)*len);
	int j = 0, k = -1;
	next[0] = -1;
	while (j < (len - 1)) {
		printf("j = %d\tk = %d\t", j, k);
		if ((k == -1) || (pattern[j] == pattern[k])) {
			++j;		++k;
			next[j] = k;
		}
		else {
			printf("\tk = %d\t",k);
			k = next[k];		/* 若两元素不等，则k回溯，
								 * 直到 p[j] == p[k] 或 k为-1 
								 */
		}
		printf("\n");
	}

	for (int i = 0; i < len; i++) { printf("%d ",next[i]); }
	printf("\n\n");

	return next;
}
#endif

#if ( BETTER_KMP_FUNC == CONFIG_ENABLE )
/*
* next[j]的值( k )表示：当 子串[j] != 主串[i]时，j指针下一次的移动位置
*/
int* getNextArray(const char *pattern) {
	int len = strlen(pattern);
	int *next = (int *)malloc(sizeof(int)*len);
	int j = 0, k = -1;
	next[0] = -1;
	while (j < (len - 1)) {
		printf("j = %d\tk = %d\t", j, k);
		if ((k == -1) || (pattern[j] == pattern[k])) {
			++j;		++k;

			if (pattern[j] == pattern[k]) {
				next[j] = next[k];
			}
			else {
				next[j] = k;
			}
			
		}
		else {
			printf("\tk = %d\t", k);
			k = next[k];		/* 若两元素不等，则k回溯，
								* 直到 p[j] == p[k] 或 k为-1
								*/
		}
		printf("\n");
	}

	for (int i = 0; i < len; i++) { printf("%d ", next[i]); }
	printf("\n\n");

	return next;
}
#endif

#if ( KMP_FUNC == CONFIG_ENABLE || BETTER_KMP_FUNC == CONFIG_ENABLE )
int strStr(const char *src, const char *pattern) {
	if (!pattern || !strlen(pattern)) {
		return 0;
	}
	const int srcLen = strlen(src);
	const int patternLen = strlen(pattern);
	int i = 0, j = 0;

	int *next = getNextArray(pattern);

	while ((i < srcLen) && (j < patternLen)) {
		if ((*(src + i) == *(pattern + j))
			|| (j == -1)) {		/* j == -1 表示模式串与主串在当前位置就不匹配，
								* 这个算法应该只有next[0]可能为-1，
								* 表达的意思是：i从下一个位置开始，j从0开始
								*/
			i++;	j++;
		}
		else {
			printf(" i = %d\t j = %d\n", i, j);
			j = next[j];
		}
	}
	free(next);
	printf("\n");
	/* 此条件满足，表明已比较完所有pattern的元素，均与src串相等 */
	return (j == patternLen) ? (i - j) : (-1);
}
#endif