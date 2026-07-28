#include <stdio.h>
#define N 7
int a[8];

int maxheapify(int n, int i)
{
    int largest = i;
    int l = (2 * i);
    int r = (2 * i) + 1;
    while (l <= n && a[l] > a[largest])
    {
        largest = l;
    }
    while (r <= n && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxheapify(n, largest);
    }
}
// Building a Max Heap
void heap_sort(int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxheapify(n, i);
    }
    // for deletion of a Max Heap
    for (int i = n; i >= 1; i--)
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        maxheapify(i - 1, 1);
    }
}
void display()
{
    for (int k = 1; k <= N; k++)
    {
        printf("%d\n", a[k]);
    }
}

int main()
{
    printf("Enter %d elements:\n", N);

    for (int i = 1; i <= N; i++)
    {

        scanf("%d", &a[i]);
    }
    heap_sort(N);

    printf("The Sorted array is :\n");
    display();

    return 0;
}