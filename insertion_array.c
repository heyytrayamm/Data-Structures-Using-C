#include <stdio.h>

int main()
{
    int arr[50];
    int SIZE;
    int num;
    int pos;
    printf("Enter the SIZE of array : \n");
    scanf("%d", &SIZE);
    printf("Enter the Elements of array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the number:\n");
     scanf("%d", &num);
    printf("enter the position:\n");
     scanf("%d", &pos);
    if (pos <= 0 || pos > SIZE + 1)
    {
        printf("INVALID INSERTION!!");
    }
    else
    {
        for (int i = SIZE - 1; i >= pos - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos - 1] = num;
        SIZE++;
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("Element at Index %d is %d\n", i, arr[i]);
    }

    return 0;
}