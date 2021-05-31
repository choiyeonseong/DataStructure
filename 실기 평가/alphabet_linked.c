/*
	대소문자 구분 없이 알파벳을 입력하면 대소문자를 판별하여 분류하고,
	사전 순으로 정렬하여 출력하는 프로그램

	- 연결리스트를 사용할 경우
	1. 입력받을 배열의 이름은 input_ary로 한다.
	2. 배열의 크기는 10으로 정한다.
	3. 정렬 알고리즘은 삽입정렬을 사용한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	char alphabet;
	struct node* next;
}Node;

typedef struct {
	Node* header;
}HeadNode;

void insertionSort(HeadNode* head);

int main()
{
	char alpha;

	HeadNode* Head = malloc(sizeof(HeadNode));
	if (Head != NULL) Head->header = NULL;

	for (int i = 0; i < 10; i++) {
		Node* newNode = malloc(sizeof(Node));
		if (newNode != NULL) {
			scanf("%c", &alpha);
			newNode->alphabet = alpha;
			newNode->next = Head->header;
			Head->header = newNode;
		}
	}

	insertionSort(Head);

	Node* curr = Head->header;

	printf("대문자 : ");
	while ('Z' >= curr->alphabet) {

		printf("%c ", curr->alphabet);

		curr = curr->next;
	}

	printf("\n소문자 : ");
	while (curr != NULL) {

		printf("%c ", curr->alphabet);

		curr = curr->next;
	}
}

// 삽입 정렬 함수
void insertionSort(HeadNode* head)
{
	Node* curr, * tmp;
	curr = head->header;

	while (curr->next != NULL)
	{
		if (curr->alphabet > curr->next->alphabet)
		{
			tmp = curr->next;
			curr->next = curr->next->next;
			tmp->next = head->header;
			head->header = curr = tmp;
			continue;
		}
		curr = curr->next;
	}
}
