#include <stdio.h>

int main()
{

    int a[] = {6, 2, 1, 5, 3};
    int *q;
    q = a;
    printf("%p\n", q);
    printf("%d\n", *q);
    printf("%p\n", a);
    //q++;
    printf("%p\n", q);
    printf("%p\n", &a[1]);
    printf("%d\n", *q);
    printf("%p\n", &a[2]);
    printf("%d\n", *(a + 2));
    printf("%d\n", *(a + 3));
    

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(a + i));
        printf("%d\n", *(q + i));
        printf("%d\n", *(i + a));


    }
    if (*a = 6)
    printf("%d\n", *(a + 1));
    printf("%d\n", *a + 2);

    

    return 0;
}