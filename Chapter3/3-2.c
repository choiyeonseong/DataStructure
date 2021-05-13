#include<stdio.h>

int main()
{
	int i, n = 0;
	int sale[2][4] = { {63, 84, 140, 130},
					   {157, 209, 251, 312} };

	// 1. 2차원 배열의 시작주소를 포인터에 저장
	int* ptr = &sale[0][0]; 

	// 2. 배열 포인터에 배열의 시작주소를 저장
	int (* pptr)[4] = sale;	

	//sale == &sale[0][0] == 배열의 시작주소

	for (i = 0; i < 8; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr);
		ptr++;
	}

	// 209 출력
	printf("\n%d", *(ptr-3));
	printf("\n%d", sale[1][1]);
	printf("\n%d",*(*(pptr+1)+1));

	// ptr 포인터의 주소
	printf("\n%d", ptr);	// ptr = sale[2][4]
	printf("\n%d", ptr+1);	// 4byte증가

	// pptr 배열 포인터의 주소
	printf("\n%d", *pptr);		// pptr = (sale[2])[4]
	printf("\n%d", *(pptr+1));	// 16byte증가

	getchar();
}