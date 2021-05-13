#include<stdio.h>

typedef struct node
{
	int data;			// data멤버
	struct node* link;	// 다음 노드의 주소를 저장할 멤버
}Node;
//
//int main()
//{
//	Node* head = (Node*)malloc(sizeof(Node));	// 헤더 노드 생성
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
//	// 첫번째 노드 초기화
	//Node* node1 = (Node*)malloc(sizeof(Node));	// 노드 생성
	//if (node1 == NULL) return;	// 동적할당에 실패하면 null포인터 반환후 프로그램 종료
//	
//	node1->data = 10;
//	node1->link = NULL;
//	head->link = node1;	// 헤더 노드에 첫번째 노드의 주소값을 넣는다
//
//	// 두번째 노드 생성
//	Node* node2 = (Node*)malloc(sizeof(Node));	// 노드 생성
//	if (node2 == NULL) return;
//	
//	node1->link = node2;
//	node2->data = 12;
//	node2->link = NULL;
//
//	// 세번째 노드 생성
//	Node* node3 = (Node*)malloc(sizeof(Node));
//	if (node3 == NULL) return;
//
//	node2->link = node3;
//	node3->data = 15;
//	node3->link = NULL;
//
//	// 네번째 노드 생성
//	Node* node4 = (Node*)malloc(sizeof(Node));
//	if (node4 == NULL) return;
//
//	node3->link = node4;
//	node4->data = 20;
//	node4->link = NULL;
//
//	// 다섯번째 노드 생성
//	Node* node5 = (Node*)malloc(sizeof(Node));
//	if (node5 == NULL) return;
//
//	node4->link = node5;
//	node5->data = 25;
//	node5->link = NULL;
//
//	// 현재 노드 출력
//	int i = 1;
//	Node* curr = head->link;
//	while (curr != NULL)
//	{
//		printf("%d번째 노드 데이터 : %d\n",i, curr->data);
//		curr = curr->link;
//		i++;
//	}
//
//	// 동적 할당 반납
//	free(head);
//	free(node1);
//	free(node2);
//
//	return 0;
//}

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));	// 헤더 노드 생성
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
		// 현재 노드 출력
	int i = 1;
	Node* curr = head->link;
	while (curr != NULL)
	{
		printf("%d번째 노드 데이터 : %d\n",i, curr->data);
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