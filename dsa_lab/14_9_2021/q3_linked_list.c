#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }

    else
    {
        printf("Stack not empty \n");
    }
}

void traversal(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("Stack underflow \n");
    }

    else
    {
        printf("Elements : \n");

        while (ptr != NULL)
        {
            printf("%d \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

struct Node *push(struct Node *top, int num)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = num;
    ptr->next = top;

    top = ptr;

    return top;
}

struct Node *pop(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
    }

    else
    {
        struct Node *del;

        del = top;
        top = top->next;

        printf("Element deleted = %d \n", del->data);

        free(del);
    }

    return top;
}

int main()
{
    int choice = 0, num;
    struct Node *top = NULL;

    while (choice != 5)
    {
        printf("Enter the choice:\n");
        printf("1 - Check if the stack is empty\n");
        printf("2 - Display contents ( traverse )\n");
        printf("3 - Push \n");
        printf("4 - Pop operation \n");
        printf("5 - Exit \n");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            isEmpty(top);
            break;

        case 2:
            traversal(top);
            break;

        case 3:
            printf("Enter the number : \n");
            scanf("%d", &num);
            top = push(top, num);
            break;

        case 4:
            top = pop(top);
            break;
        case 5:
            puts("_____________________Program terminated______________________________");
            break;

        default:
            printf("Wrong input \n");
        }
    }

    return 0;
}
