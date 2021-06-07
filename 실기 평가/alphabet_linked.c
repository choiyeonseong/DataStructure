#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {	// ���Ḯ��Ʈ ��� ����ü ����
	char alphabet;
	struct node* next;
}Node;

typedef struct {	// ����� ����ü ����
	Node* head;
}HeadNode;

void insertionSort(HeadNode* head);	// �������� �Լ�
void freeNode(HeadNode* head);	// �����Ҵ� ���� �Լ�

int main()
{
	// ���Ḯ��Ʈ ��� ����
	HeadNode* headNode = malloc(sizeof(HeadNode));	// ��� ���� �Ҵ�
	if (headNode != NULL) headNode->head = NULL;

	// 10���� ���� �Է�
	char alpha;

	for (int i = 0; i < 10; i++) {	// ���Ḯ��Ʈ�� ũ��� 10��
		Node* newNode = malloc(sizeof(Node));	// ���ο� ��� ���� �Ҵ�
		if (newNode != NULL) {
			scanf("%c", &alpha);
			newNode->alphabet = alpha;
			newNode->next = headNode->head;	// ���ο� ��带 ���� ��� �տ� �߰�
			headNode->head = newNode;		// ����� ���ο� ��� �߰�
		}
	}

	// ����
	insertionSort(headNode);	// �ƽ�Ű �ڵ� �� ������ ����

	// ���
	Node* curr = headNode->head;

	printf("�빮�� : ");	// �빮�� ���� ���
	while ('Z' >= curr->alphabet) {	
		if ('A' <= curr->alphabet)
			printf("%c ", curr->alphabet);

		curr = curr->next;

		if (curr == NULL) {	// �ҹ��ڰ� ������ �ٷ� �Ҵ� ���� �� ����
			break;
		}
	}

	printf("\n�ҹ��� : ");	// ������(�ҹ���) ���
	while (curr!=NULL && 'a' <= curr->alphabet&&'z' >= curr->alphabet) {
		
			printf("%c ", curr->alphabet);

		curr = curr->next;
	}
		freeNode(headNode);
}

// ���� ���� �Լ�
void insertionSort(HeadNode* head)
{
	Node* curr, * tmp;
	curr = head->head;

	while (curr->next != NULL)
	{
		if (curr->alphabet > curr->next->alphabet)
		{
			tmp = curr->next;				// �ű� ��带 �ӽ� ����
			curr->next = curr->next->next;	// �ű� ��� ���� ����
			tmp->next = head->head;			// tmp ���� ù ��� ����
			head->head = curr = tmp;		// ��� ��� = ���� ��� = tmp
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

	printf("�����Ҵ� ����\n");
}