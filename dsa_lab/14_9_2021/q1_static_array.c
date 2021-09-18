#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int STACK[MAX], TOP;

void display(int stack[])
{
    puts(" ");
    int i = 0;
    if (TOP == -1)
    {
        printf("Stack is Empty .\n");
        return;
    }

    printf("%d ", stack[TOP]);
    for (i = TOP - 1; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
    puts(" ");
}

void PUSH(int stack[], int value)
{
    if (TOP == MAX - 1)
    {
        printf("\nstack overflow\n");
        return;
    }
    TOP++;
    stack[TOP] = value;
}

void POP(int stack[])
{
    int deletedItem;
    if (TOP == -1)
    {
        printf("stack is empty.\n");
        return;
    }

    deletedItem = stack[TOP];
    TOP--;
    printf("deleted : %d\n", deletedItem);
    return;
}

int main()
{
    int value = 0;
    int choice = 0;
    TOP = -1;

    while (choice != 4)
    {

        printf("Enter Choice :\n1 - display\n2 - PUSH\n3 - POP\n4 - Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(STACK);
            break;
        case 2:
            printf("Enter value to be insert :");
            scanf("%d", &value);
            PUSH(STACK, value);
            break;
        case 3:
            POP(STACK);
            break;
        case 4:
            puts("_____________________Program terminated______________________________");
            exit(0);
        default:
            printf("\nInvalid choice.");
            break;
        }
    }
}
