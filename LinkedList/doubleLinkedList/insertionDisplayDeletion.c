#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prv;
    struct node *next;
};

void insert(struct node **h, int pos, int val);
void display(struct node *h);
void displayReverse(struct node *h);
void deletion(struct node **h, int val);

int main()
{
    struct node *head = NULL;
    int choice = 0;
    int position, val;
    while (choice != 5)
    {
        puts("Enter choice");
        puts("1 - Insertion\n2 - Display\n3 - Display in Reverse format");
        puts("4 - Deletion\n5 - Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            puts("Enter the position for insertion of node :");
            scanf("%d", &position);
            puts("Enter the value for the node to be inserted :");
            scanf("%d", &val);
            insert(&head, position, val);
            break;
        case 2:
            puts("Displaying the list in forward manner");
            display(head);
            break;
        case 3:
            puts("Displaying the list in reverse manner");
            displayReverse(head);
            break;
        case 4:
            puts("Enter the value for deletion of node :");
            scanf("%d", &val);
            deletion(&head, val);
            break;
        case 5:
            puts("******************************** Program Terminated ************************************");
            break;
        default:
            puts("Invalid Input");
            break;
        }
    }
    return 0;
}
void insert(struct node **h, int pos, int val)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));
    cur->data = val;
    cur->next = cur->prv = NULL;
    if (*h == NULL)
    {
        *h = cur;
    }
    else if (pos == 0)
    {
        cur->next = *h;
        (*h)->prv = cur;
        *h = cur;
    }
    else
    {
        struct node *tmp;
        tmp = *h;
        int i = 0;
        while ((i < pos - 1) && (tmp->next != NULL))
        {
            ++i;
            tmp = tmp->next;
        }
        if (tmp->next == NULL)
        {
            cur->prv = tmp;
            tmp->next = cur;
        }
        else
        {
            cur->next = tmp->next;
            cur->prv = tmp;
            tmp->next = cur;
            cur->next->prv = cur;
        }
    }
}

void display(struct node *h)
{
    struct node *tmp = h;
    int i = 0;
    if (h == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while (tmp != NULL)
        {
            i++;
            printf("Data of node %d = %d\n", i, tmp->data);
            tmp = tmp->next;
        }
    }
}

void displayReverse(struct node *h)
{
    struct node *tmp = h;
    int i = 0;
    if (h == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while (tmp->next != NULL)
        {
            i++;
            tmp = tmp->next;
        }
        do
        {
            printf("Data of node%d = %d\n", i+1, tmp->data);
            i--;
            tmp = tmp->prv;
        } while (tmp != NULL);
    }
}

void deletion(struct node **h, int val)
{
    struct node *ptr;
    if (*h == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        ptr = *h;
        while (ptr != NULL)
        {
            if (ptr->data == val)
                break;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            puts("Data not found");
        }
        else if (*h == ptr && ptr->next == NULL)
        {
            *h = NULL;
            free(ptr);
        }
        else if (*h == ptr)
        {
            *h = (*h)->next;
            (*h)->prv = NULL;
            free(ptr);
        }
        else if (ptr->next == NULL)
        {
            ptr->prv->next = NULL;
            free(ptr);
        }
        else
        {
            ptr->prv->next = ptr->next;
            ptr->next->prv = ptr->prv;
            free(ptr);
        }
    }
}