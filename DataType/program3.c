#include <stdio.h>
int main()
{
    /*Any type of pointer will be of the same size.
    The size of pointr depends on the architecture*/
    int a = 5;
    int *aptr = &a;

    float b = 3.14;
    float *bptr = &b;

    char c = 'a';
    char *cptr = &c;

    char *str[2] = {"hii", "hello"};
    char **strPtr = str;

    printf(" sizeof(int *) = %d\n", sizeof(aptr));
    printf(" sizeof(float *) = %d\n", sizeof(bptr));
    printf(" sizeof(char *) = %d\n", sizeof(cptr));
    printf(" sizeof(char**) = %d\n", sizeof(strPtr));

    return 0;
}