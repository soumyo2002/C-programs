#include <stdio.h>
#include <stdlib.h>

#define SROW 30
#define MAX 20

int create_mat(int index, int row, int column, int *arr)
{
	printf("Enter data 'row by row':\n");
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < column; j++)
		{
			scanf("%d", &arr[i*column+j]);
			if (arr[i*column+j] != 0)
				index++;
		}
	return index;
}

void display(int sparse[][3], int index)
{
	printf("Displaying triplet of sparse:\n");
	for (int i = 0; i < index + 1; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", sparse[i][j]);
		printf("\n");
	}
}

void create_triplet(int sparse[][3], int index, int row, int column, int* arr)
{
	sparse[0][0] = row;
	sparse[0][1] = column;
	sparse[0][2] = index;

	int s = 1;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			if (arr[i*column+j] != 0)
			{
				sparse[s][0] = i;
				sparse[s][1] = j;
				sparse[s][2] = arr[i*column+j];
				s++;
			}
}

void col_0re(int sparse[][3], int index)
{
	int i, max_col = sparse[1][1];
	for (i = 2; i < index+1; i++)
	{
		if (max_col < sparse[i][1])
			max_col = sparse[i][1];
	}
	sparse[0][1] = max_col+1;
	display(sparse, index);
}

void operation_actII(int sparse_g[][3], int index_g, int sparse_s[][3], int index_s, int sparse_finale[][3])
{
	sparse_finale[0][0] = sparse_g[0][0];
	sparse_finale[0][1] = sparse_g[0][1];
	if (sparse_finale[0][0] < sparse_s[0][0])
		sparse_finale[0][0] = sparse_s[0][0];
	if (sparse_finale[0][1] < sparse_s[0][1])
		sparse_finale[0][1] = sparse_s[0][1];
	int i_g = 1, i_s = 1, index = 1;
	while (i_g < index_g + 1 && i_s < index_s + 1)
	{
		if (sparse_g[i_g][0] > sparse_s[i_s][0] || (sparse_g[i_g][0] == sparse_s[i_s][0] && sparse_g[i_g][1] > sparse_s[i_s][1]))
		{
			sparse_finale[index][0] = sparse_s[i_s][0];
			sparse_finale[index][1] = sparse_s[i_s][1];
			sparse_finale[index][2] = sparse_s[i_s][2];
	
			i_s++;
			index++;
		}
		else if (sparse_g[i_g][0] < sparse_s[i_s][0] || (sparse_g[i_g][0] == sparse_s[i_s][0] && sparse_g[i_g][1] < sparse_s[i_s][1]))
		{
			sparse_finale[index][0] = sparse_g[i_g][0];
			sparse_finale[index][1] = sparse_g[i_g][1];
			sparse_finale[index][2] = sparse_g[i_g][2];
			
			i_g++;
			index++;
		}
		else
		{
			int added = sparse_g[i_g][2] + sparse_s[i_s][2];
			sparse_finale[index][0] = sparse_g[i_g][0];
			sparse_finale[index][1] = sparse_g[i_g][1];
			sparse_finale[index][2] = added;
			i_g++;
			i_s++;
			index++;
		}
	}
	while (i_g < index_g + 1)
	{
		sparse_finale[index][0] = sparse_g[i_g][0];
		sparse_finale[index][1] = sparse_g[i_g][1];
		sparse_finale[index][2] = sparse_g[i_g][2];
		index++;
		i_g++;
	}
	while (i_s < index_s + 1)
	{
		sparse_finale[index][0] = sparse_s[i_s][0];
		sparse_finale[index][1] = sparse_s[i_s][1];
		sparse_finale[index][2] = sparse_s[i_s][2];
		index++;
		i_s++;
	}
	sparse_finale[0][2] = index - 1;
	printf("The result after adding two sparse matrix in triplet format:\n");
	display(sparse_finale, index - 1);
}

void operation_actI(int sparse_1[][3], int index_1, int sparse_2[][3], int index_2, int sparse_finale[][3])
{
	int index = index_1;
	if (index < index_2)
	{
		operation_actII(sparse_2, index_2, sparse_1, index_1, sparse_finale);
	}
	else
		operation_actII(sparse_1, index_1, sparse_2, index_2, sparse_finale);
}

void display_sparse(int* arr, int row, int column, int end)
{
	int i, j;
	int column_m = column + end;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column_m; j++)
		{
			if(j<column)
				printf("%d ", arr[i * column_m + j]);
		}
		printf("\n");
	}
}

int main()
{
	//Matrix 1
	printf("Enter the value for sparse matrix no. 1:\n");
	int row_1, column_1;
	printf("Enter the number of rows (space) column: ");
	scanf("%d %d", &row_1, &column_1);
	int mat_1[row_1][column_1], sparse_1[SROW][3];
	int nzero_1 = 0;
	nzero_1 = create_mat(nzero_1, row_1, column_1, &mat_1[0][0]);
	create_triplet(sparse_1, nzero_1, row_1, column_1, &mat_1[0][0]);
	int sr_1 = nzero_1 + 1;
	sparse_1[0][0] = sparse_1[nzero_1][0]+1;
	col_0re(sparse_1, nzero_1);
	row_1 = sparse_1[0][0]; 
	int x_1 = column_1 - sparse_1[0][1];
	column_1 = sparse_1[0][1];

	//Matrix 2
	printf("Enter the value for sparse matrix no. 1:\n");
	int row_2, column_2;
	printf("Enter the number of rows (space) column: ");
	scanf("%d %d", &row_2, &column_2);
	int mat_2[row_2][column_2], sparse_2[SROW][3];
	int nzero_2 = 0;
	nzero_2 = create_mat(nzero_2, row_2, column_2, &mat_2[0][0]);
	create_triplet(sparse_2, nzero_2, row_2, column_2, &mat_2[0][0]);
	int sr_2 = nzero_2 + 1;
	sparse_2[0][0] = sparse_2[nzero_2][0]+1;
	col_0re(sparse_2, nzero_2);
	row_2 = sparse_2[0][0]; 
	int x_2 = column_2 - sparse_2[0][1];
	column_2 = sparse_2[0][1];

	int sparse_finale[SROW][3];
	operation_actI(sparse_1, nzero_1, sparse_2, nzero_2, sparse_finale);

	printf("Matrix 1 after final touch :)\n");
	display_sparse(&mat_1[0][0], row_1, column_1, x_1);
	printf("Matrix 2 after final touch :)\n");
	display_sparse(&mat_2[0][0], row_2, column_2, x_2);
}