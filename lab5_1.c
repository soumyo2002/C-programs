//Write a C code to create and reverse a doubly linked list.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}* first;
void create_double(int a);
void display();
void reverse();
void main()
{
    int a;
    first=NULL;
    int n;
    printf("Enter the no of nodes \n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("Empty \n");
    }
    else
    {
    for(int i=0;i<n;i++)
    {
        printf("Enter data%d \n",i+1);
        scanf("%d",&a);
        create_double(a);
    }
    }
    printf("Linkedlist: \n");
    display();
    reverse();
    printf("\n Linkedlist after reversing: \n");
    display();
}
void create_double(int a)
{
    struct node *temp=NULL,*ptr=NULL;
    ptr=first;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    temp->prev=NULL;
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
}
void display()
{
    struct node *ptr=NULL;
    if(first==NULL)
    {
        printf("Nothing to print \n");
    }
    ptr=first;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void reverse()
{
    struct node *ptr=NULL,*temp=NULL;
    ptr=first;
    while(ptr!=NULL)
    {
        temp=ptr->prev;
        ptr->prev=ptr->next;
        ptr->next=temp;
        ptr=ptr->prev;
    }
    if(temp!=NULL)
    first=temp->prev;
}