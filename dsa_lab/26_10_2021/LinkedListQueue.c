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
} Queue;
int insert(Queue *q, int v)
{
    struct node *cur = (struct node *)malloc(sizeof(struct node));
    if (cur == NULL)
    {
        return 1;
    }
    cur->data = v;
    cur->next = NULL;
    if (q->front == NULL)
    {
        q->front = q->rear = cur;
    }
    else
    {
        q->rear->next = cur;
        q->rear = cur;
    }
    return 0;
}
int del (Queue *q, int *d)
{
    if (q->front == NULL)
    {
        printf("Queue underflow\n");
        return 1;
    }
    else
    {
        struct node *temp = q->front;
        if (q->rear == q->front)
        {
            *d = q->front->data;
            q->front = NULL;
            temp == NULL;
            return 0;
        }
        else
        {
            *d = q->front->data;
            q->front = q->front->next;
            temp == NULL;
            return 0;
        }
    }
}
void init(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}
void traverse(Queue *q)
{
    struct node *temp;
    if (q->front == NULL)
        printf("queue is empty\n");
    else
    {
        printf("queue elements are:\n");
        for (temp = (q->front); temp->next != NULL; temp = temp->next)
            printf("%d\n", temp->data);
        printf("%d\n", temp->data);
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
            printf("enter the number to insert\n");
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