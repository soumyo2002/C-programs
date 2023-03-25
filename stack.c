#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N],top=-1;
void push();
void pop();
void display();
int main()
{
    int ch=1;
    while(ch!=4)
    {
    printf("Enter 1 for Push,2 for pop,3 to display and 4 to exit \nEnter your Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
    push();
    break;
    case 2:
    pop();
    break;
    case 3:
    display();
    break;
    case 4:
    exit(1);
    break;
    default:
    printf("Wrong choice \n");
    }
    }
    return 0;
}
void push()
{
    if(top==N-1)
    {
        printf("OVERFLOW! \n");
    }
    else
    {
        top++;
        printf("Enter data \n");
        scanf("%d",&stack[top]);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("UNDERFLOW! \n");
    }
    else
    {
        printf("%d is popped \n",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("STACK:\n");
        for(int i=top;i>=0;i--)
        printf("%d\n",stack[i]);
    }
}