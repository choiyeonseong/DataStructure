/*
	��ҹ��� ���� ���� ���ĺ��� �Է��ϸ� ��ҹ��ڸ� �Ǻ��Ͽ� �з��ϰ�,
	���� ������ �����Ͽ� ����ϴ� ���α׷�

	- �迭 ����� ���
	1. �Է¹��� �迭�� �̸��� input_ary�� �Ѵ�.
	2. �迭�� ũ��� 10���� ���Ѵ�.
	3. ���� �˰����� ���� ������ ����Ѵ�.
	4. ���� ���� �˰����� �Լ��� �����Ѵ�.
	5. �ҹ��� ���� �迭�̸��� lower_ary�� �Ѵ�.
	6. �빮�� ���� �迭�̸��� upper_ary�� �Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void insertionSort(char* pary, int sz);	// ���� ���� �Լ�
void swap(char* a, char* b);			// swap �Լ�

int main()
{
	int size = 10;
	char input_ary[11];		// 11��°�� '\0'��

	for (int i = 0; i < 10; i++)
	{
		scanf("%c", &input_ary[i]);
	}

	// ����
	insertionSort(input_ary, size);	// �ƽ�Ű�ڵ� �� ������� ����

	// ���
	int i = 1;	// input_ary[0]='\0'

	printf("\n�빮��\n");

	while ('Z' >= input_ary[i]) {		// �տ� �ִ� �빮�� ��� ���
		if ('A' <= input_ary[i])
			printf("%c ", input_ary[i]);
		
		i++;
	}

	printf("\n�ҹ���\n");
	while (i<size) {		// ������(�ҹ���) ���
		printf("%c ", input_ary[i++]);
	}
}

void insertionSort(char* pary, int sz)
{
	for (int i = 1; i < sz; i++) {		// �ι�° �� ����
		for (int j = i; j > 0; j--) {	// ���� ����� ���Ͽ�
			if (pary[j] < pary[j - 1]) {
				// ū ���� �տ� �ö� �ڿ� ���� ���� ��ü
				swap(&pary[j], &pary[j - 1]);
			}
		}
	}
}

void swap(char* a, char* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
* ��ҹ��ڸ� ����� �迭�� ����
char lower_ary[10];
char upper_ary[10];
int u = 0, l = 0;

// ��ҹ��� ����
for (int i = 0; i < size; i++)
{
	// �빮��
	if ('A' <= input_ary[i] && 'Z' >= input_ary[i])
		upper_ary[u++] = input_ary[i];
	// �ҹ���
	if ('a' <= input_ary[i] && 'z' >= input_ary[i])
		lower_ary[l++] = input_ary[i];
}

// ��������
insertionSort(upper_ary, u);
insertionSort(lower_ary, l);

// ���
printf("�빮��\n");
for (int i = 0; i < u; i++)
	printf("%c ", upper_ary[i]);

printf("\n�ҹ���\n");
for (int i = 0; i < l; i++)
	printf("%c ", lower_ary[i]);
*/