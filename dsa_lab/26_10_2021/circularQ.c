#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;
int insert(Queue *q, int v)
{
    if (q->front == (q->rear + 1) % MAX)
    {
        printf("Queue Overflow\n");
        return 1;
    }
    if (q->rear == -1)
    {
        q->front = q->rear = 0;
        q->data[q->rear] = v;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = v;
    }
    return 0;
}
int del (Queue *q, int *d)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    else if (q->rear == q->front)
    {
        *d = q->data[q->front];
        q->front = q->rear = -1;
        return 0;
    }
    else
    {
        *d = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        return 0;
    }
}
void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
void traverse(Queue *q)
{
    if (q->front == q->rear == -1)
        printf("queue is empty\n");
    else
    {
        printf("queue elements are:\n");
        for (int i = (q->front); i <= q->rear; i++)
            printf("%d\n", q->data[i]);
        puts(" ");
    }
}
int main()
{
    Queue q1;
    int d, k, c;
    init(&q1);
    do
    {
        printf("1 - to insert an element in the queue\n");
        printf("2 - to delete an element from the queue\n");
        printf("3 - to traverse the queue\n");
        printf("4 - quit\n");
        printf("enter your choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            int n;
            printf("enter the number you want to insert\n");
            scanf("%d", &n);
            k = insert(&q1, n);
            if (k == 0)
                printf("properly inserted\n");
            break;
        }
        case 2:
        {
            k = del (&q1, &d);
            if (k == 0)
                printf("properly deleted %d\n", d);
            break;
        }
        case 3:
        {
            traverse(&q1);
            break;
        }
        case 4:
            puts("Program Terminated");
            break;
        }
    } while (c != 4);
}