/*
	���Ḯ��Ʈ ������ stack
	// �ʰ� üũ ���� -> �Ѱ�ġ�� ����
*/

#include<stdio.h>
#include<stdbool.h>

typedef struct snode {
	int data;
	struct snode* link;
}SNode;

typedef struct {
	SNode* topstk;
}TStack;

// ��� ����
TStack* createStack()
{
	TStack* t = (TStack*)malloc(sizeof(TStack));
	if (t != NULL) t->topstk = NULL;
	return t;
}

// ���� üũ
int isEmpty(TStack* ptstack)
{
	if (ptstack->topstk == NULL) return true;	// ������ ��������� true
	else return false;
}

// ����, �Է�
void push(TStack* ptstack, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode == NULL) return;
	newNode->data = data;
	newNode->link = ptstack->topstk;	// ���� ���� ���'��'�� ���� �ִ� ��带 ����
	ptstack->topstk = newNode;			// top�� �׻� ������ ���� ����Ű�� �־���Ѵ�
}

// ����, ���
int pop(TStack* ptstack)
{
	int data;
	SNode* temp;
	if (isEmpty(ptstack))
	{
		printf("STACK is empty!\n");
		return;
	}
	else
	{
		data = ptstack->topstk->data;
		temp = ptstack->topstk;
		ptstack->topstk = ptstack->topstk->link;	// �����Ϸ��� ����� �� �� ��带 �̾���
		free(temp);			// �����Ϸ��� ��� ����
		return data;		// �ȿ� �ִ� ������ ��ȯ
	}
}

// top�� �� ���
int peek(TStack* ptstack)
{
	if (isEmpty(ptstack))
	{
		printf("STACK is empty!!\n");
		return;
	}
	else {
		return ptstack->topstk->data;
	}
}

// stack ��ü ���
void printStack(TStack* ptstack)
{
	SNode* curr = ptstack->topstk;
	while (curr != NULL)
	{
		printf("%d	", curr->data);
		curr = curr->link;
	}
}

int main()
{
	TStack* h = createStack();

	push(h, 10);
	push(h, 20);
	push(h, 30);
	push(h, 40);

	pop(h);	// ������ �� �������� �Էµ� ���� ������

	printStack(h);

	return 0;
}