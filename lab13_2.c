/*Given two single linked lists, write a C code to merge their nodes together to make one list,
taking nodes alternately between the two lists.
So the output with {1, 2, 3} and {7, 13, 1} should yield {1, 7, 2, 13, 3, 1}.
If either list runs out, all the nodes should be taken from the other list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *create(struct node *first, int d)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = d;
    ptr->link = NULL;
    if (first == NULL)
    {
        first = ptr;
    }
    else
    {
        temp = first;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = ptr;
    }
    return (first);
}

struct node *join(struct node *first1, struct node *first2, struct node *first3)
{
    struct node *ptr1 = first1, *ptr2 = first2, *ptr3 = first3;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        ptr3 = create(ptr3, ptr1->data);
        ptr3 = create(ptr3, ptr2->data);
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }

    while (ptr1 != NULL)
    {
        ptr3 = create(ptr3, ptr1->data);
        ptr1 = ptr1->link;
    }

    while (ptr2 != NULL)
    {
        ptr3 = create(ptr3, ptr2->data);
        ptr2 = ptr2->link;
    }

    return (ptr3);
}

void display(struct node *first)
{
    struct node *ptr = first;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *first1 = NULL;
    struct node *first2 = NULL;
    struct node *first3 = NULL;
    int n, d;
    printf("Enter the number of inputs in first LinkedList \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data \n");
        scanf("%d", &d);
        first1 = create(first1, d);
    }

    printf("Enter the number of inputs in second LinkedList \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data \n");
        scanf("%d", &d);
        first2 = create(first2, d);
    }

    printf("1st set: \n");
    display(first1);

    printf("2nd set: \n");
    display(first2);

    first3 = join(first1, first2, first3);
    printf("Combination of 1st and 2nd set: \n");
    display(first3);

    return 0;
}