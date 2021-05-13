#include<stdio.h>

typedef struct node
{
	int data;			// data���
	struct node* link;	// ���� ����� �ּҸ� ������ ���
}Node;
//
//int main()
//{
//	Node* head = (Node*)malloc(sizeof(Node));	// ��� ��� ����
//	Node* arrnode[5];
//
//	for (int i = 0; i < 5; i++)
//	{
//
//		arrnode[i] = (Node*)malloc(sizeof(Node));
//		if (arrnode[i] == NULL) return;
//
//		arrnode[i]->data = i * 10;
//		arrnode[i]->link = NULL;
//		if (i == 0)
//		{
//			head->link = arrnode[0];
//		}
//		else {
//			arrnode[i - 1]->link = arrnode[i];
//		}
//	}
//	
//	// ù��° ��� �ʱ�ȭ
	//Node* node1 = (Node*)malloc(sizeof(Node));	// ��� ����
	//if (node1 == NULL) return;	// �����Ҵ翡 �����ϸ� null������ ��ȯ�� ���α׷� ����
//	
//	node1->data = 10;
//	node1->link = NULL;
//	head->link = node1;	// ��� ��忡 ù��° ����� �ּҰ��� �ִ´�
//
//	// �ι�° ��� ����
//	Node* node2 = (Node*)malloc(sizeof(Node));	// ��� ����
//	if (node2 == NULL) return;
//	
//	node1->link = node2;
//	node2->data = 12;
//	node2->link = NULL;
//
//	// ����° ��� ����
//	Node* node3 = (Node*)malloc(sizeof(Node));
//	if (node3 == NULL) return;
//
//	node2->link = node3;
//	node3->data = 15;
//	node3->link = NULL;
//
//	// �׹�° ��� ����
//	Node* node4 = (Node*)malloc(sizeof(Node));
//	if (node4 == NULL) return;
//
//	node3->link = node4;
//	node4->data = 20;
//	node4->link = NULL;
//
//	// �ټ���° ��� ����
//	Node* node5 = (Node*)malloc(sizeof(Node));
//	if (node5 == NULL) return;
//
//	node4->link = node5;
//	node5->data = 25;
//	node5->link = NULL;
//
//	// ���� ��� ���
//	int i = 1;
//	Node* curr = head->link;
//	while (curr != NULL)
//	{
//		printf("%d��° ��� ������ : %d\n",i, curr->data);
//		curr = curr->link;
//		i++;
//	}
//
//	// ���� �Ҵ� �ݳ�
//	free(head);
//	free(node1);
//	free(node2);
//
//	return 0;
//}

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));	// ��� ��� ����
	Node* arrnode[5];

	for (int i = 0; i < 5; i++)
	{
		arrnode[i] = (Node*)malloc(sizeof(Node));
		if (arrnode[i] == NULL) return;

		arrnode[i]->data = (i+1) * 10;
		arrnode[i]->link = NULL;
		if (i == 0)
		{
			head->link = arrnode[0];
		}
		else {
			arrnode[i - 1]->link = arrnode[i];
		}
	}
		// ���� ��� ���
	int i = 1;
	Node* curr = head->link;
	while (curr != NULL)
	{
		printf("%d��° ��� ������ : %d\n",i, curr->data);
		curr = curr->link;
		i++;
	}
	free(head);
	for (int j = 0; j < 5; j++)
	{
		free(arrnode[j]);
	}
	return 0;
}