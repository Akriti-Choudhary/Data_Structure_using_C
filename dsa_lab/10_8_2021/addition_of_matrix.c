#include <stdio.h>
int main(){

    int r , c;
    puts("Enter the number of rows  :");
    scanf("%d",&r);
    puts("Enter the number of columns :");
    scanf("%d",&c);

    int arr1[r][c];

    puts("Enter the elements in the 1st matrix :");
    for(int i = 0; i < r ; ++i){
        for(int j =0 ; j < c; ++j){
            scanf("%d" ,&arr1[i][j]);
        }
    }

    int arr2[r][c];

    puts("Enter the elements in the 2nd matrix :");
    for(int i = 0; i < r ; ++i){
        for(int j =0 ; j < c; ++j){
            scanf("%d" ,&arr2[i][j]);
        }
    }
    int sum[r][c];
    puts("Sum of the elements of the matrix :");
    for(int i = 0; i < r ; ++i){
        for(int j =0 ; j < c; ++j){
            sum[i][j] = arr1[i][j] + arr2[i][j] ;
        }
    }

      for(int i = 0; i < r ; ++i){
        for(int j =0 ; j < c; ++j){
            printf("%d " ,sum[i][j]) ;
        }
        puts(" ");
    }


    return 0;
}