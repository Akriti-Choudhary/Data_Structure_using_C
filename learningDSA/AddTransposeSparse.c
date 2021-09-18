#include <stdio.h>

void inputSparse(int arr[][3], int d, int ele);
void transposeSparse(int arrTra[][3], int arr[][3], int d, int ele);
void displaySparse(int arr[][3], int d, int ele);
void add(int arrTra[][3], int arr[][3], int d, int ele);

int main()
{
    int d, ele;
    puts("Enter details of sparse matrix :");
    puts("Enter the dimension of matrix :");
    scanf("%d", &d);
    puts("Enter number of non zero elements :");
    scanf("%d", &ele);
    int arr[ele][3];
    int arrTra[ele][3];
    inputSparse(arr, d, ele);
    puts("Displaying the Sparse matrix");
    displaySparse(arr, d, ele);
    transposeSparse(arrTra, arr, d, ele);
    add(arrTra, arr, d, ele);
    return 0;
}
void inputSparse(int arr[][3], int d, int ele)
{
    arr[0][0] = d;
    arr[0][1] = d;
    arr[0][2] = ele;

    for (int i = 1; i <= ele; ++i)
    {
        puts("Enter the row , column , value");
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
}
void transposeSparse(int arrTra[][3], int arr[][3], int d, int ele)
{
    for (int i = 0; i <= ele; ++i)
    {
        arrTra[i][0] = arr[i][1];
        arrTra[i][1] = arr[i][0];
        arrTra[i][2] = arr[i][2];
    }
    puts("Displaying transpose of Sparse matrix");
    displaySparse(arrTra, d, ele);
}
void displaySparse(int arr[][3], int d, int ele)
{
    for (int i = 0; i <= ele; ++i)
    {
        printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}
void add(int arrTra[][3], int arr[][3], int d, int ele)
{
    int sum[ele + ele][3];
    int i = 0, j = 0, k = 0;
    int t1 = arr[0][2];
    int t2 = arrTra[0][2];

    while (i <= t1 && j <= t2)
    {
        if (arr[i][0] < arrTra[j][0]) //rows not equal
        {
            sum[k][0] = arr[i][0];
            sum[k][1] = arr[i][1];
            sum[k][2] = arr[i][2];
            ++i;
            ++k;
        }
        else if (arrTra[j][0] < arr[i][0]) //rows not equal
        {
            sum[k][0] = arrTra[j][0];
            sum[k][1] = arrTra[j][1];
            sum[k][2] = arrTra[j][2];
            ++j;
            ++k;
        }
        else if (arr[i][1] < arrTra[j][1]) //columns not equal,rows equal
        {
            sum[k][0] = arr[i][0];
            sum[k][1] = arr[i][1];
            sum[k][2] = arr[i][2];
            ++i;
            ++k;
        }
        else if (arrTra[j][1] < arr[i][1]) //columns not equal,rows equal
        {
            sum[k][0] = arrTra[j][0];
            sum[k][1] = arrTra[j][1];
            sum[k][2] = arrTra[j][2];
            ++j;
            ++k;
        }
        else //columns equal,rows equal
        {
            sum[k][0] = arrTra[j][0];
            sum[k][1] = arrTra[j][1];
            sum[k][2] = arr[i][2] + arrTra[j][2];
            ++i;
            ++j;
            ++k;
        }
    }
    sum[0][2] = k - 1;
    puts("");
    puts("Sum:");
    displaySparse(sum, d, k - 1);

}
