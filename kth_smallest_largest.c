#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;

struct Node* new_node(int x)
{
	struct Node* p = malloc(sizeof(struct Node));
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}


Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new_node(x);
	if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}


int count = 0,count1= 0;

Node* kthSmallest(Node* root, int k)
{
	if (root == NULL)
		return NULL;

	Node* left = kthSmallest(root->left, k);

	if (left != NULL)
		return left;

	count++;
	if (count == k)
		return root;

	return kthSmallest(root->right, k);
}

Node* kthLargest(Node* root, int k)
{
	if (root == NULL)
		return NULL;

	Node* right = kthLargest(root->right, k);

	if (right != NULL)
		return right;

	count1++;
	if (count1 == k)
		return root;

	return kthLargest(root->left, k);
}


void printKthSmallest(Node* root, int k,int key)
{
	Node* res = kthSmallest(root, k);
	if (res == NULL)
		printf("There are less than k nodes in the BST");
	else
		printf("%drd minimum is : %d\n",key, res->data);
}

void printKthLargest(Node* root, int k, int key)
{
	Node* res = kthLargest(root, k);
	if (res == NULL)
		printf("There are less than k nodes in the BST");
	else
		printf("%drd maximum is : %d\n",key ,res->data);
}


int main()
{
	Node* root = NULL;
	int a;

	for (int i = 0; i < 16; i++)
    {
        scanf("%d", &a);
        root = insert(root,a);
    }

	int k = 3;
	printKthSmallest(root, k, 3);
    printKthLargest(root, k, 3);
	return 0;
}
