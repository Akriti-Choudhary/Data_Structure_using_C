#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **h, int pos, int val);
void display(struct node *h);
void deletePosition(struct node **h, int pos);
void deleteValue(struct node **h, int val);

int main()
{
    struct node *head = NULL;
    int pos = 0, val = 0;
    int choice = 0;
    puts("Single Circular Linked List main execution begins :");
    while (choice != 5)
    {
        puts("Enter choice :");
        puts("1 - Insert\n2 - Display\n3 - Delete according to the entered position");
        puts("4 - Delete according to the entered value\n5 - Exit  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            puts("Enter the position for insertion");
            scanf("%d", &pos);
            puts("Enter the value to be inserted");
            scanf("%d", &val);
            insert(&head, pos, val);
            break;
        case 2:
            display(head);
            break;
        case 3:
            puts("Enter the position for deletion");
            scanf("%d", &pos);
            deletePosition(&head, pos);
            break;
        case 4:
            puts("Enter the value to be deleted");
            scanf("%d", &val);
            deleteValue(&head, val);
            break;
        case 5:
            puts("_______________________ Program Terminated ______________________");
            break;
        default:
            puts("Invalid choice");
        }
    }
    puts("Single Circular Linked List main execution ends :");
    return 0;
}
void insert(struct node **h, int pos, int val)
{
    struct node *cur, *tmp = *h;
    cur = (struct node *)malloc(sizeof(struct node));
    cur->data = val;
    cur->next = NULL;
    if (*h == NULL)
    {
        *h = cur;
        cur->next = *h;
    }
    else if (pos == 0)
    {
        while (tmp->next != *h)
        {
            tmp = tmp->next;
        }
        cur->next = *h;
        *h = cur;
        tmp->next = cur;
    }
    else
    {
        int i = 0;
        while (i < pos - 1) /*if the user enters position which is greater than number of nodes then insert in a circular fashion*/
        {
            tmp = tmp->next;
            i++;
        }
        cur->next = tmp->next;
        tmp->next = cur;
    }
}
void display(struct node *h)
{
    struct node *tmp = h;
    int i = 1;
    if (h == NULL)
    {
        puts("The list is empty");
    }
    else
    {
        do
        {
            printf("Data at node%d = %d\n", i, tmp->data);
            tmp = tmp->next;
            i++;
        } while (tmp != h);
    }
}
void deletePosition(struct node **h, int pos)
{
    struct node *cur = *h, *tmp = *h;
    if (*h == NULL)
    {
        puts("The list is empty");
    }
    else if ((*h)->next == *h)
    {
        free(*h);
        *h = NULL;
    }
    else
    {
        while (cur->next != *h)
        {
            tmp = cur;
            cur = cur->next;
        }
        tmp->next = cur->next;
        free(cur);
    }
}
void deleteValue(struct node **h, int val)
{
    struct node *ptr, *prv;
    if (*h == NULL)
    {
        puts("The list is empty");
    }
    else
    {
        ptr = *h;
        while (ptr->data != val && ptr->next != *h)
        {
            prv = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == *h && ptr->data != val)
        {
            puts("Data not found");
        }
        else if ((*h)->next == *h)
        {
            *h = NULL;
            free(ptr);
        }
        else if (ptr == *h)
        {
            struct node *tmp = *h;
            while (tmp->next != *h)
            {
                tmp = tmp->next;
            }
            *h = ptr->next;
            tmp->next = *h;
            free(ptr);
        }
        else
        {
            prv->next = ptr->next;
            free(ptr);
        }
    }
}