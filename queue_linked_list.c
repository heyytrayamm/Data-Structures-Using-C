#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *newnode;
node *front = NULL;
node *rear = NULL;
node *temp = NULL;

void enqueue(int x)
{
    newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = rear->next;
    }
}
void dequeue()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = front;
        printf("%d is dequeued\n", front->data);
        front = front->next;
        free(temp);
    }
}
void display()
{
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("THe Queue is Empty!\n");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        printf("The Front Element is %d\n", front->data);
    }
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("--------Queue Control Menu-------\n");
        printf("\n1.EnQueue \n 2.DeQueue \n 3.Peek\n 4.Display\n 0.Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value :");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Exiting.....\n");
            return 0;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
