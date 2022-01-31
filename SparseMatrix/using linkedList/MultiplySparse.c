#include <stdio.h>
#include <stdlib.h>

struct node
{
    int r;
    int c;
    int v;
    struct node *next;
};

void create(struct node **h)
{
    *h = (struct node *)malloc(sizeof(struct node));
    puts("Enter total number of rows , total number of columns and total number of non-zero values");
    scanf(" %d%d%d", &((*h)->r), &((*h)->c), &((*h)->v));
    puts(" ");
    (*h)->next = NULL;

    struct node *cur = NULL, *ptr;
    ptr = *h;

    for (int i = 0; i < (*h)->v; ++i)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        puts("Enter the row , column and the non-zero value");
        scanf(" %d%d%d", &cur->r, &cur->c, &cur->v);
        puts(" ");
        cur->next = NULL;

        ptr->next = cur;
        ptr = cur;
    }
}

void mul(struct node *f, struct node *g, struct node **h)
{
    if (f->c != g->r)
    {
        return;
    }
    else
    {
        struct node *ptr, *ptr1, *ptr2, *cur;

        *h = (struct node *)malloc(sizeof(struct node));
        (*h)->r = f->r;
        (*h)->c = g->c;
        (*h)->v = 0;
        (*h)->next = NULL;

        ptr = *h;

        for (ptr1 = f->next; ptr1 != NULL; ptr1 = ptr1->next)
        {
            for (ptr2 = g->next; ptr2 != NULL; ptr2 = ptr2->next)
            {
                if (ptr1->c == ptr2->r)
                {
                    cur = (struct node *)malloc(sizeof(struct node));
                    cur->r = ptr1->r;
                    cur->c = ptr2->c;
                    cur->v = ptr1->v * ptr2->v;
                    cur->next = NULL;

                    (*h)->v++;
                    ptr->next = cur;
                    ptr = cur;
                }
            }
        }
    }
}

void display(struct node *h)
{
    for (; h != NULL; h = h->next)
    {
        printf("%d\t%d\t%d\n", h->r, h->c, h->v);
    }
}

int main()
{
    struct node *f, *g, *h;
    f = g = h = NULL;

    create(&f);
    create(&g);
    mul(f, g, &h);

    puts("--------- Matrix 1 ---------");
    display(f);
    puts(" ");
    puts("--------- Matrix 2 ---------");
    display(g);
    puts(" ");
    puts("--------- Resultant Matrix ---------");
    display(h);
    puts(" ");

    return 0;
}