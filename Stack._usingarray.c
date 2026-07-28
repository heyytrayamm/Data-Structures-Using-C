#include <stdio.h>
#include <stdlib.h>
#define N 5
int stack[N];
int top = -1;

void push()
{
    int x;
    if (top == N - 1)
    {
        printf("Stack is Overflowed \n");
    }
    else
    {
        printf("Enter the Element you want to insert : \n");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("%d pushed to stack\n", x);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack is Underflowed!\n");
    }
    else
    {
        int item = stack[top];
        top--;

        printf("The Popped item is %d", item);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Top element is %d", stack[top]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack is Empty !!\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n--------Stack Menu--------\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 0);
    return 0;
}