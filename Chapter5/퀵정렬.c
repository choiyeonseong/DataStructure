/*
* ������� ���� ������ - �ٵ� ��������� ����

	������ : ��ǥ���� ���� ���� �˰���
			 ������ �Ǿ����� ���� �������� ����ϸ� ������.

	1. ���ҵ� �߿��� pivot(����)�� ����.
	2. �� pivot�� �������� �տ��� ������, �ڿ��� ū���� ��ġ��Ų��.(����)
	3. ���ҵ� ���� ����Ʈ�� ��������� ���۽�Ų��.(����)
	4. ���ĵ� ���� ����Ʈ���� �����Ѵ�.(����)
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
	if (left >= right) return;	// ��������
	int pivot = left;
	int lleft = pivot + 1;	// ���ʺ��� �Ⱦ��
	int lright = right;		// �����ʺ��� �Ⱦ��

	while (lleft <= lright)	// lleft�� lright�� ��ü�� �ȵɶ� ���� ����
	{
		while (pary[lleft] <= pary[pivot]) lleft++;		// ���� ���� ������ ������ �׳� �������� �Ѿ
		while (pary[lright] >= pary[pivot] && lright>left) lright--;	// ������ ���� ������ ������ �׳� ������ �Ѿ��, �迭 ũ�⸦ ����� �ʴ� ������ �ʿ�

		if (lleft > lright)
		{
			swap(&pary[lright], &pary[pivot]);
		}
		else
		{
			swap(&pary[lright], &pary[lleft]);
		}
	}
	// �ܰ躰�� ���
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
	printf("\n0�ܰ� : ");

	for (int i = 0; i < sz; i++)
	{
		printf("%d	", pary[i]);
	}
}
