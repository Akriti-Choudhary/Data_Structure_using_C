#include <stdio.h>
struct arr
{
    int col;
    int row;
    int value;
};
int main()
{
    int ele2;
    int row2;
    int column2;
    puts("Enter the number of non-zero elements in second array : ");
    scanf("%d", &ele2);

    //struct arr a[ele1];
    struct arr b[ele2], bTra[ele2];

    puts("Enter total number of rows of 2nd matrix:");
    scanf("%d", &row2);
    puts("Enter total number of columns of 2nd matrix:");
    scanf("%d", &column2);
    b[0].row = row2;
    b[0].col = column2;
    bTra[0].row = column2;
    bTra[0].col = row2;
    bTra[0].value = ele2;

    puts("Enter elements of 2nd matrix in triplet form(row,column,value):");
    for (int i = 1; i <= ele2; ++i)
    {
        scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].value);
    }

    //transpose
    int k = 1;
    for (int j = 0; j < column2; ++j)
    {
        for (int i = 0; i < row2; ++i)
        {
            if (b[i].col == j)
            {
                bTra[k].row = b[j].col;
                bTra[k].col = b[j].row;
                bTra[k].value = b[j].value;
                k++;
            }
        }
    }
    // display transpose

    for (int j = 0; j <= ele2; ++j)
    {
        printf("%d %d %d\n", bTra[j].row, bTra[j].col, bTra[j].value);
    }

    return 0;
}