#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int cnoe = 0; // current number of elements

void insert(int *A, int val, int pos);
void display(int *A);
void delValue(int *A, int val);
void delpos(int *A, int pos);

int main()
{
    int A[MAX];

    int choice = 0;

    while (choice != 5)
    {
        puts("1 - Insertion\n2 - Display\n3 - Deletion by value\n4 - Deletion by position");
        puts("5 - exit");
        puts("Enter choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int val, pos;
            puts("Enter the value to be inserted");
            scanf("%d", &val);
            puts("Enter the position at which the value is to be inserted");
            scanf("%d", &pos);

            insert(A, val, pos);
            break;
        }
        case 2:
            display(A);
            break;
        case 3:
        {
            int val;
            puts("Enter value to be deleted");
            scanf("%d", &val);
            delValue(A, val);
            break;
        }
        case 4:
        {
            int pos;
            puts("Enter position at which the value is to be deleted");
            scanf("%d", &pos);
            delpos(A, pos);
            break;
        }
        case 5:
            puts("-------------Program Terminated-------------");
            break;
        }
    }
    return 0;
}

void insert(int *A, int val, int pos)
{
    if (cnoe == MAX - 1)
    {
        puts("Insertion not possible");
        return;
    }
    if (pos >= cnoe)
    {
        A[cnoe] = val;
        cnoe++;
    }
    else
    {
        for (int i = MAX - 1; i >= pos; --i)
        {
            A[i + 1] = A[i];
        }
        A[pos] = val;
        cnoe++;
    }
}

void display(int *A)
{
    if (cnoe == 0)
    {
        puts("The list is empty");
        return;
    }
    for (int i = 0; i < cnoe; ++i)
    {
        printf("%d ", A[i]);
    }
    puts(" ");
}

void delpos(int *A, int pos)
{
    if (cnoe == 0 || pos >= cnoe)
    {
        puts("The value cannot be deleted");
        return;
    }
    for (int i = pos + 1; i <= cnoe - 1; ++i)
    {
        A[i - 1] = A[i];
    }
    cnoe--;
}

void delValue(int *A, int val)
{
    int i;
    for (i = 0; i < cnoe; i++)
    {
        if (val == A[i])
        {
            break;
        }
    }
    delpos(A, i);
}