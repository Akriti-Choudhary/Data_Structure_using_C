#include<stdio.h>
#include<stdlib.h>
struct node
{
    int r,c,v;
    struct node * next;
};
void create(struct node ** h)
{int row,col,count=0,i,j;
    struct node * cur,* ptr;
      printf("Enter number of rows, columns");
      scanf("%d%d",&row,&col);
      int d[50][50];
       * h=(struct node * )malloc (sizeof (struct node));
      (* h)->r=row;
      (* h)->c=col;
      for(int i=0;i<row;i++)
      {
      for(int j=0;j<col;j++)
      {
      printf("enter the element in %dth row and %dth column",i,j);
      scanf("%d",&d[i][j]);
      if(d[i][j]!=0)
      count++;
      }
      }
      for(int i=0;i<row;i++)
      {
      for(int j=0;j<col;j++)
      {
      printf("%d  ",d[i][j]);
      }
      printf("\n");
      }
      (*h)->next=NULL;
      ptr=*h;
      (*h)->v=count;
      for(int k=0;k<(*h)->v;)
      {
        for(int i=0;i<row;i++)
        {
        for(int j=0;j<col;j++)
         {
         if(d[i][j]!=0)
         {
         cur=(struct node * ) malloc (sizeof(struct node));
         cur->r=i;
         cur->c=j;
         cur->v=d[i][j];
         cur->next=NULL;
         ptr->next =cur;
         ptr=cur;
         k++;
         }
         }
         }
    }
}
void display(struct node *h)
{
    struct node *ptr;
    for(ptr=h;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d\t%d\t%d",ptr->r,ptr->c,ptr->v);
        printf("\n");
    }
}
int main()
{ 
    struct node * h;
    h=NULL;
    create(&h);
    printf("Matrix : \n");
    display(h);
    return 0;
}
