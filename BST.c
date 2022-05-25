//Program to implement BST


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* ptr,int k)
{
    if(ptr==NULL)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=k;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else if(ptr->data<k)
    {
        ptr->right=insert(ptr->right,k);
    }
    else if(ptr->data>k)
    {
        ptr->left=insert(ptr->left,k);
    }
    else
    {
        printf("Duplicate key");
    }
    return(ptr);
}

struct node* search(struct node* ptr,int k)
{
    if(ptr==NULL)
    {
        return(NULL);
    }
    else if(ptr->data > k)
    {
        return(search(ptr->left,k));
    }
    else if(ptr->data < k)
    {
        return(search(ptr->right,k));
    }
    else
    {
        return(ptr);
    }
}

void inorder(struct node* ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    inorder(ptr->left);
    printf("%d ",ptr->data);
    inorder(ptr->right);
}


void preorder(struct node* ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    printf("%d ",ptr->data);
    inorder(ptr->left);
    inorder(ptr->right);
}


void postorder(struct node* ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    inorder(ptr->left);
    inorder(ptr->right);
    printf("%d ",ptr->data);
}

int main()
{
    struct node* root=NULL,*ptr;
    int choice,k;
    while(choice!=6)
    {
    printf("Enter 1 for insertion,2 to search,3 for in,4 for pre and 5 for post and 6 to terminate \nNow please enter your choice: \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter data: \n");
        scanf("%d",&k);
        root=insert(root,k);
        break;

        case 2:
        printf("Enter data: \n");
        scanf("%d",&k);
        ptr=search(root,k);
        if(ptr==NULL)
        printf("Number not found \n");
        else
        printf("Number found \n");
        break;

        case 3:
        inorder(root);
        break;

        case 4:
        preorder(root);
        break;

        case 5:
        postorder(root);
        break;

        case 6:
        exit(1);

        default:
        printf("Wrong choice,Try again! \n");

    }
    }
    return 0;
}