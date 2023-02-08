#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    union // use just one type
    {
        int dataNum;
        float dataFloat;
        char dataStr;
        char *dataWord; // add InputWord function and option 4
    };
    struct stack *next;
} stack;

void InputWord(char *str, stack **top)
{
    int i = 0;
    int check = 0;
    char *str2;
    char strInput[10];
    stack *newStack, *ptr;
    str2 = str;

    while (*str2 != '\n')
    {
        i = 0;
        while (*str2 != ' ' && *str2 != '\n')
        {
            sscanf(str2, "%c", &strInput[i]);
            str2++;
            i++;
        }
        strInput[i] = '\0';

        // Generate new stack
        newStack = (stack *)malloc(sizeof(stack));
        newStack->dataWord = strInput; // define data
        newStack->next = NULL;         // no link

        // Link new stack to the linked list
        if (*top == NULL || check == 0)
        {
            *top = newStack; // if first stack, link from header
            check = 1;
        }
        else
            ptr->next = newStack; // if latter stack, link from current
        ptr = newStack;           // move current to new stack
        printf("%s\n", ptr->dataWord);

        if (*str2 == '\n')
        {
            break;
        }
        str2++; // skip blank space
    }
}

int main()
{
    stack *ll;
    char strInput[100];
    fgets(strInput, 100, stdin);

    InputWord(strInput, &ll);
}