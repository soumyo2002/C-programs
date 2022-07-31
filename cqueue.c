/*
#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[5];
int front=-1;
int rear=-1;
void enqueue(int);
void dequeue();
void display();
int main()
{
    int a;
    int ch;
    while(ch!=4)
    {
    printf("Enter 1 to perform Enqueue,2 to perform Dequeue,3 to Display and 4 to exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter data\n");
        scanf("%d",&a);
        enqueue(a);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(1);
        break;
        default:
        printf("Wrong choice!Try again\n");
    }
    }
    return 0;
}
void enqueue(int x)
{
   if(front==-1 && rear==-1)
   {
      front=rear=0;
      queue[rear]=x;
   }
   else if(((rear+1)%N)==front)
   {
       printf("OVERFLOW!\n");
   }
   else
   {
       rear=(rear+1)%N;
       queue[rear]=x;
   }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("UNDERFLOW!\n");
    }
    else if(front==rear)
    {
        printf("%d deleted",queue[front]);
        front=rear=-1;
    }
    else
    {
       printf("%d deleted",queue[front]);
        front=(front+1)%N; 
    }
}
void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        while(i!=rear)
        {
            printf("%d\n",queue[i]);
            i=(i+1)%N;
        }
        printf("%d\n",queue[i]);
    }
}
*/
