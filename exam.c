#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void func(struct node* start)
{
if(start == NULL) return;
printf("\nAddress going to 1st recursion:%d\n",start->data);
func(start->next);
printf("%d ", start->data);
printf("\nAddress going to 2nd recursion:%d\n",start->data);
func(start->next);
}
int main()
{
    //creating pointers which will point to struct node and then using it we can see the data and address inside of it
   struct node* head;
   struct node* second;
   struct node* third;
   struct node* fourth;
   struct node* fifth;

   //creating linkedlist
   head=(struct node*)malloc(sizeof(struct node)); //malloc returns int so we typecast it into struct node*
   second=(struct node*)malloc(sizeof(struct node));
   third=(struct node*)malloc(sizeof(struct node));
   fourth=(struct node*)malloc(sizeof(struct node));
   fifth=(struct node*)malloc(sizeof(struct node));

   //linking second to head
   head->data=10;
   head->next=second;

   //linking third to second 
   second->data=20;
   second->next=third;

   //entering fourth to third
   third->data=30;
   third->next=fourth;

   //Terminating fourth
   fourth->data=40;
   fourth->next=fifth;

   fifth->data=50;
   fifth->next=NULL;

    func(head);
    return 0;
}