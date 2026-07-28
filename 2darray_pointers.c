#include <stdio.h>
int main()
{
    int a[3][3] = {6, 2, 5, 0, 1, 3, 4, 9, 8};
    int *p;
    p = &a[0][0];
    p = a[0];
    printf("%p\n", p);
    printf("%p\n", a);
    printf("%p\n", &a);
    printf("%p\n", &a[0][0]);
    printf("%p\n", &a[0]);
    printf("%p\n", a[0]);
    printf("%p\n", a[1]);
    printf("%p\n", a[2]);
    printf("%p\n", *(a + 1));
    printf("%p\n", *(a + 2));
    printf("%p\n", *(a + 1) + 2);    // adress of 3
    printf("%d\n", *(*(a + 1) + 2)); // element
    printf("%d\n", a[1][2]);
    printf("%d\n", a[2][0]);
    printf("%d\n", *(*(a + 2) + 0));
    printf("%d\n", *(a[1] + 2));
    printf("%p\n", (a[1] + 1));
    printf("%p\n", &a[1][1]);
    printf("%p\n", &a[1] + 1);
    printf("%p\n", a[2]);

    return 0;
}