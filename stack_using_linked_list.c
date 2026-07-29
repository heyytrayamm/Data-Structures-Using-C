#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} node;

node *newnode = NULL;
node *top = NULL;
node *temp = NULL;

void push(int x)
{
    
    newnode = (node *)malloc(sizeof(node));
    if (newnode ==NULL)
    {
        printf("Stack Overflowed\n");
        return;
    }
    
    newnode->data = x;
    newnode->link = top;
    top = newnode;
    printf("%d is pushed to stack \n", x);
}
void display()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = top;
        printf("Current stack :");
        while (temp != 0)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}
void peek()
{
    if (top == NULL)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("Top element :%d\n", top->data);
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("stack is Underflowed!\n");
    }
    else
    {
        printf("%d is Popped from the stack \n", top->data);
        temp = top;
        top = top->link;
        free(temp);
    }
}
int main()
{
    int choice,value;
    while (1)
    {
        printf("--------Stack Menu--------\n");
        printf("1.Push\n2.Pop\n3.Display\n4.peek\n0.exit\n");
        printf("Enter choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            peek();
            display();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Exiting......\n");
            return 0;
        default:
            printf("Invalid Choice\n");
            break;
        }
        
    }
    return 0;
}