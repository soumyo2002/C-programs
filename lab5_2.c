//Write a C code to delete the duplicate nodes in a single linked list. For example, if input: 1->3->3->3->5->6, then output 1->3->5->6.
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
void duplicate()
{
    struct node *temp, *ptr1, *ptr2;
    ptr1 = first;
    while (ptr1 != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data && ptr2->next->next != NULL)
            {
                ptr2 = ptr2->next;
                temp = ptr2;
                ptr2 = ptr2->next;
                ptr1->next = ptr2;
                free(temp);
                temp = NULL;
                ptr2 = ptr1;
            }
            else if (ptr1->data == ptr2->next->data && ptr2->next->next == NULL)
            {
                ptr2 = ptr2->next;
                temp = ptr2;
                ptr1->next = NULL;
                free(temp);
                temp = NULL;
                ptr2 = ptr1;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
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
    duplicate();
    display();
}