#include <stdio.h>
#include <stdlib.h>

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

/*
float check .
int check 0 - 9
return 1 is int
return 2 is float
return 3 is char
*/
int checkType(char str[])
{
    int i = 0;
    while (str[i] != ' ')
    {
        if (str[i] == '.')
        {
            return 2;
        }
        else if (((str[i] >= 97 && str[i] <= 122) && str[i+1] == ' ')|| ((str[i] >= 65 && str[i] <= 90) && str[i+1] == ' '))
        {
            return 3;
        }
        else if (((str[i] >= 97 && str[i] <= 122) && (str[i+1] >= 97 && str[i + 1] <= 122)) || ((str[i] >= 65 && str[i] <= 90) && (str[i+1] >= 65 && str[i + 1] <= 90)))
        {
            return 4;
        }
        i++;
    }

    return 1;
}



void InputInt(char *str, stack **top)
{
    int num = 0;
    char *str2;
    stack *newStack, *ptr;
    *top = NULL;
    str2 = str;
    while (*str2 != '\n')
    {
        sscanf(str2, "%d", &num);

        // Generate new node
        newStack = (stack *)malloc(sizeof(stack));
        newStack->dataNum = num; // define data
        newStack->next = NULL;   // no link

        // Link new node to the linked list
        if (*top == NULL)
            *top = newStack; // if first node, link from header
        else
            ptr->next = newStack; // if latter node, link from current
        ptr = newStack;           // move current to new node

        while (*str2 != ' ' && *str2 != '\n')
        {
            str2++;
        }
        if (*str2 == '\n')
        {
            break;
        }
        str2++; // skip blank space
    }
}



void InputFloat(char *str, stack **top)
{
    char *str2;
    float num = 0;
    stack *newStack, *ptr;
    *top = NULL;

    str2 = str;
    while (*str2 != '\n')
    {
        sscanf(str2, "%f", &num);

        // Generate new node
        newStack = (stack *)malloc(sizeof(stack));
        newStack->dataFloat = num; // define data
        newStack->next = NULL;     // no link

        // Link new node to the linked list
        if (*top == NULL)
            *top = newStack; // if first node, link from header
        else
            ptr->next = newStack; // if latter node, link from current
        ptr = newStack;           // move current to new node

        while (*str2 != ' ' && *str2 != '\n')
        {
            str2++;
        }
        if (*str2 == '\n')
        {
            break;
        }
        str2++; // skip blank space
    }
}



void InputString(char *str, stack **top)
{
    char *str2;
    char strInput;
    stack *newStack, *ptr;

    str2 = str;
    while (*str2 != '\n')
    {
        sscanf(str2, "%c", &strInput);

        // Generate new node
        newStack = (stack *)malloc(sizeof(stack));
        newStack->dataStr = strInput; // define data
        newStack->next = NULL;        // no link

        // Link new node to the linked list
        if (*top == NULL)
            *top = newStack; // if first node, link from header
        else
            ptr->next = newStack; // if latter node, link from current
        ptr = newStack;           // move current to new node

        while (*str2 != ' ' && *str2 != '\n')
        {
            str2++;
        }
        if (*str2 == '\n')
        {
            break;
        }
        str2++; // skip blank space
    }
}



// cannot print ptr->dataWord  
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
        newStack->dataWord = (char*)malloc(10 * sizeof(char));
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
        //printf("%s\n", ptr->dataWord);

        if (*str2 == '\n')
        {
            break;
        }
        str2++; // skip blank space
    }
}



void popBackward(int check, stack **top) // top is start
{
    stack *ptr = *top;
    int i = 0;
    printf("%s\n", (*top)->dataWord);
    if (top == NULL)
    {
        printf("STACK UNDERFLOW");
    }
    else
    {
        *top = (*top)->next;
        if (check == 1)
        {
            printf("%d ", ptr->dataNum);
        }
        else if (check == 2)
        {
            printf("%g ", ptr->dataFloat);
        }
        else if (check == 3)
        {
            printf("%c ", ptr->dataStr);
        }
        else if (check == 4)
        {
            while (ptr->dataWord[i] != '\0')
            {
                printf("%c", ptr->dataWord[i]);
            }
            printf(" ");
            
        }
    }
    free(ptr);
}



int popForward(int check, stack **top) // top is last one in linked list check pt->next == NULL
{
    stack *ptr = *top, *preptr = *top;
    if (top == NULL)
    {
        printf("STACK UNDERFLOW");
    }
    else
    {
        if (ptr->next == NULL)
        {
            if (check == 1)
            {
                printf("%d ", ptr->dataNum);
            }
            else if (check == 2)
            {
                printf("%g", ptr->dataFloat);
            }
            else if (check == 3)
            {
                printf("%c ", ptr->dataStr);
            }
            else if (check == 4)
            {
                printf("%s ", ptr->dataWord);
            }
            (*top) = NULL;
            return 0;
        }
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        if (check == 1)
        {
            printf("%d ", ptr->dataNum);
        }
        else if (check == 2)
        {
            printf("%g ", ptr->dataFloat);
        }
        else if (check == 3)
        {
            printf("%c ", ptr->dataStr);
        }
        else if (check == 4)
        {
            printf("%s ", ptr->dataWord);
        }
        free(ptr);
    }
}



int main()
{
    char str[100];
    int check = 0;
    stack *ll;
    fgets(str, 100, stdin);
    if (str[0] == '\n')
    {
        return 0;
    }
    check = checkType(str);
    //printf("check %d", check);
    if (check == 1)
    {
        InputInt(str, &ll);
        while (ll != NULL)
        {
            popBackward(check, &ll);
        }
        printf("\n");
        InputInt(str, &ll);
        while (ll != NULL)
        {
            popForward(check, &ll);
        }
    }
    else if (check == 2)
    {
        InputFloat(str, &ll);
        while (ll != NULL)
        {
            popBackward(check, &ll);
        }
        printf("\n");
        InputFloat(str, &ll);
        while (ll != NULL)
        {
            popForward(check, &ll);
        }
    }
    else if (check == 3)
    {
        InputString(str, &ll);
        while (ll != NULL)
        {
            popBackward(check, &ll);
        }
        printf("\n");
        InputString(str, &ll);
        while (ll != NULL)
        {
            popForward(check, &ll);
        }
    }
    else if (check == 4)
    {
        InputWord(str, &ll);
        //printf("%s", ll->dataWord);
        while(ll != NULL)
        {
            popBackward(check, &ll);
        }
        printf("\n");
        InputWord(str, &ll);
        while(ll != NULL)
        {
            popForward(check, &ll);
        }
    }

    return 0;
}