#include <stdio.h>

int main()
{

    int arr[5];

    printf("Enter the numbers of 5 students :\n");

    for (int i = 0; i < 5; i++)
    {

        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 5; i++)
    {

        printf("the marks at index %d is %d\n", i, arr[i]);
    }

    return 0;
}