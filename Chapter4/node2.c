#include<stdio.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

void addNode(Node* target, int data)
{
	// newNode = node2, target = head
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;	
	newNode->link = target->link;	// node2�� ���� ���� head->link = node1�� �ּ�
	target->link = newNode;	// head->link ���� node2�� �ּ�
}

int main()
{
	Node* head = (Node *)malloc(sizeof(Node));
	head->link = NULL;

	Node* curr = (Node*)malloc(sizeof(Node));

	addNode(head, 10);	// node1 ����
	addNode(head, 20);	// node2 ����
	addNode(head, 30);	// node3 ����

	// data ���
	curr = head->link;
	while (curr != NULL)	// 3,2,1 ������ ���
	{
		printf("%d\n", curr->data);
		curr = curr->link;
	}

	// ���� �Ҵ� ��ȯ
	Node* tmp;
	curr = head->link;
	while (curr != NULL)	// 3,2,1 ������ ��ȯ
	{
		tmp = curr->link;
		free(curr);
		curr = tmp;
	}
	free(head);

	return 0;
}