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
	int ary[] = { 3,5,2,4,7,6,1,8 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);

	return 0;
}

void quickSort(int* pary, int left, int right)
{
	int pivot = (left + right) / 2;	// n/2를 피봇을 설정한다. 
	int lidx = left;				// 왼쪽부터 훑어옴 = 0
	int ridx = right;				// 오른쪽부터 훑어옴 = size-1

	while (lidx <= ridx)	// lleft와 lright가 교체되기 전 까지 수행
	{
		while (pary[lidx] < pary[pivot]) lidx++;	// 피봇의 왼쪽 리스트 중 작은 값은 통과
		while (pary[ridx] > pary[pivot]) ridx--;	// 피봇의 오른쪽 리스트 중 큰 값은 통과

		if (lidx <= ridx)	// 정렬할 조건이 되면(lidx == ridx 이면 pivot값이다.)
		{
			swap(&pary[ridx], &pary[lidx]);	// 찾은 리스트의 두 값을 교환하여 정렬한다.
			lidx++;
			ridx--;
		}
	}
	// 단계별로 출력
	for (int k = 0; k < right + 1; k++) {
		printf("%d	", pary[k]);
	}
	printf("\n");

	if (left < ridx)quickSort(pary, left, ridx);	// a
	if (lidx < right)quickSort(pary, lidx, right);	// b
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
