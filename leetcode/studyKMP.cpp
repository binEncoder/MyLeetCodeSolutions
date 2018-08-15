
#include "common.h"

/* �����㷨 */
#define				NORMAL_FUNC					DISABLE				

/* KMP�㷨���� �Ӵ����ƶȽϸ�ʱ ��"�����㷨"�������������� */
#define				KMP_FUNC					ENABLE				

/* �Ľ���KMP�㷨��Ŀǰ���ֵ����ģʽƥ���㷨 */
#define				BETTER_KMP_FUNC				DISABLE

#if( NORMAL_FUNC + KMP_FUNC + BETTER_KMP_FUNC > ENABLE)
	#error "config macro error"
#endif

#if( NORMAL_FUNC == ENABLE )
/* ����ģʽƥ�� */
int strStr(const char *src, const char *pattern) {
	if (!pattern || !strlen(pattern)) {
		return 0;
	}
	const int srcLen = strlen(src);
	const int patternLen = strlen(pattern);
	int i = 0, j = 0;
	while ((i < srcLen) && (j < patternLen)) {
		if (*(src + i) == *(pattern + j)) {			/* ���������Ƚ� */
			i++;	j++;
		}
		else {
			printf(" i = %d\t j = %d\n", i, j);
			i = i - j + 1;		/* ���Ⱥ���������һ�ο�ʼλ��+1��λ�ý��бȽ� */
								/* i = i - j �൱�ڻص����αȽϵ���ʼλ�ã� 
								 * i = i - j + 1 ��Ȼ�������ƶ�1��Ԫ�� 
								 */
			j = 0;				/* ���Ⱥ�ģʽ������ͷ��ʼ�Ƚ� */
		}
	}

	/* ���������㣬�����ѱȽ�������pattern��Ԫ�أ�����src����� */
	return (j == patternLen) ? (i - j) : (-1);
}
#endif

#if ( KMP_FUNC == ENABLE )
/*
 * next[j]��ֵ( k )��ʾ���� �Ӵ�[j] != ����[i]ʱ��jָ����һ�ε��ƶ�λ��
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
			k = next[k];		/* ����Ԫ�ز��ȣ���k���ݣ�
								 * ֱ�� p[j] == p[k] �� kΪ-1 
								 */
		}
		printf("\n");
	}

	for (int i = 0; i < len; i++) { printf("%d ",next[i]); }
	printf("\n\n");

	return next;
}
#endif

#if ( BETTER_KMP_FUNC == ENABLE )
/*
* next[j]��ֵ( k )��ʾ���� �Ӵ�[j] != ����[i]ʱ��jָ����һ�ε��ƶ�λ��
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
			k = next[k];		/* ����Ԫ�ز��ȣ���k���ݣ�
								* ֱ�� p[j] == p[k] �� kΪ-1
								*/
		}
		printf("\n");
	}

	for (int i = 0; i < len; i++) { printf("%d ", next[i]); }
	printf("\n\n");

	return next;
}
#endif

#if ( KMP_FUNC == ENABLE || BETTER_KMP_FUNC == ENABLE )
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
			|| (j == -1)) {		/* j == -1 ��ʾģʽ���������ڵ�ǰλ�þͲ�ƥ�䣬
								* ����㷨Ӧ��ֻ��next[0]����Ϊ-1��
								* ������˼�ǣ�i����һ��λ�ÿ�ʼ��j��0��ʼ
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
	/* ���������㣬�����ѱȽ�������pattern��Ԫ�أ�����src����� */
	return (j == patternLen) ? (i - j) : (-1);
}
#endif