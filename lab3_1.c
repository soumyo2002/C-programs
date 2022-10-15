/*Write a C program to add an original sparse matrix with the transpose of the same matrix
then represent the output matrix in three tuple method.
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int mat[100][100], sparse[100][100], transpose[100][100], sum[100][100];
	int i, j, nz=0,sr,s=1,n,m;
	printf("Enter the number of rows: \n ");
	scanf("%d",&n);
	printf("Enter the number of columns:\n ");
	scanf("%d",&m);
	printf("Enter the elements: \n ");
	for (i=0;i<m;i++)
	for(j=0;j<n;j++)
	scanf("%d",&mat[i][j]);
	for (i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	printf("%d",mat[i][j]);
	printf("\n");
	}
	for (int i = 0; i < m; i++)
 	for (int j = 0; j < n; j++)
    transpose[j][i] = mat[i][j];
	printf("Transpose of the matrix:\n");
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) 
	{
    printf("%d  ", transpose[i][j]);
    if (j == n - 1)
    printf("\n");
	}	
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	sum[i][j]=mat[i][j]+transpose[i][j];
	printf("The sum of the two matrices:\n");
	for (i=0;i<m;i++)
	{
	for (j=0;j<n;j++)
	{
	printf("%d  ",sum[i][j]);
	if (sum[i][j]!=0)
	nz++;
	}
	printf("\n");
	}
	sr=nz+1;
	sparse[0][0]=m;
	sparse[0][1]=n;
	sparse[0][2]=nz;
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	{
		if(sum[i][j]!=0)
		{
			sparse[s][0]=i;
			sparse[s][1]=j;
			sparse[s][2]=sum[i][j];
			s++;
		}
	}
	for (i=0;i<sr;i++)
	{
	for (j=0;j<3;j++)
	printf("%d  ",sparse[i][j]);
	printf("\n");
	}
	return 0;
}