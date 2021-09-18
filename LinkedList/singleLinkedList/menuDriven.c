#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

/*Traversal of the list*/
void traverse(struct node *h)
{
    if (h == NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
        while (h != NULL)
        {
            printf("Data = %d \n", h->data);
            h = h->next;
        }
    }
    puts("");
}

/*To check whether the list is empty or not*/
void isEmpty(struct node *h)
{
    if (h == NULL)
    {
        printf("\n The list is empty\n");
    }
    else
    {
        printf("\n The list is not empty\n");
    }
    puts("");
}

/*To insert a node at a given position in the list*/
void insert(struct node **h, int pos)
{
    struct node *cur = NULL;
    cur = (struct node *)malloc(sizeof(struct node));
    if (cur == NULL)
    {
        puts("Memory is not allocated");
    }
    printf("\nEnter data for the created node \n");
    scanf("%d", &cur->data);
    cur->next = NULL;

    if (*h == NULL) //to insert a node in an empty list
    {
        *h = cur;
    }
    else if (pos == 0) //to insert a node at the beginning of the list
    {
        cur->next = *h;
        *h = cur;
    }
    else
    {
        struct node *tmp = *h;
        int i = 0;
        while ((i < pos - 1) && (tmp->next != NULL))
        {
            tmp = tmp->next;
            ++i;
        }
        cur->next = tmp->next;
        tmp->next = cur;
    }
    puts("");
}

/*To delete a node at a given position from the list*/
void deleteNode(struct node **h, int pos)
{
    if (*h == NULL)
    {
        puts("The list is empty");
    }
    else if ((pos == 0) && ((*h)->next == NULL))
    {
        free(*h);
        *h = NULL;
    }

    else
    {
        struct node *tmp = *h, *cur = *h;
        int i = 0;
        while ((i <= pos - 1) && (cur->next != NULL))
        {
            ++i;
            tmp = cur;
            cur = cur->next;
        }
        if (pos == 0)
        {
            *h = cur->next;
            free(cur);
        }
        else if ((*h)->next == NULL)
        {
            free(*h);
            *h = NULL;
        }
        else
        {
            tmp->next = cur->next;
            free(cur);
        }
    }
    puts("");
}

/*Delete a node for the given key*/
void delkey(struct node **h, int val)
{
    if (*h == NULL)
    {
        puts("The list is empty");
    }
    else
    {
        struct node *tmp = *h, *cur = *h;
        while (cur != NULL)
        {
            if (cur->data == val)
                break;
            else
            {
                tmp = cur;
                cur = cur->next;
            }
        }
        if (cur == NULL)
        {
            printf("Data not found\n");
        }
        else if (cur == *h)
        {
            *h = cur->next;
            free(cur);
        }
        else
        {
            tmp->next = cur->next;
            free(cur);
        }
    }
    puts("");
}

/*Count total number of nodes*/
void countNodes(struct node *h)
{
    int count = 0;
    if (h == NULL)
    {
        puts("count of nodes present = 0");
    }
    else
    {
        while (h->next != NULL)
        {
            ++count;
            h = h->next;
        }
        printf("count of nodes present = %d \n", count + 1);
    }
}
//error
void searchEle(struct node *h, int val)
{
    while (h->next != NULL)
    {
        if (h->data != val)
        {
            puts("Data not found");
        }
        else
        {
            puts("Data is present in the list");
        }
        h = h->next;
    }
}
int main()
{
    struct node *head = NULL;
    int position;
    int value;
    int ch = 0;
    while (ch != -1)
    {
        puts("Enter the choice :");
        puts("1 - Traversal of the list\n"
             "2 - Check if the list is empty\n"
             "3 - Insert a node at the certain position (at beginning/end/any position)\n"
             "4 - Delete a node at the certain position (at beginning/end/any position)\n"
             "5 - Delete a node for the given key\n"
             "6 - Count the total number of nodes\n"
             "7 - Search for an element\n"
             "-1 - To exit");
        puts("");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            traverse(head);
            break;

        case 2:
            isEmpty(head);
            break;

        case 3:
            puts("Enter the position at which the node is to be inserted");
            scanf("%d", &position);
            insert(&head, position);
            break;
        case 4:
            puts("Enter the position at which the node is to be deleted");
            scanf("%d", &position);
            deleteNode(&head, position);
            break;
        case 5:
            puts("Enter the value for which the node is to be deleted");
            scanf("%d", &value);
            delkey(&head, value);
            break;
        case 6:
            countNodes(head);
            break;
        case 7:
            puts("Enter the value to be searched");
            scanf("%d", &value);
            searchEle(head, value);
            break;
        case -1:
            puts("-------------------------Terminated-----------------------------");
            break;
        default:
            puts("Wrong choice");
            break;
        }
    }

    return 0;
}