/*
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
} * first; //used to store the first linkedlist
void createLinkedlist(int a)
{
    struct node *temp; //used to create a temporary node to pass it over to the chain of linkedlists formed
    struct node *ptr;  //used for traversing the linkedlist
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = a;     //creating temporary linkedlist
    temp->next = NULL; //creating temporary linkedlist
    if (first == NULL) //if the first is empty then that means that the LL is empty so we fill the first element
    {
        first = temp; //assign the temporary LL to start,SO first WILL CONTAIN THE ADDRESS WHICH WILL "SELF REFERENCE" TO THE NODE AND STORE TEMP DATA AND ADDRESS OF THE NEXT LL
    }
    else //if LL is not empty
    {
        //suppose we have created a LL so far as 23->42->73->NULL and temp has 99->NULL
        ptr = first;              //here ptr will point to start of the LL
        while (ptr->next != NULL) //we won't write just ptr else it would skip 73->NULL
            ptr = ptr->next;      //Here the ptr will tranverse the LL till it reaches NULL
        ptr->next = temp;         //here we assign address of temp to ptr so it will now connect to LL temp and can access its data and next address
        //Thus the new LL becomes 23->42->73->99->NULL
    }
}
void display()
{
    struct node *ptr;  //pointer to traverse the LL
    if (first == NULL) //if first is empty then that means LL first is empty
    {
        printf("Linked List is Empty! \n");
        return;
    }
    ptr = first;
    while (ptr != NULL) //we wont write ptr->next,otherwise in 23->44->NULL,it will ignore 44->NULL and 44 won't print,whereas of we write only ptr then it will print 44 and then the LL becomes empty and it will stop
    {
        printf("%d \n", ptr->val);
        ptr = ptr->next;
    }
}
void rev_even()
{
    
}
int main()
{
    struct node *first = NULL; //start will be empty
    int n;                     // to store the number of nodes required
    printf("Enter the number of nodes required: \n");
    scanf("%d", &n);
    int a; //to store the data part of linkedlist
    printf("Enter data: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        createLinkedlist(a);
    }
    printf("Elements inside linkedlist \n");
    display();
    rev_even();
    printf("Elements inside linkedlist \n");
    display();
    return 0;
}
*/
/*
#include<stdio.h>
void replace(int a[], int size){
    int j;
for(int i=0;i<size-1;i++){
int flag=0;
for(j=i+1;j<size;j++)
if(a[j]>a[i]){
flag=1; break;
} 
if(flag)
a[i]=a[j];
} }

int main()
{
    int a[20];
    printf("Enter:\n");
    for(int i=0;i<20;i++)
    {
    scanf("%d",&a[i]);
    }
    replace(a,20);
    printf("New array:\n");
    for(int i=0;i<20;i++)
    {
    printf("%d\n",a[i]);
    }
}
*/
#include<stdio.h>
int main()
{
    int a[3][4];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n%d",*((a+3)+2));
}
