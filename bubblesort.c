#include<stdio.h>
int main()
{
    int arr[]={5,4,3,2,1};
    int n=5;
    
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<(n-i);j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                c++;
            }
        }
        //VERY IMPORTANT STEP,IF THE ARRAY IS ALREADY SORTED OR SORTED BEFORE SCANNIONG ENTIRE ARRAY THEN TERMINATE THE LOOP TO SAVE TIME AND SPCAE
        if(c==0)
        break;
    }
    printf("Sorted array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}