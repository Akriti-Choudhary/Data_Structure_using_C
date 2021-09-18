#include <stdio.h>
void merge(int arr[], int start, int mid, int end)
{
    puts("hii");
    int temp[start - end + 1];
    int i = start, j = mid + 1, k = 0;
    //traverse both arrays and in each iteration add smaller of both element in temp
    while ((i <= mid) && (j <= end))
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            ++k;
            ++i;
        }
        else
        {
            temp[k] = arr[j];
            ++k;
            ++j;
        }
    }
    //add elements left in the first interval
    while (i <= mid)
    {
        temp[k] = arr[i];
        ++k;
        ++i;
    }
    //add elements left in the second interval
    while (j <= end)
    {
        temp[k] = arr[j];
        ++k;
        ++j;
    }
    //copy temp to original interval
    for (int i = start; i <= end; ++i)
    {
        arr[i] = temp[i - start];
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, end);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main()
{
    int n;
    int key, temp, j;
    puts("Enter size of an array");
    scanf("%d", &n);
    int arr[n];
    puts("Enter elements of an array");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    puts("");
    mergeSort(arr, 0, n);

    //printing
    puts("Sorted elements of an array :");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}