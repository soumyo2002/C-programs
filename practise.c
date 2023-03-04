/*#include<stdio.h>
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
    //creating pointers
   struct node* head;
   struct node* second;
   struct node* third;
   struct node* fourth;

   //creating linkedlist
   head=(struct node*)malloc(sizeof(struct node));
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
}*/


/*#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    fork();
    fork();
    fork();
    printf("Hello world");
    return 0;
}*/

#include <stdio.h>
#include<unistd.h>
#define _XOPEN_SOURCE 600
int main()
{
    int n=fork();
    if(n>0)
    printf("P");
    else
    printf("C");
    return 0;
}