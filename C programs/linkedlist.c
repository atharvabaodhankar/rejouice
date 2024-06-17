#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;

void createList()
{
    int n, i, val;
    printf("\nEnter number of nodes : ");
    scanf("%d", &n);

    if (head != NULL)
    {
        printf("\nList is already present");
    }
    else
    {
        if (n != 0)
        {
            struct node *newnode = malloc(sizeof(struct node));
            printf("\nEnter data of head : ");
            scanf("%d", &val);
            newnode->data = val;
            newnode->link = NULL;
            head = newnode;
            struct node *temp = head;

            for (i = 2; i <= n; i++)
            {
                newnode = malloc(sizeof(struct node));
                printf("\nEnter data of node : ");
                scanf("%d", &val);
                newnode->data = val;
                newnode->link = NULL;
                temp->link = newnode;
                temp = temp->link;
            }
        }
    }
}
void insertAtBegin()
{
    int val;
    struct node *newnode = malloc(sizeof(struct node));
    printf("\nEnter data of node : ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->link = head;
    head = newnode;
}

void insertAtMid()
{

    int val, pos;
    printf("\nEnter position : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertAtBegin();
    }
    else
    {
        pos--;
        struct node *newnode, *ptr;
        ptr = head;
        newnode = malloc(sizeof(struct node));
        printf("\nEnter data of node : ");
        scanf("%d", &val);
        newnode->data = val;

        while (pos != 1)
        {
            ptr = ptr->link;
            pos--;
        }
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}
void insertAtEnd()
{
    int val;
    struct node *newnode, *ptr;
    ptr = head;
    newnode = malloc(sizeof(struct node));
    printf("\nEnter data of node : ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->link = NULL;

    while(ptr -> link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
}
void deleteAtBegin()
{
    struct node *ptr = head;
    head = head->link;
    free(ptr);
    ptr = NULL;
}

void deleteAtMid()
{
    int pos;
    printf("\nEnter position : ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        deleteAtBegin();
    }
    else
    {

    struct node *current, *previous;
    current = previous = head;
    while(pos != 1)
    {
        previous = current;
        current = current->link;
        pos--;
    }
    previous->link = current->link;
    free(current);
    current = previous = NULL;
    }
}
void deteleAtEnd()
{
    struct node *ptr = head;
    while(ptr -> link ->link != NULL)
    {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
}

void display()
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
}
void search()
{
    int key;
    printf("\nEnter key : ");
    scanf("%d ", &key);
    
    struct node *ptr = head;

    while(ptr != NULL)
    {
        if(ptr->data == key)
        {
            printf("\nkey found");
            break;
        }
        ptr = ptr->link;
    }
    if(ptr == NULL)
    {
        printf("\nKey not found");
    }
}

int main()
{
    int ch = 0;

    createList();

    while (ch != 9)
    {
        printf("\n1. insertbegin \n 2. insertend \n 3. insertpos \n 4. deletebegin \n 5. deleteend \n 6. deletepos \n 7. search \n 8. Display \n 9. Exit");
        printf("\n\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtBegin();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtMid();
            break;  
        case 4:
            deleteAtBegin();
            break;      
        case 5:
            deteleAtEnd();
            break;
        case 6:
            deleteAtMid();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            break;
        default:
            printf("\nInvalid choice");
            break;
        }

    }
}