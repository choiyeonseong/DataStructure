#include<stdio.h>
int main()
{
	char str[20] = { "Data Structure!" };
	int i=0,cnt=0;
	printf("\n���� �迭 str[] : \n");
	for (i = 0; str[i]; i++)	// ������ �Ǹ� ����
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


	getchar();	// ��ٸ�
}