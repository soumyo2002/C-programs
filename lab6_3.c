//Implement PUSH,POP,TRAVERSE in Stack
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
}*top;
void push(int);
void pop(int);
void display();
int main()
{
    int n,a,b;
    top=NULL;
    printf("How many elements in stack do you want to enter \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    printf("Enter data \n");
    scanf("%d",&a);
    push(a);
    }
    printf("Elements in stack \n");
    display();
    printf("\nHow many elements in stack do you want to delete \n");
    scanf("%d",&b);
    if(b<=n)
    {
    pop(b);
    if(b<n)
    {
    printf("Updated elements after popping \n");
    display();
    }
    else
    {
        printf("Stack empty after popping");
    }
    }
    else
    {
        printf("Overflow!");
    }
    return 0;
}
void push(int a)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=top;
    top=temp;
}
void pop(int n)
{
    if(top==NULL)
    {
        printf("Underflow");
    }
    else
    {
    struct node*ptr;
    for(int i=0;i<n;i++)
    {
        ptr=top;
        top=top->next;
        printf("%d popped \n",ptr->data);
        free(ptr);
    }
    }
}
void display()
{
    struct node*ptr;
    ptr=top;
    if(top==NULL)
    {
        printf("Stack is empty \n");
    }
    else
    {
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    }
}