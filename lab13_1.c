/*
Given a BST and a range low-to-high(inclusive). Write a C code to count the number of nodes in the BST that lie in the given range. 
 
Input:
  	 10
 	/  \
   5    50
  /     / \
 1     40  100
 
low = 5, high = 45
Output: 3 (5, 10, 40 are the nodes in the range.)
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(struct node* ptr,int d)
{
    if(ptr==NULL)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=d;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else if(ptr->data>d)
    {
        ptr->left=create(ptr->left,d);
    }
    else if(ptr->data<d)
    {
        ptr->right=create(ptr->right,d);
    }
    return(ptr);
}

int freq(struct node* ptr,int l,int h)
{
    if(ptr==NULL)
    {
        return 0;
    }
    else if(ptr->data==h && ptr->data==l)
    {
        return 1;
    }
    else if(ptr->data>=l && ptr->data<=h)
    {
        return 1+freq(ptr->left,l,h)+freq(ptr->right,l,h);
    }
    else if(ptr->data<l)
    {
        return(freq(ptr->right,l,h));
    }
    else
    {
       return(freq(ptr->left,l,h)); 
    }
}

int main()
{
    struct node* root=NULL;
    int n,d,l,h;
    int arr[n];
    printf("Enter the number of nodes \n");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
    {
    printf("Enter the data \n");
    scanf("%d", &d);
    root=create(root,d);
    }

    printf("Enter Range: \n");
    scanf("%d%d",&l,&h);

    int z=freq(root,l,h);
    printf("Frequency=%d",z);

    return 0;
}