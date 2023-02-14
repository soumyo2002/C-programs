// Implement insertion sort.

#include <stdio.h>

void insertionsort(int a[], int N)
{
    for (int i = 0; i <= (N - 2); i++)
    {
        for (int j = (i + 1); j > 0; j--)
        {
            if (a[j] < a[j - 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", a[i]);
    }
}

int main()
{
    int a[] = {5, 3, 4, 1, 2};
    int N = 5;
    insertionsort(a, N);
    return 0;
}