/*
	선택 정렬 : 0번방을 최소값이라고 가정하고
				나머지 원소들과 비교해서 더 작은값과 교환
*/

#include<stdio.h>

void selectionSort(int* pary, int size);
void swap(int* a, int* b);
void printArray(int* pary, int sz);

int main()
{
	int ary[] = { 4,2,7,5,9,1,8,3,6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	
	printArray(ary,size);

	selectionSort(ary, size);

	return 0;
}

// 선택 정렬
void selectionSort(int* pary, int size)
{
	int min, i, j;

	for (i = 0; i < size; i++)
	{
		min = i;	// 첫번째를 가장 작은 원소로 두고
		for (j = i +1; j < size; j++)
		{
			if (pary[min] > pary[j])
			{
				min = j;	// 첫번째 이후 값 중 최소값을 찾아서
			}
		}
		swap(&pary[min], &pary[i]);	// 첫번째 값과 최소값을 자리바꿈

		// 단계별로 출력
		printf("\n%d단계 : ", i+1);
		for (int k = 0; k < size; k++) {
			printf("%d	", pary[k]);
		}
	}
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
