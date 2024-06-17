#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void createlist()
{

    int data, i, n;
    printf("Enter no. of nodes : ");
    scanf("%d", &n);

    if (head != NULL)
    {
        printf("List Exists!");
    }
    else
    {
        if (n != 0)
        {

            struct node *newnode, *temp;
            newnode = malloc(sizeof(struct node));

            printf("Enter data of head node : ");
            scanf("%d", &data);
            newnode->data = data;
            newnode->link = head;
            head = newnode;
            temp = head;

            for (i = 2; i <= n; i++)
            {
                newnode = malloc(sizeof(struct node));
                printf("Enter data of head node : ");
                scanf("%d", &data);
                newnode->data = data;
                newnode->link = head;
                temp->link = newnode;
                temp = temp->link;
            }
        }
    }
}

void display()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("No list ");
    }
    else
    {
        do
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        } while (ptr != head);
    }
}

void insertbegin()
{
    int data;
    struct node *newnode = malloc(sizeof(struct node));
    struct node *ptr;
    ptr = head;
    printf("Enter data of new node : ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->link = head;
    while (ptr->link != head)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    head = newnode;
}

void insertend()
{
    int data;
    struct node *newnode, *ptr;
    ptr = head;
    newnode = malloc(sizeof(struct node));
    printf("Enter data of new node : ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->link = head;
    while (ptr->link != head)
    {
        ptr = ptr->link;
    }

    ptr->link = newnode;
}

void insertpos()
{
    int pos, data;
    struct node *newnode, *ptr;
    ptr = head;
    newnode = malloc(sizeof(struct node));
    printf("Enter position : ");
    scanf("%d", &pos);
    printf("Enter data of new node : ");
    scanf("%d", &data);
    newnode->data = data;

    if (pos == 1)
    {
        newnode->link = head;
        while (ptr->link != head)
            ptr = ptr->link;

        ptr->link = newnode;
        head = newnode;
    }
    else
    {
        pos--;
        while (pos != 1)
        {
            ptr = ptr->link;
            pos--;
        }
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}

void deletebegin()
{
    struct node *temp = head, *ptr = head;
    if (head == NULL)
    {
        printf("List Empty!");
    }
    else
    {

        while (ptr->link != head)
            ptr = ptr->link;

        ptr->link = head->link;
        head = head->link;
        free(temp);
        temp = NULL;
    }
}

void deleteend()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List Empty!");
    }
    else
    {
        temp = head;
        while (temp->link->link != head)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = head;
    }
}

void deletepos()
{
    int pos;
    struct node *previous = head, *current = head , *temp = head;
    printf("Enter position : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
         while (temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = head->link;
        head = head->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (pos != 1)
        {
            previous = current;
            current = current->link;
            pos--;
        }

        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

void search()
{
    int key;
    printf("Enter key : ");
    scanf("%d", &key);
    struct node *ptr;
    ptr = head;
    do
    {
        if (key == ptr->data)
        {
            printf("Key Found!");
            break;
        }
        ptr = ptr->link;
    } while (ptr != head);

    if (ptr == head)
    {
        printf("Key Not Found!");
    }
}
int main()
{
    createlist();
    int ch = 0;

    while (ch != 9)
    {
        printf("\n1. insertbegin \n 2. insertend \n 3. insertpos \n 4. deletebegin \n 5. deleteend \n 6. deletepos \n 7. search \n 8. Display \n 9. Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertbegin();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertpos();
            break;
        case 4:
            deletebegin();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            deletepos();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            break;
        }
    }

    return 0;
}