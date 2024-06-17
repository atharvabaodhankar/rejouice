#include<stdio.h>

int main()
{
    int n, key, i;
    printf("Enter array : ");
    n = 10;
    int arr[n];
    printf("Enter array elements : ");
    for (i = 0; i < n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to be searched : ");
    scanf("%d", &key);

    for (i = 0; i < n;i++)
    {
        if(key == arr[i])
        {
            printf("Key found at %d index ", i);
            break;
        }
    }

        if (i == n)
        {
            printf("Key not found");
        }

        return 0;
}