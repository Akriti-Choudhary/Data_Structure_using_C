#include <stdio.h>
#include <stdlib.h>

struct dist
{
    int k;
    int m;
};

int main()
{
    struct dist *d1, *d2 ,sum1;
    d1 = (struct dist *)malloc(sizeof(struct dist));
    d2 = (struct dist *)malloc(sizeof(struct dist));

    puts("Enter distance in km");
    scanf(" %d", &(d1->k));
    puts("Enter distance in m");
    scanf(" %d", &(d1->m));

    puts("Enter distance in km");
    scanf(" %d", &(d2->k));
    puts("Enter distance in m");
    scanf(" %d", &(d2->m));
  
    sum1.k = d1->k + d2->k;
    sum1.m = d1->m + d2->m;

    if (sum1.m >= 1000)
    {
        sum1.k = sum1.k + 1;
        sum1.m = sum1.m - 1000;
    }
    printf("distance in km = %d \n", sum1.k);
    printf("distance in m = %d \n", sum1.m);
  
    free(d1);
    free(d2);
    puts("Memory is freed successfully");
    return 0;
}