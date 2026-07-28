#include <stdio.h>
#define N 5
int a[N], temp;

int partition(int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}
void quick_sort(int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(lb, ub);
        quick_sort(lb, loc - 1);
        quick_sort(loc + 1, ub);
    }
}

void display()
{
    for (int k = 0; k < N; k++)
    {
        printf("%d\n", a[k]);
    }
}

void print_signature()
{
    printf("\n\033[1;32m==========================================\033[0m\n");
    printf("\033[1;36m       TRAYAM'S INVENTORY SYSTEM          \033[0m\n");
    printf("\033[1;32m==========================================\033[0m\n");
    printf("Status: \033[1;33mExecution Success\033[0m\n\n");
}

int main()
{
    printf("Enter %d elements:\n", N);

    for (int i = 0; i < N; i++)
    {

        scanf("%d", &a[i]);
    }
    quick_sort(0, N - 1);
    printf("The Sorted array is :\n");
    display();
    print_signature();
    return 0;
}