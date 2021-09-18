#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *arr;
    int n;

    puts("Enter the size of array ");
    scanf("%d", &n);

    arr = (int *)(malloc(n * sizeof(int)));

    puts("Enter the elements of array ");

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    puts("Displaying the next greater element :");
    printf("element\tNGE\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                printf("%d\t%d\n", arr[i], arr[j]);
                break;
            }
            if(j == n-1){
                printf("%d\t%d\n", arr[i], -1);
                }
        }
    }
    puts("");
    free(arr);
    puts("The dynamic memory has been freed");
}