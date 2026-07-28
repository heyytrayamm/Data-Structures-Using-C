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
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// find minimum (inorder successor)
node* find_min(node *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

// delete node from BST
node* delete_node(node *root, int key)
{
    if(root == NULL)
        return root;

    // search node
    if(key < root->data)
        root->left = delete_node(root->left, key);

    else if(key > root->data)
        root->right = delete_node(root->right, key);

    else
    {
        // case 1: no child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // case 2: one child
        else if(root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        // case 3: two children
        node *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

// inorder display
void inorder(node *root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    printf("Before deletion:\n");
    inorder(root);

    root = delete_node(root, 50);

    printf("\nAfter deletion:\n");
    inorder(root);

    return 0;
}