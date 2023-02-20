#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};

void linkedlistprint(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("ELEMENT: %d \n",ptr->data);
        ptr=ptr->next; //counter for pointer
    }
}
int main()
{
    //creating pointers which will point to struct node and then using it we can see the data and address inside of it
   struct node* head;
   struct node* second;
   struct node* third;
   struct node* fourth;

   //creating linkedlist
   head=(struct node*)malloc(sizeof(struct node)); //malloc returns int so we typecast it into struct node*
   second=(struct node*)malloc(sizeof(struct node));
   third=(struct node*)malloc(sizeof(struct node));
   fourth=(struct node*)malloc(sizeof(struct node));

   //linking second to head
   head->data=11;
   head->next=second;

   //linking third to second 
   second->data=23;
   second->next=third;

   //entering fourth to third
   third->data=71;
   third->next=fourth;

   //Terminating fourth
   fourth->data=66;
   fourth->next=NULL;

   linkedlistprint(head);
}