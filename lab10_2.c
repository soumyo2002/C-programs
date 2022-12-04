//Write a C code to add two polynomials having two numbers of unknown variables
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int co,ex;
    struct node * next;
}*first1,*first2,*first3;
struct node * input(int a,int b,struct node *first)
{
    struct node *ptr,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->co=a;
    temp->ex=b;
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
    return(first);
}
void add(struct node*first1,struct node*first2)
{
    struct node *ptr1,*ptr2;
    ptr1=first1;
    ptr2=first2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->ex>ptr2->ex)
        {
            first3=input(ptr1->co,ptr1->ex,first3);
            ptr1=ptr1->next;
        }
        else if(ptr1->ex<ptr2->ex)
        {
           first3=input(ptr2->co,ptr2->ex,first3); 
           ptr2=ptr2->next;
        }
        else
        {
          first3=input(ptr2->co+ptr1->co,ptr2->ex,first3); 
          ptr1=ptr1->next;
          ptr2=ptr2->next; 
        }
    }
    while(ptr1!=NULL)
    {
       first3=input(ptr1->co,ptr1->ex,first3);
       ptr1=ptr1->next; 
    }
    while(ptr2!=NULL)
    {
        first3=input(ptr2->co,ptr2->ex,first3); 
        ptr2=ptr2->next;
    }
}
void display(struct node *first3)
{
    struct node *ptr=first3;
    while(ptr!=NULL)
    {
        printf("%dx^%d",ptr->co,ptr->ex);
        ptr=ptr->next;
        if(ptr!=NULL && ptr->co>0)
        printf("+");
        else
        printf("\n");
    }
}
int main()
{
    first1=NULL;
    first2=NULL;
    first3=NULL;
    int n,m,a,b;
    printf("Enter the number of inputs for first and second polynomials:\n");
    scanf("%d%d",&n,&m);
    printf("First polynomial:\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter coefficient and exponent part:\n");
        scanf("%d%d",&a,&b);
        first1=input(a,b,first1);
    }
    printf("Second polynomial:\n");
    for(int i=0;i<m;i++)
    {
        printf("Enter coefficient and exponent part:\n");
        scanf("%d%d",&a,&b);
        first2=input(a,b,first2);
    }
    add(first1,first2);
    printf("Resulting polynomial:\n");
    display(first3);
    return 0;
}