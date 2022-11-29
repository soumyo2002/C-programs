//Write a C code of O(n) order to remove all the odd numbers from the array. Example: the array contains 10, 2, 3, 7, 8, 6, 11. 
//The output should be 10, 2, 8, and 6.

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the number of elements in array: \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: \n");
    for(int i=0;i<n;i++)
    {
       scanf("%d",&a[i]); 
    }
    int c=0;
    int m=n;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {
            c++;
            m--;
            continue;
        }
        if(c>0)
        {
            a[i-c]=a[i];
        }
    }
    printf("Array after eliminating odd numbers: \n");
    for(int i=0;i<m;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}