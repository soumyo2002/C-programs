/*
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
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}*front,*rear;
void enqueue();
void dequeue();
void display();
int main()
{
    front=rear=NULL;
    int ch;
    while(ch!=4)
    {
    printf("Enter 1 to perform Enqueue,2 to perform Dequeue,3 to Display and 4 to exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(1);
        break;
        default:
        printf("Wrong choice!Try again\n");
    }
    }
    return 0;
}
void enqueue()
{
struct node *temp,ptr;
printf("Enter data\n");
scanf("%d",&temp->data);
temp->next=NULL;
if(first=NULL)
{
    first=rear=temp;
}
else
{
    temp->
}
}
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *link;
};

void insert();
void display();


typedef struct node DATA_NODE;

DATA_NODE *head_node, *first_node, *temp_node = 0, *prev_node, next_node;
int data;

int main() {
  int option = 0;
  while (option < 5) {

    printf("\nOptions\n");
    printf("1 : Insert into Linked List \n");
    printf("2 : Display Linked List\n");
    printf("Others : leave()\n");
    printf("Enter your option: \n");
    scanf("%d", &option);
    switch (option) {
      case 1:
        insert();
        break;
      case 2:
        display();
        break;
      default:
        break;
    }
  }

  return 0;
}

void insert() {
  printf("\nEnter Element for Insert Linked List : \n");
  scanf("%d", &data);

  temp_node = (DATA_NODE *) malloc(sizeof (DATA_NODE));

  temp_node->info = data;

  if (first_node == 0) {
    first_node = temp_node;
  } else {
    head_node->link = temp_node;
  }
  temp_node->link = 0;
  head_node = temp_node;
  fflush(stdin);
}

void display() {
  int count = 0;
  temp_node = first_node;
  printf("\nDisplay Linked List : \n");
  while (temp_node != 0) {
    printf("%d ", temp_node->info);
    count++;
    temp_node = temp_node->link;
  }
}
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * first, *ptr;
void create(int);
void display();
void reverse(struct node *);
int main()
{
    first = NULL;
    ptr = NULL;
    int a, n;
    printf("Enter the number of nodes \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data \n");
        scanf("%d", &a);
        create(a);
    }
    printf("Linked list: \n");
    display();
    reverse(first);
    printf("\nLinked list after reversing it: \n");
    display();
    return 0;
}
void create(int a)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = a;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        ptr = first;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
void display()
{
    ptr = first;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void reverse(struct node *ptr)
{
    if (ptr->next == NULL)
    {
        first = ptr;
        return;
    }
    reverse(ptr->next);
    struct node *q;
    q = ptr->next;
    q->next = ptr;
    ptr->next = NULL;
}
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}* top;
void push();
void pop();
void display();
int main()
{
    int n;
    top=NULL;
    printf("Enter the number of nodes \n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        push();
    }
    printf("Stack:\n");
    display();
    pop();
    printf("\nUpdated Stack:\n");
    display();
    return 0;
}
void push()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter data \n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("Underflow");
    }
    else
    {
         struct node *temp;
        printf("\n%d is popped",top->data);
        temp=top;
        top=top->next;
        temp=NULL;
        free(temp);
    }
}
void display()
{
    struct node *ptr=top;
    while(ptr->next!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}
*/

#include<stdio.h>
int main()
{
    int a;
    for(int i=0;i<5;i++)
    {
    printf("Enter 1 to know strawhat pirates,2 to know his allies,3 to know the 4 emperors and 5 to know future king of the pirates \n ");
    scanf("%d",&a);
    if(a==1)
    {
        printf("Strawhat pirates: \n 1.Bador.D.Luffy \n2.Navigation master Zoro \n3.Cat Buglar Nami \n4.Great warrior of the sea(with 8,000 followers)Usopp \n5.Kalo pa sakt launda,A failure of vinsmoke family,Sanji \n6.Racoon dog tony tony chopper(pet) \n7.Ma Durga Robin(10 hands) \n8.Iron man copied Franky  \n9.Billy Mandi aur life mein hadi wala Hadi Brook \n10.Illish mach Jimbe \n ");
    }
    else if(a==2)
    {
        printf("Traffy,kid,batholomeu");
    }
    else if(a==3)
    {
        printf("Kalo Dari \nShanks \nKaido \nBigmom");
    }
    else
    {
        printf("BUGGY WILL BE THE NEXT KING OF THE PIRATES \n");
    }
    }
    for(int i=0;i<2;i++)
    {
    int ch;
    printf("Enter bounty of the man to be searched \n");
    scanf("%d",&ch);
    if(ch==1770000)
    printf("Kalo pa sakt launda,A failure of vinsmoke family,Sanji");
    else
    printf("Racoon dog tony tony chopper(pet)");
    }
    printf("TO BE CONTINUED")
}
