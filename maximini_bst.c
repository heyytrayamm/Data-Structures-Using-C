#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node* create_node(int value)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// insert in BST
node* insert(node *root, int value)
{
    if(root == NULL)
        return create_node(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// find minimum
void find_min(node *root)
{
    if(root == NULL)
        return;

    while(root->left != NULL)
        root = root->left;

    printf("Minimum element = %d\n", root->data);
}

// find maximum
void find_max(node *root)
{
    if(root == NULL)
        return;

    while(root->right != NULL)
        root = root->right;

    printf("Maximum element = %d\n", root->data);
}

int main()
{
    node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    find_min(root);
    find_max(root);

    return 0;
}