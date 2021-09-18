#include <stdio.h>
#include <string.h>
int main()
{
    int size1, size2, count = 0;
    puts("Enter the size of the string1 :");
    scanf("%d", &size1);
    char String1[size1];
    puts("Enter the string1 :");
    scanf(" %[^\n]", String1);

    puts("Enter the size of the string2 :");
    scanf("%d", &size2);
    char String2[size2];
    puts("Enter the string2 :");
    scanf(" %[^\n]", String2);

    int size3 = strlen(String1) + strlen(String2);
    char String3[size3];
    for (int i = 0; i < strlen(String1) - 1; ++i)
    {
        String3[i] = String1[i];
    }
    for (int i = strlen(String1) - 1; i < size3; ++i)
    {
        String3[i] = String2[count];
        count++;
    }

    printf("The concatenated string is : %s \n", String3);

    return 0;
}