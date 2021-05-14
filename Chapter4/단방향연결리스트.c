#include<stdio.h>

// ��� ����ü
typedef struct node
{
	int data;
	struct node* next;
}Node;

// ��� ��� ����ü
typedef struct
{
	Node* head;	// ��带 ����ų�� �ִ� Ÿ���� �;��Ѵ�
}HeadNode;

HeadNode* createHead();
void preInsertNode(HeadNode* h_node, int data);	// h_node�� ���μ��� head
void rearInsertNode(HeadNode* h_node, int data);
void printNode(HeadNode* h_node);
void deleteList(HeadNode* h_node);

Node* searchNode(HeadNode* h_node, int data);
void deleteNode(HeadNode* h_node, Node* pre);

int main()
{
	HeadNode* h = createHead();

	// ���� ����
	preInsertNode(h, 1);
	//preInsertNode(h, 2);
	//preInsertNode(h, 3);
	//preInsertNode(h, 4);
	//preInsertNode(h, 5);

	//// ���� ����
	//rearInsertNode(h, 10);
	//rearInsertNode(h, 20);
	//rearInsertNode(h, 30);
	//rearInsertNode(h, 40);
	//rearInsertNode(h, 50);

	// ���Ḯ��Ʈ ���
	printNode(h);

	// ���Ḯ��Ʈ ����
	/*deleteList(h);
	printNode(h);*/

	// ��� �˻�
	Node* s_node = searchNode(h, 5);

	// ��� ����
	deleteNode(h, s_node);
	printNode(h);

	return 0;
}

/* ����� �����ϴ� �Լ� */
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));	// ����� ����
	if (h != NULL) h->head = NULL;

	return h;
}

/* ���� ��� ���� */
void preInsertNode(HeadNode* h_node, int data)	// h_node�� ���μ��� head
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = h_node->head;
		h_node->head = newNode;
	}
}

/* ���� ��� ���� */
void rearInsertNode(HeadNode* h_node, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
	}

	// ó������ �����Ǵ� ����� ���
	if (h_node->head == NULL)
	{
		h_node->head = newNode;
	}

	// �̹� ������ ��尡 �ִ� ���
	else
	{
		//������ ��� ã��
		Node* curr = h_node->head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		// ������ ��� �ڿ� ���ο� ��� ����
		curr->next = newNode;
	}
}

/* ��� ��� */
void printNode(HeadNode* h_node)
{
	if (h_node->head == NULL)
	{
		printf("��尡 ������ϴ�.\n");
		return;
	}

	Node* curr = h_node->head;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d��° ��� �� : %d\n", i++, curr->data);
		curr = curr->next;
	}
}

/* ����Ʈ ���� */
void deleteList(HeadNode* h_node)
{
	// ��尡 ���� ���
	if (h_node->head == NULL)
	{
		printf("��尡 ����ֽ��ϴ�.\n");
	}
	else
	{
		Node* curr = h_node->head;

		while (curr != NULL)
		{
			Node* tmp = curr->next;
			free(curr);
			curr = tmp;
		}
		h_node->head = NULL;	// h_node�� free���� ����
		printf("���� ��\n");
	}
}

/* ��� �˻� �Լ� */
Node* searchNode(HeadNode* h_node, int data)
{
	Node* curr = h_node->head;
	int i = 1;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("ã�� �� : %d��° %d\n", i, curr->data);
			return curr;
		}
		else {
			curr = curr->next;
			i++;
		}
	}

	printf("ã�� ���� �����ϴ�.");
	return curr;
}

/* ��� ���� */
void deleteNode(HeadNode* h_node, Node* d_node)
{
	if (d_node == NULL)
	{
		printf("�ش��ϴ� ���� ����\n");
		return;
	}

	if (h_node->head == NULL)
	{
		printf("��尡 �������\n");
		return;
	}

	Node* curr = h_node->head;	// ������ ���
	if (curr == d_node)
	{
		h_node->head = d_node->next;
	}
	else {
		while (curr != NULL)
		{
			if (curr->next == d_node)
			{
				curr->next = d_node->next;
				free(d_node);
			}
			curr = curr->next;
		}
	}
}


