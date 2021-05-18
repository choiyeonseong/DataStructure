/*
	�迭 ������ stack
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define STACK_SZ	3
//#define TRUE	1
//#define FALSE 2	==> stdbool.h�� ���Խ�Ű�� bool�� ����� �� ����

int isEmpty();		// ���� üũ
int isFull();		// ��ȭ üũ
void push(int);		// ����, �Է�
int pop();			// ����, ���
int peek();			// �� ���� ��(top)�� Ȯ��
void printStack();	// ���� ��ü ���

int stack[STACK_SZ];
int top = -1;	// ���� ������ ��ġ, �׻� ������ �� ���� ����Ų��

int main()
{
	push(1);
	push(2);
	push(10);

	pop();
	
	push(20);

	printStack();

	return 0;
}

int isEmpty()
{
	if (top <= -1)	return true;	// ������ ��� true�� ��ȯ
	else return false;
}

int isFull()
{
	if (top >= STACK_SZ - 1) return true;	// ������ ��� true�� ��ȯ
	else return false;
}

void push(int data)
{
	if (isFull())
	{
		printf("STACK overflow!!\n");	// ������ ���� á��
		return;
	}
	else {
		stack[++top] = data;	// ó���� -1�̴ϱ� ������Ų�� �����͸� ����
	}
}

int pop()
{
	if (isEmpty())
	{
		printf("STACK underflow!!\n");
		return -1;
	}
	else {
		return stack[top--];	// top���� pop�ѵ� ����
	}
}

int peek() 
{
	if (isEmpty())
	{
		printf("STACK underflow!!\n");
		return -1;
	}
	else return stack[top];
}

void printStack()
{
	int i;
	if (!isEmpty())
	{
		for (i = 0; i <= top; i++)
		{
			printf("%d	", stack[i]);
		}
	}
}