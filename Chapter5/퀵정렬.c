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
	int ary[] = { 3,5,2,4,7,6,1,8 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);

	return 0;
}

void quickSort(int* pary, int left, int right)
{
	int pivot = (left + right) / 2;	// n/2�� �Ǻ��� �����Ѵ�. 
	int lidx = left;				// ���ʺ��� �Ⱦ�� = 0
	int ridx = right;				// �����ʺ��� �Ⱦ�� = size-1

	while (lidx <= ridx)	// lleft�� lright�� ��ü�Ǳ� �� ���� ����
	{
		while (pary[lidx] < pary[pivot]) lidx++;	// �Ǻ��� ���� ����Ʈ �� ���� ���� ���
		while (pary[ridx] > pary[pivot]) ridx--;	// �Ǻ��� ������ ����Ʈ �� ū ���� ���

		if (lidx <= ridx)	// ������ ������ �Ǹ�(lidx == ridx �̸� pivot���̴�.)
		{
			swap(&pary[ridx], &pary[lidx]);	// ã�� ����Ʈ�� �� ���� ��ȯ�Ͽ� �����Ѵ�.
			lidx++;
			ridx--;
		}
	}
	// �ܰ躰�� ���
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
	printf("\n0�ܰ� : ");

	for (int i = 0; i < sz; i++)
	{
		printf("%d	", pary[i]);
	}
}
