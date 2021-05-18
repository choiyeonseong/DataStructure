/*
	연결리스트 형태의 stack
	// 초과 체크 없음 -> 한계치가 없음
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

// 헤더 생성
TStack* createStack()
{
	TStack* t = (TStack*)malloc(sizeof(TStack));
	if (t != NULL) t->topstk = NULL;
	return t;
}

// 공백 체크
int isEmpty(TStack* ptstack)
{
	if (ptstack->topstk == NULL) return true;	// 스택이 비어있으면 true
	else return false;
}

// 삽입, 입력
void push(TStack* ptstack, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode == NULL) return;
	newNode->data = data;
	newNode->link = ptstack->topstk;	// 새로 들어가는 노드'뒤'에 원래 있던 노드를 연결
	ptstack->topstk = newNode;			// top은 항상 맨위의 값을 가르키고 있어야한다
}

// 삭제, 출력
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
		ptstack->topstk = ptstack->topstk->link;	// 삭제하려는 노드의 앞 뒤 노드를 이어줌
		free(temp);			// 삭제하려는 노드 삭제
		return data;		// 안에 있던 데이터 반환
	}
}

// top의 값 출력
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

// stack 전체 출력
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

	pop(h);	// 무조건 맨 마지막에 입력된 값이 삭제됨

	printStack(h);

	return 0;
}