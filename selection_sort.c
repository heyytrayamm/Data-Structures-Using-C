#include <stdio.h>
#define N 5
int a[N], i, j;

void selection_sort()
{
    for (i = 0; i < N - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < N; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
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
    selection_sort();
    printf("The Sorted array is :\n");
    display();
    print_signature();
    return 0;
}