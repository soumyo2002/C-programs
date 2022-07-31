#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*front,*rear;
void enqueue(int);
void dequeue();
void display();
int main()
{
    front==NULL;
    rear=NULL;
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
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=temp;
        rear=temp;
        rear->next=front;
    }
    else
    {
       rear->next=temp;
       rear=temp; 
       rear->next=front;
    }
}
void dequeue()
{
    struct node*ptr;
    if(front==NULL && rear==NULL)
    {
        printf("UNDERFLOW!\n");
    }
    else if(front==rear)
    {
        ptr=front;
        printf("%d deleted\n",ptr->data);
        ptr=NULL;
        free(ptr);
        front=NULL;
        rear=NULL;
    }
    else 
    {
        ptr=front;
        printf("%d deleted\n",ptr->data);
        front=front->next;
        ptr=NULL;
        free(ptr);
    }
}
void display()
{
    struct node*ptr=front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
    printf("Queue:\n");
    while(ptr!=rear)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
    }
}