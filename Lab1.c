#include<stdio.h>
void main()
{
    float n;
    printf("Enter the value of Richter scale number \n");
    scanf("%f",&n);
    if(n<5)
    {
        printf("Little or no damage");
    }
    else if( n>=5 && n<5.5)
    {
       printf("some damage"); 
    }
    else if( n>=5.5 && n<6.5)
    {
       printf("serious damage : walls may crack or wall"); 
    }
    else if( n>=6.5 && n<7.5)
    {
       printf("disaster:houses and building may collapse"); 
    }
    else 
    {
       printf("catastrophe :most building destroyed"); 
    }
}