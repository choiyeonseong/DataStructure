// 원형 리스트 : 마지막 노드를 헤더가 가르켜야 한다.

#include<stdio.h>

typedef struct listnode
{
	int data;
	struct listnode* link;
}ListNode;

typedef struct
{
	ListNode* head;
}HeadNode;

HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}

ListNode* createNode(HeadNode* phead, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));	// heap영역에 할당, newNode는 시작주소
	if (newNode == NULL)
	{
		printf("메모리 할당 실패\n");
		return;
	}
	else
	{
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}

void insertFirstNode(HeadNode* phead, ListNode* newNode)	// head는 그대로, 앞에 입력
{
	if (phead->head == NULL)	// 공백 리스트 일때
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = phead->head->link;
		phead->head->link = newNode;
	}
}

void insertLastNode(HeadNode* phead, ListNode* newNode)	// 마지막에 입력되는 값이 head가 되어야함
{
	if (phead->head == NULL)	// 공백 리스트 일때
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = phead->head->link;
		phead->head->link = newNode;
		phead->head = newNode;	// 마지막 노드를 헤더가 가르켜야 한다
	}
}

void printNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("노드가 비었습니다.\n");
	}
	else {
		ListNode* curr = phead->head;
		int i = 1;

		do {
			printf("%d번째 노드 : %d\n", i++, curr->data);
			curr = curr->link;
		} while (curr != phead->head);
	}
}

int main()
{
	HeadNode* h = createHead();

	ListNode* node1 = createNode(h, 8);
	ListNode* node2 = createNode(h, 16);
	ListNode* node3 = createNode(h, 20);

	insertFirstNode(h, node1);
	insertFirstNode(h, node2);
	insertFirstNode(h, node3);

	printNode(h);

	return 0;
}