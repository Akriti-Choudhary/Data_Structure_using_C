#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void insert(struct node **h, int pos, int data); //insertion of nodes
void deletion(struct node **h, int pos);         //Deletion of nodes
void display(struct node *h);                    //Traversal of the list
void reverse(struct node *h);                    //Reverse
int main()
{
    struct node *head = NULL;
    int choice = 0;
    int position;
    int data;

    while (choice != 5)
    {

        puts("Enter choice");
        puts("1 - Insertion\n2 - Display\n3 - Deletion\n4 - Reverse and display\n5 - exit"); //Displaying the choice list
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: //insertion of nodes
            puts("Enter the position for insertion of node :");
            scanf("%d", &position);
            puts("Enter the data to be stored in the node :");
            scanf("%d", &data);
            insert(&head, position, data);
            break;
        case 2: //Traversal of the list
            puts("Displaying the entire list");
            display(head);
            break;
        case 3: //Deletion of nodes
            puts("Enter the position for deletion of node :");
            scanf("%d", &position);
            deletion(&head, position);
            break;
        case 4: //reverse
            puts("Reverse the list and display");
            reverse(head);
            break;
        case 5: //termination of the program
            puts("_____________________________ Program terminated ___________________________________");
            break;
        default:
            puts("Invalid choice");
            break;
        }
    }
    return 0;
}
void insert(struct node **h, int pos, int data) //insertion of nodes
{
    struct node *cur, *tmp;
    cur = (struct node *)malloc(sizeof(struct node)); //creation of the current node
    cur->data = data;
    cur->next = NULL;

    if (*h == NULL) //if no nodes are present
    {
        *h = cur;
    }
    else if (pos == 0) //to insert node in the beginning
    {
        cur->next = *h;
        *h = cur;
    }
    else //To insert node at any given position
    {
        int i = 0;
        tmp = *h;
        while ((i < pos - 1) && (tmp->next != NULL))
        {
            ++i;
            tmp = tmp->next;
        }
        cur->next = tmp->next;
        tmp->next = cur;
    }
}
void deletion(struct node **h, int pos) //Deletion of nodes
{
    if (*h == NULL) //if no nodes are present
    {
        puts("The list is empty");
    }
    else
    {
        struct node *prv, *ptr;
        ptr = *h;
        prv = *h;
        int i = 0;
        while ((i < pos) && (ptr->next != NULL))
        {
            ++i;
            prv = ptr;
            ptr = ptr->next;
        }
        if ((*h)->next == NULL) //when only one node is present
        {
            free(ptr);
            *h = NULL;
        }
        else if (pos == 0) //delete first node
        {
            *h = ptr->next;
            free(ptr);
        }
        else //delete node at a given index
        {
            prv->next = ptr->next;
            free(ptr);
        }
    }
}
void display(struct node *h) //Traversal of the list
{
    struct node *tmp = h;
    int i = 0;
    if (h == NULL) //if no nodes are present
    {
        puts("The list is empty");
    }
    else
    {
        while (tmp != NULL)
        {
            printf("Data at node%d = %d\n", i + 1, tmp->data); //displaying the data of the current node
            tmp = tmp->next;                                   //moving to the next node
            ++i;
        }
    }
}
void reverse(struct node *h)
{
    struct node *ptr, *ptr1;
    ptr = h;
    while (ptr->next != NULL)
    {
        ptr1 = ptr->next;
        ptr->next = ptr1->next;
        ptr1->next = h;
        h = ptr1;
    }
    display(h);
}