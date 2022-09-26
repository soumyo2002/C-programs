#include<stdio.h>
int main()
{
    int a,x,v=0;
    printf("Enter the array size \n");
    scanf("%d",&a);
    int a1[a],b1[a];
    printf("Enter the array elements of 1st array: \n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("Enter the array elements of 2nd array: \n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&b1[i]);
    }
    printf("Enter the number \n");
    scanf("%d",&x);
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            if(a1[i]+b1[j]==x)
            {
                v++;
                printf("The pair of numbers are: %d,%d \n",a1[i],b1[j]);
                break;
            }
        }
    }
    if(v==0)
    printf("No pair found");
    return 0;
}

A5)
#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the array sizes of 3 arrays \n");
    scanf("%d%d%d",&a,&b,&c);
    int a1[a],b1[b],c1[c];
    printf("Enter the array elements of 1st array: \n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("Enter the array elements of 2nd array: \n");
    for(int i=0;i<b;i++)
    {
        scanf("%d",&b1[i]);
    }
    printf("Enter the array elements of 3rd array: \n");
    for(int i=0;i<c;i++)
    {
        scanf("%d",&c1[i]);
    }
    printf("Common elements from the given three arrays: \n");
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            for(int k=0;k<c;k++)
            {
                if(a1[i]==b1[j] && b1[j]==c1[k])
                {
                    printf("%d",a1[i]);
                }
            }
        }
    }
    return 0;
}