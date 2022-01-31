#include <stdio.h>
#define MAX 5

typedef struct
{
    int top;
    int data[MAX];
} STACK;

void init(STACK *S);
int push(STACK *S, int val);
int pop(STACK *S, int *val);

int main()
{
    STACK S;
    init(&S);
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
            k = push(&S, val);
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
            k = pop(&S, &d);
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
            if(S.top == -1)
            {
                puts("Stack is empty");
                break;
            }
            for (int i = S.top; i >= 0; --i)
            {
                printf("%d ", S.data[i]);
            }
            puts(" ");

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
void init(STACK *S)
{
    S->top = -1;
}

int push(STACK *S, int val)
{
    if (S->top == MAX - 1)
    {
        puts("Stack Overflow");
        return 0;
    }
    else
    {
        S->top++;
        S->data[S->top] = val;
        return 1;
    }
}

int pop(STACK *S, int *val)
{
    if (S->top == -1)
    {
        puts("Stack underflow");
        return 0;
    }
    else
    {
        *val = S->data[S->top];
        S->top--;
        return 1;
    }
}