/*
	삽입 정렬 : 두번재 자료부터 앞 자료(뒤에서 앞으로)를 비교하여 정렬한다.
	insertionSort
*/
#include<stdio.h>

void insertionSort(int* pary, int sz);
void swap(int* a, int* b);
void printArray(int* pary, int sz);

int main()
{
	int ary[] = { 4,2,7,5,9,1,8,3,6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	
	printArray(ary, size);

	insertionSort(ary, size);
	
	return 0;
}

// 삽입 정렬
void insertionSort(int* pary, int sz)
{
	int i, j, tmp;
	for (i = 1; i < sz; i++) {	// 전체 배열의 개수만큼 실행
		for (j = i; j > 0; j--) {	// 부분 정렬의 맨 뒤부터 비교하기 시작
			if (pary[j] < pary[j - 1])
			{
				swap(&pary[j], &pary[j - 1]);
			}
		}

		// 단계별로 출력
		printf("\n%d단계 : ", i);
		for (int k = 0; k < sz; k++) {
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