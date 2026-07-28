#include <stdio.h>

#define N 8
int a[N], data;
int binarysearch()
{
    int l = 0, r = N - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (data == a[mid])
        {
            return mid;
        }
        else if (data < a[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    printf("Enter %d elements:\n", N);

    for (int i = 0; i < N; i++)
    {

        scanf("%d", &a[i]);
    }
    printf("enter Data you want to search:");
    scanf("%d", &data);
    int result = binarysearch();
    if (result != -1)
    {
        printf("Element is Found at index %d\n", result);
    }
    else
    {
        printf("Element is Not Found\n");
    }
    return 0;
}