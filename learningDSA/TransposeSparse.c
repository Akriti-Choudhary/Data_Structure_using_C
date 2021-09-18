#include <stdio.h>
#define size 20
void inputSparse(int arr[][3], int r, int c, int ele);
void transposeSparse(int arrTra[][3], int arr[][3], int r, int c, int ele);
void displaySparse(int arr[][3], int r, int c, int ele);

int main()
{
    int r, c, ele;
    int arr[size][3];
    int arrTra[size][3];
    puts("Enter details of sparse matrix :");
    puts("Enter number of rows and columns :");
    scanf("%d%d", &r, &c);
    puts("Enter number of non zero elements :");
    scanf("%d", &ele);
    inputSparse(arr, r, c, ele);
    puts("Displaying the Sparse matrix");
    displaySparse(arr, r, c, ele);
    transposeSparse(arrTra, arr, r, c, ele);
    return 0;
}
void inputSparse(int arr[][3], int r, int c, int ele)
{
    arr[0][0] = r;
    arr[0][1] = c;
    arr[0][2] = ele;

    for (int i = 1; i <= ele; ++i)
    {
        puts("Enter the row , column , value");
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
}
void transposeSparse(int arrTra[][3], int arr[][3], int r, int c, int ele)
{
    for (int i = 0; i <= ele; ++i)
    {
        arrTra[i][0] = arr[i][1];
        arrTra[i][1] = arr[i][0];
        arrTra[i][2] = arr[i][2];
    }
    puts("Displaying transpose of Sparse matrix");
    displaySparse(arrTra , r , c , ele);
}
void displaySparse(int arr[][3], int r, int c, int ele)
{
    for (int i = 0; i <= ele; ++i)
    {
        printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}
