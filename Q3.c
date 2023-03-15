#include<stdio.h>
void main()
{
    float current[12],previous[12];
    float totalc=0.0,totalp=0.0,avgc=0.0,avgp=0.0;
    printf("Enter the rainfall data for both current and previous year rainfall \n");
    for(int i=0;i<12;i++)
    {
        scanf("%f%f",&current[i],&previous[i]);
    }
    for(int i=0;i<12;i++)
    {
        totalc=totalc+current[i];
        totalp=totalp+previous[i];
    }
    avgc=totalc/12.0;
    avgp=totalp/12.0;
    printf("\n Table of monthly rainfall: \n");
    printf(" Months:");
    printf("       January   February    March     April      May       June     July     August   September  October  November  December ");
    printf("\n This year:    ");
    for(int i=0;i<12;i++)
    {
        printf("%f  ",current[i]);
    }
    printf("\n Previous year:");
    for(int i=0;i<12;i++)
    {
        printf("%f  ",previous[i]);
    }
    printf("\n Total rainfall this year: %f \n",totalc);
    printf("Total rainfall last year: %f \n",totalp);
    printf("Average monthly rainfall for this year: %f \n",avgc);
    printf("Average monthly rainfall for last year: %f \n",avgp);
}