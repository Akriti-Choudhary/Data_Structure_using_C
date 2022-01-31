#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int front;
    int rear;
    int data[];
} Queue;
int insert(Queue *q, int v)
{
    if (q->rear == -1)
    {
        q->front = q->rear = 0;
        q->data[q->rear] = v;
    }
    else
    {
        q->data[++(q->rear)] = v;
    }
    return 0;
}
int del (Queue *q, int *d)
{
    if (q->front == -1)
    {
        printf("Queue is empty");
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
        q->front++;
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
    }
}
int main()
{
    struct Queue *data = malloc(sizeof(int));
    Queue q1;
    int d, k, c;
    init(&q1);
    do
    {
        printf("1 - insert an element in the queue\n");
        printf("2 - delete an element from the queue\n");
        printf("3 - traverse the stack\n");
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
                printf("number is inserted in the queue\n");
            break;
        }
        case 2:
        {
            k = del (&q1, &d);
            if (k == 0)
                printf("%d is deleted from the queue\n", d);
            break;
        }
        case 3:
        {
            traverse(&q1);
            break;
        }
        case 4:
            break;
        }
    } while (c != 4);
}