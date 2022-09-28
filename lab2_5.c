#include<stdio.h>
int main()
{
    int a,b,c=0;
    printf("Enter the array size \n");
    scanf("%d",&a);
    int a1[a];
    printf("Enter the array elements: \n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("Enter the element to be searched: \n");
    {
        scanf("%d",&b);
    }
    for(int i=0;i<a;i++)
    {
        if(a1[i]==b)
        {
            c++;
        }
    }
    if(c>0)
    {
        printf(" The element is found and it is present in the array %d times",c);
    }
    else
    {
        printf(" The element is not found");
    }
    return 0;
}