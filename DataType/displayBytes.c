/*WAP to display all 4 bytes of an int variable,display each byte seperately*/

#include <stdio.h>

int main()
{
    int n = 1782;
    printf("%x\n", n);
    int fb = 0x00FF & n;
    printf("Block1 = %x\n", fb);
    int sb = 0xFF0 & n;
    sb = sb >> 8;
    printf("Block2 = %x\n", sb);
    int tb = 0xFF0000 & n;
    tb = tb >> 16;
    printf("Block3 = %x\n", tb);
    int b = 0xF000 & n;
    b = b >> 24;
    printf("Block4 = %x\n", b);

    return 0;
}