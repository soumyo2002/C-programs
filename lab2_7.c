
#include<stdio.h>
int main()
{
    int a,temp,b;
    printf("Enter the array size \n");
    scanf("%d",&a);
    int a1[a];
    printf("Enter the array elements: \n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&a1[i]);
    }
    b=a/2;
    for(int i=0;i<b;i++)
    {
        temp=a1[i];
        a1[i]=a1[a-i-1];
        a1[a-i-1]=temp;
    }
    printf("Reversed array: \n");
    for(int i=0;i<a;i++)
    {
        printf("%d",a1[i]);
    }
    return 0;
}