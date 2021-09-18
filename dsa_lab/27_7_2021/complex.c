#include <stdio.h>
struct complex{
int real , img;
};
struct complex sum(struct complex com_num1 ,struct complex com_num2){
    struct complex com_num3;
    com_num3.real = com_num1.real + com_num2.real;
    com_num3.img = com_num1.img + com_num2.img;

    return com_num3;

}

int main(){
    struct complex com_num1;
    struct complex com_num2 , total;
    puts("Enter the first complex number: ");
    scanf("%d" ,&com_num1.real);
    scanf("%d" ,&com_num1.img);

    puts("Enter the second complex number: ");
    scanf("%d%d" ,&com_num2.real ,&com_num2.img);

    total = sum(com_num1 , com_num2);
    printf("Sum of two complex numbers : %d + i %d \n" ,total.real,total.img);
    return 0;
}