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

    int key;
    puts("Enter the value to search for :");
    scanf("%d" ,&key);

    for (int i = 0; i < n; ++i)
    {
        if(arr[i] == key){
            printf("%d was found at index %d \n" ,key , i + 1);
        }
    }
   
    free(arr);
    puts("The dynamic memory has been freed");
}