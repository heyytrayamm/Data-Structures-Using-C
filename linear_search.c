#include <stdio.h>
int a[8];
int data, i;

void linearsearch()
{
    for (i = 0; i < 8; i++)
    {
        if (a[i] == data)
        {
            printf("Data Found at index %d", i);
            break;
        }
    }
    if (i == 8)
    {
        printf("Data Not Found\n");
    }
}
int main()
{
    printf("Enter 8 elements:\n");

    for (int i = 0; i < 8; i++)
    {

        scanf("%d", &a[i]);
    }
    printf("enter Data you want to search:");
    scanf("%d", &data);
    linearsearch();
    return 0;
}
