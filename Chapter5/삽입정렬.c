/*
	���� ���� : �ι��� �ڷ���� �� �ڷ�(�ڿ��� ������)�� ���Ͽ� �����Ѵ�.
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

// ���� ����
void insertionSort(int* pary, int sz)
{
	int i, j, tmp;
	for (i = 1; i < sz; i++) {	// ��ü �迭�� ������ŭ ����
		for (j = i; j > 0; j--) {	// �κ� ������ �� �ں��� ���ϱ� ����
			if (pary[j] < pary[j - 1])
			{
				swap(&pary[j], &pary[j - 1]);
			}
		}

		// �ܰ躰�� ���
		printf("\n%d�ܰ� : ", i);
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
	printf("\n0�ܰ� : ");

	for (int i = 0; i < sz; i++)
	{
		printf("%d	", pary[i]);
	}
}