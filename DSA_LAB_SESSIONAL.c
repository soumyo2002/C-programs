/*Develop a calculator program for infix arithmetic expressions. For example, given the expression 5 ∗ (((9 + 8) ∗ (4 ∗ 6)) + 7),
 the function outputs the result 2075. Hint: Convert the infix expression to postfix expression, then evaluate.
NOTE:
The code must be properly commented, so that any end user can easily understand. [2 marks]
The input may be any arithmetic expression. Your function should read the expression from standard input,
perform the computation and output the result.
[5 marks]
Your program must check whether the given expression is valid or not. Some examples of invalid expressions are:
((2+3), (2+3)), 2+3*, 2--, ++5, 3/0 etc.
[3 marks]
*/

// Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50     // defining max=50
char infix[MAX];   // to store infix expression
char postfix[MAX]; // to store postfix
int stack[MAX];
int top;

// function to check invalid input
int check()
{
    char prev, symbol;
    for (int i = 0; i < strlen(infix); i++)
    {
        if (i > 0)
            prev = infix[i - 1];
        symbol = infix[i];
        if (symbol == ',')
            return 0;
        else if (symbol == '+' && prev == '+')
            return 0;
        else if (symbol == '-' && prev == '-')
            return 0;
        else if (symbol == '0' && prev == '/')
            return 0;
    }
    return 1;
}

int isempty() // to check if the stack is empty or not
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int symbol)
{
    if (top > MAX)
    {
        printf("STACK OVERFLOW!\n");
        exit(1);
    }
    stack[++top] = symbol;
}
int pop()
{
    if (isempty())
    {
        printf("STACK OVERFLOW!\n");
        exit(1);
    }
    return (stack[top--]);
}
// function to check precedence
int priority(char symbol)
{
    switch (symbol)
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
    int a, b, temp, result, i; // a to store top element,b to store next to top element,temp to store result,result to store the FINAL ANSWER
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] <= '9' && postfix[i] >= '0')
            push(postfix[i] - '0');
        else
        {
            a = pop(); // stores top value
            b = pop(); // stores top-1 value
            switch (postfix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = pow(b, a);
                break;
            }
            push(temp); // inserting it in the stack
        }
    }
    result = pop();
    return (result);
}
void infix_to_postfix()
{
    int i, p = 0;
    char next, symbol;
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
                postfix[p++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while (!isempty() && priority(stack[top]) >= priority(symbol))
                postfix[p++] = pop();
            push(symbol);
            break;
        default:
            postfix[p++] = symbol;
        }
    }
    while (!isempty())
        postfix[p++] = pop();
    postfix[p] = '\0';
}
void main()
{
    top = -1;
    int value; // to store the evaluated value of postfix
    printf("Enter the infix statement\n");
    gets(infix);
    if (check(infix) == 1)
    {
        infix_to_postfix();
        printf("Postfix:\n");
        printf("%s\n", postfix);
        value = eval_post();
        printf("Value of the postfix expression is %d", value);
    }
    else
    {
        printf("Invalid Input!Please try again \n");
    }
}