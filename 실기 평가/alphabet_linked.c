/*
	��ҹ��� ���� ���� ���ĺ��� �Է��ϸ� ��ҹ��ڸ� �Ǻ��Ͽ� �з��ϰ�,
	���� ������ �����Ͽ� ����ϴ� ���α׷�

	- ���Ḯ��Ʈ�� ����� ���
	1. �Է¹��� �迭�� �̸��� input_ary�� �Ѵ�.
	2. �迭�� ũ��� 10���� ���Ѵ�.
	3. ���� �˰����� ���������� ����Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {	// ���Ḯ��Ʈ ��� ����ü ����
	char alphabet;
	struct node* next;
}Node;

typedef struct {	// ����� ����ü ����
	Node* header;
}HeadNode;

void insertionSort(HeadNode* head);	// �������� �Լ�

int main()
{
	char alpha;

	HeadNode* Head = malloc(sizeof(HeadNode));	// ��� ���� �Ҵ�
	if (Head != NULL) Head->header = NULL;

	for (int i = 0; i < 10; i++) {	// ���Ḯ��Ʈ�� ũ��� 10��
		Node* newNode = malloc(sizeof(Node));	// ���ο� ��� ���� �Ҵ�
		if (newNode != NULL) {
			scanf("%c", &alpha);
			newNode->alphabet = alpha;
			newNode->next = Head->header;	// ���ο� ��带 ���� ��� �տ� �߰�
			Head->header = newNode;		// ����� ���ο� ��� �߰�
		}
	}

	insertionSort(Head);	// �ƽ�Ű �ڵ� �� ������ ����

	Node* curr = Head->header;

	printf("�빮�� : ");
	while ('Z' >= curr->alphabet) {	// �빮�� ���� ���
		if('A' <= curr->alphabet)
			printf("%c ", curr->alphabet);
		
		curr = curr->next;
		if (curr->next == NULL)
			return;
	}

	printf("\n�ҹ��� : ");	// ������(�ҹ���) ���
	while ('z' >= curr->alphabet) {
		if ('a' <= curr->alphabet)
			printf("%c ", curr->alphabet);

		curr = curr->next;
		if (curr->next == NULL)
			return;
	}
}

// ���� ���� �Լ�
void insertionSort(HeadNode* head)
{
	Node* curr, * tmp;
	curr = head->header;

	while (curr->next != NULL)
	{
		if (curr->alphabet > curr->next->alphabet)
		{
			tmp = curr->next;				// �ű� ��带 �ӽ� ����
			curr->next = curr->next->next;	// �ű� ��� ���� ����
			tmp->next = head->header;		// tmp ���� ù ��� ����
			head->header = curr = tmp;		// ��� ��� = ���� ��� = tmp
			continue;
		}
		curr = curr->next;
	}
}
