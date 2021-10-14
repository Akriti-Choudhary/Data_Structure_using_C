#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int expo;
    struct node *next;
};

void create(struct node **h);
void mul(struct node *head1, struct node *head2, struct node **head);
void simplify(struct node **head);
void display(struct node *h);
void delList(struct node *h);

int main()
{
    struct node *h = NULL;
    struct node *h1 = NULL;
    struct node *h2 = NULL;
    create(&h1);
    create(&h2);
    mul(h1, h2, &h);

    simplify(&h);

    display(h);

    delList(h2);
    delList(h1);
    delList(h);

    return 0;
}
void create(struct node **h)
{
    int num;
    puts("Enter number of nodes to be created");
    scanf(" %d", &num);
    struct node *cur, *ptr;
    for (int i = 0; i < num; i++)
    {
        cur = (struct node *)(malloc(sizeof(struct node)));
        puts("Enter the coefficient and exponent");
        cur->next = NULL;
        scanf(" %d %d", &(cur->coef), &(cur->expo));
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
    puts("The list is created");
}

void mul(struct node *head1, struct node *head2, struct node **head)
{
    struct node *ptr1, *ptr2, *cur, *ptr;
    for (ptr1 = head1; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = head2; ptr2 != NULL; ptr2 = ptr2->next)
        {
            cur = (struct node *)malloc(sizeof(struct node));
            cur->coef = ptr1->coef * ptr2->coef;
            cur->expo = ptr1->expo + ptr2->expo;
            cur->next = NULL;

            if (*head == NULL)
            {
                *head = cur;
                ptr = cur;
            }
            else
            {
                ptr->next = cur;
                ptr = cur;
            }
        }
    }
}

void simplify(struct node **head)
{
    struct node *ptr = *head;
    struct node *ptr1 = NULL;
    struct node *prev = NULL;

    while (ptr != NULL)
    {
        prev = ptr;
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr->expo == ptr1->expo)
            {
                ptr->coef += ptr1->coef;
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
    while (h != NULL)
    {
        if (h->coef > 0)
        {
            printf(" + %d x^%d  ", h->coef, h->expo);
        }
        else
        {
            printf("  %d x^%d  ", h->coef, h->expo);
        }

        h = h->next;
    }
    printf("\n");
}
void delList(struct node *h)
{
    struct node *ptr = h;
    while (ptr != NULL)
    {
        h = ptr->next;
        free(ptr);
        ptr = h;
    }
    printf("Dynamic memory has been Deleted\n");
}