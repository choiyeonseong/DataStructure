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

	printf("�빮�� : ");
	while ('Z' >= curr->alphabet) {

		printf("%c ", curr->alphabet);

		curr = curr->next;
	}

	printf("\n�ҹ��� : ");
	while (curr != NULL) {

		printf("%c ", curr->alphabet);

		curr = curr->next;
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
			tmp = curr->next;
			curr->next = curr->next->next;
			tmp->next = head->header;
			head->header = curr = tmp;
			continue;
		}
		curr = curr->next;
	}
}
