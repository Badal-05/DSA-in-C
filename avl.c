#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};


int max(int a, int b);


int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return 1+max(height(N->left), height(N->right));
}


int max(int a, int b)
{
	return (a > b)? a : b;
}


struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 0; 
	return(node);
}


struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	x->right = y;
	y->left = T2;


	y->height = height(y);
	x->height = height(x);

	
	return x;
}


struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	
	y->left = x;
	x->right = T2;


	x->height = height(x);
	y->height = height(y);


	return y;
}


int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


struct Node* insert(struct Node* node, int key)
{
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = height(node);

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 

struct Node* delete(struct Node* root, int key)
{
    if (root == NULL)
        return root;
 
    if ( key < root->key )
        root->left = delete(root->left, key);
 
    else if( key > root->key )
        root->right = delete(root->right, key);

    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left : root->right;
 
            
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp; 
            free(temp);
        }
        else
        {
            struct Node* temp = minValueNode(root->right);
 
            root->key = temp->key;
 
            root->right = delete(root->right, temp->key);
        }
    }
 
    
    if (root == NULL)
      return root;
 
    root->height = 1 + max(height(root->left),height(root->right));
 
    int balance = getBalance(root);
 
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 

void inOrder(struct Node *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
        printf("%d ", root->key);
		inOrder(root->right);
	}
}


int main()
{
    struct Node *root = NULL;
    char arr[100];
    scanf("%s",arr);
    root = insert(root, 35);
    root = insert(root, 56);
    root = insert(root, 62);
    root = insert(root, 23);
    root = insert(root, 31);
    root = delete(root, 62);
    root = insert(root, 47);
    root = insert(root, 48);
    root = insert(root, 12);
    root = delete(root, 47);
    root = delete(root, 56);
    root = insert(root, 50);

    inOrder(root);

    return 0;
}
