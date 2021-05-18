/*
	���� ���� : 0������ �ּҰ��̶�� �����ϰ�
				������ ���ҵ�� ���ؼ� �� �������� ��ȯ
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

// ���� ����
void selectionSort(int* pary, int size)
{
	int min, i, j;

	for (i = 0; i < size; i++)
	{
		min = i;	// ù��°�� ���� ���� ���ҷ� �ΰ�
		for (j = i +1; j < size; j++)
		{
			if (pary[min] > pary[j])
			{
				min = j;	// ù��° ���� �� �� �ּҰ��� ã�Ƽ�
			}
		}
		swap(&pary[min], &pary[i]);	// ù��° ���� �ּҰ��� �ڸ��ٲ�

		// �ܰ躰�� ���
		printf("\n%d�ܰ� : ", i+1);
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
	printf("\n0�ܰ� : ");

	for (int i = 0; i < sz; i++)
	{
		printf("%d	", pary[i]);
	}
}
