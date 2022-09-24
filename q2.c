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
 
void leafnodes(struct node* newnode)
{

    if(newnode != NULL)
    {   
        leafnodes(newnode->left);
        if((newnode->left == NULL) && (newnode->right == NULL))
        {
            printf("%d ",newnode->key);
        }
        leafnodes(newnode->right);
    }
 
}
struct node* insert(struct node* node, char key)
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
    printf("The leaf nodes are ");
    struct node* root = NULL;
    char arr[13] ={'A','B','C','D','0','E','F','0','G','0','0','0','H'} ;
    
    root = insert(root, arr[0]);
    for(int i = 1; i<13;i++)
    {
        insert(root,arr[i]);
    }

    leafnodes(root);
   
    
    return 0;
}