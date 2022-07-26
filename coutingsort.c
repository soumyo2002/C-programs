#include<stdio.h>

int find_max(int a[],int n)
{
    int max=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    return(max);
}

void counting_sort(int a[],int n,int max)
{
    
    int count[max+1],temp[n];

    for(int i=0;i<=max;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        ++count[a[i]];
    }

    for(int i=1;i<=max;i++)
    {
        count[i]+=count[i-1];
    }

    for(int i=(n-1);i>=0;i--)
    {
        count[a[i]]=count[a[i]]-1;
        temp[count[a[i]]]=a[i];
    }

    for(int i=0;i<n;i++)
    {
        a[i]=temp[i];
    }
}

int main()
{
    int a[]={2,0,1,0,3};

    int n=5;

    int max=find_max(a,n);

    printf("Original array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    counting_sort(a,n,max);

    printf("\nSorted array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}