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
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("the dequeued element is %d\n", temp->data);
        front = rear = 0;
        free(temp);
    }
    else
    {
        printf("the dequeued element is %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        do
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp->next != front);
        printf("%d\n", temp->data);
    }
}
void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d", front->data);
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
