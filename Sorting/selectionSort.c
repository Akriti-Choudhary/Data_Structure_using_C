#include <stdio.h>
int main()
{
    int n, i, j, position, t;

    puts("Enter number of elements");
    scanf("%d", &n);
    int array[n];
    puts("Enter the elements\n");

    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for (i = 0; i < (n - 1); i++)
    {
        position = i;

        for (j = i + 1; j < n; j++)
        {
            if (array[position] > array[j])
                position = j;
        }
        if (position != i)
        {
            t = array[i];
            array[i] = array[position];
            array[position] = t;
        }
    }

    puts("Sorted list in ascending order:");

    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    
    puts(" ");

    return 0;
}