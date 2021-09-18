#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int coeff;
    int pow;
    struct link *next;
} poly;

void createPoly(poly **);
void DisplayPoly(poly *);
void Addpoly(poly **, poly *, poly *);

int main(void)
{

    poly *poly1, *poly2, *poly3;

    printf("Create 1st expression\n");
    createPoly(&poly1);
    printf("Printing 1st expression :\n");
    DisplayPoly(poly1);

    printf("\nCreate 2nd expression\n");
    createPoly(&poly2);
    printf("Printing 2nd expression :\n");
    DisplayPoly(poly2);

    Addpoly(&poly3, poly1, poly2);
    printf("\nPrinting the result :\n");
    DisplayPoly(poly3);

    free(poly1);
    free(poly2);
    free(poly3);
    puts("\nDynamic allocated memory is freed");
    return 0;
}

void createPoly(poly **node)
{
    int flag;
    int coeff, pow;
    poly *tmp;
    tmp = (poly *)malloc(sizeof(poly));
    *node = tmp;
    do
    {
        puts("Enter Coeff:");
        scanf("%d", &coeff);
        tmp->coeff = coeff;
        puts("Enter Pow:");
        scanf("%d", &pow);
        tmp->pow = pow;
        tmp->next = NULL;

        printf("Enter 1 to add more items in the list ,else enter 0 :");
        scanf("%d", &flag);
        if (flag)
        {
            tmp->next = (poly *)malloc(sizeof(poly));
            tmp = tmp->next;
            tmp->next = NULL;
        }
    } while (flag);
    free(tmp);
}

void DisplayPoly(poly *node)
{
    while (node != NULL)
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node != NULL && node->coeff >=0)
            printf(" + ");
        else
            printf(" ");
    }
}

void Addpoly(poly **result, poly *poly1, poly *poly2)
{
    poly *tmp;
    tmp = (poly *)malloc(sizeof(poly));
    tmp->next = NULL;
    *result = tmp;

    while (poly1 && poly2)
    {
        if (poly1->pow > poly2->pow)
        {
            tmp->pow = poly1->pow;
            tmp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow)
        {
            tmp->pow = poly2->pow;
            tmp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            tmp->pow = poly1->pow;
            tmp->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (poly1 && poly2)
        {
            tmp->next = (poly *)malloc(sizeof(poly));
            tmp = tmp->next;
            tmp->next = NULL;
        }
    }

    while (poly1 || poly2)
    {
        tmp->next = (poly *)malloc(sizeof(poly));
        tmp = tmp->next;
        tmp->next = NULL;

        if (poly1)
        {
            tmp->pow = poly1->pow;
            tmp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2)
        {
            tmp->pow = poly2->pow;
            tmp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }
    puts("Temporary memory is cleared");
    free(tmp);
}