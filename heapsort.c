#include<stdio.h>

void swap(int a[],int i,int largest)
{
    int temp=a[largest];
    a[largest]=a[i];
    a[i]=temp;
}

void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=(2*i)+1;
    int r=2*i+2;

    while(l<n && a[largest]<a[l])
    {
        largest=l;
    }
    while(r<n && a[largest]<a[r])
    {
        largest=r;
    }

    if(largest!=i)
    {
        swap(a,i,largest);
        heapify(a,n,largest);
    }
}

int main()
{
    int a[]={15,5,20,1,17,10,30};
    int n=7;

    printf("Unsorted array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    for(int i=(n/2-1);i>=0;i--)
    {
        heapify(a,n,i);
    }

    for(int i=(n-1);i>0;i--)
    {
        swap(a,i,0);
        heapify(a,i,0);
    }

    printf("\nSorted array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}