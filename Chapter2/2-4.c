#include<stdio.h>
int main()
{
	char str[20] = { "Data Structure!" };
	int i=0,cnt=0;
	printf("\n문자 배열 str[] : \n");
	for (i = 0; str[i]; i++)	// 거짓이 되면 종료
	{
		printf(""%c", str[i]);
		cnt++;
	}
	printf("%d\n", cnt);

	/*while (str[i])
	{
		printf("%c", str[i++]);
		cnt++;
	}
	printf("%d\n", cnt);*/


	getchar();	// 기다림
}