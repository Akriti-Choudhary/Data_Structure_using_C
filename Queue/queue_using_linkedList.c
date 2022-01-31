#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct
{
    struct node *front;
    struct node *rear;
} QUEUE;

void init(QUEUE *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int insert(QUEUE *q, int v)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    if (cur == NULL)
    {
        return 0;
    }
    cur->data = v;
    cur->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = cur;
    }
    else
    {
        q->rear->next = cur;
        q->rear = cur;
    }
    return 1;
}

int del(QUEUE *q, int *val)
{
    if (q->front == NULL)
    {
        puts("The list is empty");
        return 0;
    }
    if (q->front == q->rear)
    {
        *val = q->front->data;
        free(q->front);
        init(q);
        return 1;
    }
    else
    {
        *val = q->rear->data;
        struct node *ptr = q->front->next;
        free(q->front);
        q->front = ptr;
        return 1;
    }
}

void display(QUEUE q)
{
    struct node *ptr;
    for (ptr = q.front; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    puts(" ");
}

void empty(QUEUE *q)
{
    struct node *ptr, *cur;
    for (cur = q->front; cur != NULL;)
    {
        ptr = cur->next;
        free(cur);
        cur = ptr;
    }
    puts("The list is deleted");
}

int main()
{
    QUEUE q;

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