#include <stdio.h>
int main()
{
    //same size of storage but different format of storage
    //and different operations depending upon the datatype
    int a = 5;
    float b = 10.01;
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(float) = %d\n", sizeof(float));
    printf("a%2 = %d\n", a % 2);
    ///printf("b%2 = %f\n", b%2);
    //in float type we cannot use % operator

    return 0;
}