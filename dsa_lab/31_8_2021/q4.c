#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *nextptr;
} * startnode;

void create(int n);
void display();

int main()
{
    int n;
    startnode = NULL;

    printf(" Input the number of nodes : ");
    scanf("%d", &n);

    create(n);
    display();
    return 0;
}

void create(int n)
{
    int i, value;
    struct node *preptr, *newnode;

    if (n >= 1)
    {
        startnode = (struct node *)malloc(sizeof(struct node));

        printf(" Input data for node 1 : ");
        scanf("%d", &value);
        startnode->value = value;
        startnode->nextptr = NULL;
        preptr = startnode;
        for (i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf("%d", &value);
            newnode->value = value;
            newnode->nextptr = NULL;
            preptr->nextptr = newnode;
            preptr = newnode;
        }
        preptr->nextptr = startnode;
    }
}

void display()
{
    struct node *tmp;
    int n = 1;

    if (startnode == NULL)
    {
        printf(" No data found in the List yet.\n");
    }
    else
    {
        tmp = startnode;
        printf(" Displaying the list\n");

        do
        {
            printf(" Data %d = %d\n", n, tmp->value);

            tmp = tmp->nextptr;
            n++;
        } while (tmp != startnode);
    }
}