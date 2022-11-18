#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 13 //defining max=10
char infix[MAX];
char postfix[MAX];
int stack[MAX];
int top;
int isempty()//to check if the stack is empty or not
{
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(int symbol)
{
    if(top>MAX)
    {
        printf("STACK OVERFLOW!\n");
        exit(1);
    }
    stack[++top]=symbol;
}
int pop()
{
    if(isempty())
    {
        printf("STACK OVERFLOW!\n");
        exit(1);
    }
    return(stack[top--]);
}
int priority(char symbol)
{
    switch(symbol)
    {
        case '(':
        return 0;
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        case '%':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}
int eval_post()
{
    int a,b,temp,result,i;//a to store top element,b to store next to top element,temp to store result,result to store the FINAL ANSWER
    for(int i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
        push(postfix[i]-'0');
        else
        {
            a=pop();//stores top value
            b=pop();//stores top-1 value
            switch(postfix[i])
            {
                case '+':temp=b+a;
                break;
                case '-':temp=b-a;
                break;
                case '*':temp=b*a;
                break;
                case '/':temp=b/a;
                break;
                case '%':temp=b%a;
                break;
                case '^':temp=pow(b,a);
                break;
            }
            push(temp);//inserting it in the stack
        }
    }
    result=pop();
    return(result);
}
void infix_to_postfix()
{
    int i,p=0;
    char next,symbol;
    for(int i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':push(symbol);
            break;
            case ')':
            while((next=pop())!='(')
            postfix[p++]=next;
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            while(!isempty() && priority(stack[top])>=priority(symbol))
            postfix[p++]=pop();
            push(symbol);
            break;
            default:
            postfix[p++]=symbol;
        }
    }
    while(!isempty())
    postfix[p++]=pop();
    postfix[p]='\0';
}
void main()
{
    top=-1;
    int value;//to store the evaluated value of postfix
    printf("Enter the infix statement\n");
    gets(infix);
    infix_to_postfix();
    printf("Postfix:\n");
    printf("%s\n",postfix);
    value=eval_post();
    printf("Value of the postfix expression is %d",value);
}