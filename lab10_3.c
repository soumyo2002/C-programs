/*Write a C code to delete all prime numbers present in a doubly linked list.
For example, if input: 5->6->11->4->12->16, then output 6->4->12->16.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
}*first;
void insert(int);
int prime(int);
void delete();
void display();
int main()
{
    int n,a;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data\n");
        scanf("%d",&a);
        insert(a);
    }
    printf("Double linkedlist:\n");
    display();
    delete();
    printf("Updated double linkedlist:\n");
    display();
    return 0;
}
void insert(int x)
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        ptr=first;
        while(ptr->next!=NULL)
        ptr=ptr->next;
        temp->prev=ptr;
        ptr->next=temp;
    }
}
int prime(int a)
{
    int c = 0;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            c++;
            break;
        }
    }
    if (c > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void display()
{
    struct node*ptr;
    ptr=first;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void delete()
{
    struct node*ptr,*ptr1,*ptr3;
    ptr=first;
    while(ptr!=NULL)
    {
        if(prime(ptr->data)==1)
        {
            if(ptr->prev==NULL)
            {
                first=first->next;
                first->prev=NULL;
                ptr1=ptr;
                ptr1=NULL;
                free(ptr1);
                ptr=first;
            }
            else if(ptr->next==NULL)
            {
                ptr1=first;
                while(ptr1->next->next!=NULL)
                ptr1=ptr1->next;
                ptr1->next=NULL;
                ptr=NULL;
                free(ptr);
            }
            else
            {
                ptr3=first;
                while(ptr3->next!=ptr)
                ptr3=ptr3->next;
                ptr1=ptr->next;
                ptr3->next=ptr->next;
                ptr1->prev=ptr->prev;
                ptr3=ptr;
                ptr3=NULL;
                free(ptr3);
                ptr=ptr1;
            }
        }
        else
        {
            ptr=ptr->next;
        }
    }
}





