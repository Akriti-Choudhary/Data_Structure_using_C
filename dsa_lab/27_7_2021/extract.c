#include <stdio.h>
#include <string.h>
int main()
{
    int size;
    puts("Enter the size of the string :");
    scanf("%d", &size);
    char S[size];
    puts("Enter the string :");
    scanf(" %[^\n]", S);
    printf("The entered string is : %s \n", S);
    printf("The last character of the string is : %c \n", S[strlen(S) - 1]);

    return 0;
}