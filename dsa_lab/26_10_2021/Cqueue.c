#include <stdio.h>
#define MAX 5
typedef struct
{
    int data[MAX];
    int f;
    int R;
} Cqueue;

void init(Cqueue *q1);
int insert(Cqueue *q, int v);
int del(Cqueue *q, int *d);

int main()
{
    int ch = 0;
    while (ch != 4)
    {
        puts("Enter your choice");
        puts("1 - Insert");
        puts("2 - Delete");
        puts("3 - Display");
        puts("4 - Exit");
        scanf("%d", &ch);

        Cqueue q1;
        init(&q1);
        switch (ch)
        {
        case 1:
        {
            int val;
            puts("Enter the value to be inserted");
            scanf("%d", &val);
            int k = insert(&q1, val);
            if (k == 1)
            {
                puts("Queue overflow");
            }
            else
            {
                puts("Value is inserted in queue");
            }
            break;
        }

        case 2:
        {
            int d = 0;
            int p = del(&q1, &d);
            if (p == 1)
            {
                puts("Queue underflow");
            }
            else
            {
                puts("Value is deleted from the queue");
            }
            break;
        }
        case 3:
        {
        }
        case 4:
        {
            puts("Program Terminated");
            break;
        }
        default:
        {
            puts("Invalid choice");
            break;
        }
        }
    }
    return 0;
}

void init(Cqueue *q1)
{
    q1->f = -1;
    q1->R = -1;
}

int insert(Cqueue *q, int v)
{
    if (q->f == (q->R + 1) % MAX)
        return 1;
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
    return 0;
}

int del(Cqueue *q, int *d)
{
    if (q->f == -1)
        return 1;
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
}