#include<stdio.h>
#include<stdlib.h>

int main()
{

    int val,x,choice = 1;
    struct Node *start,*newnode,*temp,*end,*temp1;
    struct Node
{
    int data;
    struct Node *next;
};

void create(int data)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = NULL;
        start = newnode;
    }

    void insertAtTheBeginning(int data)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = start;
        start = newnode;
    }

    void insertAtTheEnd(int data)
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        end = temp;
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = NULL;
        end->next = newnode;
        end = newnode;
    }

    void insertAtTheMiddle(int data, int value)
    {
        temp = start;
        while(temp->data != value)
        {
            temp = temp->next;
        }
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deleteAtTheBeginning()
    {
        temp = start;
        start = start->next;
        free(temp);
    }

    void deleteAtTheEnd()
    {
        temp = start;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        end = temp;
        temp=temp->next;
        end->next = NULL;
        free(temp);
        
    }

    void deleteAtTheMiddle(int value)
    {
        temp = start;
        temp1 = start;
        while(temp->data != value)
        {
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp1 = temp1->next;
        temp->next = temp1->next;
        free(temp1);
    }

    void display()
    {
        temp = start;
        printf("\nYour Linked list is :\n");
        while(temp != NULL)
        {
            printf("|%d|",temp->data);
            printf("-->");
            temp = temp->next;
        }
        printf("\n");
    }


    while(choice)
    {
        printf("\nEnter your choice.\n1 --> To create the first node\n2 --> Insert at the end\n3 --> Insert at the middle\n4 --> Insert at the start\n5 --> Delete at the end\n6 --> Delete at the beginning\n7 --> Delete at the middle\n8 --> Display\n9 --> exit\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                create(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&val);
                insertAtTheEnd(val);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d",&val);
                printf("After which value do you want to enter the new node: ");
                scanf("%d",&x);
                insertAtTheMiddle(val,x);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d",&val);
                insertAtTheBeginning(val);
                break;

            case 5:
                deleteAtTheEnd();
                break; 
            case 6:
                deleteAtTheBeginning();
                break;
            case 7:
                printf("After which value do you want to delete the node: ");
                scanf("%d",&val);
                deleteAtTheMiddle(val);
                break;
            case 8:
                display();
                break;
            case 9:
                choice=0;
                break; 

            default:
                choice = 0;
                break;
                         
        }
    }
    
}
