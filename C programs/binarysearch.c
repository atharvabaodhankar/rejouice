#include<stdio.h>

int main()
{
    int n, key, i, mid, top = 0, bottom;
    n = 5;
    bottom = n - 1;
    int arr[n];
    printf("Enter array elements : ");
    for (i = 0; i < n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to be searched : ");
    scanf("%d", &key);
  
    while(top <= bottom)
    {
        mid = (top + bottom) / 2;
        if(key == arr[mid])
        {
            printf("Key found at index : %d" , mid);
            break;
        }

        if(key > arr[mid])
        {
            top = mid + 1;
        }
        else
        {
            bottom = mid - 1;
        }

    }
   
    if(top > bottom)
    {
      printf("Element not found");
    }

   


        return 0;
}