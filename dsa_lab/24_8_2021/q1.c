//to create n nodes
//display the data of each node
//display in reverse order using recursion
//to print mth node from the last of a linked list of n nodes.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nextPtr;
} * startPtr, *nextNode;

void createList(int n);                 //to create n nodes
void displayList(int n);                //traverse and display the list in forward manner
void revDispRec(struct node *startPtr); //to display list in reverse order using recursion
void LastDispM(int n, int m);           //to print mth node from the last of a linked list of n nodes.

int main()
{
    startPtr = NULL;
    nextNode = NULL;
    int n, m;
    printf("Enter the number of nodes to be created : ");
    scanf("%d", &n);

    createList(n);
    puts("Printing in forward manner :");
    displayList(n);
    puts("Printing in reverse order :");
    revDispRec(startPtr);
    printf("Enter the index of node from the last to be displayed : ");
    scanf("%d", &m);
    LastDispM(n, m);

    free(startPtr);
    free(nextNode);
    puts("The memory has been freed successfully");
    return 0;
}
void createList(int n)
{
    struct node *temp;

    startPtr = (struct node *)malloc(sizeof(struct node));
    if (startPtr == NULL)
    {
        puts("Memory is not allocated");
    }
    else
    {
        puts("Enter data in the node 1");
        scanf("%d", &startPtr->data);
        startPtr->nextPtr = NULL;
        temp = startPtr;

        for (int i = 2; i <= n; ++i)
        {
            nextNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data in the node : %d \n", i);
            scanf("%d", &nextNode->data);
            nextNode->nextPtr = NULL;
            temp->nextPtr = nextNode;
            temp = nextNode;
        }
    }
}
void displayList(int n)
{
    struct node *temp = startPtr;
    if (startPtr == NULL)
    {
        puts("The list is empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Data : %d \n", temp->data);
            printf("address of the next node : %p \n" ,temp->nextPtr);
            temp = temp->nextPtr;
        }
    }
}
void revDispRec(struct node *startPtr)
{
    struct node *temp = startPtr;

    if (temp == NULL)
    {
        return;
    }
    else
    {
        revDispRec(temp->nextPtr);
        printf("Data = %d \n", temp->data);
    }
}
void LastDispM(int n, int m)
{
    struct node *temp = startPtr;
    int count = 0;
    if (startPtr == NULL)
    {
        puts("The list is empty");
    }
    else
    {
        while (temp != NULL)
        {
            count++;
            if (count == (n - m + 1))
            {
                printf("Data : %d \n", temp->data);
                break;
            }
            temp = temp->nextPtr;
        }
    }
}