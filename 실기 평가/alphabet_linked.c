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

typedef struct node {	// 연결리스트 노드 구조체 선언
	char alphabet;
	struct node* next;
}Node;

typedef struct {	// 헤더의 구조체 선언
	Node* header;
}HeadNode;

void insertionSort(HeadNode* head);	// 삽입정렬 함수

int main()
{
	char alpha;

	HeadNode* Head = malloc(sizeof(HeadNode));	// 헤더 동적 할당
	if (Head != NULL) Head->header = NULL;

	for (int i = 0; i < 10; i++) {	// 연결리스트의 크기는 10개
		Node* newNode = malloc(sizeof(Node));	// 새로운 노드 동적 할당
		if (newNode != NULL) {
			scanf("%c", &alpha);
			newNode->alphabet = alpha;
			newNode->next = Head->header;	// 새로운 노드를 이전 노드 앞에 추가
			Head->header = newNode;		// 헤더에 새로운 노드 추가
		}
	}

	insertionSort(Head);	// 아스키 코드 값 순으로 정렬

	Node* curr = Head->header;

	printf("대문자 : ");
	while ('Z' >= curr->alphabet) {	// 대문자 먼저 출력
		if('A' <= curr->alphabet)
			printf("%c ", curr->alphabet);
		
		curr = curr->next;
		if (curr->next == NULL)
			return;
	}

	printf("\n소문자 : ");	// 나머지(소문자) 출력
	while ('z' >= curr->alphabet) {
		if ('a' <= curr->alphabet)
			printf("%c ", curr->alphabet);

		curr = curr->next;
		if (curr->next == NULL)
			return;
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
			tmp = curr->next;				// 옮길 노드를 임시 저장
			curr->next = curr->next->next;	// 옮길 노드 빼고 연결
			tmp->next = head->header;		// tmp 다음 첫 노드 연결
			head->header = curr = tmp;		// 헤더 노드 = 현재 노드 = tmp
			continue;
		}
		curr = curr->next;
	}
}
