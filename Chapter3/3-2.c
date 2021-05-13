#include<stdio.h>

int main()
{
	int i, n = 0;
	int sale[2][4] = { {63, 84, 140, 130},
					   {157, 209, 251, 312} };

	// 1. 2���� �迭�� �����ּҸ� �����Ϳ� ����
	int* ptr = &sale[0][0]; 

	// 2. �迭 �����Ϳ� �迭�� �����ּҸ� ����
	int (* pptr)[4] = sale;	

	//sale == &sale[0][0] == �迭�� �����ּ�

	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr);
		ptr++;
	}

	// 209 ���
	printf("\n%d", *(ptr-3));
	printf("\n%d", sale[1][1]);
	printf("\n%d",*(*(pptr+1)+1));

	// ptr �������� �ּ�
	printf("\n%d", ptr);	// ptr = sale[2][4]
	printf("\n%d", ptr+1);	// 4byte����

	// pptr �迭 �������� �ּ�
	printf("\n%d", *pptr);		// pptr = (sale[2])[4]
	printf("\n%d", *(pptr+1));	// 16byte����

	getchar();
}