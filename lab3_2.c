/*Given two sorted arrays A and B. Array A is full and array B is partially full and the number of empty slots are just enough to accommodate all elements of array A. Write one C program to merge the two sorted arrays to fill the array B without using the third array.
*/
#include<stdio.h>
int main()
{
    int n,m,k=0;
    printf("Enter the sizes of array A and B \n");
    scanf("%d%d",&n,&m);
    int a[n],b[m];
    printf("Enter sorted array A \n");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    printf("Enter sorted array B and enter zero if no element is need to be inserted \n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<m;i++)
    {
        if(b[i]==0)
        {
            if(k!=n)
            {
            b[i]=a[k];
            k++;
            }
            else
            {
                m--;
            }
        }
    }
    for (int i = 0; i < m; i++) 
        {
 
            for (int j=i+1;j<m;j++)
            {
 
                if (b[i]>b[j]) 
                {
 
                    int temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                }
 
            }
 
        }
        printf("The sorted merged array: \n");
        for(int i=0;i<m;i++)
        {
            printf("%d ",b[i]);
        }
        return 0;
}