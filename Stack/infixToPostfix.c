#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct
{
    char data[MAX];
    int top;
} STACK;

STACK S1;

void init(STACK *s)
{
    s->top = -1;
}

int isempty(STACK s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

void push(char t)
{
    if (S1.top == MAX - 1)
    {
        puts("Stack overflow");
    }
    S1.data[S1.top++] = t;
}

int pop(char *t)
{
    if (!isempty(S1))
    {
        // puts("Stack underflow");
        return 1;
    }
    *t = (S1).data[(S1).top--];
    return 0;
}

void display(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c ", arr[i]);
    }
    puts(" ");
}

int getv(char d)
{
    int k = 0;
    switch (d)
    {
    case '+':
    case '-':
        k = 1;
        break;

    case '*':
    case '/':
        k = 2;
        break;

    case '^':
        k = 3;
        break;
    }
    return k;
}

int isLH(char a, char b)
{
    if (getv(a) < getv(b))
        return 1;
    else
        return 0;
}

int isOperand(char c)
{
    if ((c >= 'A') && (c <= 'Z') || (c >= 'a') && (c <= 'z'))
    {
        return 1;
    }
    else
        return 0;
}

void infixToPostfix(char *inf, char *outf)
{
    int i = 0, j = 0;
    char t;
    int k;

    while (inf[i] != '\0')
    {
        if (isOperand(inf[i]))
        {
            outf[j++] = inf[i];
        }
        else if (inf[i] == '(')
        {
            push(inf[i]);
        }
        else if (inf[i] == ')')
        {
            while (1)
            {
                pop(&t);
                if (t == '(')
                {
                    break;
                }
                outf[j++] = t;
            }
        }
        else // operator
        {
            if (isempty(S1))
            {
                push(inf[i]);
            }
            else
            {
                pop(&t);
                if (t == '(')
                {
                    push('(');
                    push(inf[i]);
                }
                else
                {
                    if (isLH(t, inf[i]))
                    {
                        push(t);
                        push(inf[i]);
                    }
                    else
                    {
                        outf[j++] = t;
                        i--;
                    }
                }
            }
        }
        i++;
    }
    while ((k = pop(&t)) == 0)
    {
        outf[j++] = t;
    }
    outf[j] = '\0';
}

int main()
{
    char inf[MAX];
    char out[MAX];

    puts("Enter the infix expression :");
    scanf("%s", inf);

    puts("The infix expression :");
    display(inf);

    infixToPostfix(inf, out);

    puts("The postfix expression :");
    display(out);

    return 0;
}