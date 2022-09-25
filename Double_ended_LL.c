#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main()
{
    struct Node *start,*temp,*newnode,*temp1;
    int val,pos,choice =1;

    void create(int data)
    {
        if(start == NULL)
        {
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = data;
            newnode->next = NULL;
            newnode->prev = NULL;
            start = newnode;
            temp = start;
        }
        else
        {
            printf("Head node already created.");
        }
    }

    void insertAtTheEnd(int data)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode;
    }

    void insertAtTheBeginning(int data)
    {
        if(start == NULL)
        {
            create(data);
        }
        
        else
        {
            temp = start;
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = data;
            newnode->prev = NULL;
            newnode->next = start;
            start = newnode;
        }
    }

    void insertAtTheMiddle(int data,int pos)
    {
        temp = start;
        int count = 0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        
        if(pos<count)
        {
            temp = start;
        
            for(int i = 0 ; i<pos-1 ;i++)
            {
                //printf("%d ",temp->data);
                temp = temp->next;
                //printf("%d ",temp->data);
            }
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
            newnode->data = data;
        }    

        else
        {
            printf("The position you entered is out of bound.\n");
        }    
    }

    void deleteAtTheEnd()
    {
        temp = start;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        //free(temp->next);
        temp->next = NULL;
    }

    void deleteAtTheBeginning()
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        //free(temp);
    }

    void deleteAtTheMiddle(int pos)
    {
        temp = start;
        int count = 0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        
        if(pos == 0)
        {
            deleteAtTheBeginning();
        }

        else if(pos<count-1)
        {
            temp = start;
        
            for(int i = 0 ; i<pos-1 ;i++)
            {
                temp = temp->next;
            }
            temp1 = temp->next->next;
            temp->next = temp1;
            temp1->prev = temp;
            //free(temp->next);
        }    

        else
        {
            printf("The position you entered is out of bound.\n");
        }    
    }
    void display()
    {
        printf("Your Double Ended Linked List is: \n");
        temp = start;
        while(temp->next != NULL)
        {
            printf("%d ----> ",temp->data);
            temp = temp->next;
        }
        printf("%d \n\n",temp->data);

    }

    while(choice)
    {
        printf("Enter your choice.\n1. To create the head node\n2. To insert at the end\n3. To insert at the beginning \n4. To insert anywhere. (** The indexing starts from 0 **)\n5. To delete at the end\n6. To delete at the beginning\n7. To delete anywhere. (**The indexing starts from 0**)\n8. To display the Circular Linked List\n9. To exit\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter the value of head node: ");
                scanf("%d",&val);
                create(val);
                break;

            case 2:
                printf("Enter the value for subsequent node: ");
                scanf("%d",&val);
                insertAtTheEnd(val);
                break;

            case 3:
                printf("Enter the value for subsequent node: ");
                scanf("%d",&val);
                insertAtTheBeginning(val);
                break;

            case 4:
                printf("Enter the value for the next node and the position after which you want to insert: ");
                scanf("%d %d",&val,&pos);
                insertAtTheMiddle(val,pos);
                break;

            case 5:
                deleteAtTheEnd();
                break;

            case 6:
                deleteAtTheBeginning();
                break;

            case 7:
                printf("Enter the position after which you want to delete the node: ");
                scanf("%d",&pos);
                deleteAtTheMiddle(pos);
                break;

            case 8:
                display();
                break;

            case 9:
                choice = 0;
                break;

            default :
                choice = 0;
                break;
        }
    }

}