#include <stdio.h>
int main()
{
    //same storage size but different range
    char a = 128;
    unsigned char b = -123;              //although we store a negative value unsigned will give us positive value
    printf("char a = %d\n", a);          //-128
    printf("unsigned char b = %d\n", b); //133
    return 0;
}
