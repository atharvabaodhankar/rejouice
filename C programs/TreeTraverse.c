#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
 
 
struct node
{
    struct node *left;
    int item;
    struct node *right;
};

struct node* createnode(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->item = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insertleft(struct node* root , int val)
{
    root->left = createnode(val);

    return root->left;
}
struct node* insertright(struct node* root , int val)
{
    root->right = createnode(val);

    return root->right;
}

void preorder(struct node* root)
{
    if(root == NULL)
        return;

    printf("%d->", root->item);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d->", root->item);
    inorder(root->right);
}
void postorder(struct node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->item);
}

int main()
{

    struct node *root = createnode(10);
    insertleft(root, 5);
    insertright(root, 20); 

    insertleft(root->left, 3);
    insertright(root->left, 9);

    insertleft(root->right, 15);
    insertright(root->right, 25);

    printf("\nPreorder : ");
    preorder(root);

    printf("\nInorder : ");
    inorder(root);

    printf("\nPostorder : ");
    postorder(root);

    return 0;
}
