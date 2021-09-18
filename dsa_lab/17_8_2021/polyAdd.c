#include <stdio.h>

void print(int poly[], int n);
void add(int A[], int B[], int m, int n);
void multi(int A[], int B[], int m, int n);

int main()
{

    int m, n;
    puts("Creation of Polynomial P");
    printf("Enter number of terms in poly1: ");
    scanf("%d", &m);
    puts("");
    int A[m];
    puts("Enter the terms in poly1 in increasing order :");
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter number of terms in poly2: ");
    scanf("%d", &n);
    puts("");
    int B[n];
    puts("Enter the terms in poly2 in increasing order :");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &B[i]);
    }
    add(A, B, m, n);
    multi(A, B, m, n);
    return 0;
}
void print(int poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", poly[i]);
        if (i != 0)
            printf("x^%d", i);
        if (i != n - 1)
            printf(" + ");
    }
    puts("");
}
void add(int A[], int B[], int m, int n)
{
    int size = (m > n) ? m : n;

    int sum[size];
    if (m > n)
    {
        for (int i = 0; i < m; i++)
            sum[i] = A[i];

        for (int i = 0; i < n; i++)
            sum[i] += B[i];
    }
    else
    {
        for (int i = 0; i < n; i++)
            sum[i] = B[i];

        for (int i = 0; i < m; i++)
            sum[i] += A[i];
    }
    puts("The addition of polynomial is :");
    print(sum, size);
}
void multi(int A[], int B[], int m, int n)
{
    int size = m + n - 1;
    int P[size];

    for (int i = 0; i < size; i++)
        P[i] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            P[i + j] += A[i] * B[j];
    }
    puts("The multiplication of polynomial is :");
    print(P, size);
}