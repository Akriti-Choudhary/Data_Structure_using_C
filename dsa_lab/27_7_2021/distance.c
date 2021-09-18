#include <stdio.h>
struct dist{
    int d_feet;
    double d_inch;
};
int main()
{
    struct dist d1, d2, sum;
    puts("Enter the distance in feet and inch for first distance  :");
    scanf("%d%lf",&d1.d_feet,&d1.d_inch);

    puts("Enter the distance in feet and inch for second distance  :");
    scanf("%d%lf",&d2.d_feet,&d2.d_inch);

    sum.d_feet = d1.d_feet + d2.d_feet;
    sum.d_inch = d1.d_inch + d2.d_inch;

    while(sum.d_inch >= 12){
        sum.d_inch = sum.d_inch - 12;
        sum.d_feet = sum.d_feet + 1;
    }
    puts("");
    printf("The sum of distances in feet : %d and inches : %.2ld \n" ,sum.d_feet ,sum.d_inch);

    return 0;

}