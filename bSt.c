#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
 
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
int count =0;
int leafnodes(struct node* newnode)
{

    if(newnode != NULL)
    {   
        leafnodes(newnode->left);
        if((newnode->left == NULL) && (newnode->right == NULL))
        {
            count++;
            printf("%d ",newnode->key);
        }
        leafnodes(newnode->right);
    }
    return count;
 
}



struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    return node;
}
 
int main()
{
    
    struct node* root = NULL;
    int arr[12];
    for(int i = 0 ;i<12;i++)
    {
        scanf("%d",&arr[i]);
    }
    root = insert(root, arr[0]);
    for(int i = 1; i<12;i++)
    {
        insert(root,arr[i]);
    }
    int count = leafnodes(root);
    printf("\nThere are %d nodes present in the tree",count);     
    
    return 0;
}