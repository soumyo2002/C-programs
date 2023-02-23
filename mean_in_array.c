//Write a C program to find the mean of n number using an array
#include <stdio.h>
void main()
{
    int n, total = 0;
    float avg, temp;
    printf("Enter the size of array \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element%d\n", (i + 1));
        scanf("%d", &a[i]);
    }
    printf("\nElements of array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        total = total + a[i];
    }
    temp = (float)n;
    avg = (float)(total / temp);
    printf("\nMean of %d numbers is: %f\n", n, avg);
}

#include <stdio.h>
void main()
{
    int count = 0,i,j,k;
    int n = 5;
    for (i = 1; i <= n; i ++)
    {
        for (j = 1; j <= 1000; j = j + 2)
        {
            for (k = -50; k <= -1; k++)
            {
                count++;
            }
        }
    }
    printf("%d",count);
}