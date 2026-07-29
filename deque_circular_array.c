#include <stdio.h>
#define N 5
int deque[N];
int front = -1;
int rear = -1;

void enqueuefront(int x)
{

    if (front == 0 && rear == N - 1 || front == rear + 1)
    {
        printf("The Queue is Full\n");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front == 0)
    {
        front = N - 1;
        deque[front] = x;
    }
    else
    {
        front--;
        deque[front] = x;
    }
}

void enqueuerear(int x)
{
    if (front == 0 && rear == N - 1 || front == rear + 1)
    {
        printf("The Queue is Full\n");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }

    else if (rear == N - 1)
    {
        rear = 0;
        deque[rear] = x;
    }
    else
    {
        rear++;
        deque[rear] = x;
    }
}

void dequeuefront()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else if (front == rear)
    {
        printf("%d is Dequeued", deque[front]);
        front = rear = -1;
    }
    else if (front == N - 1)
    {
        printf("%d is Dequeued", deque[front]);
        front = 0;
    }
    else
    {
        printf("%d is Dequeued", deque[front]);
        front++;
    }
}
void dequeuerear()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else if (front == rear)
    {
        printf("%d is Dequeued", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("%d is Dequeued", deque[rear]);
        rear = N - 1;
    }
    else
    {
        printf("%d is Dequeued", deque[rear]);
        rear--;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        while (i != rear)
        {
            printf("%d\n", deque[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", deque[rear]);
    }
}

void getfront()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d\n", deque[front]);
    }
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("--------Queue Control Menu-------\n");
        printf("\n1.EnQueue_front \n 2.EnQueue_rear \n 3.Dequeue_front\n 4.Dequeue_rear\n 5.Display\n 6.getfront\n 0.Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value :");
            scanf("%d", &value);
            enqueuefront(value);
            break;
        case 2:
            printf("Enter Value :");
            scanf("%d", &value);
            enqueuerear(value);
            break;
        case 3:
            dequeuefront();
            break;
        case 4:
            dequeuerear();
            break;
        case 5:
            display();
            break;
        case 6:
            getfront();
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
