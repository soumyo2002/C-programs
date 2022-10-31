//Write a C code that exchanges data of every node with its next node, starting from the first node in a single linked list.
//Example: Input: 1->2->3->4->5->6->7,  Output: 2->1->4->3->6->5->7

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * first;
void create_linkedlist(int a)
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
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void swap()
{
    int a, b;
    struct node *ptr;
    ptr = first;
    while (ptr != NULL && ptr->next != NULL)
    {
        a = ptr->data;
        b = ptr->next->data;
        ptr->next->data = a;
        ptr->data = b;
        ptr = ptr->next->next;
    }
}
void display()
{
    printf("After exchanging data: \n");
    struct node *ptr;
    ptr = first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int b, n;
    printf("Enter the number of nodes needed: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data%d \n", i + 1);
        scanf("%d", &b);
        create_linkedlist(b);
    }
    swap();
    display();
}
