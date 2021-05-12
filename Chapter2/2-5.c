#include<stdio.h>
int main()
{
	char str[20];
	int i, cnt = 0;
	printf("\n문자 배열 str[] : \n");
	gets(str);
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		cnt++;
	}
	printf("\n문자열의 길이 : %d\n", cnt);

	getchar();	// 기다림
}