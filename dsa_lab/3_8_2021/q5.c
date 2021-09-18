#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
    int i;
    int x,y;
    int index_x=0,index_y=0;
	
	printf("Enter the size of the array :\n");
	scanf("%d",&n);
	
	int *arr=(int*)malloc(n*sizeof(int));

	puts("Enter the elements into the array :");
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	puts("Enter the number x :");
	scanf("%d",&x);
	
	puts("Enter the number y :");
	scanf("%d",&y);
	
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			index_x=i;
			break;
		}
	}
	
	for(i=n-1;i>=0;i--)
	{
		if(arr[i]==y)
		{
			index_y=i;
			break;
		}
	}
	
	printf("Number of integers from x to y : %d \n",((index_y - index_x) + 1));

    free(arr);
    puts("The dynamic memory has been freed");
	
	return 0;
	
	
	
}
