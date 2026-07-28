#include <stdio.h>
#include<stdlib.h>

#define N 6
int a[N], i, j;
int temp;

void insertion_sort()
{
    for (i = 1; i < N; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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
    insertion_sort();
    printf("The Sorted array is :\n");
    display();
    print_signature();
    return 0;
}