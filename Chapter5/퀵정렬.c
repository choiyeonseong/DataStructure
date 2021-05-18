/*
* 어려워용 이해 못했음 - 근데 써먹을일은 없대

	퀵정렬 : 대표적인 분할 정복 알고리즘
			 정렬이 되어있지 않은 구조에서 사용하면 빠르다.

	1. 원소들 중에서 pivot(기준)을 고른다.
	2. 이 pivot을 기준으로 앞에는 작은값, 뒤에는 큰값을 위치시킨다.(분할)
	3. 분할된 작은 리스트를 재귀적으로 동작시킨다.(정복)
	4. 정렬된 작은 리스트들을 결합한다.(결합)
*/

#include<stdio.h>

void quickSort(int*, int, int);
void swap(int* a, int* b);
void printArray(int* pary, int sz);

int main()
{
	int ary[] = { 3,5,2,4,7,6,1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size-1);

	return 0;
}

void quickSort(int* pary, int left, int right)
{
	if (left >= right) return;	// 기저조건
	int pivot = left;
	int lleft = pivot + 1;	// 왼쪽부터 훑어옴
	int lright = right;		// 오른쪽부터 훑어옴

	while (lleft <= lright)	// lleft와 lright가 교체가 안될때 까지 수행
	{
		while (pary[lleft] <= pary[pivot]) lleft++;		// 왼쪽 부터 순서가 맞으면 그냥 다음으로 넘어감
		while (pary[lright] >= pary[pivot] && lright>left) lright--;	// 오른쪽 부터 순서가 맞으면 그냥 앞으로 넘어옴, 배열 크기를 벗어나지 않는 조건이 필요

		if (lleft > lright)
		{
			swap(&pary[lright], &pary[pivot]);
		}
		else
		{
			swap(&pary[lright], &pary[lleft]);
		}
	}
	// 단계별로 출력
	for (int k = 0; k < right+1; k++) {
		printf("%d	", pary[k]);
	}
	printf("\n");

	quickSort(pary, left, lright - 1);
	quickSort(pary, lright + 1, right);
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printArray(int* pary, int sz)
{
	printf("\n0단계 : ");

	for (int i = 0; i < sz; i++)
	{
		printf("%d	", pary[i]);
	}
}
