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
	newNode->link = target->link;	// node2의 다음 값은 head->link = node1의 주소
	target->link = newNode;	// head->link 값은 node2의 주소
}

int main()
{
	Node* head = (Node *)malloc(sizeof(Node));
	head->link = NULL;

	Node* curr = (Node*)malloc(sizeof(Node));

	addNode(head, 10);	// node1 생성
	addNode(head, 20);	// node2 생성
	addNode(head, 30);	// node3 생성

	// data 출력
	curr = head->link;
	while (curr != NULL)	// 3,2,1 순서로 출력
	{
		printf("%d\n", curr->data);
		curr = curr->link;
	}

	// 동적 할당 반환
	Node* tmp;
	curr = head->link;
	while (curr != NULL)	// 3,2,1 순서로 반환
	{
		tmp = curr->link;
		free(curr);
		curr = tmp;
	}
	free(head);

	return 0;
}