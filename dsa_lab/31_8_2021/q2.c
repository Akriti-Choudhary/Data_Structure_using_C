#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} * head, *last;

void createList(int n);

void displayListFromEnd();

int main()
{
    int n, choice;

    head = NULL;
    last = NULL;

    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    createList(n);

    printf("Printing list from End : ");

    displayListFromEnd();

    return 0;
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if (head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            for (i = 2; i <= n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if (newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last;
                    newNode->next = NULL;

                    last->next = newNode;
                    last = newNode;
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}

void displayListFromEnd()
{
    struct node *temp;
    int n = 0;

    if (last == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = last;
        puts("");
        while (temp != NULL)
        {
            printf("node %d = %d\n", n, temp->data);

            n++;

            temp = temp->prev;
        }
    }
}