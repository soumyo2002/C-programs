/* ptr==NULL(means LL is empty) whereas ptr->link==NULL (means adress of LL is link). 
Example: there is an LL:23->42->73->NULL
now ptr==NULL then enter 99->NULL then new LL will be 23->42->73->NULL  99->NULL(a disjointed LL)
but ptr->next==NULL then enter 99->NULL then when it reaches 73->NUll it will replace NUll with 99 and new address NUll
so new LL will be 23->42->73->99->NULL
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
} * first; //used to store the first linkedlist
void createLinkedlist(int a)
{
        struct node * temp;//used to create a temporary node to pass it over to the chain of linkedlists formed
        struct node * ptr;//used for traversing the linkedlist
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=a;//creating temporary linkedlist
        temp->next=NULL;//creating temporary linkedlist
        if(first==NULL)//if the first is empty then that means that the LL is empty so we fill the first element
        {
            first=temp;//assign the temporary LL to start,SO first WILL CONTAIN THE ADDRESS WHICH WILL "SELF REFERENCE" TO THE NODE AND STORE TEMP DATA AND ADDRESS OF THE NEXT LL
        }
        else//if LL is not empty
        {
            //suppose we have created a LL so far as 23->42->73->NULL and temp has 99->NULL
            ptr=first;//here ptr will point to start of the LL
            while(ptr->next!=NULL)//we won't write just ptr else it would skip 73->NULL
            ptr=ptr->next;//Here the ptr will tranverse the LL till it reaches NULL
            ptr->next=temp;//here we assign address of temp to ptr so it will now connect to LL temp and can access its data and next address
            //Thus the new LL becomes 23->42->73->99->NULL
        }
}
void display()
{
    struct node* ptr;//pointer to traverse the LL
    if(first==NULL)//if first is empty then that means LL first is empty
    {
        printf("Linked List is Empty! \n");
        return;
    }
    ptr=first;
    while(ptr!=NULL)//we wont write ptr->next,otherwise in 23->44->NULL,it will ignore 44->NULL and 44 won't print,whereas of we write only ptr then it will print 44 and then the LL becomes empty and it will stop
    {
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}
void search(int b)
{
    int pos=1;
    struct node * ptr;//pointer to traverse the LL
        ptr=first;
        while(ptr!=NULL)
        {
            if(ptr->data==b)
            {
            printf("Element found at %d position \n",pos);
            return;
            }
            ptr=ptr->next;
            pos++;
        }
        if(ptr==NULL)//if LL reaches the end
        {
            printf("Not found: \n");
        }
}
void freq(int c)
{
        int count=0;
        struct node * ptr;//pointer to traverse the LL
        ptr=first;
        while(ptr!=NULL)
        {
            if(ptr->data==c)
            {
            count++;
            }
            ptr=ptr->next;
        }
        if(count==0)
        {
            printf("element not found");
        }
        else
        {
            printf("Frequency of the element is %d",count);
        }
}
int main()
{
    struct node * first=NULL;//start will be empty
    int n;// to store the number of nodes required
    printf("Enter the number of nodes required: \n");
    scanf("%d",&n);
    int a;//to store the data part of linkedlist
    printf("Enter data: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        createLinkedlist(a);
    }
    printf("Elements inside linkedlist \n");
    display();
    int b;
    printf("Enter the number to be searched:\n");
    scanf("%d",&b);
    search(b);
    int c;
    printf("Enter the number whose frequency has to be searched:\n");
    scanf("%d",&c);
    freq(c);
}