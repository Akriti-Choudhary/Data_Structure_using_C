
#include <stdio.h>

int Linearsearch(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int size;
    puts("Enter the size of the element : ");
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; ++i)
    {
        printf("Enter the %d element : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int x;
    puts("Enter the element to search for : ");
    scanf("%d", &x);

    int result = Linearsearch(arr, size, x);
    (result == -1)
        ? printf("Element is not present ")
        : printf("Element is present at index %d", result+1);
    return 0;
}