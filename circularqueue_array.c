#include <stdio.h>


#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Undeflowed !!\n");
    }
    else if (front == rear)
    {
        printf("The Dequeued element is %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("The Dequeued element is %d", queue[front]);
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty !!\n");
    }
    else
    {
        while (i != rear)
        {
            printf("%d\n", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty !!\n");
    }
    else
    {
        printf("%d", queue[front]);
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
