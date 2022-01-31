#include <stdio.h>
#include <stdlib.h>
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;
NODE *node;
NODE *createtree(NODE *node, int data)
{
    if (node == NULL)
    {
        NODE *temp;
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < (node->data))
    {
        node->left = createtree(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = createtree(node->right, data);
    }
    return node;
}
void inorder(NODE *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}
void preorder(NODE *node)
{
    if (node != NULL)
    {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(NODE *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}
NODE *smallest(NODE *node)
{
    while (node != NULL && node->left != NULL)
        node = node->left;
    printf("smallest value is %d\n", node->data);
    return node;
}
void largest(NODE *node)
{
    while (node != NULL && node->right != NULL)
        node = node->right;
    printf("largest value is %d\n", node->data);
}
NODE *del(NODE *node, int data)
{
    NODE *temp;
    if (node == NULL)
    {
        printf("\nElement not found");
    }
    else if (data < node->data)
    {
        node->left = del(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = del(node->right, data);
    }
    else
    {
        if (node->right && node->left)
        {
            temp = smallest(node->right);
            node->data = temp->data;
            node->right = del(node->right, temp->data);
        }
        else
        {
            temp = node;
            if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
}
NODE *insert(NODE *node, int key)
{
    if (node == NULL)
    {
        return createtree(node, key);
    }
    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right,key);
    }
    return node;
}
    int main()
    {
        int data, ch, i, n;
        NODE *root = NULL;
        do
        {
            printf("\n----------------------");
            printf("Binary Search Tree Menu");
            printf("-----------------------\n");
            printf("\n0. Quit");
            printf("\n1. Create");
            printf("\n2. Inorder Traversal");
            printf("\n3. Preorder Traversal");
            printf("\n4. Postorder Traversal");
            printf("\n5. Find smallest element");
            printf("\n6. Find largest element");
            printf("\n7. Insert an element");
            printf("\n8. Delete an element");
            printf("\nEnter your choice: ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 0:
                printf("-------Program Terminated---------\n");
                break;
            case 1:
                printf("\nEnter number of nodes: ");
                scanf("%d", &n);
                printf("\nEnter %d elements \n", n);
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &data);
                    root = createtree(root, data);
                }
                printf("The BST is created\n");
                break;
            case 2:
                printf("\nThe Inorder Traversal is: ");
                inorder(root);
                break;
            case 3:
                printf("\nThe Preorder Traversal is: ");
                preorder(root);
                break;
            case 4:
                printf("\nThe Postorder Traversal is: ");
                postorder(root);
                break;
            case 5:
                smallest(root);
                break;
            case 6:
                largest(root);
                break;
            case 7:  printf("\nEnter the element to insert: ");
                 scanf("%d", &data);
                 root=insert(root, data);
                break;
            case 8:
                printf("\nEnter the element to delete: ");
                scanf("%d", &data);
                root = del(root, data);
                break;
            default:
                printf("\nWrong option");
                break;
            }
        } while (ch != 0);
    }