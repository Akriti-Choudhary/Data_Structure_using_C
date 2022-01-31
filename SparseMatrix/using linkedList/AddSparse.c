#include <stdio.h>
#include <stdlib.h>

struct node
{
    int r;
    int c;
    int v;
    struct node *next;
};

void create(struct node **h);
void add(struct node *h1, struct node *h2, struct node **h);
void display(struct node *h);

int main()
{
    struct node *h1, *h2, *head;
    h1 = h2 = head = NULL;
    create(&h1);
    create(&h2);
    add(h1, h2, &head);
    display(head);

    return 0;
}
void create(struct node **h)
{
    *h = (struct node *)malloc(sizeof(struct node));
    puts("Enter total number of rows , columns and non-zero values");
    scanf("%d %d %d", &((*h)->r), &((*h)->c), &((*h)->v));

    struct node *cur = NULL;
    struct node *ptr = *h;
    for (int i = 0; i < (*h)->v; ++i)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        puts("Enter  rows , column and value");
        scanf("%d %d %d", &(cur->r), &(cur->c), &(cur->v));
        cur->next = NULL;

        ptr->next = cur;
        ptr = cur;
    }
}
void add(struct node *h1, struct node *h2, struct node **h)
{
    puts("Start");
    if (h1->r != h2->r || h1->c != h2->c)
    {
        return;
    }
    struct node *ptr, *ptr1, *cur, *prev;
    //ptr = ptr1 = cur = prev = NULL;

    *h = (struct node *)malloc(sizeof(struct node));
    (*h)->r = h1->r;
    (*h)->c = h1->c;
    (*h)->v = h1->v + h2->v;

    ptr = *h;

    for (ptr1 = h1->next; ptr1 != NULL; ptr1 = ptr1->next)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        cur->r = ptr1->r;
        cur->c = ptr1->c;
        cur->v = ptr1->v;

        ptr->next = cur;
        ptr = cur;
    }

    puts("copied head1 list");

    for (ptr1 = h2->next; ptr1 != NULL; ptr1 = ptr1->next)
    {
        cur = (struct node *)malloc(sizeof(struct node));
        cur->r = ptr1->r;
        cur->c = ptr1->c;
        cur->v = ptr1->v;

        ptr->next = cur;
        ptr = cur;
    }
    puts("copied head2 list");


    // simplify

    for (ptr = (*h)->next; ptr != NULL; ptr = ptr->next)
    {
        prev = ptr;
        ptr1 = ptr->next;
        while (ptr != NULL)
        {
            if ((ptr->r == ptr1->r) && (ptr->c == ptr1->c))
            {
                ptr->v += ptr1->v;
                prev->next = ptr1->next;
                free(ptr1);
                ptr1 = prev;
                (*h)->v--;
            }
            ptr1 = ptr1->next;
        }
    puts("loop");
    }
    puts("done");

}

void display(struct node *h)
{
    while (h != NULL)
    {
        printf("%d %d %d\n", h->r, h->c, h->v);
        h = h->next;
    }
}