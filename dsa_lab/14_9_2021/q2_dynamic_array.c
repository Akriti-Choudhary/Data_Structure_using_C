#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S;
};
void create(struct Stack *st)
{
    printf("Enter Size");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    x = st.S[st.top - index + 1];
    return x;
}
int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}
int main()
{
    struct Stack st;
    create(&st);
    int choice = 0;
    while (choice != 5)
    {
        puts("Enter choice :");
        puts("1 - check if the stack is empty");
        puts("2 - Display the content of the stack");
        puts("3 - Push");
        puts("4 - Pop");
        puts("5 - Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int n = isEmpty(st);
            if (n == 1)
            {
                puts("Stack is empty");
            }
            else
                puts("Stack is not empty");
            break;
        }

        case 2:
            Display(st);
            break;
        case 3:
            int x;
            puts("Enter the value to be entered");
            scanf("%d", &x);
            push(&st, x);
            break;
        case 4:
            pop(&st);
            break;
        case 5:
            puts("_____________________Program terminated______________________________");
            break;
        default:
            puts("Invalid choice");
            break;
        }
    }
    return 0;
}