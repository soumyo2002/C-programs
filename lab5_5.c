//Write a C code to split the original single linked list into two sub-lists, where the first and second sub-list contains the even position nodes and odd position nodes of the original list respectively, and then join the second sub-list at the end of the first sub-list. Example: If the list contains 3->4->2->1->7->9->8, then the function needs to produce 3->2->7->8->4->1->9.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * first, *head, *start;
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
void sub()
{
    struct node *ptr;
    ptr = first;
    int a = 1;
    while (ptr != NULL)
    {
        if (a % 2 == 0)
        {
            struct node *temp, *ptr1;
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = ptr->data;
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                ptr1 = head;
                while (ptr1->next != NULL)
                {
                    ptr1 = ptr1->next;
                }
                ptr1->next = temp;
            }
        }
        else
        {
            struct node *temp1, *ptr2;
            temp1 = (struct node *)malloc(sizeof(struct node));
            temp1->data = ptr->data;
            temp1->next = NULL;
            if (start == NULL)
            {
                start = temp1;
            }
            else
            {
                ptr2 = start;
                while (ptr2->next != NULL)
                {
                    ptr2 = ptr2->next;
                }
                ptr2->next = temp1;
            }
        }
        a++;
        ptr = ptr->next;
    }
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
}
void display()
{
    printf("After joining the two sublists: \n");
    struct node *ptr;
    ptr = start;
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
    sub();
    display();
}