#include<stdio.h>
int main()
{
    int arr[]={5,4,3,2,1};
    int n=5,index;

    int a[]={5,2,1,4,7};
    int m=5,point;

    //Sorting by placing MAX elements
    for(int i=0;i<n;i++)
    {
        int max=0;
        for(int j=0;j<(n-i);j++)
        {
           if(max<arr[j])
           {
               max=arr[j];
               index=j;
           } 
        }
        if(index!=(n-i-1))
        {
        int temp=arr[index];
        arr[index]=arr[n-i-1];
        arr[n-i-1]=temp;
        }
    }

    //Sorting by placing MIN elements
    for(int i=0;i<m;i++)
    {
        int min=a[m-1];
        for(int j=i;j<m;j++)
        {
           if(min>a[j])
           {
               min=a[j];
               point=j;
           } 
        }
        if(point!=i)
        {
        int temp=a[point];
        a[point]=a[i];
        a[i]=temp;
        }
    }
    

    printf("First sorted set(using max elements) \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n Second sorted set(using min elements) \n");
    for(int i=0;i<m;i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}