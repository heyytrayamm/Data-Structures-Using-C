#include <stdio.h>

#define N 5
int a[N];
void bubble_sort()
{
    int flag;
    int temp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
void display()
{
    for (int k = 0; k < N; k++)
    {
        printf("%d\n", a[k]);
    }
}

int main()
{
    printf("Enter %d elements:\n", N);

    for (int i = 0; i < N; i++)
    {

        scanf("%d", &a[i]);
    }
    bubble_sort();
    printf("The Sorted array is :\n");
    display();
    printf("\n\n");
    printf("  _______   _____             __     __            __      __ \n");
    printf(" |__   __| |  __ \\     /\\     \\ \\   / /     /\\    |  \\    /  |\n");
    printf("    | |    | |__) |   /  \\     \\ \\_/ /     /  \\   | \\ \\  / / |\n");
    printf("    | |    |  _  /   / /\\ \\     \\   /     / /\\ \\  | |\\ \\/ /| |\n");
    printf("    | |    | | \\ \\  / ____ \\     | |     / ____ \\ | | \\__/ | |\n");
    printf("    |_|    |_|  \\_\\/_/    \\_\\    |_|    /_/    \\_\\|_|      |_|\n");
    printf("\n             T  R  A  Y  A  M  '  S   I  N  V  E  N  T  O  R  Y\n");

    return 0;
}
