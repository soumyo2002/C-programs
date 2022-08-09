#include<stdio.h>
#include<stdlib.h>
int main()
{
    int* arr;
    int k,c=0,a=0;
    if(a==0)
    {
    arr=(int*)malloc(sizeof(int));
    }
    printf("Sir please enter the elements of the array: and to stop entering enter (-1)\n");
    while(a==0)
    {
        scanf("%d",&k);
        if(k==-1)
        {
            break;
        }
        arr[c]=k;
        c++;
    }
    printf("Array elements:\n");
    for(int i=0;i<c;i++)
    {
        printf("%d\n",arr[i]);
    }
    free(arr);
    return 0;
}