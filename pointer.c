#include <stdio.h>

int main()
{
    int b = 10;
    int *p;
    p = &b;
    printf("%d\n", b);
    printf("%p\n", &b);
    printf("%d\n", *p);
    printf("%p\n", p);
    printf("%p", *(&p));
    printf("%p", &p);
    return 0;
}