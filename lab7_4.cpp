#include<stdio.h>
int main()
{
    int a,b,nz=0,r=1,rr=1,rc=1,m;
    printf("Enter rows and coloumns of the sparse matrix:\n");
    scanf("%d%d",&a,&b);
    int s[a][b];
    printf("Enter elements of the matrix:\n");
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            scanf("%d",&s[i][j]);
            if(s[i][j]!=0)
            nz++;
        }
    }
    printf("Sparse matrix:\n");
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
    int t[nz+1][3];
    t[0][0]=a;
    t[0][1]=b;
    t[0][2]=nz;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(s[i][j]!=0)
            {
                t[r][0]=i;
                t[r][1]=j;
                t[r][2]=s[i][j];
                r++;
            }
        }
    }
    printf("Sparse matrix in triplet format:\n");
    for(int i=0;i<=nz;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
    for(int i=(a-1);i>=0;i--)
    {
        for(int j=0;j<b;j++)
        {
           if(s[i][j]!=0)
           break;
           else if (s[i][j]!=0 && rr<3)
           {
               rr=0;
               break;
           }
           else
           rr++;
        }
        if(rr==0)
        break;
    }
    for(int i=(b-1);i>=0;i--)
    {
        for(int j=0;j<a;j++)
        {
           if(s[j][i]!=0)
           break;
           else if(s[j][i]!=0 && rc<3)
           {
               rc=0;
               break;
           }
           else
           rc++;
        }
        if(rc==0)
        break;
    }
    if(rr!=0)
    {
    rr--;
    m=rr%3;
    rr=rr-m;
    rr=rr/3;
    }
    if(rc!=0)
    {
    rc--;
    m=rc%3;
    rc=rc-m;
    rc=rc/3;
    }
    int h=a-rr;
    int y=b-rc;
    int s1[h][y];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<y;j++)
        {
            s1[i][j]=s[i][j];
        }
    }
    printf("Updated Sparse matrix:\n");
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<y;j++)
        {
            printf("%d ",s1[i][j]);
        }
        printf("\n");
    }
    int t1[nz+1][3];
    t1[0][0]=h;
    t1[0][1]=y;
    t1[0][2]=nz;
    r=1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(s1[i][j]!=0)
            {
                t1[r][0]=i;
                t1[r][1]=j;
                t1[r][2]=s1[i][j];
                r++;
            }
        }
    }
    printf("Sparse matrix in triplet format:\n");
    for(int i=0;i<=nz;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",t1[i][j]);
        }
        printf("\n");
    }
    int t2[nz+1][3];
    t2[0][0]=h;
    t2[0][1]=y;
    t2[0][2]=nz;
    for(int i=0;i<=nz;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j!=2)
            {
                t2[i][j]=t1[i][j];
            }
            else
            {
                t2[i][j]=t1[i][j]+t[i][j];
            }
        }   
    }
    printf("Sparse matrix in triple form after addition of two sparse matrix(in triple form):\n");
    for(int i=0;i<=nz;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",t2[i][j]);
        }
        printf("\n");
    }
    return 0;
}