#include <stdio.h>
#include <conio.h>

#define N 5
int s1[N], s2[N];
int top1 = -1;
int top2 = -1;
int count = 0;

void push1(int data)
{
    if (top1 == N - 1)
    {
        printf("Queue is Overflowing!!\n");
    }
    else
    {
        top1++;
        s1[top1] = data;
    }
}
void push2(int data)
{
    if (top2 == N - 1)
    {
        printf("Queue is Overflowing!!\n");
    }
    else
    {
        top2++;
        s2[top2] = data;
    }
}
int pop1()
{

    return s1[top1--];
}
int pop2()
{

    return s2[top2--];
}

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    int a, b;
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        b = pop2();
        printf("%d is Dequeued\n", b);
        count--;
        for (int i = 0; i < count; i++)
        {
            a = pop2();
            push1(a);
        }
    }
}
void display()
{
    if (top1 == -1)
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("%d\n", s1[i]);
        }
    }
}

void peek()
{
    if (top1 == -1)
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        printf("The front element is %d\n", s1[0]);
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
