// Construct a BST, implement all the cases of deletion, then display the tree using preorder traversal.
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

struct node *case_a(struct node *root, struct node *par, struct node *ptr)
{
    if (par == NULL)
        root = NULL;
    else if (ptr == par->lchild)
        par->lchild = NULL;
    else
        par->rchild = NULL;
    free(ptr);
    return (root);
}

struct node *case_b(struct node *root, struct node *par, struct node *ptr)
{
    struct node *child;
    if (ptr->lchild != NULL)
        child = ptr->lchild;
    else
        child = ptr->rchild;
    if (par == NULL)
        root = child;
    else if (ptr == par->lchild)
        par->lchild = child;
    else
        par->rchild = child;
    free(ptr);
    return (root);
}

struct node *case_c(struct node *root, struct node *par, struct node *ptr)
{
    struct node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->rchild;
    while (succ->lchild != NULL)
    {
        parsucc = succ;
        succ = succ->lchild;
    }
    ptr->info = succ->info;
    if (succ->lchild == NULL && succ->rchild == NULL)
        root = case_a(root, parsucc, succ);
    else
        root = case_b(root, parsucc, succ);
    return (root);
}

struct node *del(struct node *root, int dkey)
{
    struct node *par, *ptr;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (dkey == ptr->info)
            break;
        par = ptr;
        if (ptr == NULL)
            printf("dkey is not present in the tree: \n");
        else if (ptr->lchild != NULL && ptr->rchild != NULL)
            root = case_c(root, par, ptr);
        else if (ptr->lchild != NULL)
            root = case_b(root, par, ptr);
        else if (ptr->rchild != NULL)
            root = case_b(root, par, ptr);
        else
            root = case_a(root, par, ptr);
        return (root);
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

void main()
{
    struct node *root = NULL, *ptr;
    int choice, k;
    while (choice != 4)
    {
        printf("\nEnter 1 to insert \nEnter 2 for preorder \nEnter 3 for deletion \nEnter 4 to terminate \nEnter choice \n");
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
            printf("Enter the key to be deleted \n");
            scanf("%d", &k);
            root = del(root, k);
            break;

        case 4:
            exit(1);

        default:
            printf("Wrong choice! \n");
        }
    }
}