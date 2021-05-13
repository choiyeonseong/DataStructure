#include<stdio.h>

void hanoi(int n, int start, int work, int target);
int count = 0;
int  main()
{
	hanoi(3, 'A', 'B', 'C');

	printf("%d", count);
	getchar();
}

void hanoi(int n, int start, int work, int target)	// ���ۺ�, �۾���, ������
{
	count++;
	if (n == 1)
	{
		printf(" %c���� ���� %d�� %c�� �ű� \n", start, n, target);
	}
	else
	{
		hanoi(n - 1, start, target, work);	// ���ۺ��� �ִ� ������ �������� �̿��� �۾������� �ű��
		printf(" %c���� ���� %d�� %c�� �ű� \n", start, n, target);
		hanoi(n - 1, work, start, target);
	}
}
