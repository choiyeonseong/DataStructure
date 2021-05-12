#include<stdio.h>

void main()
{
	int score[5] = {1,2,3};
	char grade[5] = { 'A','B','C' };

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", score[i]);
		printf("%c\n", grade[i]);
	}
}