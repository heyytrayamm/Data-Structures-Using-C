#include <stdio.h>
#define N 5
int a[N];
int b[N];
void merge(int lb, int mid,int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}

void merge_sort(int lb, int ub)
{
    if (lb < ub)
    {

        int mid = (lb + ub) / 2;
        merge_sort(lb, mid);
        merge_sort(mid + 1, ub);
        merge(lb, mid, ub);
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
    merge_sort(0, N - 1);

    printf("The Sorted array is :\n");
    display();
    print_signature();
    return 0;
}