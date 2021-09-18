#include <stdio.h>
int main()
{

    int n;
    puts("Enter the number of rows and columns of  square matrix  :");
    scanf("%d", &n);

    int arr1[n][n];

    puts("Enter the elements in the 1st matrix :");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    int arr2[n][n];

    puts("Enter the elements in the 2nd matrix :");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &arr2[i][j]);
        }
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
            printf("%d ",multi[i][j]);
        }
        puts(" ");
    }

    return 0;
}