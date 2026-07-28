#include <stdio.h>

int main()
{

    int a[2][3]; /// only can be represented as a[i][j],a[][j] i =row,j = column

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("The Element of [%d][%d] is :", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("The Element of [%d][%d] is %d\n", i, j, a[i][j]);
        }
   
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}