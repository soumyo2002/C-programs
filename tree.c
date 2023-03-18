#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create()
{
    int x;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d",&x);

    if(x==-1)
    {
        return NULL;
    }
    new->data=x;

    printf("Enter data for left child: \n");
    new->left=create();

    printf("Enter data for right child: \n");
    new->right=create();

    return(new);
}

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    struct node*root=NULL;
    root=create();
    printf("Inorder traversal: \n");
    inorder(root);

    printf("\nPreorder traversal: \n");
    preorder(root);

    printf("\npostorder traversal: \n");
    postorder(root);
    return 0;
}
