#include<stdio.h>

int main()
{
	int a;

	while (1)
	{
		printf("1~9������ ���� : \n$");
		scanf("%d", &a);
		if (a > 9 || a < 1)
		{
			printf("���α׷� ����");
			break;
		}

		for (int i = 1; i < 10; i++)
		{
			printf("%d * %d = %d\n", a, i, a * i);
		}
	}

	return 0;
}