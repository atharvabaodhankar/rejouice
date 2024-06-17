#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *head = NULL;


void createList()
{
    int n;
    if(head != NULL)
    {
        printf("List Exists!");
    }
    else
    {
        printf("Enter number of nodes : ");
        scanf("%d", &n);
        if(n != 0 )
        {
            struct node *newnode, *temp;
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of head : ");
            scanf("%d", &newnode->data);
            newnode->link = head;
            head = newnode;
            temp = head;
            for(int i = 2; i <= n; i++)
            {
                newnode = (struct node *)malloc(sizeof(struct node));
                printf("Enter data of node : ");
                scanf("%d", &newnode->data);
                newnode->link = head;
                temp->link = newnode;
                temp = temp -> link;
            }
        }
    }
}

void insertAtBegin()
{
    int val;
    struct node *newnode,*ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of new node : ");
    scanf("%d", &val);
    newnode->data = val;
    while(ptr -> link != head)
    {
        ptr = ptr->link;
    }
    ptr -> link = newnode;
    newnode->link = head;
    head = newnode;
}
void insertAtMid()
{
    int pos, val;
    struct node *newnode, *ptr;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter position : ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        insertAtBegin();
    }
    else
    {
    printf("Enter data of new node : ");
    scanf("%d", &val);
    newnode->data = val;
        pos--;
        while(pos != 1)
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
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of new node : ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->link = head;

    while(ptr -> link != head)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode; 
}
void deleteAtBegin()
{
    struct node *ptr = head;
    while(ptr -> link != head)
    {
        ptr = ptr->link;
    }
    ptr -> link = head -> link;
    ptr = head;
    head = head -> link;
    free(ptr);
    ptr = NULL;
}
void deleteAtMid()
{
    int pos;
    struct node *current, *previous;
    current = previous = head;
    printf("Enter position : ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        deleteAtBegin();
    }
    else
    {
        while(pos != 1)
        {
            previous = current;
            current = current->link;
            pos--;
        }
        previous -> link = current -> link;
        free(current);
        current = NULL;
    }
}
void deleteAtEnd()
{
    struct node *ptr = head;
    while(ptr -> link -> link != head)
    {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = head;
}
void display()
{
    struct node *ptr = head;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }while(ptr != head);
}   
void search()
{
    int key;
    printf("Enter key : ");
    scanf("%d", &key);
    struct node *ptr = head;
    do
    {
        if(ptr->data == key)
        {
            printf("Key found!");
            break;
        }
        ptr = ptr->link;
    }while(ptr != head);
    if(ptr == head)
    {
        printf("Key not found!");
    }
}

int main()
{
    createList();
    int ch = 0;
    while(ch != 9)
    {
        printf("\n1. insertbegin \n 2. insertend \n 3. insertpos \n 4. deletebegin \n 5. deleteend \n 6. deletepos \n 7. search \n 8. Display \n 9. Exit");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch(ch)
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
                deleteAtEnd();
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
                exit(0);
                break;
            default:
                printf("Wrong choice");
                break;
        }
    }
}