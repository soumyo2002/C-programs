/*Write a C code to traverse a singly linked list from the beginning to the end and reverse 
all the increasing and decreasing sequence of components present in the list. 
Component is the collection of continuous elements either in increasing or decreasing order. 
Example: Let the list contains 1, 2, 3, 7, 4, 2, 9, 7, 8 elements. Here the components are “1, 2, 3, 7”, “4, 2”, “9, 7”, and “8”. 
The code should produce the list with elements 7, 3, 2, 1, 2, 4, 7, 9, 8.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * first;
void create(int a);
void display();
void component();
void greater();
void reverse();
int main()
{
    int n, a;
    first = NULL;
    printf("Enter number of nodes \n");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Linkedlist is empty \n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Enter the elements: \n");
            scanf("%d", &a);
            create(a);
        }
    }
    display();
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
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
void display()
{
    struct node *ptr;
    if (first == NULL)
    {
        printf("Linked list is empty \n");
        return;
    }
    else
    {
        ptr = first;
        printf("Elements: \n");
        while (ptr != NULL)
        {
            printf("%d \n", ptr->data);
            ptr = ptr->next;
        }
    }
}
void component()
{
    struct node *ptr;
    ptr = first;
    while (ptr != NULL)
    {
        if (ptr->data < ptr->next->data)
        {
            greater();
        }
    }
}
void greater()
{
    struct node *ptr;
    ptr = first;
    while (ptr != NULL)
    {
        if(ptr->data > ptr->next->data)
        {
            break;
        }
        ptr=ptr->next;
    }
    reverse(ptr);
}
void reverse(struct node *ptr)
{
    struct node *temp, *temp1;
    temp = NULL;
    ptr=ptr->next;
    while (first != ptr)
    {
        temp1 = first->next;
        first->next = temp;
        temp = first;
        first = temp1;
    }
    first = temp;
    display();
}
