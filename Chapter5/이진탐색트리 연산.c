/*
	����Ʈ���� ��Ģ
		: �θ��� �������� �������δ� ������, �����ʿ��� ū��
	����Ʈ���� ������ȸ�� ����ϸ� ���ĵ� ���·� ���
*/

#include<stdio.h>
#include<stdlib.h>

typedef char element;		// ���� Ž�� Ʈ�� element�� �ڷ����� char�� ����
typedef struct treeNode
{
	char key;				// ������ �ʵ�
	struct treeNode* left;	// ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;	// ������ ���� Ʈ�� ��ũ �ʵ�
}treeNode;

// ���� Ž�� Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� ����
treeNode* searchBST(treeNode* root, char x)
{
	if (root == NULL) printf("\n������ ��尡 �����ϴ�.\n");
	else
	{
		treeNode* p = root;
		while (p != NULL)
		{
			if (x < p->key) p = p->left;
			else if (x == p->key) return p;
			else p = p->right;
		}
		printf("\n ã�� Ű�� �����ϴ�.\n");
		return p;
	}
}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
treeNode* insertNode(treeNode* p, char x)
{
	treeNode* newNode;

	// root��带 �����Ҷ�
	if (p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));

		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	// root���� ���� ���̸� ���� ��忡
	else if (x < p->key) p->left = insertNode(p->left, x);
	// root���� ū ���̸� ������ ��忡
	else if (x > p->key) p->right = insertNode(p->right, x);
	// �ߺ��Ǵ� ��尡 �ִ� ��� (x == p->key)
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�.\n");

	return p;
}

// ��Ʈ ������ Ž���Ͽ� Ű���� ���� ��带 ã�� �����ϴ� ����
void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key))	// ������ ����� ��ġ Ž��
	{
		parent = p;
		if (key < p->key)p = p->left;
		else p = p->right;
	}

	// ������ ��尡 ���� ���
	if (p == NULL)
	{
		printf("\n ã�� Ű�� ����Ʈ���� �����ϴ�.\n");
		return;
	}

	// ������ ��尡 �ܸ� ����� ��� -> ���� ����
	if ((p->left == NULL) && (p->right == NULL))
	{
		if (parent != NULL)
		{
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// ������ ��尡 �ڽ� ��带 �Ѱ� ���� ���
	else if ((p->left == NULL) || (p->right == NULL))
	{
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL)
		{
			if (parent->left == p) parent->left = child;	// p�� �ڸ��� child�� ����
			else parent->right = child;
		}
		else root = child;
	}

	// ������ ��尡 �ڽ� ��带 �ΰ� ���� ���
	else
	{
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL)	// ���� ����Ʈ������ �İ��� ã��
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

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
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
	insertNode(root, 'e');	// ����Ʈ���� �ߺ��� ������ ����
	insertNode(root, 'f');
	insertNode(root, 'g');
	insertNode(root, 'h');

	deleteNode(root, 'b');
	deleteNode(root, 'b');

	displayInorder(root);

	return 0;
}

