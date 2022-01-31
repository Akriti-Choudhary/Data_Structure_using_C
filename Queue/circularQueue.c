/*Problem in Display part*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct
{
    int data[MAX];
    int f;
    int R;
} CQueue;

void init(CQueue *q)
{
    q->R = q->f = -1;
}

int insert(CQueue *q, int v)
{
    if (q->f == (q->R + 1) % MAX)
    {
        return 0;
    }
    if (q->R == -1)
    {
        q->f = q->R = 0;
        q->data[q->R] = v;
    }
    else
    {
        q->R = (q->R + 1) % MAX;
        q->data[q->R] = v;
    }
    return 1;
}

int del(CQueue *q, int *d)
{
    if (q->f == -1)
        return 0;
    if (q->f == q->R)
    {
        *d = q->data[q->f];
        q->f = q->R = -1;
    }
    else
    {
        *d = q->data[q->f];
        q->f = (q->f + 1) % MAX;
    }
    return 1;
}

void display(CQueue q)
{
    puts("The elements present in the Queue are : ");
    if ((q.f == -1) && (q.R == -1))
    {
        puts("Queue is empty");
    }
    else
    {
        int i = q.f;
        if (q.f <= q.R)
        {
            while (i <= q.R)
            {
                printf("%d ", q.data[i]);
                i++;
            }
            puts(" ");
        }
        else
        {
            while (i < MAX)
            {
                printf("%d ", q.data[i]);
                i++;
            }
            i = 0;
            while (i <= q.R)
            {
                printf("%d ", q.data[i]);
                i++;
            }
            puts(" ");
        }
    }
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

    return 0;
}