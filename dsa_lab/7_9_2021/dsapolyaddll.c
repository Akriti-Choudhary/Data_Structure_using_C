//to add 2 polynomials using link list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int exp;
    int cof;
    struct node *next;
};
void create(struct node **h)
{
    int n;
    struct node *cur, *ptr;
    printf("enter the no. of terms in the polynomial");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        printf("enter the coefficient and the exponent of the %dth term", i + 1);
        scanf("%d%d", &cur->cof, &cur->exp);
        cur->next = NULL;
        if (*h == NULL)
        {
            *h = cur;
            ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    }
}
void join(struct node **h1, struct node *h2)
{
    if (*h1 == NULL)
        *h1 = h2;
    else
    {
        struct node *ptr;
        for (ptr = *h1; ptr->next != NULL; ptr = ptr->next)
            ;
        ptr->next = h2;
    }
}
void simplify(struct node **h)
{
    struct node *ptr, *ptr1, *prev;
    ptr = *h;
    while (ptr != NULL)
    {
        prev = ptr;
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr1->exp == ptr->exp)
            {
                ptr->cof += ptr1->cof;
                prev->next = ptr1->next;
                free(ptr1);
                ptr1 = prev;
            }
            prev = ptr1;
            ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}
void display(struct node *h)
{
    struct node *ptr;
    ptr = h;
    if (h == NULL)
    {
        printf("list is empty");
        return;
    }
    for (; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->cof >= 0)
        {
            if (ptr != NULL)
                printf("+");
        }
        printf("%dX^%d\t", ptr->cof, ptr->exp);
    }
    printf("\n\n");
}
int main()
{
    struct node *h1, *h2;
    h1 = h2 = NULL;
    create(&h1);
    create(&h2);
    printf("the 1st polynoial is\n");
    display(h1);
    printf("the 2nd polynoial is\n");
    display(h2);
    join(&h1, h2);
    simplify(&h1);
    printf("the polynomial after adding is\n");
    display(h1);
}
