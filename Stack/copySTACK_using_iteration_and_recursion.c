#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct
{
    struct node *top;
} STACK;

void init(STACK *s);
int push(STACK *s, int val);
int pop(STACK *s, int *val);
void display(STACK s);
void copy(STACK *s, STACK *R);
void copyRec(STACK *s, STACK *R);
int isEmpty(STACK *s);

int main()
{
    STACK s;
    init(&s);

    int ch = 0;

    while (ch != 6)
    {
        puts("1 - push \n2 - pop \n3 - display\n4 - copy in the new stack(using iteration)\n5 - copy in the new stack(using recursion)\n6 - exit");
        puts("Enter choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            puts("Enter an element to push in the stack");
            int val;
            scanf("%d", &val);
            int k;
            k = push(&s, val);
            if (k == 0)
            {
                puts("Element was not pushed in the stack");
            }
            else
            {
                puts("Element was pushed in the stack");
            }
            break;
        }
        case 2:
        {
            int d;
            int k;
            k = pop(&s, &d);
            if (k == 0)
            {
                puts("Element was not poped from the stack");
            }
            else
            {
                printf("%d was poped from the stack\n", d);
            }
            break;
        }
        case 3:
        {
            display(s);
            break;
        }
        case 4:
        {
            STACK R;
            init(&R);
            copy(&s, &R);
            puts("Displaying the copied stack");
            display(R);
            break;
        }
        case 5:
        {
            STACK R;
            init(&R);
            copyRec(&s, &R);
            puts("Displaying the copied stack(using recursion)");
            display(R);
            break;
        }
        case 6:
        {
            puts("------Exit---------");
            break;
        }
        default:
        {
            puts("Wrong input");
        }
        }
    }

    return 0;
}

void init(STACK *s)
{
    s->top = NULL;
}

int push(STACK *s, int val)
{
    struct node *cur;
    cur = (struct node *)malloc(sizeof(struct node));

    if (cur == NULL)
    {
        puts("Overflow");
        return 0;
    }
    else
    {
        cur->data = val;
        cur->next = s->top;
        s->top = cur;

        return 1;
    }
}

int pop(STACK *s, int *val)
{

    if (s->top == NULL)
    {
        puts("Underflow");
        return 0;
    }
    else
    {
        struct node *ptr;
        ptr = s->top;
        *val = ptr->data;
        s->top = s->top->next;
        free(ptr);
        ptr = NULL;

        return 1;
    }
}

void display(STACK s)
{
    struct node *ptr;
    ptr = s.top;
    if (ptr == NULL)
    {
        puts("Stack is empty");
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    puts(" ");
}

void copy(STACK *s, STACK *R)
{
    STACK s2;
    int d;
    init(&s2);
    while (!isEmpty(s))
    {
        pop(s, &d);
        push(&s2, d);
    }
    while (!isEmpty(&s2))
    {
        pop(&s2, &d);
        push(R, d);
        push(s, d);
    }
}

int isEmpty(STACK *s)
{
    if (s->top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void copyRec(STACK *s, STACK *R)
{
    int d;
    if (!isEmpty(s))
    {
        pop(s, &d);
        copyRec(s, R);
        push(R, d);
    }
}