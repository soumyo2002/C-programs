#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *link;
    int info;
} * start;

void print_now(struct node *beg, struct node *dig)
{
    printf("Pair: \n");
    while (beg != dig)
    {
        printf(" %d", beg->info);
        beg = beg->link;
    }
}

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

void sum_node()
{
    struct node *q, *q2, *q3;
    for (q = start; q != NULL; q = q->link)
    {
        for (q2 = start; q2->link != q->link; q2 = q2->link)
        {
            q3 = q2;
            int sum = 0;
            while (q3 != q)
            {
                sum += q3->info;
                q3 = q3->link;
            }
            if (sum == q->info)
            {
                print_now(q2, q);
            }
        }
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
        printf("Enter data\n");
        scanf("%d", &data);
        create_list(data);
    }

    sum_node();
}