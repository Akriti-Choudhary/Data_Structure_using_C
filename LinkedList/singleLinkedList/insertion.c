#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *nextPtr;
};

void insertFirst(struct node **sPtr, int value);    //to insert an element at the start
void insertAfter(struct node **preNode, int value); //to insert an element after a given node
void insertLast(struct node **sPtr);                //insert at last
void printList(struct node **sPtr);
int main()
{
    struct node *startPtr = NULL;

    int val, val1;
    puts("Enter the data to be inserted in the list :");
    scanf("%d", &val);
    insertFirst(&startPtr, val);
    puts("Enter the data to be inserted in the list :");
    scanf("%d", &val1);
    insertAfter(&startPtr, val1);
    insertLast(&startPtr);

    printList(&startPtr);

    return 0;
}
void insertFirst(struct node **sPtr, int value)
{
    struct node *newPtr = (struct node *)malloc(sizeof(struct node));
    if (newPtr == NULL)
    {
        puts("Memory is not allocated");
    }
    else
    {
        newPtr->data = value;
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    }
}
void insertAfter(struct node **preNode, int value)
{
    if (preNode == NULL)
    {
        puts("Previous node cannot be NULL ");
        return;
    }
    struct node *newPtr = (struct node *)malloc(sizeof(struct node));
    if (newPtr == NULL)
    {
        puts("Memory is not allocated");
    }
    else
    {
        newPtr->data = value;
        newPtr->nextPtr = (*preNode)->nextPtr;
        (*preNode)->nextPtr = newPtr;
    }
}
void insertLast(struct node **sPtr)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    puts("Enter data to be inserted in the last :");
    scanf("%d", &new_node->data);
    new_node->nextPtr = NULL;
    if (*sPtr == NULL)
    {
        *sPtr = new_node;
    }
    else
    {
        struct node *temp = (*sPtr);
        while (temp->nextPtr != NULL)
        {
            temp = temp->nextPtr;
        }
        temp->nextPtr = new_node;
    }
    return;
}

void printList(struct node **sPtr)
{
    struct node *temp = *sPtr;
    while (temp != NULL)
    {
        printf("Data = %d \n", temp->data);
        temp = temp->nextPtr;
    }
}