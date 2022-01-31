#include <stdio.h>
struct arr
{
    int col;
    int row;
    int value;
};

int main()
{
    int ele1, ele2;
    int row1, row2;
    int column1, column2;
    // puts("Enter the number of non-zero elements in first array : ");
    // scanf("%d", &ele1);
    puts("Enter the number of non-zero elements in second array : ");
    scanf("%d", &ele2);

    //struct arr a[ele1];
    struct arr b[ele2], bTra[ele2];

    //input

    // puts("Enter total number of rows of 1st matrix:");
    // scanf("%d", &row1);
    // puts("Enter total number of columns of 1st matrix:");
    // scanf("%d", &column1);
    // a[0].row = row1;
    // a[0].col = column1;
    // puts("Enter elements of 1st matrix in triplet form(row,column,value):");
    // for (int i = 1; i <= ele1; ++i)
    // {
    //     scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    // }

    puts("Enter total number of rows of 2nd matrix:");
    scanf("%d", &row2);
    puts("Enter total number of columns of 2nd matrix:");
    scanf("%d", &column2);
    b[0].row = row2;
    b[0].col = column2;

    puts("Enter elements of 2nd matrix in triplet form(row,column,value):");
    for (int i = 1; i <= ele2; ++i)
    {
        scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].value);
    }

    //transpose
    int j;
    int rowTerms[row2], startingPos[row2];
    int numCols = b[0].col, numTerms = b[0].row;
    bTra[0].row = numCols;
    bTra[0].col = b[0].row;
    bTra[0].value = numTerms;
    if (numTerms > 0)
    {
        for (int i = 0; i < numCols; ++i)
            rowTerms[i] = 0;
        for (int i = 1; i <= numTerms; ++i)
            rowTerms[b[i].col]++;
        for (int i = 0; i < numCols; ++i)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        for (int i = 0; i < numCols; ++i)
        {
            j = startingPos[b[i].col];
            bTra[j].row = b[i].col;
            bTra[j].col = b[i].row;
            bTra[j].value = b[i].value;

        }
    }

    // display transpose

    for (j = 0; j <= ele2; ++j)
    {
        printf("%d %d %d\n", bTra[j].row, bTra[j].col, bTra[j].value);
    }

    return 0;
}