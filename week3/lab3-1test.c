#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// push
void push(char *stack, char data, int *top)
{
    stack[++(*top)] = data;
}

// pop
char pop(char *stack, int *top)
{
    return stack[(*top)--];
}

// peek
char peek(char *stack, int top)
{
    return stack[top];
}

// is empty
int isEmpty(int top)
{
    return top == -1;
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


void infix_to_postfix(char *infix, char *postfix)
{
    char stack[100];
    int top = -1;

    for (int i = 0; i <= strlen(infix); i++)
    {
        char c = infix[i];
        if (c == '\0')
        {
            while (!isEmpty(top))
            {
                postfix[strlen(postfix)] = pop(stack, &top);
            }
        }
        else if (c == '(')
        {
            push(stack, c, &top);
        }
        else if (c == ')')
        {
            while (peek(stack, top) != '(')
            {
                postfix[strlen(postfix)] = pop(stack, &top);
            }
            pop(stack, &top);
        }
        else if (isOperator(c))
        {
            while (!isEmpty(top) && priority(peek(stack, top)) >= priority(c))
            {
                postfix[strlen(postfix)] = pop(stack, &top);
            }
            push(stack, c, &top);
        }
        else
        {
            postfix[strlen(postfix)] = c;
        }
    }
    postfix[strlen(postfix)] = '\0';
}

void reverse(char *str)
{
    int length = strlen(str);
    int i;
    for (i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    for (i = 0; i < length; i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }
}

void infix_to_prefix(char *infix, char *prefix)
{
    reverse(infix);
    infix_to_postfix(infix, prefix);
    reverse(prefix);
}

int main()
{
    char infix[100] = "";
    char prefix[100] = "";
    char postfix[100] = "";

    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    infix_to_prefix(infix, prefix);

    printf("%s\n", prefix);
    printf("%s\n", postfix);
}