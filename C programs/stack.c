#include <stdio.h>

int n, a[50], top = -1;

void push()
{
    int val;
    if(top == n - 1)
    {
        printf("\nStack Overflow!");
        return;
    }
    else
    {
        top++;
        printf("\nEnter value : ");
        scanf("%d", &val);
        a[top] = val;
    }
}
void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow!");
        return;
    }
    else{
        printf("\nTop = %d", a[top]);
        top--;
    }
}
void display()
{
    int i;
    if(top == -1)
    {
         printf("\nStack Underflow!");
        return;
    }
    else
    {
        for (i = 0; i <= top;i++)
        {
            printf("\n%d \t", a[i]);
        }
    }
}
int main()
{
    int ch = 0;
    printf("\nEnter size of Stack : ");
    scanf("%d", &n);

    while(ch != 5)
    {
        printf("\n\n1. Push \n2. Pop \n 3. Display \n 5.Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 5:
            break;

        
        default:
            printf("\nEnter valid choice");
            break;
        }
    }
    return 0;
}