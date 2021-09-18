#include <stdio.h>

int main()
{
    int n;
    puts("Enter the size of the array : ");
    scanf("%d", &n);
    puts("Enter the elements of the array : ");
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    int sum;
    puts("Enter the sum : ");
    scanf("%d", &sum);

    puts("The pairs are : ");
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (sum == (arr[i] + arr[j]))
            {
                printf("%d %d \n", arr[i], arr[j]);
            }
        }
    }
    return 0;
}