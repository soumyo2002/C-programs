//Write a program to copy the contents of one stack to another stack in the same order without using any extra data structure.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * top1, *top2;
struct node * push(struct node *, int);
void reverse(struct node *);
void copy();
void display(struct node *);
int main()
{
    int n, a;
    top1 = NULL;
    top2 = NULL;
    printf("How many elements in stack do you want to enter \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data \n");
        scanf("%d", &a);
        top1=push(top1, a);
    }
    printf("Elements in stack \n");
    display(top1);
    reverse(top1);
    copy();
}
struct node * push(struct node *top, int a)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = top;
    top = temp;
    return(top);
}
void reverse(struct node *ptr)
{
    if (ptr->next == NULL)
    {
        top1 = ptr;
        return;
    }
    reverse(ptr->next);
    struct node *q;
    q = ptr->next;
    q->next = ptr;
    ptr->next = NULL;
}
void display(struct node *top)
{
    struct node *ptr;
    ptr = top;
    if (top == NULL)
    {
        printf("Stack is empty \n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
void copy()
{
    struct node *ptr1;
    ptr1 = top1;
    while (ptr1 != NULL)
    {
        top2=push(top2, ptr1->data);
        ptr1 = ptr1->next;
    }
    printf("\nElements of copied stack \n");
    display(top2);
}