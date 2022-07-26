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
    struct node *next;
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
    for (int i = 0; i < n; i++)
    {
        printf("Enter data \n");
        scanf("%d", &a);
        create(a);
    }
    printf("Circular linked list: \n");
    display();
    printf("\nEnter position to insert \n");
    scanf("%d",&pos);
    insert(pos, n);
    printf("Circular linked list after insertion: \n");
    display();
    printf("\nEnter position to delete \n");
    scanf("%d",&pos);
    delete(pos,n+1);
    printf("Circular linked list after deletion: \n");
    display();
    reverse();
    printf("\nReversed Circular linked list: \n");
    display();
    return 0;
}
void create(int a)
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        ptr = first;
        while (ptr->next != first)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    temp->next = first;
}
void display()
{
    struct node *ptr;
    ptr = first;
    while (ptr->next != first)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}
void insert(int pos, int n)
{
    struct node *temp, *ptr,*ptr1;
    int b;
    printf("Enter data of the node to be inserted \n");
    scanf("%d",&b);
    if (pos == 1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = b;
        temp->next = first;
        first = temp;
        ptr = first;
        ptr=ptr->next;
        while (ptr->next != first->next)
        {
            ptr = ptr->next;
        }
        ptr->next = first;
    }
    else if (pos == n)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = b;
        temp->next = first;
        ptr = first;
        while (ptr->next != first)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = b;
        ptr = first;
        ptr1 = first;
        for (int i = 0; i < (pos - 1); i++)
        {
            ptr = ptr->next;
            if (i < (pos - 2))
            {
                ptr1 = ptr1->next;
            }
        }
        temp->next = ptr;
        ptr1->next = temp;
    }
}
void delete(int pos,int n)
{
    struct node * ptr,*ptr1;
    ptr=first;
    ptr1=first;
    if(pos==1)
    {
        while(ptr1->next!=NULL)
        ptr1=ptr1->next;
        first=first->next;
        ptr=NULL;
        free(ptr);
        ptr1->next=first;
    }
    else if(pos==n)
    {
        for(int i=1;i<(n-1);i++)
        {
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
         ptr1=ptr1->next;
         ptr->next=ptr1->next;
         ptr=NULL;
         free(ptr);
    }
    else
    {
        for(int i=1;i<=(pos-2);i++)
        {
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
         ptr1=ptr1->next;
         ptr->next=ptr1->next;
         ptr=NULL;
         free(ptr);
    }
}
/* 100-->1|101-->2|102-->3|103-->4|104-->5|100
         1|104<--2|100<--3|101<--4|102<--5|103<--104
*/
void reverse()
{
    struct node *ptr,*ptr1,*ptr3;
    ptr=first;
    ptr1=first;
    ptr1=ptr1->next;
    ptr3=first;
    ptr3=ptr3->next;
    ptr3=ptr3->next;
    while(ptr3!=first)
    {
    ptr1->next=ptr;
    ptr=ptr1;
    ptr1=ptr3;
    ptr3=ptr3->next;
    }
    ptr1->next=ptr;
    first->next=ptr1;
    first=ptr1;
}