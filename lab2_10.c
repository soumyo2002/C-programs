//Find the maximum, minimum and average of the elements of an array.
#include<stdio.h>
int main()
{
    int a,max=0,sum=0;
    float avg;
    printf("Enter the array size \n");
    scanf("%d",&a);
    int a1[a];
    printf("Enter the array elements: \n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&a1[i]);
    }
    int min=a1[0];
    for(int i=0;i<a;i++)
    {
        if(a1[i]>max)
        {
            max=a1[i];
        }
        if(a1[i]<min)
        {
            min=a1[i];
        }
        sum=sum+a1[i];
    }
    avg=sum/a;
    printf(" Maximum element=%d , Minimum element=%d , average=%f ",max,min,avg);
    return 0;
}