#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, n;
int a[100];

void enqueue()
{
    int data;
    if(rear == n-1)
    {
        printf("Queue is full\n");
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
        printf("Enter data : ");
        scanf("%d", &data);
        a[rear] = data;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element is %d\n", a[front]);
        front++;
    }
}

void peek()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element is %d\n", a[front]);
    }
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i = front; i <= rear; i++)
        {
            printf("%d ", a[i]);
        }
    }
}

int main()
{
    int ch = 0;

    printf("enter size of stack : ");
    scanf("%d", &n);

    while(ch!=4)
    {
        printf("\n1. enqueue\n2. dequeue\n3. display\n4. exit\n");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch(ch)
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
            case 4:
                peek();
                break;
            case 5:
                break;
        }
    }

    return 0;
}