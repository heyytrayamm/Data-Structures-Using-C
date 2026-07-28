#include <stdio.h>

int main()
{
    int arr[50], pos;
    int SIZE;
    printf("Enter the SIZE of array : \n");
    scanf("%d", &SIZE);
    printf("Enter the Elements of array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the position:\n");
    scanf("%d", &pos);

    if (pos <= 0 || pos > SIZE)
    {
        printf("INVALID POSITION !!");
    }

    else
    {
        for (int i = pos - 1; i < SIZE - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        SIZE--;
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("Element at index %d is %d\n", i, arr[i]);
    }
    printf("the Size of array now is %d", SIZE);
    return 0;
}