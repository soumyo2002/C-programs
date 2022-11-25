//Write a C code to replace every element in a linked list with the next greatest element present in 
// the same list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*first;
void input();
void update();
int large(struct node*);
void display();
int main()
{
    int a;
    first=NULL;
    int n;
    printf("Enter the size of Linkedlist \n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    printf("Enter data \n");
    scanf("%d",&a);
    input(a);
    }
    update();
    printf("Resulting linkedlist:\n");
    display();
    return 0;
}
void input(int x)
{
    struct node*temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
      ptr=first;
      while(ptr->next!=NULL)
      ptr=ptr->next;
      ptr->next=temp;  
    }
}
void update()
{
     struct node*ptr,*ptr1;
     int max;
     ptr=first;
     ptr1=ptr->next;
     while(ptr1!=NULL)
     {
         max=large(ptr1);
         if(ptr->data<max)
         {
         ptr->data=max;
         }
         ptr=ptr->next;
         ptr1=ptr1->next;
     }
}
int large(struct node*ptr)
{
    int max=0;
    while(ptr!=NULL)
    {
        if(max<ptr->data)
        max=ptr->data;
        ptr=ptr->next;
    }
    return(max);
}
void display()
{
    struct node*ptr=first;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
