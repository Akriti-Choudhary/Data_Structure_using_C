#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nextPtr;
} * stnode, *nextNode;
void createList(int n);
void reversePrintList(struct node *head);

int main()
{
    int n;
    puts("Enter the number of nodes :");
    scanf("%d", &n);

    //to create list
    createList(n);

    //to display list
    reversePrintList(stnode);

    free(stnode);
    free(nextNode);
    return 0;
}
void createList(int n)
{
    struct node *temp;
    int num, i;
    //creating 1st node
    stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode == NULL)
    {
        puts("Memory is not allocated");
    }
    else
    {
        printf("Enter data for node 1 : ");
        scanf("%d", &num);
        stnode->data = num;
        stnode->nextPtr = NULL;
        temp = stnode;

        //creating n nodes and adding to linked list

        for (i = 2; i <= n; ++i)
        {
            nextNode = (struct node *)malloc(sizeof(struct node));
            if (nextNode == NULL)
            {
                puts("Memory is not allocated");
            }
            else
            {
                printf("Enter data for node %d : ", i);
                scanf("%d", &num);
                nextNode->data = num;
                nextNode->nextPtr = NULL;
                temp = stnode;

                temp->nextPtr = nextNode;
                temp = temp->nextPtr;
            }
        }
    }
}
void reversePrintList(struct node *head)
{
    if (head == NULL)
        return;
    reversePrintList(head->nextPtr);
    printf("data = %d \n", head->data);
}