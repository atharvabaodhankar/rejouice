#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int i,j,k,temp,n,a[50];

    printf("Enter Size : ");
    scanf("%d", &n);

    printf("Enter Array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n;i++)
    {
        temp = a[i];
        k = i - 1;
        while(k >= 0 && a[k] > temp)
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = temp;
    }

        for (i = 0; i < n; i++)
        {
            printf("%d\t", a[i]);
        }

        return 0;
}
