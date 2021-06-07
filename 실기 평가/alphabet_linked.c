#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {	// 연결리스트 노드 구조체 선언
	char alphabet;
	struct node* next;
}Node;

typedef struct {	// 헤더의 구조체 선언
	Node* head;
}HeadNode;

void insertionSort(HeadNode* head);	// 삽입정렬 함수
void freeNode(HeadNode* head);	// 동적할당 해제 함수

int main()
{
	// 연결리스트 헤더 생성
	HeadNode* headNode = malloc(sizeof(HeadNode));	// 헤더 동적 할당
	if (headNode != NULL) headNode->head = NULL;

	// 10개의 문자 입력
	char alpha;

	for (int i = 0; i < 10; i++) {	// 연결리스트의 크기는 10개
		Node* newNode = malloc(sizeof(Node));	// 새로운 노드 동적 할당
		if (newNode != NULL) {
			scanf("%c", &alpha);
			newNode->alphabet = alpha;
			newNode->next = headNode->head;	// 새로운 노드를 이전 노드 앞에 추가
			headNode->head = newNode;		// 헤더에 새로운 노드 추가
		}
	}

	// 정렬
	insertionSort(headNode);	// 아스키 코드 값 순으로 정렬

	// 출력
	Node* curr = headNode->head;

	printf("대문자 : ");	// 대문자 먼저 출력
	while ('Z' >= curr->alphabet) {	
		if ('A' <= curr->alphabet)
			printf("%c ", curr->alphabet);

		curr = curr->next;

		if (curr == NULL) {	// 소문자가 없으면 바로 할당 해제 후 종료
			break;
		}
	}

	printf("\n소문자 : ");	// 나머지(소문자) 출력
	while (curr!=NULL && 'a' <= curr->alphabet&&'z' >= curr->alphabet) {
		
			printf("%c ", curr->alphabet);

		curr = curr->next;
	}
		freeNode(headNode);
}

// 삽입 정렬 함수
void insertionSort(HeadNode* head)
{
	Node* curr, * tmp;
	curr = head->head;

	while (curr->next != NULL)
	{
		if (curr->alphabet > curr->next->alphabet)
		{
			tmp = curr->next;				// 옮길 노드를 임시 저장
			curr->next = curr->next->next;	// 옮길 노드 빼고 연결
			tmp->next = head->head;			// tmp 다음 첫 노드 연결
			head->head = curr = tmp;		// 헤더 노드 = 현재 노드 = tmp
			continue;
		}
		curr = curr->next;
	}
}

void freeNode(HeadNode* head)
{
	printf("\n");

	Node* curr, * tmp;
	curr = head->head;

	while (curr != NULL)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}

	free(head);

	printf("동적할당 해제\n");
}