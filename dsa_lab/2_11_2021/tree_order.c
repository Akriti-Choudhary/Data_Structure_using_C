#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node *create(struct Node *root, int val)
{

    if (root == NULL)
    {
        return newNode(val);
    }

    if (val < root->data)
    {
        root->left = create(root->left, val);
    }
    else
    {
        root->right = create(root->right, val);
    }
    return root;
}
void inorder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    struct Node *root = NULL;
    int n;
    int a;
    int b;
    printf("BST-");
    do{
    printf("\n1 -> Create\n2 -> In-order\n3 -> Postorder\n4 -> Preorder\n5 -> Quit");
    printf("\nEnter your choice : ");
    scanf("%d", &b);
    switch (b)
    {
    case 1:

        printf("\nEnter total numbers of nodes to be created : ");
        scanf("%d", &n);
        printf("\nEnter root : ");
        scanf("%d", &a);
        root = create(root, a);
        for (int i = 0; i < n - 1; i++)
        {
            printf("\nEnter value of root to be inserted : ");
            scanf("%d", &a);
            create(root, a);
        }
        break;
    case 2:
        inorder(root);
        break;
    case 3:
        postorder(root);
        break;
    case 4:
        preorder(root);
        break;
    case 5:
        puts("--------Program Terminated-------");
        break;
    default:
        break;
    }
    }while(b!=5);
}