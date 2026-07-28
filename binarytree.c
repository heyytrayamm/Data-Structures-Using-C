#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;
node *createnode()
{
    int x;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter value:(enter -1 for no child)\n");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    newnode->data = x;
    printf("Left Child of %d :", x);
    newnode->left = createnode();
    printf("Right Child of %d :", x);
    newnode->right = createnode();
    return newnode;
}
node *preorder(node *root)
{
    if (root == 0)
    {
        return 0;
    }
    else
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
node *inorder(node *root)
{
    if (root == 0)
    {
        return 0;
    }
    else
    {

        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}
node *postorder(node *root)
{
    if (root == 0)
    {
        return 0;
    }
    else
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}
int main()
{
    node *root = NULL;
    root = createnode();
    printf("\nTree Construction Completed \n");
    printf("\nPreorder is :\n");
    preorder(root);
    printf("\nInorder is :\n");
    inorder(root);
    printf("\nPostorder is :\n");
    postorder(root);
    return 0;
}
