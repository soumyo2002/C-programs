// Implement BST and its operations.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};
struct node *insert(struct node *ptr, int ikey)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (ikey < ptr->info)
    {
        ptr->lchild = insert(ptr->lchild, ikey);
    }
    else if (ikey > ptr->info)
    {
        ptr->rchild = insert(ptr->rchild, ikey);
    }
    else
    {
        printf("Duplicate Key \n");
    }
    return ptr;
}

struct node *search(struct node *ptr, int skey)
{
    if (ptr == NULL)
    {
        printf("Key not found \n");
        return NULL;
    }
    else if (skey < ptr->info)
    {
        return (search(ptr->lchild, skey));
    }
    else if (skey > ptr->info)
    {
        return (search(ptr->rchild, skey));
    }
    else
    {
        return ptr;
    }
}

void preorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d\n", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d\n", ptr->info);
    inorder(ptr->rchild);
}

void postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    postorder(ptr->lchild);
    inorder(ptr->rchild);
    printf("%d\n", ptr->info);
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->lchild != NULL)
        current = current->lchild;
    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->info)
        root->lchild = deleteNode(root->lchild, key);
    else if (key > root->info)
        root->rchild = deleteNode(root->rchild, key);
    else
    {
        if (root->lchild == NULL)
        {
            struct node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct node *temp = root->lchild;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->rchild);
        root->info = temp->info;
        root->rchild = deleteNode(root->rchild, temp->info);
    }
    return root;
}

void main()
{
    struct node *root = NULL, *ptr;
    int choice, k;
    while (choice != 7)
    {
        printf("\nEnter 1 to insert \nEnter 2 for preorder \nEnter 3 for inorder\nEnter 4 for postorder\nEnter 5 for searching \nEnter 6 for deletion \nEnter 7 to terminate \nEnter choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to be inserted \n");
            scanf("%d", &k);
            root = insert(root, k);
            break;

        case 2:
            preorder(root);
            break;

        case 3:
            inorder(root);
            break;

        case 4:
            postorder(root);
            break;

        case 5:
            printf("Enter the key to be searched \n");
            scanf("%d", &k);
            ptr = search(root, k);
            if (ptr == NULL)
                printf("Key is not present \n");
            else
                printf("Key is present \n");
            break;

        case 6:
            printf("Enter the key to be deleted \n");
            scanf("%d", &k);
            root = deleteNode(root, k);
            break;

        case 7:
            exit(1);

        default:
            printf("Wrong choice! \n");
        }
    }
}



/*
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define ESP 0.0001
#define X1(x2,x3) ((20 + (3*x2) - (2*x3)) /8)
#define X2(x1,x3) ((33-(4*x1) + (x3)) /11)
#define X3(x1,x2) ((9- (x1)- (x2) ) /4)
void main()
{ 
double x1=0,x2=0, x3=0,y1, y2, y3;
int i=0;

printf("\n______\n");
printf("In x1\t\t x2\t\t x3 \n") ;
printf("\n______\n");
printf("\n%f\t%f\tf",x1, x2, x3) ;
do 
{
y1=X1(x2,x3);
y2=X2(y1,x3) ;
y3=X3 (y1,y2);
if (fabs (y1-x1)<ESP && fabs (y2-x2)<ESP && fabs (y3-x3)<ESP)
{
printf("\n_______\n");
printf("\n\nx1 = %.31f",y1);
printf("\n\nx2 = %.31f",y2);
printf("\n\nx3 = %.31f",y3);
i = 1;
}
else 
{
x1 = y1; x2 = y2; x3 = y3;
printf("\n%f\t%f\t%f",x1, x2, x3) ; } }
while(i != 1);
getch();
}
*/
