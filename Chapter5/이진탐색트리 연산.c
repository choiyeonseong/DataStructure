/*
	이진트리의 규칙
		: 부모노드 기준으로 왼쪽으로는 작은값, 오른쪽에는 큰값
	이진트리를 중위순회로 출력하면 정렬된 상태로 출력
*/

#include<stdio.h>
#include<stdlib.h>

typedef char element;		// 이진 탐색 트리 element의 자료형을 char로 정의
typedef struct treeNode
{
	char key;				// 데이터 필드
	struct treeNode* left;	// 왼쪽 서브 트리 링크 필드
	struct treeNode* right;	// 오른쪽 서브 트리 링크 필드
}treeNode;

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, char x)
{
	if (root == NULL) printf("\n생성된 노드가 없습니다.\n");
	else
	{
		treeNode* p = root;
		while (p != NULL)
		{
			if (x < p->key) p = p->left;
			else if (x == p->key) return p;
			else p = p->right;
		}
		printf("\n 찾는 키가 없습니다.\n");
		return p;
	}
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertNode(treeNode* p, char x)
{
	treeNode* newNode;

	// root노드를 생성할때
	if (p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));

		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	// root보다 작은 값이면 왼쪽 노드에
	else if (x < p->key) p->left = insertNode(p->left, x);
	// root보다 큰 값이면 오른쪽 노드에
	else if (x > p->key) p->right = insertNode(p->right, x);
	// 중복되는 노드가 있는 경우 (x == p->key)
	else printf("\n 이미 같은 키가 있습니다.\n");

	return p;
}

// 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key))	// 삭제할 노드의 위치 탐색
	{
		parent = p;
		if (key < p->key)p = p->left;
		else p = p->right;
	}

	// 삭제할 노드가 없는 경우
	if (p == NULL)
	{
		printf("\n 찾는 키가 이진트리에 없습니다.\n");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우 -> 문제 없음
	if ((p->left == NULL) && (p->right == NULL))
	{
		if (parent != NULL)
		{
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// 삭제할 노드가 자식 노드를 한개 가진 경우
	else if ((p->left == NULL) || (p->right == NULL))
	{
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL)
		{
			if (parent->left == p) parent->left = child;	// p의 자리를 child가 차지
			else parent->right = child;
		}
		else root = child;
	}

	// 삭제할 노드가 자식 노드를 두개 가진 경우
	else
	{
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL)	// 왼쪽 서브트리에서 후계자 찾기
		{
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode* root)
{
	if (root)
	{
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}

int main()
{
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;

	//searchBST(root, 'k');

	root = insertNode(root, 'a');
	insertNode(root, 'b');
	insertNode(root, 'c');
	insertNode(root, 'd');	
	insertNode(root, 'e');	// 이진트리는 중복이 있을수 없음
	insertNode(root, 'f');
	insertNode(root, 'g');
	insertNode(root, 'h');

	deleteNode(root, 'b');
	deleteNode(root, 'b');

	displayInorder(root);

	return 0;
}

