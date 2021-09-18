#include <stdio.h>
#include <stdlib.h>

int countNonZero(int *s[], int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (s[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}
int SumAboveLeadingDiagonal(int *s[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            sum += s[i][j];
        }
    }
    return sum;
}
void DisplayBelowMinorDiagonal(int *s[], int size)
{
    int sum = 0;
    for (int i = 1; i < size; ++i)
    {
        for (int j = size - i; j < size; ++j)
        {
            printf("%d ", s[i][j]);
        }
        puts(" ");
    }
}
void ProductOfDiagonal(int *s[], int size)
{
    int leadingPro = 1;
    int MinorPro = 1;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == j)
            {
                leadingPro *= s[i][j];
            }
            if (i == (size - j - 1))
            {
                MinorPro *= s[i][j];
            }
        }
    }
    printf("Product of leading diagonal =  %d\n", leadingPro);
    printf("Product of Minor diagonal =  %d\n", MinorPro);
}

int main()
{

    puts("Enter the number of elements in a square matrix");
    int n;
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(n * sizeof(int));

    puts("Enter the elements in the square matrix");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Menu: \n 1 : Number of non zero elements in the matrix \n 2 : Sum of the elements above the leading diagonal \n 3 :Elements below the minor diagonal\n 4: Product of diagonals\n");
    int ch;
    printf("Enter choice :\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Number of non zero elements in the matrix : %d \n", countNonZero(arr, n));
        break;
    case 2:
        printf("Sum of the elements above the leading diagonal : %d \n", SumAboveLeadingDiagonal(arr, n));
        break;
    case 3:
        printf("Elements below the minor diagonal \n");
        DisplayBelowMinorDiagonal(arr, n);
        break;
    case 4:
        printf("Product of diagonals: \n");
        ProductOfDiagonal(arr, n);
        break;
    default:
        printf("The choice is invalid \n");
        break;
    }

    free(arr);
    return 0;
}