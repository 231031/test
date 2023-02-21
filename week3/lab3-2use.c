#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
    char *dataWord; // add InputWord function and option 4
    struct stack *next;
} stack;

void createdNode(char *str, stack **top)
{
    int i = 0;
    stack *newNode, *ptr;
    char *str2 = str;
    char strInput[100];
    *top = NULL;
    while (str[i] != '\n')
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
        newNode = (stack *)malloc(sizeof(stack));
        newNode->dataWord = (char*)malloc((i+1) * sizeof(char));
        strcpy(newNode->dataWord, strInput);
        //newNode->dataWord = strInput; // define data
        newNode->next = NULL;         // no link

        // Link new stack to the linked list
        if (*top == NULL)
        {
            *top = newNode; // if first stack, link from header
        }
        else
            ptr->next = newNode; // if latter stack, link from current
        ptr = newNode;           // move current to new stack
        //printf("%s\n", ptr->dataWord);

        if (*str2 == '\n')
        {
            break;
        }
        str2++; // skip blank space
    }

}



void popBackward(stack **top) // top is start
{
    stack *ptr = *top;
    char *str;
    if (*top == NULL)
    {
        printf("STACK UNDERFLOW");
    }
    else
    {
        *top = (*top)->next;
        str = ptr->dataWord;
        printf("%s ",str);
    }
    free(ptr);
}



int popForward(stack **top) // top is last one in linked list check pt->next == NULL
{
    char *str;
    stack *ptr = *top, *preptr = *top;
    if (*top == NULL)
    {
        printf("STACK UNDERFLOW");
    }
    else
    {
        if (ptr->next == NULL)
        {
            str = ptr->dataWord;
            printf("%s", str);
            (*top) = NULL;
            return 0;
        }
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        str = ptr->dataWord;
        printf("%s ", str);
        free(ptr);
    }
}

int main()
{
    char str[10000];
    stack *ll;
    fgets(str, 10000, stdin);
    if(str[0] == '\n')
    {
        return 0;
    }
    createdNode(str, &ll);
    while (ll != NULL)
    {
        popBackward(&ll);
    }
    printf("\n");
    createdNode(str, &ll);
    while (ll != NULL)
    {
        popForward(&ll);
    }
    return 0;
}