#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char data;
    struct Node * next;
};
typedef struct 
{
    struct Node * top;
}Stack;
int IsEmpty(Stack s);
int push(Stack * s,char v);
int pop(Stack  * s,struct Node ** v);
int IsOperand(int c);
int getVal(char a);
int IsHtoL(char a,char b);
int Infix_Prefix(char * inp , char * out);
char* reverse(char *inout);
struct Node * m;
int Infix_Prefix(char *inp , char *out)
{
    Stack s;
    s.top=NULL; 
    int i=0,k=0,p,q;
    inp=reverse(inp);
    while(inp[i] != '\0')
    {
        if(IsOperand(inp[i]))
        {
            out[k++]=inp[i];
        }
        else if(inp[i]=='(')
        {
            q=push(&s,inp[i]);
        }
        else if(inp[i]==')')
        {
            while(1)
            {
                p=pop(&s,&m);
                if(m->data=='(')
                    break;
                out[k++]=m->data;
            }
        }
        else
        {
            if(IsEmpty(s))
            {
                q=push(&s,inp[i]);
            }
            else 
            {
                p=pop(&s,&m);
                if((m->data=='('))
                {
                    push(&s,m->data);
                    push(&s,inp[i]);
                }
                else if(IsHtoL(m->data,inp[i]))
                {
                    out[k++]=m->data;
                    i--;
                }
                else
                {
                push(&s,m->data);
                push(&s,inp[i]);
                }
            }
        }
        i++;
    }
    while(!(IsEmpty(s)))
    {
        p=pop(&s,&m);
        out[k++]=m->data;
    }
    out[k]='\0';
   out=reverse(out);
}
char* reverse(char *str)
 {
 int len=0;
 while(str[len] != '\0')
    {
        len++;
    }
 char str_tmp[len];
   int j = 0;
   for (int i = len - 1; i >= 0; i--)
   {
     if (*(str+i) == '(')
     {
       *(str_tmp+j) = ')';
       j++;
     }
     else if (*(str+i) == ')')
     {
       *(str_tmp+j) = '(';
       j++;
     }
     else
     {
       *(str_tmp+j) = *(str+i);
       j++;
     }
   }
   *(str_tmp+(j++)) = '\0';
   strcpy(str,str_tmp);
   return str;
 }
int IsHtoL(char a,char b)
{
    if(getVal(a)>getVal(b))
        return 1;
    else 
        return 0;
}
int getVal(char a)
{
    int t;
    switch(a)
    {
        case '+':
        case '-': t=1;
                break;
        case '*':
        case '/':t=2;
                break;
        case '^':t=3;
                break;
    }
    return t;
}
int IsOperand(int c)
{
    if( ((c>=65)&&(c<=90)) || ((c>=97)&&(c<=122)) )
    {
        return 1;
    }
    return 0;
}
int IsEmpty(Stack s)
{
    if(s.top==NULL)
        return 1;
    return 0;
}
int push(Stack *s,char v)
{
    struct Node *cur;
    cur= (struct Node *)malloc(sizeof(struct Node));
    if(cur==NULL)
    {
        printf("Overflow");
        return 1;
    }
    cur->data=v;
    cur->next = s->top;
    s->top=cur;
    return 0;
}
int pop(Stack * s,struct Node ** v)
{
    if(IsEmpty(* s))
    {
        printf("Underflow");
        return 1;
    }
    * v = s->top;
    s->top=s->top->next;
    return 0;
}
int main()
{   
    char inp[100];
    int l=0,i=0;
    printf("Enter infix expression:");
    scanf("%s",inp);
    while(inp[l] != '\0')
    {
        l++;
    }
    char out[l];
    printf("The prefix Expression is:");
    int c=Infix_Prefix(inp,out);
    while(out[i]!='\0')
    {
        printf("%c",out[i]);
        i++;
    }
    return 0;
}