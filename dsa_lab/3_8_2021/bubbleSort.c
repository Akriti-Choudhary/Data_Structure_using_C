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
    //Sorting
    int temp = 0;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0; j < n - i -1 ; ++j){
            if(arr[j] > arr[j+1]){

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
    puts("The sorted array in ascending order :");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    puts("");
    free(arr);
    puts("The dynamic memory has been freed");

}