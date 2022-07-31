/*Implement the following operations on a circular linked list using C.
Create
traverse
Insert
Delete
reverse
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
} * first;
void create(int);
void display();
void insert(int, int);
void delete (int,int);
void reverse();
int main()
{
    first = NULL;
    int n, a, pos;
    printf("Enter the number of nodes \n");
    scanf("%d", &n);
    if(n==0)
    {
        printf("List is empty");
    }
    else
    {
    for (int i = 0; i < n; i++)
    {
        printf("Enter data \n");
        scanf("%d", &a);
        create(a);
    }
    printf("Doubly linked list: \n");
    display();
    printf("\nEnter position to insert \n");
    scanf("%d",&pos);
    insert(pos, n);
    printf("Doubly linked list after insertion: \n");
    display();
    printf("\nEnter position to delete \n");
    scanf("%d",&pos);
    delete(pos,n+1);
    printf("Doubly linked list after deletion: \n");
    display();
    reverse();
    printf("\nReversed Doubly linked: \n");
    display();
    }
    return 0;
}
void create(int a)
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    temp->prev = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        ptr = first;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->prev=ptr;
        ptr->next=temp;
    }
}
void display()
{
    if(first==NULL)
    {
        printf("List is empty");
    }
    else
    {
    struct node *ptr;
    ptr = first;
    while (ptr->next != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    }
}
void insert(int pos,int n)
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    int b;
    printf("Enter data of the node to be inserted \n");
    scanf("%d",&b);
    temp->data = b;
    temp->next = NULL;
    temp->prev = NULL;
    ptr=first;
    if(pos==1)
    {
      temp->next=ptr;
      first->prev=temp;
      first=temp;  
    }
    else if(pos==n)
    {
        while(ptr->next!=NULL)
        ptr=ptr->next;
        temp->prev=ptr;
        ptr->next=temp;
    }
    else
    {
        for(int i=1;i<(pos-1);i++)
        {
            ptr=ptr->next;
        }
            temp->next=ptr->next;
            temp->prev=ptr;
            ptr->next=temp;
    }
}
void delete(int pos,int n)
{
    struct node * ptr,*ptr1,*ptr2;
    ptr=first;
    ptr1=first;
    ptr2=first;
    if(pos==1)
    {
        first=first->next;
        ptr=NULL;
        free(ptr);
    }
    else if(pos==n)
    {
        while(ptr->next->next!=NULL)
        {
        ptr=ptr->next;
        ptr1=ptr1->next;
        }
        ptr1=ptr1->next;
        ptr->next=NULL;
        ptr1=NULL;
        free(ptr1);
    }
    else
    {
        for(int i=1;i<(pos-2);i++)
        {
            ptr=ptr->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        ptr2=ptr2->next;
        ptr->next=ptr1->next;
        ptr2->prev=ptr1->prev;
        ptr1=NULL;
        free(ptr1);
    }
}
void reverse()
{
    struct node *ptr1,*ptr2;
    ptr1=first;
    ptr2=ptr1->next;
    while(ptr2!=NULL)
    {
        ptr1->next=ptr1->prev;
        ptr1->prev=ptr2;
        ptr1=ptr2;
        ptr2=ptr2->next;
    }
    first=ptr1;
    ptr2=ptr1->next;
    ptr1->next=ptr1->prev;
    ptr1->prev= ptr2;
}