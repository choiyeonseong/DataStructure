/*
	���� ����Ʈ ������ queue

	// �ʰ� üũ ���� -> �Ѱ�ġ�� ����
*/

#include<stdio.h>
#include<stdbool.h>

typedef struct snode {
	int data;
	struct snode* link;
}SNode;

typedef struct {
	SNode* frontQ;
	SNode* rearQ;
}RQueue;

RQueue* createQueue()
{
	RQueue* q = (RQueue*)malloc(sizeof(RQueue));
	if (q != NULL) q->frontQ = q->rearQ = NULL;
	return q;
}

int isEmpty(RQueue* ptQ)
{
	if (ptQ->frontQ == NULL) return true;	// ť�� �������
	else return false;
}

void enQueue(RQueue* ptQ, int data)
{
	SNode* newQ = (SNode*)malloc(sizeof(SNode));
	if (newQ != NULL)
	{
		newQ->data = data;
		newQ->link = NULL;
		if (isEmpty(ptQ))	// �����̸� ù��° ť=������ ť
		{
			ptQ->frontQ = newQ;
			ptQ->rearQ = newQ;
		}
		else
		{
			ptQ->rearQ->link = newQ;
			ptQ->rearQ = newQ;
		}
	}
}

int deQueue(RQueue* ptQ)
{
	if (isEmpty(ptQ))
	{
		printf("Queue is empty!!\n");
		exit(1);
	}
	else
	{
		SNode* temp = ptQ->frontQ;
		int data = ptQ->frontQ->data;
		ptQ->frontQ = ptQ->frontQ->link;
		if (ptQ->frontQ == NULL)
		{
			ptQ->rearQ = NULL;
		}
		free(temp);
		return data;
	}
}

int peek(RQueue* ptQ)
{
	if (isEmpty(ptQ))
	{
		printf("Queue is empty!!\n");
		exit(1);
	}
	else
	{
		return ptQ->frontQ->data;
	}
}

void printQueue(RQueue* ptQ)
{
	SNode* curr = ptQ->frontQ;

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->link;
	}
}

int main()
{
	RQueue* q = createQueue();

	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);
	enQueue(q, 5);
	enQueue(q, 6);
	enQueue(q, 7);

	printf("peek\n");
	printf("%d\n", peek(q));
	printf("%d\n", peek(q));
	printf("%d\n", peek(q));


	printf("��ü���\n");
	printQueue(q);

	printf("dequeue\n");
	printf("%d\n", deQueue(q));
	printf("%d\n", deQueue(q));
	printf("%d\n", deQueue(q));


	return 0;
}