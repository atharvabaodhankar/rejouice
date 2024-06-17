#include <stdio.h>

int n, a[50], front = -1, rear = -1;

void enqueue()
{
    int val;
    if (rear == n - 1)
    {
        printf("Queue Overflow");
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    printf("Enter data : ");
    scanf("%d", &val);
    a[rear] = val;
}
void dequeue()
{
    int val = a[front];
    if (front == -1)
    {
        printf("Queue Underflow");
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    printf("%d deleted", val);
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue Underflow");
        return;
    }
    else
    {

        for (i = front; i <= rear; i++)
        {
            printf("%d\t", a[i]);
        }
    }
}

int main()
{
    printf("\nEnter size of the Queue : ");
    scanf("%d", &n);
    int ch = 0;
    while (ch != 5)
    {
        printf("\n1.Enqueue \n 2.Dequeue \n 3.Display \n 5.Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 5:
            break;
        default:
            break;
        }
    }

    return 0;
}
