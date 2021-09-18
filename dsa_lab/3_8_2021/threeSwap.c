#include <stdio.h>

void swap(int *x , int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a , b , c;

    puts("Enter the three values ");
    scanf("%d%d%d" ,&a ,&b ,&c);

    swap(&a ,&b);
    swap(&a ,&c);

    puts("The three swaped values ");
    printf("a = %d \nb = %d \nc = %d \n",a , b ,c);
}