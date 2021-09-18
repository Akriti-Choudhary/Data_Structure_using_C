#include <stdio.h>
struct element
{
    int value;
    int frequency;
};
void input(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
}
void sortByFre(int *arr, int n)
{
    struct element A[n];
    int temp;
    for (int i = 0; i < n; ++i)
    {
        A[i].value = arr[i];
        A[i].frequency = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (A[i].value == A[j].value)
                A[i].frequency++;
        }
    }
    //sorting
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (A[j].frequency <= A[j + 1].frequency)
            {
                temp = A[j].frequency;
                A[j].frequency = A[j + 1].frequency;
                A[j + 1].frequency = temp;

                temp = A[j].value;
                A[j].value = A[j + 1].value;
                A[j + 1].value = temp;
            }
        }
    }
    //printing
    puts("Result ");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", A[i].value);
    }
    puts(" ");
}
int main()
{
    int n;
    puts("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[n];
    puts("Enter the elements of the array : ");
    input(arr, n);
    sortByFre(arr, n);
    return 0;
}