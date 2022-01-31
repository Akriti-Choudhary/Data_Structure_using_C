#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct
{
    struct node *R;
} CQueue;

void init(CQueue *q)
{
    q->R = NULL;
}

int insert(CQueue *q, int v)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));
    if (cur == NULL)
    {
        return 0;
    }
    cur->data = v;
    if (q->R == NULL)
    {
        cur->next = cur;
        q->R = cur;
    }
    else
    {
        cur->next = q->R->next;
        q->R->next = cur;
        q->R = cur;
    }
    return 0;
}

int del(CQueue *q, int *d)
{
    if (q->R == NULL)
    {
        return 1;
    }
    if (q->R->next == q->R)
    {
        *d = q->R->data;
        free(q->R);
        q->R = NULL;
    }
    else
    {
        struct node *ptr = q->R->next;
        *d = ptr->data;
        q->R->next = ptr->next;
        free(ptr);
    }
    return 1;
}

void display(CQueue q)
{
    struct node *ptr;
    for (ptr = q.R->next; ptr != q.R; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    printf("%d ", ptr->data);
    puts(" ");
}

void empty(CQueue *q)
{
    struct node *ptr, *cur;
    for (cur = q->R; cur != NULL;)
    {
        ptr = cur->next;
        free(cur);
        cur = ptr;
    }
    puts("The list is deleted");
}

int main()
{
    CQueue q;

    init(&q);
    int val, k;
    int v, p;
    int ch = -1;
    while (ch != 4)
    {
        puts("Enter choice :");
        puts("1 - Insertion\n2 - Deletion \n3 - Display \n4 - Exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            puts("Enter the value to be pushed");
            scanf(" %d", &val);
            k = insert(&q, val);
            if (k == 1)
            {
                printf("%d is inserted in the queue\n", val);
            }
            break;

        case 2:

            p = del(&q, &val);
            if (p == 1)
            {
                printf("%d is deleted from the queue\n", val);
            }
            break;

        case 3:
            display(q);
            break;

        case 4:
            puts("EXIT");
            break;

        default:
            puts("Wrong choice");
            break;
        }
    }
    empty(&q);

    return 0;
}