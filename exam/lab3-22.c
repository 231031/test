/*
Problem :

Implement two stacks, one to read input elements in forward order and another to read input elements in backward order.

Input : 

First Line : An array, arr (1 <= arr.length <= 10^5)

Output : 

First and Second Line : Pop two stacks , stack_forward ( Second Line ) and stack_backward ( First Line ) , to store the elements of the input array in the order they appear in the input, and in the reverse order, respectively.

1 2 3 4 5 6
output
1 2 3 4 5 6
6 5 4 3 2 1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char *data;
    struct stack *next;
} stack;

void push(stack **top, char *str)
{
    stack *newNode;
    newNode = (stack*) malloc(sizeof(stack));
    newNode->data = (char*) malloc(sizeof(char)*100);
    strcpy(newNode->data, str);

    if (*top == NULL)
    {
        newNode->next = NULL;
        *top = newNode;
    }
    else
    {
        newNode->next = *top;
        (*top) = newNode;
    }
}

int pop(stack **top)
{
    stack *ptr;
    char *str;
    if (*top == NULL)
    {
        printf("None\n");
        return -1;
    }
    else
    {
        ptr = *top;
        *top = (*top)->next;
        str = ptr->data;
        printf("%s ", str);
    }
    return 0;
}

int main()
{
    stack *top = NULL; // 6 5 4 3 2 1
    stack *top2 = NULL; // 1 2 3 4 5 6
    stack *ptr;
    char *token;
    int check = 0;
    char dataInput[10000];
    fgets(dataInput, 10000, stdin); // input string

    token = strtok(dataInput, " "); 
    token[strlen(token)] = '\0'; 

    // input 1 2 3 4 5 6
    // top 6 5 4 3 2 1
    while (token != NULL)
    {
        push(&top, token); // push newNode to top of stack
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            break;
        }
        if (token[strlen(token)-1] == '\n')
        {
            token[strlen(token)-1] = '\0';
        }
        else
        {
            token[strlen(token)] = '\0';
        }
    }

    // created stack2 from stack from linked 
    // stack ที่ได้ 1 2 3 4 5 6
    ptr = top;
    while (ptr != NULL)
    {
        token = ptr->data;
        push(&top2, token);
        ptr = ptr->next; // 
    }



    // print stack
    while (top2 != NULL && check != -1) // pop 1 2 3 4 5 6
    {
        check = pop(&top2);
    }
    check = 0;
    printf("\n");
    while (top != NULL && check != -1) // pop 6 5 4 3 2 1
    {
        check = pop(&top);
    }
}