#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *start,*end,*temp,*newnode,*temp1;
    start = NULL;
    int val,pos,choice = 1;

    void insertAtTheEnd(int data)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        end->next = newnode;
        end = newnode;
        end->next = start;
    }

    void create(int data)
    {
        if(start ==  NULL)
        {
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = data;
            start=newnode;
            end = newnode;
            end->next = start;   
        }
        else
        {
            printf("Head node already created !!!");
        }      
    }

    void insertAtTheBeginning(int data)
    {
        if(start == NULL)
        {
            create(data);
        }
        else
        {
            temp = end;
            newnode = (struct Node*)malloc(sizeof(struct Node));
            newnode->data = data;
            temp->next = newnode;
            newnode->next = start;
            start = newnode;
        }
    }

    void insertAtTheMiddle(int data,int pos)
    {
        int count =0;
        temp = start;
        while(temp->next != start)
        {
            temp = temp->next;
            count++;
        }
        
        if(pos<count+1)
        {
            if(pos==0)
            {
                insertAtTheBeginning(data);
            }

            else if(pos == count)
            {
                insertAtTheEnd(data);
            }

            else
            {
                temp = start;
                for(int i = 0; i<pos-1;i++)
                {
                    temp = temp->next;
                }
                newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->data = data;
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }

        else
        {
            printf("There are not as many nodes as your position.\n\n");
        }
    }

    void deleteAtTheEnd()
    {
        temp = start;
        while(temp->next->next!=start)
        {
            temp=temp->next;
        }
        end = temp;
        free(end->next);
        end->next = start;
    }

    void deleteAtTheBeginning()
    {
        temp = start;
        end->next = temp->next;
        start = start->next;
        free(temp);        
    }

    void deleteAtTheMiddle(int pos)
    {
        int count =0;
        temp = start;
        while(temp->next != start)
        {
            temp = temp->next;
            count++;
        }
        
        if(pos < count+1)
        {
            temp = start;
            for(int i = 0; i<pos-1;i++)
            {
                temp = temp->next;
            }
            temp1 = temp;
            temp->next = temp->next->next;
        }
        else
        {
            printf("There are not as many nodes as your position.\n\n");
        }
    }

    void display()
    {
        temp = start;
        printf("Your Circular Linked List is :\n");
        while(temp->next!=start)
        {
            printf("%d ----> ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
        printf("\n\n");
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