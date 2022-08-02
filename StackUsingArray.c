#include<stdio.h>

int main()
{
    int max,a;
    printf("Enter the size of the array");
    scanf("%d",&max);
    int arr[max];
    int top=-1;

    int isFull()
    {
        if(top == max-1)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }

    int isEmpty()
    {
        if(top == -1)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    void push(int x)
    {
        
        if(isFull())
        {
            printf("Stack overflow\n");
        }
        else 
        {
            top++;
            arr[top] = x;
        }
    }

    void pop()
    {
        
        if(isEmpty())
        {
            printf("Stack underflow\n");
        }
        else
        {
            printf("The deleted element is %d\n",arr[top]);
            top--;
        }
    }

    void display()
    {
        
        if (isEmpty())
        {
            printf("Empty Array\n");
        }
        
        else{
            for(int i =top;i>-1;i--)
        {
            printf("%d  ",arr[i]);
            
        }
        printf("\n");
        }
       
    }

    int choice;
    
    while (1)
    {
        printf("Enter the choice\n1.Push\n2.Pop\n3.Display\n4.isFull\n5.isEmpty\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter the number: ");
            scanf("%d",&a);
            push(a);
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            if (isFull())
            {
                printf("Stack is full!!!\n");
            }

            else{
                printf("Stack is not full!!\n");
            }
            break;

            case 5:
            if (isEmpty())
            {
                printf("Stack is empty!!!");
            }

            else{
                printf("Stack is not empty!!");
            }
            break;

            default:
            printf("Enter a valid number!!\n");
            break;

        }       
    }
    
    
}