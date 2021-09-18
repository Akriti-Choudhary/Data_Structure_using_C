#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void insert(struct node **h, int pos, int data);
void deletion(struct node **h, int pos);
void display(struct node *h);
int main()
{
    struct node *head = NULL;
    int choice = 0;
    int position;
    int data;

    while (choice != 4)
    {

        puts("Enter choice");
        puts("1 - Insertion\n2 - Display\n3 - Deletion\n4 - exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            puts("Enter the position for insertion of node :");
            scanf("%d", &position);
            puts("Enter the data to be stored in the node :");
            scanf("%d", &data);
            insert(&head, position, data);
            break;
        case 2:
            puts("Displaying the entire list");
            display(head);
            break;
        case 3:
            puts("Enter the position for deletion of node :");
            scanf("%d", &position);
            deletion(&head, position);
            break;
        case 4:
            puts("_____________________________ Program terminated ___________________________________");
            break;
        default:
            puts("Invalid choice");
            break;
        }
    }
    return 0;
}
void insert(struct node **h, int pos, int data)
{
    struct node *cur, *tmp;
    cur = (struct node *)malloc(sizeof(struct node));
    cur->data = data;
    cur->next = NULL;

    if (*h == NULL)
    {
        *h = cur;
    }
    else if (pos == 0)
    {
        cur->next = *h;
        *h = cur;
    }
    else
    {
        int i = 0;
        tmp = *h;
        while ((i < pos - 1) && (tmp->next != NULL))
        {
            ++i;
            tmp = tmp->next;
        }
        cur->next = tmp->next;
        tmp->next = cur;
    }
}
void deletion(struct node **h, int pos)
{
    if (*h == NULL)
    {
        puts("The list is empty");
    }
    else
    {
        struct node *prv, *ptr;
        ptr = *h;
        prv = *h;
        int i = 0;
        while ((i < pos) && (ptr->next != NULL))
        {
            ++i;
            prv = ptr;
            ptr = ptr->next;
        }
        if ((*h)->next == NULL)
        {
            free(ptr);
            *h = NULL;
        }
        else if (pos == 0)
        {
            *h = ptr->next;
            free(ptr);
        }
        else
        {
            prv->next = ptr->next;
            free(ptr);
        }
    }
}
void display(struct node *h)
{
    struct node *tmp = h;
    int i = 0;
    if (h == NULL)
    {
        puts("The list is empty");
    }
    else
    {
        while (tmp != NULL)
        {
            printf("Data at node%d = %d\n", i + 1, tmp->data);
            tmp = tmp->next;
            ++i;
        }
    }
}