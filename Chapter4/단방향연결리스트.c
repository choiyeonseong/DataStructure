

#include<stdio.h>

// 노드 구조체
typedef struct node
{
	int data;
	struct node* next;
}Node;

// 헤더 노드 구조체
typedef struct
{
	Node* head;	// 노드를 가리킬수 있는 타입이 와야한다
}HeadNode;

HeadNode* createHead();	// 헤더 생성
void preInsertNode(HeadNode* h_node, int data);	// 전위 노드 삽입
void rearInsertNode(HeadNode* h_node, int data);	// 후위 노드 삽입
void printNode(HeadNode* h_node);	// 노드 출력
void deleteList(HeadNode* h_node);	// 리스트 삭제
Node* searchNode(HeadNode* h_node, int data);	// 노드 검색
void deleteNode(HeadNode* h_node, Node* pre);	// 노드 삭제
void midInsertNode(HeadNode* h_node, Node* prenode, int data);	// 중간 노드 삽입


int main()
{
	HeadNode* h = createHead();

	// 전위 삽입
	preInsertNode(h, 1);
	preInsertNode(h, 2);
	preInsertNode(h, 3);
	preInsertNode(h, 4);
	preInsertNode(h, 5);

	// 후위 삽입
	rearInsertNode(h, 10);
	rearInsertNode(h, 20);
	rearInsertNode(h, 30);
	rearInsertNode(h, 40);
	rearInsertNode(h, 50);

	// 연결리스트 삭제
	//deleteList(h);

	// 노드 검색
	Node* s_node = searchNode(h, 50);

	// 노드 삭제
	//deleteNode(h, s_node);

	// 가운데 노드 추가
	midInsertNode(h, s_node, 7);
	
	// 연결리스트 출력
	printNode(h);

	return 0;
}

/* 헤더를 생성하는 함수 */
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));	// 헤드노드 생성
	if (h != NULL) h->head = NULL;

	return h;
}

/* 전위 노드 생성 */
void preInsertNode(HeadNode* h_node, int data)	// h_node의 실인수는 head
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = h_node->head;
		h_node->head = newNode;
	}
}

/* 후위 노드 생성 */
void rearInsertNode(HeadNode* h_node, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
	}

	// 처음으로 생성되는 노드인 경우
	if (h_node->head == NULL)
	{
		h_node->head = newNode;
	}
	// 이미 생성된 노드가 있는 경우
	else
	{
		//마지막 노드 찾기
		Node* curr = h_node->head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		// 마지막 노드 뒤에 새로운 노드 삽입
		curr->next = newNode;
	}
}

/* 노드 출력 */
void printNode(HeadNode* h_node)
{
	if (h_node->head == NULL)
	{
		printf("error : 노드가 비었습니다.\n");
		return;
	}

	Node* curr = h_node->head;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d번째 노드 값 : %d\n", i++, curr->data);
		curr = curr->next;
	}
}

/* 리스트 삭제 */
void deleteList(HeadNode* h_node)
{
	// 노드가 없는 경우
	if (h_node->head == NULL)
	{
		printf("error : 노드가 비어있습니다.\n");
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
		h_node->head = NULL;	
		//free(h_node);		// h_node는 free되지 않음(출력해서 보기위해)
		printf("삭제 끝\n");
	}
}

/* 노드 검색 */
Node* searchNode(HeadNode* h_node, int data)
{
	Node* curr = h_node->head;
	int i = 1;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("찾은 값 : %d번째 %d\n", i, curr->data);
			return curr;
		}
		else {
			curr = curr->next;
			i++;
		}
	}

	printf("error : 찾는 값이 없습니다.\n");
	return curr;
}

/* 노드 삭제 */
void deleteNode(HeadNode* h_node, Node* d_node)
{
	if (d_node == NULL)
	{
		printf("error : 찾으려는 노드가 존재하지 않습니다.\n");
		return;
	}

	if (h_node->head == NULL)
	{
		printf("error : 노드가 비어있습니다.\n");
		return;
	}

	Node* curr = h_node->head;	// 삭제할 노드
	if (curr == d_node)	// 첫번째 노드를 삭제할때
	{
		h_node->head = d_node->next;
	}
	else {	// 이후 노드를 삭제할때
		while (curr != NULL)
		{
			if (curr->next == d_node)
			{
				curr->next = d_node->next;
			}
			curr = curr->next;
		}
	}
	free(d_node);	// 삭제할 노드를 동적할당 해제
}

/* prenode 뒤에 노드 삽입 */
void midInsertNode(HeadNode* h_node, Node* prenode, int data)
{
	if (prenode == NULL)
	{
		printf("error : 이전 노드가 존재하지않습니다.\n");
		return;
	}
	if (h_node->head == NULL)
	{
		printf("error : 노드가 존재하지않습니다.\n");
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (prenode == h_node->head) // 첫번째 노드 뒤에 삽입할때
	{
		newNode->next= h_node->head->next;
		h_node->head->next = newNode;
	}
	else	// 이후 노드 뒤에 삽입할때
	{
		newNode->next = prenode->next;
		prenode->next = newNode;
	}
}