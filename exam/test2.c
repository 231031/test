#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    char data;
    struct stack *next;
} stack;


void push(stack **top, char str)
{
    stack *newNode;
    newNode = (stack*) malloc(sizeof(stack));
    newNode->data = str;

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

char pop(stack **top)
{
    stack *ptr;
    char str;
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
    }
    return str;
}

void makePalindrome(stack **top, char *str)
{
    char *str2 = str;   
    char chr;
    stack *top2;
    stack *temp;
    stack *ptr;
    int check = strlen(str);
    check = check - 1;
    int i = 0;
    int count = 0;

    //printf("%d", check);
    while (*str2 != '\n' && i != check)
    {
        push(top, *str2);
        str2++;
        i++;
    } // elpmaxE

    ptr = *top;
    i = 0;
    while (ptr != NULL && i != check)
    {
        push(&temp, ptr->data);
        ptr = ptr->next;
        i++;
    } // Example

    ptr = temp;
    i = 0;
    while (ptr != NULL && i != check)
    {
        push(&top2, ptr->data);
        ptr = ptr->next;
        i++;
    } // elpmaxE

    // use top and top2

    i = 0;
    while (top2 != NULL && i != check)
    {
        if (check%2 == 0 && count == 0)
        {
            count++;
            pop(&top2);
        }
        else
        {
            chr = pop(&top2);
            push(top, chr);
        }
        i++;
    }
    


}

int main()
{
    stack *top = NULL;
    stack *top2 = NULL;
    char input[1000];
    fgets(input, 1000, stdin);
    makePalindrome(&top, input);

    while(top != NULL)
    {
        printf("%c", top->data);
        top = top->next;
    }
    
    return 0;
}