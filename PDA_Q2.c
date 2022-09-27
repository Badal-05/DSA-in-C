

/*
Write a program to count the number of leaf nodes in the given binary tree

Note :  The elements are stored in a one dimensional array in the following manner.  Blank cells indicate that the respective child( Left or Right ) is not present in the binary tree 

A B C D _ E F _ G _ _ _ H
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[] = {'A', 'B', 'C', 'D', ' ', 'E', 'F', ' ', 'G', ' ', ' ', ' ', 'H'};
    int n = 13;
    printf("The leaf nodes are");
    for(int i=0;i<n;i++)
    {
        if(arr[i] == ' ') 
            continue;
        if(2*i+1 >= n && 2*i+2>=n) 
        {
            printf(" %c", arr[i]);
            continue;
        }
        if(2*i+1 < n && 2*i+2 >= n && arr[2*i+1] == ' ') 
        {
            printf(" %c", arr[i]); 
            continue;
        }
        if(2*i+1 < n && 2*i+2 < n && arr[2*i+1] == ' ' && arr[2*i+2] == ' ')
        { 
            printf(" %c", arr[i]); 
            continue;
        }
    }

}