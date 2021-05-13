#include<stdio.h>

int main()
{
	int i, n = 0, * ptr;
	// 순차 자료구조 : 메모리에 연속적으로 저장, 주소 순서대로 구성
	int sale[2][2][4] = 
	{
		{
			{63,84,140,130},
			{157,209,251,312}
		},
		{
			{59,80,130,135},
			{149,187,239,310}
		}
	};
	ptr = &sale[0][0][0];	// 3차원 배열의 시작주소를 포인터에 저장
	for (i = 0; i < 16; i++)
	{
		printf("\n address : %u sale %2d = %3d", ptr, i, *ptr);
		ptr++;
	}
	getchar();
}