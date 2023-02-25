#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, b[100];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {11,8,9,4};
    merge_sort(arr,0,3);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}