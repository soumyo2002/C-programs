/*Let a linked list consists of n number of nodes, 
where each node consists of an unique character that represents the grades of the students (O, E, A, B, C ), 
and pointer to the next node. 
Write the C code to group the students having the same grade in consecutive places and 
also finally all the nodes should be in sorting order as per their grade value.  (O->O->E->E->E->A->B->B->C->C->C)
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *next;
};
void sortedInsert(struct Node **head_ref,
                  struct Node *new_node)
{
    struct Node *current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
struct Node *newNode(char new_data)
{
    struct Node *new_node = (struct Node *)malloc(
        sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    return new_node;
}
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%c  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct Node *head = NULL;
    int n;char a;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    struct Node *new_node = newNode(n);
    for(int i=0;i<n;i++)
    {
    printf("Enter grade\n");
    scanf(" %c",&a);
    sortedInsert(&head, new_node);
    new_node = newNode(a);
    }
    printf("\n Created Linked List\n");
    printList(head);
    return 0;
}