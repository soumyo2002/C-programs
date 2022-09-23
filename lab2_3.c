#include<stdio.h>
int main()
{
    int a;
    printf("Enter the array size \n");
    scanf("%d",&a);
    int a1[a],b1[a],add[a],sub[a],mul[a];
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
    for(int i=0;i<a;i++)
    {
        add[i]=a1[i]+b1[i];
        if(a1[i]>b1[i])
        {
        sub[i]=a1[i]-b1[i];
        }
        else
        {
           sub[i]=b1[i]-a1[i]; 
        }
        mul[i]=(a1[i])*(b1[i]);
    }
    for(int i=0;i<a;i++)
    {
        printf("Sum of element%d is %d \n",(i+1),add[i]);
        printf("Difference of element%d is %d \n",(i+1),sub[i]);
        printf("multiplication of element%d is %d \n",(i+1),mul[i]);
    }
    return 0;
}