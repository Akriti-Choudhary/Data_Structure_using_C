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
  
    struct dist *sum = &sum1 ;
    sum->k = d1->k + d2->k;
    sum->m = d1->m + d2->m;

    if (sum->m >= 1000)
    {
        sum->k = sum->k + 1;
        sum->m = sum->m - 1000;
    }
    printf("distance in km = %d \n", sum->k);
    printf("distance in m = %d \n", sum->m);
  
    free(d1);
    free(d2);
    free(sum);
    puts("Memory is freed successfully");
    return 0;
}