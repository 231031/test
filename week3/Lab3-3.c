#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char *data;
    struct node *next;
} stack;

void createdLl(stack **start, char *str)
{
    stack *ptr, *newNode;
    int i = 0;
    *start = NULL;
    char *str2 = str;
    char *strInput;
    while (*str2 != '\n')
    {
        
        while(*str2 != ' ')
        {
            sscanf(str2, "%c", &strInput[i]);
            str2++;
            i++;
        }
        strInput[i] = '\0';

        newNode = (stack*) malloc(sizeof(stack));
        strcpy(newNode->data, strInput);
        newNode->next = NULL;
        if (*start == NULL)
        {
            *start = newNode;
        }
        else
        {
            ptr->next = newNode;
        }
        ptr = newNode;

        if (*str2 == '\n')
        {
            break;
        }
        str2++;
    }
}

void topStack(stack **top)
{
    stack *ptr;
    ptr = *top;
    while (ptr != NULL)
    {
        ptr = ptr->next;
    }
    pop(ptr);
}

void pop(stack **top)
{

}


int main()
{
    stack *ll;
    char str[1000];
    int i = 0;
    int count = 0;

    fgets(str, 10000, stdin);
    scanf("%d", &count);
    while (count != i)
    {
        i++;
    }
}