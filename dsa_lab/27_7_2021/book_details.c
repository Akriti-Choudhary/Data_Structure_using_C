#include <stdio.h>
#include <stdlib.h>
struct book{
char title[20];
char author[20];
char publication[20];
double price;
struct book *nextPtr;
};
struct book enter(struct book b,struct book *nextPtr )
{
    scanf(" %[^\n] ",nextPtr->title);
    scanf(" %[^\n] ",nextPtr->author);
    scanf(" %[^\n] ",nextPtr->publication);
    scanf(" %lf ",&nextPtr->price);
}
struct book display(struct book b,struct book *nextPtr )
{
    printf(" Title : %s \n",nextPtr->title);
    printf(" Author : %s \n",nextPtr->author);
    printf(" Publication : %s \n ",nextPtr->publication);
    printf(" Price : %lf \n",nextPtr->price);
}

int main(){
    int n;
    puts("Enter the value of n :");
    struct book b1;
    scanf(" %d" ,&n);
    struct book *newPtr = (struct book *)malloc(n * sizeof(struct book));
    for(int i = 1; i < n ; ++i){
        enter(b1 ,newPtr);
        newPtr++;
    }
    for(int i = 1; i < n ; ++i){
        printf("Details of %d book : \n");
        display(b1 ,newPtr);
        newPtr++;
    }
    
    free(newPtr);
    

}