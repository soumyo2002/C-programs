/*Implement the following operations on a single linked list using C.
Create
traverse
Insert
Delete
reverse
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} * first;
void create(int a)
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        ptr = first;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
void display()
{
    struct node *ptr;
    if (first == NULL)
    {
        printf("Linked list is empty \n");
        return;
    }
    else
    {
        ptr = first;
        printf("Elements: \n");
        while (ptr != NULL)
        {
            printf("%d \n", ptr->data);
            ptr = ptr->next;
        }
    }
}
void insert(int a, int pos, int n)
{
    struct node *ptr, *temp;
    ptr = first;
    temp = (struct node *)malloc(sizeof(struct node));
    if (first == NULL)
    {
        printf("List is already empty \n");
        return;
    }
    else if (pos == 1)
    {
        temp->data = a;
        temp->next = first;
        first = temp;
    }
    else if (pos == n)
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        temp->data = a;
        temp->next = NULL;
        ptr->next = temp;
    }
    else
    {
        for (int i = 1; i < (pos - 1); i++)
        {
            ptr = ptr->next;
        }
        temp->data = a;
        temp->next = ptr->next;
        ptr->next = temp;
    }
    printf("Elements after insertion: \n");
    display();
}
void delete (int pos, int n)
{
    struct node *ptr, *temp;
    ptr = first;
    if (first == NULL)
    {
        printf("List is already empty \n");
        return;
    }
    else if (pos == 1)
    {
        temp = first;
        first = first->next; //first moves to the next element
        free(temp);          //we delete the first element
        temp = NULL;         //delete the address of the deleted element of LL
    }
    else if (pos == n)
    {
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
        ptr = NULL;
    }
    else
    {
        temp = first;
        for (int i = 0; i < (pos - 1); i++)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        free(ptr);
        ptr = NULL;
    }
    printf("Elements after deletion");
    display();
}
void reverse()
{
    struct node *temp, *temp1;
    temp = NULL;
    while (first != NULL)
    {
        temp1 = first->next;
        first->next = temp;
        temp = first;
        first = temp1;
    }
    first = temp;
    printf("Reversed linkedlist \n");
    display();
}
int main()
{
    int a, c = 0, n, y, v, s, p;
    struct node *first = NULL;
    while (c < 6)
    {
        printf("Enter 1 to create a single linked list \n Enter 2 to traverse a single linked list \n Enter 3 to insert in a single linked list \n Enter 4 to delete a single linked list \n Enter 5 to reverse a single linked list \n");
        printf(" \n Press 6 to Exit \n");
        printf("Enter your choice: \n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the number of nodes to be created \n");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter data \n");
                scanf("%d", &v);
                create(v);
            }
            break;

        case 2:
            display();
            break;

        case 3:
            printf("Enter data \n");
            scanf("%d", &s);
            printf("Enter position \n");
            scanf("%d", &p);
            insert(s, p, n);
            break;

        case 4:
            printf("Enter the position to be deleted \n");
            scanf("%d", &y);
            delete (y, n);
            break;

        case 5:
            reverse();
            break;

        case 6:
            exit(1);

        default:
            printf("Wrong choice!Try again \n");
        }
        if (a > 0 && a < 7)
            c++;
    }
    return 0;
}