#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *createNode(int data)
{
	struct Node *n;
	n = (struct Node *)malloc(sizeof(struct Node));

	n->data = data;
	n->left = NULL;
	n->right = NULL;
}

struct Node *insert(struct Node *root, int val)
{
	if (root == NULL)
	{
		return createNode(val);
	}

	if (val < root->data)
	{
		root->left = insert(root->left, val);
	}

	if (val > root->data)
	{
		root->right = insert(root->right, val);
	}

	return root;
}

void preOrder(struct Node *root)
{

	if (root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct Node *root)
{

	if (root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(struct Node *root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

int main()
{

	int choice, i, n, num, c;

	struct Node *root = NULL;

	do
	{
		printf("Binary Search Tree ( BST ) Menu \n");
		printf("0. Quit \n");
		printf("1. Create \n");
		printf("2. Inorder Traversal \n");
		printf("3. PreOrder Traversal \n");
		printf("4. PostOrder Traversal \n");

		printf("Enter your choice (0/1/2/3/4) : \n");
		scanf("%d", &choice);

		switch (choice)
		{

		case 0:
			exit(0);
			break;

		case 1:
			printf("Enter the number of Nodes : \n");
			scanf("%d", &n);

			printf("Enter %d elements : \n", n);

			for (i = 1; i <= n; i++)
			{
				scanf("%d", &num);

				root = insert(root, num);
			}

			break;

		case 2:
			if (root == NULL)
				printf("Tree is Empty \n");

			else
			{
				printf("Inorder Traversal : \n");
				inOrder(root);
			}
			printf("\n");
			break;

		case 3:
			if (root == NULL)
				printf("Tree is Empty \n");

			else
			{
				printf("PreOrder Traversal : \n");
				preOrder(root);
			}
			printf("\n");
			break;

		case 4:
			if (root == NULL)
				printf("Tree is Empty \n");

			else
			{
				printf("PostOrder Traversal : \n");
				postOrder(root);
			}
			printf("\n");
			break;

		default:
			printf("Wrong input .... \n");
		}

	} while (1);

	return 0;
}
