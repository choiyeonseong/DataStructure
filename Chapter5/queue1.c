/*
	배열 형태의 큐
	rear==front -> empty
	rear+1==front => full
	원형 큐에서는 마지막 방 하나를 비워둬야한다
*/

#include<stdio.h>
#include<stdbool.h>

#define SIZE	6

int isEmpty();
int isFull();
void enQueue(int);	// q에 삽입
int deQueue();		// q에서 제거

int rear = 0;		// 입구
int front = 0;		// 출구
int queue[SIZE];

int main()
{
	enQueue(10);
	enQueue(20);
	enQueue(30);
	printf("%d\n", deQueue()); //삭제된 놈 출력
	printf("%d\n", deQueue()); //삭제된 놈 출력
	printf("%d\n", deQueue()); //삭제된 놈 출력
	printf("%d\n", deQueue()); //underflow 출력


	return 0;
}


int isEmpty()
{
	if (rear == front) return true;	// 원형 큐에서 시작과 끝이 같으면 큐가 비어있음
	else return false;
}
int isFull()
{
	if ((rear + 1) % SIZE == front) return true;	// 0~5까지의 공간만 사용해야함
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
		//queue[(rear % SIZE)] = data;	// 위의 두 식을 합침
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