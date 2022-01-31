#include <stdio.h>

int getMax(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
void countingSort(int a[], int n, int place)
{
    int output[n + 1];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}
void radixsort(int a[], int n)
{
    int max = getMax(a, n);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(a, n, place);
}
int main()
{
    int count = 0;
    printf("Enter size of array : ");
    scanf("%d", &count);
    int a[count];
    
    for (int i = 0; i < count; i++)
    {
        printf("Enter the %d element : " ,i+1);
        scanf("%d", &a[i]);
    }
    radixsort(a, count);

    printf("Displaying Sorted array in ascending order: \n");
    for (int i = 0; i < count; ++i)
        printf("%d  ", a[i]);

    printf("\n");
    return 0;
}