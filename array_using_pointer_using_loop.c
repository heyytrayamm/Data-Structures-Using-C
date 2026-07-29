#include <stdio.h>

int main()
{
    int a[5] ;
    int *q = a;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &q[i]); //&(*(q+i)) = &q[i]
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", q[i]); 
    }

    return 0;
}