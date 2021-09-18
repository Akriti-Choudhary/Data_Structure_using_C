#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *arr;
    int n;

    puts("Enter the size of array \n");
    scanf("%d", &n);

    arr = (int *)(malloc(n * sizeof(int)));
    
    puts("Enter the elements of array \n");

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("Maximum value = %d \nMinimum value = %d \n", max, min);

    free(arr);
    puts("The dynamic memory has been freed");
}