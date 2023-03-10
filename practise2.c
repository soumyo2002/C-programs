/*#include<stdio.h>
#include<stdlib.h>
struct A
{
    int a;
};

typedef struct B
{
    int b;
}B;


int main()
{
  struct A var1;
  var1.a=9;
  printf("%d\n",var1.a);
  B var2;
  var2.b=900;
  printf("%d",var2.b);
  return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>
struct A
{
    char a;
    int c;
    char b;
};
int main()
{
  struct A var1;
  printf("%d",sizeof(var1));
  return 0;
}