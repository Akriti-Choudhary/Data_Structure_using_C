#include <stdio.h>
int main()
{

    int n;
    puts("Enter the number of rows and columns of  square matrix  :");
    scanf("%d", &n);
    int count = 0;
    int arr1[n][n];

    puts("Enter the elements in the 1st matrix :");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &arr1[i][j]);
            if (arr1[i][j] != 0)
            {
                count++;
            }
        }
    }

    if (count < 0.5 * n * n)
    {
        puts("The entered matrix is not a sparse matrix ");
    }

    int arr2[n][n];
    count = 0;
    puts("Enter the elements in the 2nd matrix :");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &arr2[i][j]);
            if (arr2[i][j] != 0)
            {
                count++;
            }
        }
    }
    if (count < 0.5 * n * n)
    {
        puts("The entered matrix is not a sparse matrix ");
    }
    int multi[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            multi[i][j] = 0;
            for (int k = 0; k < n; ++k)
            {
                multi[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    puts("The result matrix:");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", multi[i][j]);
        }
        puts(" ");
    }

    printf("ROW\tCOLUMN\tELEMENT\n");

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            if (multi[i][j] != 0)
            {
                printf("%d \t %d \t %d \n", i, j, multi[i][j]);
            }
        }
    }

    return 0;
}