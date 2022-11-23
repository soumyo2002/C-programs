/*
Given a Queue consisting of first n natural numbers (in random order). 
The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. 
The operations allowed are: 
Push and Pop elements in the stack 
Delete  from the given Queue. 
Insert into another Queue.
Examples :
 Input : Queue[] = { 5, 1, 2, 3, 4 }; Output : Yes 
Delete the first element of the given Queue i.e 5. 
Push 5 into the stack. 
Now, Delete all the elements of the given Queue and Insert them to the second Queue. 
Now, pop element 5 from the stack and Insert it to the second Queue. 
Input : Queue[] = { 5, 1, 2, 6, 3, 4 }; Output : No 
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*front,*rear,*front1,*rear1,*top;
void enqueue(int);
void show();
void copy(int);
void dequeue(int);
void push(int);
void pop();
int peek();
int check(int,int);
int main()
{
    front=NULL;
    front1=NULL;
    rear=NULL;
    rear1=NULL;
    top=NULL;
    int n,a,min,result;
    printf("Enter the size of queue \n");
    scanf("%d",&n);
    printf("Enter data \n");
    scanf("%d",&a);
    min=a;
    enqueue(a);
    for(int i=1;i<n;i++)
    {
    printf("Enter data \n");
    scanf("%d",&a);
    if(min>a)
    min=a;
    enqueue(a);
    }
    printf("Queue:\n");
    show();
    result=check(min,n);
    if(result==1)
    {
    printf("YES\n");
    }
    else
    {
    printf("NO\n");
    }
}
void enqueue(int x)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}
void show()
{
    while(front!=NULL)
    {
        printf("%d\n",front->data);
        front=front->next;
    }
}
void copy(int x)
{
    struct node*temp1;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=x;
    temp1->next=NULL;
    if(front1==NULL && rear1==NULL)
    {
        front1=rear1=temp1;
    }
    else
    {
        rear1->next=temp1;
        rear1=temp1;
    }
}
void dequeue(int x)//x=0 queue and x=1 stack
{
    struct node*ptr=front;
    if(x==1)
    {
        push(ptr->data);
    }
    else
    {
        copy(ptr->data);
    }
    front=front->next;
}
void push(int x)
{
   struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    } 
}
void pop()
{
   copy(top->data);
   top=top->next;
}
int peek()
{
    if(top!=NULL)
    {
    return(top->data);
    }
    else
    {
        return(-1);
    }
}
int check(int series,int n)
{
    int topper;
    struct node*ptr=front;
    while(ptr!=NULL)
    {
        topper=peek();
        if(ptr->data==series)
        {
            dequeue(0);
            series++;
        }
        else if(ptr->data!=series && topper==-1)
        {
            dequeue(1);
        }
        else if(ptr->data!=series && ptr->data>topper)
        {
            return 0;
        }
        else
        {
           dequeue(1); 
        }
        ptr=ptr->next;
    }
    while(top!=NULL)
    {
        pop();
        series++;
    }
    if(series==n)
    return 1;
}