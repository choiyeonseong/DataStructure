#include<stdio.h>
int main()
{
	char str[20];
	int i, cnt = 0;
	printf("\n���� �迭 str[] : \n");
	gets(str);
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		cnt++;
	}
	printf("\n���ڿ��� ���� : %d\n", cnt);

	getchar();	// ��ٸ�
}