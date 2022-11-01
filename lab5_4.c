//Write a C code to convert a doubly linked list into a circular doubly linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * first;
void create_double(int a);
void display();
void convert();
void displaycircular();
void main()
{
    int a;
    first = NULL;
    int n;
    printf("Enter the no of nodes \n");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Empty \n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Enter data%d \n", i + 1);
            scanf("%d", &a);
            create_double(a);
        }
    }
    printf("Linkedlist: \n");
    display();
    convert();
    printf("\n circular Linkedlist: \n");
    displaycircular();
}
void create_double(int a)
{
    struct node *temp = NULL, *ptr = NULL;
    ptr = first;
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
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}
void display()
{
    struct node *ptr = NULL;
    if (first == NULL)
    {
        printf("Nothing to print \n");
    }
    ptr = first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void convert()
{
    struct node *ptr1, *ptr;
    ptr = first;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    first->prev = ptr;
    ptr->next = first;
}
void displaycircular()
{
    struct node *ptr;
    ptr = first;
    if(first!=NULL)
    {
      do
      {
          printf("%d ",ptr->data);
          ptr=ptr->next;
      } while (ptr!=first); 
    }
}
