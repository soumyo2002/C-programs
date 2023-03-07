/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int rev(int n,int i)
{
    if(n==0)
    {
        return 0;
    }
    int z=((n%10)*(pow(10,i)));
    return (z+rev(n/10,i-1));
}
int main()
{
    int n=rev(367112,5);
    printf("%d\n",n);
    return 0;
}*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int count(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n%10==0)
    {
        return(1+count(n/10));
    }
    else
    {
        return(0+count(n/10));
    }
}
int main()
{
    int n=count(300960102);
    printf("%d\n",n);
    return 0;
}
*/

//Count the steps needed to reduce a number to zero.
//If n is even then divide by 2
//If n is odd,then subtract n by 1 and then divide by 2

/*
#include<stdio.h>
#include<stdlib.h>

int steps(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n%2==0)
    {
        return(1+steps(n/2));
    }
    else
    {
        return(1+steps((n-1)/2));
    }
}
int main()
{
    int n=steps(8);
    printf("%d\n",n);
    return 0;
}
*/

/*
//Linear search using recursion

#include<stdio.h>
#include<stdlib.h>

int sort(int a[],int n,int target,int count)
{
     if(n==0 && count==0)
     return 0;
     else if(n==0)
     return(count);
     else if(a[n-1]!=target)
     return sort(a,n-1,target,count);
     else 
     return sort(a,n-1,target,count+1);
}

int main()
{
    int arr[6]={1,3,13,2,7,4};
    int n=sort(arr,6,12,0);
    if(n>0)
    {
        printf("Found %d times",n);
    }
    else
    {
        printf("Not Found");
    }
    return 0;
}
*/

/*
//Return an array having the element to be found and its index
#include<stdio.h>
#include<stdlib.h>

static int* find(int arr[],int index,int size,int target)
{
    static int ar[2];
    static int c=0;
    if(index==(size-1))
    {
        return(ar);
    }
    if(arr[index]==target)
    {
        ar[c]=index;
        c++;
    }
    return(find(arr,index+1,size,target));
}
int main()
{
    int arr[5]={1,4,4,6,7};
    //int ar[2]={-1,-1};
    int *ar=find(arr,0,5,4);
    printf("[%d,%d]",ar[0],ar[1]);
    return 0;
}
*/

/*print using recursion:
* * * * 
* * * 
* * 
*

#include<stdio.h>
#include<stdlib.h>

int pls_print_pattern(char a,int rows,int col)
{
    if(rows==0)
    return 1;
    else if(col!=0)
    {
    printf("%c ",a);
    return(pls_print_pattern(a,rows,col-1));
    }
    else
    {
        printf("\n");
        return(pls_print_pattern(a,rows-1,rows-1));
    }
}
int main()
{
    int n=pls_print_pattern('Bah',4,4);
    return 0;
}


Print using recusion:
*
* * 
* * * 
* * * * 


#include<stdio.h>
#include<stdlib.h>

int pls_print_pattern(char a,int rows,int col)
{
    if(rows==0)
    return 1;
    else if(col!=0)
    {
    printf("%c ",a);
    return(pls_print_pattern(a,rows,col-1));
    }
    else
    {
        printf("\n");
        return(pls_print_pattern(a,rows-1,rows-1));
    }
}
int main()
{
    int n=pls_print_pattern('*',4,4);
    return 0;
}


Use Bubble sort using recursion


#include<stdio.h>

int* bubble(int a[],int index,int count,int size)
{
    if(index==(size-1) && count==0)
    {
        return(a);
    }
    else if(index==(size-1))
    {
        return(bubble(a,0,0,size));
    }

    if(a[index]>a[index+1])
    {
        int temp=a[index];
        a[index]=a[index+1];
        a[index+1]=temp;
        return(bubble(a,index+1,count+1,size));
    }
    else if(a[index]<a[index+1])
    {
        return(bubble(a,index+1,count,size));
    }
    
}

int main()
{
    int arr[5]={1,4,3,7,2};
    int* ptr=bubble(arr,0,0,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ",ptr[i]);
    }
    return 0;
}

Use Selection sort using recursion
*/

#include<stdio.h>

int max(int arr[],int size)
{
    int max=0,point=0;
    while(size!=-1)
    {
        if(max<arr[size])
        {
        max=arr[size];
        point=size;
        }
        size--;
    }
    return(point);
}
int* selection(int a[],int index)
{
    if(index==0)
    {
    return(a); 
    }
    else
    {
        int m=max(a,index);
        int temp=a[index];
        a[index]=a[m];
        a[m]=temp;
        return(selection(a,index-1));
    } 
}

int main()
{
    int arr[5]={1,4,3,7,2};
    int* ptr=selection(arr,4);
    for(int i=0;i<5;i++)
    {
        printf("%d ",ptr[i]);
    }
    return 0;
}

