/*Write the C code to delete all the nodes from the single linked list which are
divisible by a given number k. (The INFO part of the node must be divisible by k)
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *link;
    int info;
} * start;

void create_list(int data)
{
    struct node *q, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        q = start;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = tmp;
    }
}

void delete_divisible(int k)
{
    struct node *prev, *q;
    int n = 0;
    q = start;
    prev = start;
    while (q != NULL)
    {
        if (n == 0 && q->info % k == 0)
        {
            start = q->link;
            free(q);
            q = start;
            n = 0;
        }
        else if (n > 0 && q->info % k == 0)
        {
            prev->link = q->link;
            free(q);
            q = prev->link;
        }
        else
        {
            prev = q;
            q = q->link;
            n++;
        }
    }
}

void display()
{
    struct node *q;
    if (start == NULL)
    {
        printf("Life is empty");
        return;
    }
    q = start;
    while (q != NULL)
    {
        printf("%d\n", q->info);
        q = q->link;
    }
}

int main()
{
    int no_node;
    start = NULL;
    printf("Enter the number of nodes : ");
    scanf("%d", &no_node);

    int data;
    for (size_t i = 0; i < no_node; i++)
    {
        scanf("%d", &data);
        create_list(data);
    }

    int k;
    printf("Enter the value of k : ");
    scanf("%d", &k);
    delete_divisible(k);

    display();
}