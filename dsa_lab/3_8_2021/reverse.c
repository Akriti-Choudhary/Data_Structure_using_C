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
    int temp = 0;
    for(int i = 0 ; i < n/2 ; ++i){
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    puts("The reversed array :");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    free(arr);
    puts("The dynamic memory has been freed");

}