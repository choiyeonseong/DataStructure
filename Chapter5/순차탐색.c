/*
	순차 탐색 : 정렬되지 않은 배열
*/
#include<stdio.h>

int LSearch(int * pary, int sz, int tg)
{
	for (int i = 0; i < sz; i++)
	{
		if (pary[i] == tg)
		{
			//printf("%d 번째 값 : %d", i, pary[i]);
			return i;
		}
	}
	return -1;	
}

int main()
{
	int ary[] = { 3,5,8,2,7,6,1 };
	int size = sizeof(ary) / sizeof(ary[0]);

	int index = LSearch(ary, size, 10);
	
	if (index < 0) 
		printf("찾기 실패!!\n");
	else 
		printf("%d", index);

	return 0;
}