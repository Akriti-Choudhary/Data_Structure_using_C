#include <stdio.h>

int BinarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return BinarySearch(arr, low, mid - 1, x);

        return BinarySearch(arr, mid + 1, high, x);
    }

    return -1;
}

int main()
{
    int size;
    puts("Enter the size of the element : ");
    scanf("%d", &size);
    int arr[size];

    puts("Enter the elements in sorted ascending order");
    for (int i = 0; i < size; ++i)
    {
        printf("Enter the %d element : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int x;
    puts("Enter the element to search for : ");
    scanf("%d", &x);

    int result = BinarySearch(arr, 0, size - 1, x);
    (result == -1)
        ? printf("Element is not present ")
        : printf("Element is present at index %d", result+1);
    return 0;
}