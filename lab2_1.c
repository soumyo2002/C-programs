#include<stdio.h>
int main()
{
    int a,b,n=0,v=0;
    printf("Enter the array sizes \n");
    scanf("%d%d",&a,&b);
    int a1[a],b1[b];
    printf("Enter the contents of 1st array \n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("Enter the contents of 2nd array \n");
    for(int i=0;i<b;i++)
    {
        scanf("%d",&b1[i]);
    }
    printf("Elements after performing the union: \n ");
    for(int i=0;i<a;i++)
    {
       for(int j=0;j<b;j++)
       {
           if(a1[i]==b1[j])
           {
               printf("%d ",a1[i]);
               break;
           }
        } 

    }
    printf("Elements after performing the intersection: \n ");
    for(int i=0;i<a;i++)
    {
       for(int j=0;j<b;j++)
       {
           if(a1[i]==b1[j])
           {
               v++;
               break;
           }
        } 
        if(v==0)
        {
            printf("%d ",a1[i]);
        }
        v=0;
    }
    for(int i=0;i<b;i++)
    {
       for(int j=0;j<a;j++)
       {
           if(b1[i]==a1[j])
           {
               v++;
               break;
           }
        } 
        if(v==0)
        {
            printf("%d ",b1[i]);
        }
        v=0;
    }
    return 0;
}