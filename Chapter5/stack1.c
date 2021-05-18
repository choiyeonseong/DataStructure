/*
	배열 형태의 stack
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define STACK_SZ	3
//#define TRUE	1
//#define FALSE 2	==> stdbool.h를 포함시키면 bool을 사용할 수 있음

int isEmpty();		// 공백 체크
int isFull();		// 포화 체크
void push(int);		// 삽입, 입력
int pop();			// 삭제, 출력
int peek();			// 맨 위의 값(top)을 확인
void printStack();	// 스택 전체 출력

int stack[STACK_SZ];
int top = -1;	// 현재 스택의 위치, 항상 스택의 맨 위를 가리킨다

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
	if (top <= -1)	return true;	// 공백인 경우 true를 반환
	else return false;
}

int isFull()
{
	if (top >= STACK_SZ - 1) return true;	// 가득찬 경우 true를 반환
	else return false;
}

void push(int data)
{
	if (isFull())
	{
		printf("STACK overflow!!\n");	// 스택이 가득 찼다
		return;
	}
	else {
		stack[++top] = data;	// 처음에 -1이니까 증가시킨후 데이터를 삽입
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
		return stack[top--];	// top값을 pop한뒤 삭제
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