/*Let the number "XYZ" be represented as Z->Y->X in the linked list. If two such numbers are given in two different linked lists, then with the above representation, write a C-program to subtract the second number (represented in the second linked list) from the first number (represented in the first linked list) and store the result in the third linked list with above representation.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void push(struct node** head,int data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}
void display(struct node* n)
{
	while(n!=NULL)
	{
		printf("%d",n->data);
		n = n->next;
	}
}

int main()
{
	int n[3];
	printf("Enter the number to be stored in the list:\n");
	scanf("%d%d",&n[0],&n[1]);
    printf("The number and the output in the form XYZ represented in the form ZYX: \n");
	n[2] = n[0] - n[1];
	struct node* head[3];
	for(int i=0; i<3; ++i)
	{
		head[i] = NULL;
	}
	for(int i=0; i<3; ++i)
	{
			push(&head[i],n[i]/100);
			n[i] = n[i] - (n[i]/100)*100;
			push(&head[i],n[i]/10);
			n[i] = n[i] - (n[i]/10)*10;
			push(&head[i],n[i]);
	}
	for(int i=0; i<3; ++i)
	{
		display(head[i]);
		printf("\n");
	}
	return 0;
}