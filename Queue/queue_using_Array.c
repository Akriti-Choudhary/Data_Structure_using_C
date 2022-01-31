#include <stdio.h>
#define MAX 10
typedef struct
{
    int data[MAX];
    int rear;
    int front;

} QUEUE;

void init(QUEUE *q)
{
    q->rear = q->front = -1;
}

int insert(QUEUE *q, int val)
{
    if (q->rear == MAX - 1)
    {
        puts("Queue Overflow");
        return 0;
    }
    else if (q->rear == -1)
    {
        q->rear = q->front = 0;
        q->data[q->rear] = val;
    }
    else
    {
        q->data[++(q->rear)] = val;
    }
    return 1;
}

int del(QUEUE *q, int *v)
{
    if (q->front == -1)
    {
        puts("Queue Underflow");
        return 0;
    }
    else if (q->front == q->rear)
    {
        *v = q->data[q->front];
        q->front = q->rear = -1;
        return 1;
    }
    else
    {
        *v = q->data[q->front];
        q->front++;
        return 1;
    }
}

void display(QUEUE *q)
{
    puts("The elements present in the Queue are : ");
    if ((q->front == -1) && (q->rear == -1))
    {
        puts("Queue is empty");
    }
    else
    {
        for (int i = q->front; i <= q->rear; ++i)
        {
            printf("%d ", q->data[i]);
        }
        puts(" ");
    }
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
            display(&q);
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