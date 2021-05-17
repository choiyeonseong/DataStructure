#include<stdio.h>
#include<stdlib.h>

typedef struct dlistnode
{
	int data;
	struct dlistnode* next;	// ���� ���
	struct dlistnode* prev;	// ���� ���
}DListNode;

typedef struct {	// ����� ����ü
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
		printf("error : �޸� �Ҵ� ����\n");
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
	if (phead->head == NULL)	// ���� ����Ʈ�� ���
	{
		phead->head = newNode;
	}
	else
	{
		if (preNode == NULL)	// ù��° ���� ����
		{
			newNode->next = phead->head;
			phead->head->prev = newNode;
			phead->head = newNode;
		}
		else // �߰� �Ǵ� ������ ���� ����
		{
			newNode->prev = preNode;
			newNode->next = preNode->next;
			if (preNode->next != NULL) // ������ ��尡 �ƴ� ���
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
			printf("%d��° ��� %d\n", i++, curr->data);
			curr = curr->next;
		}
	}
	else {
		printf("error : ��尡 ������ϴ�.\n");
	}
}

void allDelNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("error : ��尡 ������ϴ�.\n");
		return;
	}
	DListNode* curr = phead->head;

	// 1. �ϳ��� �Ѿ�鼭 ����(temp ���)
	//DListNode* temp = curr->next;
	//while (curr != NULL)
	//{
	//	temp = curr->next;
	//	free(curr);
	//	curr = temp;
	//}
	//phead->head = NULL;

	// 2. ���������� ��� ��� ����(temp ���X)
	while (phead->head != NULL)
	{
		curr = phead->head;
		phead->head = curr->next;
		free(curr);
		curr = NULL;
	}

	//free(phead);	// �����Ҵ� �ݳ�
}

DListNode* findNode(HeadNode* phead, int data)
{
	if (phead->head == NULL)
	{
		printf("error : ��尡 ������ϴ�.\n");
		return;
	}
	DListNode* curr = phead->head;
	int i = 1;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("ã�� �� : %d ��° ��� - %d\n", i++, curr->data);
			return curr;
		}
		curr = curr->next;
	}
	printf("ã�� ���� �����ϴ�.\n");
	return curr;
}

int main()
{
	// ��� ����
	HeadNode* h = createHeadNode();

	// ��� ����
	DListNode* newNode1 = createNode(8);
	DListNode* newNode2 = createNode(16);
	DListNode* newNode3 = createNode(24);

	// ��� ����
	insertNode(h, NULL, newNode1);
	insertNode(h, newNode1, newNode2);
	insertNode(h, newNode1, newNode3);

	printNode(h);

	// ����Ʈ ����
	allDelNode(h);

	// ��� ã��
	//findNode(h, 8);

	// ��� ���
	printNode(h);

	return 0;
}