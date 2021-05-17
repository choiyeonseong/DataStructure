// ���� ����Ʈ : ������ ��带 ����� �����Ѿ� �Ѵ�.

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
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));	// heap������ �Ҵ�, newNode�� �����ּ�
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	else
	{
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}

void insertFirstNode(HeadNode* phead, ListNode* newNode)	// head�� �״��, �տ� �Է�
{
	if (phead->head == NULL)	// ���� ����Ʈ �϶�
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = phead->head->link;
		phead->head->link = newNode;
	}
}

void insertLastNode(HeadNode* phead, ListNode* newNode)	// �������� �ԷµǴ� ���� head�� �Ǿ����
{
	if (phead->head == NULL)	// ���� ����Ʈ �϶�
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = phead->head->link;
		phead->head->link = newNode;
		phead->head = newNode;	// ������ ��带 ����� �����Ѿ� �Ѵ�
	}
}

void printNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("��尡 ������ϴ�.\n");
	}
	else {
		ListNode* curr = phead->head;
		int i = 1;

		do {
			printf("%d��° ��� : %d\n", i++, curr->data);
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