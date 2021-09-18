//to create n nodes , display the data of each node and also display in reverse order using recursion
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

int main()
{
    startPtr = NULL;
    nextNode = NULL;
    int n;
    printf("Enter the number of nodes to be created : ");
    scanf("%d", &n);

    createList(n);
    puts("Printing in forward manner :");
    displayList(n);
    puts("Printing in reverse order :");
    revDispRec(startPtr);

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
