#include<stdio.h>

void hanoi(int n, int start, int work, int target);
int count = 0;
int  main()
{
	hanoi(3, 'A', 'B', 'C');

	printf("%d", count);
	getchar();
}

void hanoi(int n, int start, int work, int target)	// 시작봉, 작업봉, 목적봉
{
	count++;
	if (n == 1)
	{
		printf(" %c에서 원반 %d를 %c로 옮김 \n", start, n, target);
	}
	else
	{
		hanoi(n - 1, start, target, work);	// 시작봉에 있는 원반을 목적봉을 이용해 작업봉으로 옮긴다
		printf(" %c에서 원반 %d를 %c로 옮김 \n", start, n, target);
		hanoi(n - 1, work, start, target);
	}
}
