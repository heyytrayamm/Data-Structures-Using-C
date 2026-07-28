#include <stdio.h>

int main()
{
    int arr[50];
    int SIZE;
    printf("Enter the SIZE of array : \n");
    scanf("%d", &SIZE);
    printf("Enter the Elements of array:\n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Traversing the Array :)\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Element at index %d is %d\n", i, arr[i]);
    }
    return 0;
}