#include <stdio.h>

int main()
{
    int r, c;
    int count = 0;
    puts("Enter the number of rows and columns :");
    scanf("%d%d", &r, &c);
    int arr[r][c];
    int numEle = r * c;

    puts("Enter the elements of the matrix :");
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0)
                count++;
        }
    }
    //printing the entered matrix
    puts("printing the entered matrix :");
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }

    //check for sparse matrix

    if (count < 0.5 * numEle)
    {
        puts("The entered matrix is not a sparse matrix ");
    }
    else
    {
        printf("ROW\tCOLUMN\tELEMENT\n");

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {

                if (arr[i][j] != 0)
                {
                    printf("%d \t %d \t %d \n", i, j, arr[i][j]);
                }
            }
        }
    }

    return 0;
}