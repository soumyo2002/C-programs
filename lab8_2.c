// 2. Write a C code to add two polynomials using array.
#include <stdio.h>
void main()
{
    int co, ex, n, m, p;
    printf("Enter the number of terms in 1st polynomial \n");
    scanf("%d", &n);
    printf("Enter the number of terms in 2nd polynomial \n");
    scanf("%d", &m);
    if (m > n)
        p = m;
    else
        p = n;
    int a[n][2];
    int b[m][2];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient and exponent part of the 1st polynomial \n");
        scanf("%d%d", &co, &ex);
        a[i][0] = co;
        a[i][1] = ex;
    }
    for (int i = 0; i < m; i++)
    {
        printf("Enter the coefficient and exponent part of the 2nd polynomial \n");
        scanf("%d%d", &co, &ex);
        b[i][0] = co;
        b[i][1] = ex;
    }
    printf("First polynomial:\n");
    for (int i = 0; i < n; i++)
    {
        if (a[i][1] != 0)
        {
            printf("%dx^%d", a[i][0], a[i][1]);
        }
        else
        {
            printf("%d", a[i][0]);
        }
        if (i == (n - 1))
        {
            printf("\n");
        }
        else if (a[i + 1][0] > 0)
        {
            printf("+");
        }
    }
    printf("Second polynomial:\n");
    for (int i = 0; i < m; i++)
    {
        if (b[i][1] != 0)
        {
            printf("%dx^%d", b[i][0], b[i][1]);
        }
        else
        {
            printf("%d", b[i][0]);
        }
        if (i == (m - 1))
        {
            printf("\n");
        }
        else if (b[i + 1][0] > 0)
        {
            printf("+");
        }
    }
    int c[p][2];
    int k = m, v = n;
    int temp = p;
    p--;
    v--;
    k--;
    while (p != -1)
    {
        if (a[v][1] == b[k][1])
        {
            c[p][0] = a[v][0] + b[k][0];
            c[p][1] = b[k][1];
            p--;
            v--;
            k--;
        }
        else if (a[v][1] > b[k][1])
        {
            c[p][0] = b[k][0];
            c[p][1] = b[k][1];
            p--;
            k--;
        }
        else
        {
            c[p][0] = a[v][0];
            c[p][1] = a[v][1];
            p--;
            v--;
        }
    }
    printf("Resulting polynomial after addition:\n");
    for (int i = 0; i < temp; i++)
    {
        if (c[i][1] != 0)
        {
            printf("%dx^%d", c[i][0], c[i][1]);
        }
        else
        {
            printf("%d", c[i][0]);
        }
        if (i == (temp - 1))
        {
            printf("\n");
        }
        else if (c[i + 1][0] > 0)
        {
            printf("+");
        }
    }
}
