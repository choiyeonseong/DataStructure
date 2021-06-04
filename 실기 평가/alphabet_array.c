/*
	대소문자 구분 없이 알파벳을 입력하면 대소문자를 판별하여 분류하고,
	사전 순으로 정렬하여 출력하는 프로그램

	- 배열 사용할 경우
	1. 입력받을 배열의 이름은 input_ary로 한다.
	2. 배열의 크기는 10으로 정한다.
	3. 정렬 알고리즘은 삽입 정렬을 사용한다.
	4. 삽입 정렬 알고리즘은 함수로 구현한다.
	5. 소문자 저장 배열이름은 lower_ary로 한다.
	6. 대문자 저장 배열이름은 upper_ary로 한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void insertionSort(char* pary, int sz);	// 삽입 정렬 함수
void swap(char* a, char* b);			// swap 함수

int main()
{
	int size = 10;
	char input_ary[11];		// 11번째는 '\0'값

	for (int i = 0; i < 10; i++)
	{
		scanf("%c", &input_ary[i]);
	}

	// 정렬
	insertionSort(input_ary, size);	// 아스키코드 값 순서대로 정렬

	// 출력
	int i = 1;	// input_ary[0]='\0'

	printf("\n대문자\n");

	while ('Z' >= input_ary[i]) {		// 앞에 있는 대문자 모두 출력
		if ('A' <= input_ary[i])
			printf("%c ", input_ary[i]);
		
		i++;
	}

	printf("\n소문자\n");
	while (i<size) {		// 나머지(소문자) 출력
		printf("%c ", input_ary[i++]);
	}
}

void insertionSort(char* pary, int sz)
{
	for (int i = 1; i < sz; i++) {		// 두번째 값 부터
		for (int j = i; j > 0; j--) {	// 이전 값들과 비교하여
			if (pary[j] < pary[j - 1]) {
				// 큰 값이 앞에 올때 뒤에 작은 값과 교체
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
* 대소문자를 나누어서 배열에 저장
char lower_ary[10];
char upper_ary[10];
int u = 0, l = 0;

// 대소문자 구별
for (int i = 0; i < size; i++)
{
	// 대문자
	if ('A' <= input_ary[i] && 'Z' >= input_ary[i])
		upper_ary[u++] = input_ary[i];
	// 소문자
	if ('a' <= input_ary[i] && 'z' >= input_ary[i])
		lower_ary[l++] = input_ary[i];
}

// 삽입정렬
insertionSort(upper_ary, u);
insertionSort(lower_ary, l);

// 출력
printf("대문자\n");
for (int i = 0; i < u; i++)
	printf("%c ", upper_ary[i]);

printf("\n소문자\n");
for (int i = 0; i < l; i++)
	printf("%c ", lower_ary[i]);
*/