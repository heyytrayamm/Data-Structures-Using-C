#include <stdio.h>
#include <conio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Overflowed !\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("UnderFlow!\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("The Dequeued Element is %d\n", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("The queue is Empty!!\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("The Queue is empty!!\n");
    }
    else
    {
        printf("The front element is %d", queue[front]);
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