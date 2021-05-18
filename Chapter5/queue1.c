/*
	�迭 ������ ť
	rear==front -> empty
	rear+1==front => full
	���� ť������ ������ �� �ϳ��� ����־��Ѵ�
*/

#include<stdio.h>
#include<stdbool.h>

#define SIZE	6

int isEmpty();
int isFull();
void enQueue(int);	// q�� ����
int deQueue();		// q���� ����

int rear = 0;		// �Ա�
int front = 0;		// �ⱸ
int queue[SIZE];

int main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);
	printf("%d\n", deQueue()); //������ �� ���
	printf("%d\n", deQueue()); //������ �� ���
	printf("%d\n", deQueue()); //������ �� ���
	printf("%d\n", deQueue()); //underflow ���


	return 0;
}


int isEmpty()
{
	if (rear == front) return true;	// ���� ť���� ���۰� ���� ������ ť�� �������
	else return false;
}
int isFull()
{
	if ((rear + 1) % SIZE == front) return true;	// 0~5������ ������ ����ؾ���
	else return false;
}
void enQueue(int data)
{
	if (isFull())
	{
		printf("Queue overflow!!\n");
		return;
	}
	else {
		rear = rear % SIZE;
		queue[rear++] = data;
		//queue[(rear % SIZE)] = data;	// ���� �� ���� ��ħ
	}
}
int deQueue()
{
	if (isEmpty())
	{
		printf("Queue is empty!!\n");
		exit(1);
	}
	else{
		
		return queue[front++%SIZE];
	}
}