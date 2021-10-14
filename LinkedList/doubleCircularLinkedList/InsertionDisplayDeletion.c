#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void insertion(struct node **h, int value, int position)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));
    cur->data = value;
    cur->next = NULL;
    cur->prev = NULL;

    if (*h == NULL)
    {
        *h = cur->prev = cur->next = cur;
    }
    else if (position == 0)
    {
        cur->next = *h;
        cur->prev = (*h)->prev;
        (*h)->prev = cur;
        cur->prev->next = cur;
        *h = cur;
    }
    else
    {
        struct node *ptr = (*h)->next;
        int i = 0;
        while (i < position - 1)
        {
            ptr = ptr->next;
            i++;
        }
        if (ptr->next == *h)
        {
            cur->prev = (*h)->prev;
            cur->next = *h;
            cur->prev->next = cur;
            (*h)->prev = cur;
        }
        else
        {
            cur->prev = ptr;
            cur->next = ptr->next;
            ptr->next = cur;
            cur->next->prev = cur;
        }
    }
}

void DeletionPos(struct node **h, int position)
{
}
void DeletionVal(struct node **h, int value)
{
}
void Display(struct node *h)
{
    struct node *tmp = h;
    int i = 0;
    if (h == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        do
        {
            i++;
            printf("Data of node %d = %d\n", i, tmp->data);
            tmp = tmp->next;
        } while (tmp != h);
    }
}
int main()
{
    struct node *head = NULL;
    int value;
    int position;

    int choice = 0;
    while (choice != 5)
    {
        puts("Enter choice :");
        puts("1 - Insert\n2 - Display\n3 - Delete according to the entered position");
        puts("4 - Delete according to the entered value\n5 - Exit  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            puts("Enter the value to be inserted");
            scanf("%d", &value);
            puts("Enter the position at which the node needs to get inserted");
            scanf("%d", &position);
            insertion(&head, value, position);
            break;
        case 2:
            Display(head);
            break;
        case 3:
            puts("Enter the position after which the node is to be deleted");
            scanf("%d", &position);
            DeletionPos(&head, position);
            break;
        case 4:
            puts("Enter the value to be deleted");
            scanf("%d", &value);
            DeletionVal(&head, value);
            break;
        case 5:
            puts("________________________Program Terminated_______________________");
            break;
        default:
            puts("Invalid Input");
            break;
        }
    }
    return 0;
}