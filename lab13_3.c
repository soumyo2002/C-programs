//Write the C code to print the postorder traversal of a binary tree from its preorder and inorder traversal.

#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int data, int n)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == data)
			return i;
	return -1;
}


void PostOrder(int in[], int pre[], int n)
{
	int root = search(in, pre[0], n);
	if (root != 0)
		PostOrder(in, pre + 1, root);
	if (root != n - 1)
		PostOrder(in + root + 1, pre + root + 1, n - root - 1);
	printf("%d",pre[0]);
}

int main()
{
    int n;
	printf("Enter the size of the tree \n");
    scanf("%d",&n);
    int in[n],pre[n];

    printf("Enter inorder list: \n");
    for(int i=0;i<6;i++)
    scanf("%d",&in[i]);
    

    printf("Enter preorder list: \n");
    for(int i=0;i<6;i++)
    scanf("%d",&pre[i]);

	printf("Postorder traversal \n");
	PostOrder(in, pre, n);
	return 0;
}
