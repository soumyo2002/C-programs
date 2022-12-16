/*Two arrays are given. Write the C code to swap elements from each array such that after swapping, sum of elements of
array1=sum of elements of array2..
Example:
Array 1: 3, 2, 10, 12
Array 2: 6, 4, 9, 10
After swapping 3 (from Array 1) with 4 (from Array 2)
Array1: 4, 2, 10, 12 Sum = 28
Array2: 6, 3, 9, 10 Sum = 28
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m,c=0;
    printf("Enter size of 1st arrays:\n");
    scanf("%d", &n);
    int a[n], sum1=0,sum2=0,temp1=0,temp2=0;
    printf("Enter array elements for 1st array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter size of 2nd arrays:\n");
    scanf("%d", &m);
    int b[m];
    printf("Enter array elements for 2nd array:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum1=sum1+a[i];
    }
    for (int i = 0; i < m; i++)
    {
        sum2=sum2+b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp1 = sum1 - a[i] + b[j];
            temp2 = sum2 + a[i] - b[j];
            if (temp1 == temp2)
            {
                a[i] = a[i] + b[j];
                b[j] = a[i] - b[j];
                a[i] = a[i] - b[j];
                c++;
                break;
            } 
        }
        if(c==1)
        break;
    }
    printf("Arrays after swapping:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("\n second array: \n");
    for (int i = 0; i < m; i++)
    {
        printf("%d\n", b[i]);
    }
    return 0;
}