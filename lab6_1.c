//WAP to perform addition and multiplication of polynomials
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int co, ex;
    struct node *next;
} * first1, *first2, *first3;
struct node *create(struct node *, int, int);
void display(struct node *);
void add();
void mul();
int main()
{
    first1 = NULL;
    first2 = NULL;
    first3 = NULL;
    int n, c, e;
    printf("Enter the number of nodes for first polynomial \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter coeficient and exponent \n");
        scanf("%d%d", &c, &e);
        first1 = create(first1, c, e);
    }
    printf("Enter the number of nodes for second polynomial \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter coeficient and exponent \n");
        scanf("%d%d", &c, &e);
        first2 = create(first2, c, e);
    }
    printf("Displaying the first polynomial: \n");
    display(first1);
    printf("Displaying the second polynomial: \n");
    display(first2);
    add();
    mul();
    return 0;
}
struct node *create(struct node *first, int c, int e)
{
    struct node *ptr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->co = c;
    temp->ex = e;
    if (first == NULL || e > first->ex)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        ptr = first;
        while (ptr->next != NULL && ptr->next->ex > e)
            ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return (first);
}
void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        if (ptr->ex != 0)
            printf("%dx^%d", ptr->co, ptr->ex);
        else
            printf("%d", ptr->co);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            if (ptr->co > 0)
                printf("+");
        }
        else
            printf("\n");
    }
}
void add()
{
    struct node *ptr1, *ptr2;
    ptr1 = first1;
    ptr2 = first2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->ex > ptr2->ex)
        {
            first3 = create(first3, ptr1->co, ptr1->ex);
            ptr1 = ptr1->next;
        }
        else if (ptr1->ex < ptr2->ex)
        {
            first3 = create(first3, ptr2->co, ptr2->ex);
            ptr2 = ptr2->next;
        }
        else
        {
            first3 = create(first3, ptr1->co + ptr2->co, ptr2->ex);
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
    }
    while(ptr1!=NULL)
    {
        first3 = create(first3, ptr1->co, ptr1->ex);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL)
    {
       first3 = create(first3, ptr2->co, ptr2->ex);
       ptr2 = ptr2->next; 
    }
    printf("resultant polynomial after addition: \n");
    display(first3);
}
void mul()
{
    struct node* ptr1,*ptr2;
    first3=NULL;
    ptr1 = first1;
    while (ptr1 != NULL)
    {
        ptr2 = first2;
        while(ptr2!=NULL)
        {
           first3=create(first3,ptr1->co*ptr2->co,ptr1->ex+ptr2->ex);
           ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    printf("polynomial after multiplication: \n");
    display(first3);
}