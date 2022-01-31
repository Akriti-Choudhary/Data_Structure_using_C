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
void display(STACK s);
int push(STACK *s, int val);
int pop(STACK *s, int *val);


int main()
{
    STACK s;
    init(&s);
    int ch = 0;

    while (ch != 4)
    {
        puts("1 - push \n2 - pop \n3 - display\n4 - exit");
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

void display(STACK s)
{
    struct node *ptr = s.top;
    if(ptr == NULL)
    {
        puts("The list is empty");
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    puts("");
}

int push(STACK *s, int val)
{
    struct node *cur;
    cur = (struct node *)(malloc(sizeof(struct node)));

    if (cur == NULL)
    {
        puts("OVERFLOW");
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
        puts("UNDERFLOW");
        return 0;
    }
    else
    {
        struct node *ptr;
        ptr = s->top;
        s->top = s->top->next;
        *val = ptr->data;
        free(ptr);
        ptr = NULL;

        return 1;
    }
}