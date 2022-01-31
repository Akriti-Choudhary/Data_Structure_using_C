#include <stdio.h>
#include <stdlib.h>

int n;
int *arr;
int *brr;

void input()
{
	int i;

	printf("Enter %d numbers into the array : \n", n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void display()
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void merge(int low, int mid, int high)
{
	int l1, l2, i;

	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
	{
		if (arr[l1] <= arr[l2])
			brr[i] = arr[l1++];

		else
			brr[i] = arr[l2++];
	}

	while (l1 <= mid)
	{
		brr[i++] = arr[l1++];
	}

	while (l2 <= high)
	{
		brr[i++] = arr[l2++];
	}

	for (i = low; i <= high; i++)
	{
		arr[i] = brr[i];
	}
}

void sort(int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		sort(low, mid);
		sort(mid + 1, high);
		merge(low, mid, high);
	}
}

int main()
{
	puts("Enter the size of the array :");
	scanf("%d", &n);

	arr = (int *)malloc(n * sizeof(int));
	brr = (int *)malloc(n * sizeof(int));

	input();

	sort(0, n - 1);

	puts("After Sorting : ");
	display();

	return 0;
}
