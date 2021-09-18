#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int data;
    struct Node *next;
};
struct Node *insertNodeAtTail(struct Node *head, int r, int c, int d)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->row = r;
    ptr->col = c;
    ptr->data = d;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}

void display(struct Node *head)
{
    struct Node *ptr = head;

    printf("Printing the matrix in triplet form :\n");
    printf("Row   Column  Element \n");
    while (ptr != NULL)
    {
        printf("%d\t%d\t%d\n", ptr->row, ptr->col, ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head = NULL;
    int row, col, n, i, r, c, num;
    printf("Enter the dimension of the matrix :\n");
    printf("Enter the no. of row :\n");
    scanf("%d", &row);
    printf("Enter the no. of columns :\n");
    scanf("%d", &col);
    printf("Enter the number of non-zero inputs to be given to the matrix :\n");
    scanf("%d", &n);
    if (n < (row * col) / 2)
    {
        for (i = 0; i < n; i++)
        {
            printf("Enter the row index :\n");
            scanf("%d", &r);

            printf("Enter the column index :\n");
            scanf("%d", &c);

            printf("Enter the element :\n");
            scanf("%d", &num);

            head = insertNodeAtTail(head, r, c, num);
        }
        display(head);
    }
    else
    {
        printf("Matrix is not sparse\n");
    }
    return 0;
}
