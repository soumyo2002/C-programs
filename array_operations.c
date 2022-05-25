//Program to insert and delete from array using switch case


#include <stdio.h>
#include <stdlib.h>
int insert(int arr[], int n, int pos)
{
    int x;
    printf("Enter the element:\n");
    scanf("%d", &x);
    for (int i = (n - 1); i >= (pos - 1); i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = x;
    printf("final array after inserting the value is\n");
    for (int i = 0; i <= n; i++)
        printf("%d\n", arr[i]);
    n++;
    return (n);
}
int delete (int arr[], int n, int pos)
{

    for (int i = (pos - 1); i < (n - 1); i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("final array after deleting the value is\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return (n);
}
int main()
{
    int n, ch, pos;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    int arr[100];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (ch != 3)
    {
        printf("Enter 1 to insert element to the array:\n");
        printf("Enter 2 to delete element from the array:\n");
        printf("Enter 3 to Exit:\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the position to insert array element:\n");
            scanf("%d", &pos);
            n = insert(arr, n, pos);
            break;
        case 2:
            printf("Enter the position to delete array element:\n");
            scanf("%d", &pos);
            n = delete (arr, n, pos);
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("Wrong choice!Try again");
        }
    }
    return 0;
}
