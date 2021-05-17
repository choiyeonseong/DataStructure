#include<stdio.h>
#include<stdlib.h>

typedef struct dlistnode
{
	int data;
	struct dlistnode* next;	// 다음 노드
	struct dlistnode* prev;	// 이전 노드
}DListNode;

typedef struct {	// 헤드노드 구조체
	DListNode* head;
}HeadNode;

HeadNode* createHeadNode()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

DListNode* createNode(int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("error : 메모리 할당 실패\n");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
}

void insertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode)
{
	if (phead->head == NULL)	// 공백 리스트인 경우
	{
		phead->head = newNode;
	}
	else
	{
		if (preNode == NULL)	// 첫번째 노드로 삽입
		{
			newNode->next = phead->head;
			phead->head->prev = newNode;
			phead->head = newNode;
		}
		else // 중간 또는 마지막 노드로 삽입
		{
			newNode->prev = preNode;
			newNode->next = preNode->next;
			if (preNode->next != NULL) // 마지막 노드가 아닌 경우
				newNode->next->prev = newNode;
			preNode->next = newNode;
		}
	}
}

void printNode(HeadNode* phead)
{
	if (phead->head != NULL)
	{
		DListNode* curr = phead->head;
		int i = 1;
		while (curr != NULL)
		{
			printf("%d번째 노드 %d\n", i++, curr->data);
			curr = curr->next;
		}
	}
	else {
		printf("error : 노드가 비었습니다.\n");
	}
}

void allDelNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("error : 노드가 비었습니다.\n");
		return;
	}
	DListNode* curr = phead->head;

	// 1. 하나씩 넘어가면서 삭제(temp 사용)
	//DListNode* temp = curr->next;
	//while (curr != NULL)
	//{
	//	temp = curr->next;
	//	free(curr);
	//	curr = temp;
	//}
	//phead->head = NULL;

	// 2. 순차적으로 헤드 노드 삭제(temp 사용X)
	while (phead->head != NULL)
	{
		curr = phead->head;
		phead->head = curr->next;
		free(curr);
		curr = NULL;
	}

	//free(phead);	// 동적할당 반납
}

DListNode* findNode(HeadNode* phead, int data)
{
	if (phead->head == NULL)
	{
		printf("error : 노드가 비었습니다.\n");
		return;
	}
	DListNode* curr = phead->head;
	int i = 1;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("찾은 값 : %d 번째 노드 - %d\n", i++, curr->data);
			return curr;
		}
		curr = curr->next;
	}
	printf("찾는 값이 없습니다.\n");
	return curr;
}

int main()
{
	// 헤드 생성
	HeadNode* h = createHeadNode();

	// 노드 생성
	DListNode* newNode1 = createNode(8);
	DListNode* newNode2 = createNode(16);
	DListNode* newNode3 = createNode(24);

	// 노드 삽입
	insertNode(h, NULL, newNode1);
	insertNode(h, newNode1, newNode2);
	insertNode(h, newNode1, newNode3);

	printNode(h);

	// 리스트 삭제
	allDelNode(h);

	// 노드 찾기
	//findNode(h, 8);

	// 노드 출력
	printNode(h);

	return 0;
}