#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nextPtr;
} *head = NULL, *temp = NULL;
//for inserting a node
void insert()
{
    if (temp == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
            puts("Memory is not allocated");
        }
        else
        {
            puts("Enter data :");
            scanf("%d", head->data);
            head->nextPtr = NULL;
        }
    }
    else
    {
        struct node *nextNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data in the node :\n");
        scanf("%d", &nextNode->data);
        nextNode->nextPtr = NULL;
        temp->nextPtr = nextNode;
        temp = nextNode;
    }
}
//for displaying the list
void traverse()
{
    struct node *newTemp = head;
    while (newTemp != NULL)
    {
        printf("Data : %d \n", temp->data);
        newTemp = newTemp->nextPtr;
    }
}
//check for empty list
void isEmpty()
{
    if (head == NULL)
    {
        puts("The list is empty");
    }
    else
        puts("The list is not empty");
}
//for deleting the node
void Delete()
{
    struct node *newTemp = head;
    struct node *prev;
    if (temp == head)
    {
        free(head);
        temp = NULL;
        return;
    }
    while (newTemp->nextPtr != NULL)
    {
        prev->nextPtr = newTemp;
        newTemp = newTemp->nextPtr;
    }
    free(newTemp);
    temp = prev;
}
//delete a node from a given link
void deleteNodeKey(int key)
{
    struct node *newTemp = head;
    struct node *prev;

    if (newTemp != NULL && newTemp->data == key)
    {
        head = newTemp->nextPtr;
        free(newTemp);
        return;
    }
    while (newTemp != NULL && newTemp->data != key)
    {
        prev = newTemp;
        newTemp = newTemp->nextPtr;
    }
    if (newTemp == NULL)
        return;

    prev->nextPtr = newTemp->nextPtr;

    free(newTemp);
}
void Count()
{
    struct node *newTemp = head;
    int c = 0;
    while (newTemp != NULL)
    {
        c++;
        newTemp = newTemp->nextPtr;
    }
    printf("Total number of nodes = %c \n", c);
}
void searchElement( int key)
{
    struct node *newTemp = head;

    while (newTemp != NULL && newTemp->data != key)
    {
        newTemp = newTemp->nextPtr;
    }
    if (newTemp->data == key)
    {
        printf("key found \n");
    }
    else
        printf("key not found \n");
}
int main()
{

    //struct node *head = NULL;
    //struct node *temp = head;
    temp = head;
    int ch;
    puts("Enter choice :\n1 - to insert a node \n2 - Traversal\n3 - check for empty list");
    puts("4 - Delete a node\n5 - Delete a node from the given key\n6 - count total nodes \n7 - search element");
    puts("0 - exit");
    scanf("%d", &ch);
    while (ch)
    {
        switch (ch)
        {
        case1:
            insert();
            break;
        case2:
            traverse();
            break;
        case3:
            isEmpty();
            break;
        case4:
            Delete();
            break;
        case5:
            int key;
            puts("Enter key :");
            scanf("%d", &key);
            deleteNodeKey(key);
            break;
        case6:
            Count();
            break;
        case7:
            puts("Enter key :");
            scanf("%d", &key);
            searchElement(key);
            break;

        Default:
            puts("Invalid choice");
            break;
        }
    }
    return 0;
}